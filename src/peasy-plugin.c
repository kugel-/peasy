/*
 *      peas.c - libpeas-based plugin provider for Geany
 *
 *      Copyright 2015 Thomas Martitz <kugel@rockbox.org>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License along
 *      with this program; if not, write to the Free Software Foundation, Inc.,
 *      51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

/* plugin API, always comes first */
#include <geanyplugin.h>

#include <libpeas/peas-engine.h>
#include <libpeas/peas-activatable.h>
#include <libpeas/peas-extension-base.h>

static gchar *
get_mod_name(const gchar *filename)
{
	gchar *basename = g_path_get_basename(filename);
	/* strip extension */
	gchar *p = strrchr(basename, '.');
	*p = 0;
	if (g_str_has_prefix(basename, "lib"))
		memmove(basename, basename+3, strlen(basename)-3+1 /* copy NUL too */);

	return basename;
}


static gboolean
peas_proxy_init(GeanyPlugin *plugin, gpointer pdata)
{
	printf("Hello Peas!\n"); 
	peas_activatable_activate(PEAS_ACTIVATABLE(pdata));
	return TRUE;
}


static GtkWidget *
peas_proxy_configure(GeanyPlugin *plugin, GtkDialog *dialog, gpointer pdata)
{
}


static void
peas_proxy_help(GeanyPlugin *plugin, gpointer pdata)
{
}


static void
peas_proxy_cleanup(GeanyPlugin *plugin, gpointer pdata)
{
	printf("Bye Peas!\n");
	peas_activatable_deactivate(PEAS_ACTIVATABLE(pdata));
}


static gint
peasy_probe(GeanyPlugin *plugin, const gchar *filename, gpointer pdata)
{
	gint ret = PROXY_IGNORED;
	PeasEngine *peas = (PeasEngine *) pdata;
	gchar *modname = get_mod_name(filename);
	if (peas_engine_get_plugin_info(peas, modname) != NULL)
	{
		/* We only *load* .plugin files, however we are
		 * responsible for the corresponding code as wel */
		ret = PROXY_MATCHED;
		if (!g_strrstr(filename, ".plugin"))
			ret |= PROXY_NOLOAD;
	}
	g_free(modname);

	return ret;
}


static gpointer
peasy_load(GeanyPlugin *plugin, GeanyPlugin *inferior,
           const gchar *filename, gpointer pdata)
{
	PeasEngine *peas = (PeasEngine *) pdata;
	gchar *modname = get_mod_name(filename);
	gboolean loaded;
	PeasPluginInfo *info = peas_engine_get_plugin_info(peas, modname);
	PeasExtension *obj;
	g_free(modname);

	if (!info)
		return NULL;

	loaded = peas_engine_load_plugin(peas, info);
	if (!loaded)
		return NULL;

	if (!peas_engine_provides_extension(peas, info, PEAS_TYPE_ACTIVATABLE))
		goto unload;

	obj = peas_engine_create_extension(peas, info, PEAS_TYPE_ACTIVATABLE, NULL);
	if (!obj)
		goto unload;

	inferior->info->name = peas_plugin_info_get_name(info);
	inferior->info->description = peas_plugin_info_get_description(info);
	inferior->info->version = peas_plugin_info_get_version(info);
	inferior->info->author = peas_plugin_info_get_authors(info)[0];

	inferior->funcs->init = peas_proxy_init;
	inferior->funcs->cleanup = peas_proxy_cleanup;

	/* TODO: perform ABI check */
	if (GEANY_PLUGIN_REGISTER(inferior, 224))
	{
		/* Don't pass g_object_unref because the object needs to be still alive
		 * in peasy_unload() */
		geany_plugin_set_data(inferior, obj, NULL);
		return obj;
	}

unref:
	g_object_unref(obj);
unload:
	peas_engine_unload_plugin(peas, info);
	return NULL;
}


static void
peasy_unload(GeanyPlugin *plugin, GeanyPlugin *inferior, gpointer proxy_data, gpointer pdata)
{
	PeasEngine *peas = (PeasEngine *) pdata;
	PeasExtension *obj = PEAS_EXTENSION(proxy_data);
	PeasPluginInfo *info;

	g_object_get(obj, "plugin-info", &info, NULL);
	g_object_unref(obj);
	peas_engine_unload_plugin(peas, info);
}


extern GeanyPlugin *peasy_object_peasy_plugin;
/* Called by Geany to initialize the plugin */
static gboolean
peasy_init(GeanyPlugin *plugin, gpointer pdata)
{
	const gchar *extensions[] = { "plugin", "so", NULL };
	PeasEngine *peas = peas_engine_get_default();
	GError *err = NULL;
	GITypelib *t;

	geany_plugin_set_data(plugin, peas, g_object_unref);
	geany_plugin_register_proxy(plugin, extensions);

	peas_engine_enable_loader(peas, "python");
	peas_engine_add_search_path(peas, GEANY_PLUGINDIR, plugin->geany_data->app->datadir);

	if (strncmp(TYPELIBDIR, "/usr/lib", 8))
		g_irepository_prepend_search_path(TYPELIBDIR);
	t = g_irepository_require(NULL, "Peasy", NULL, 0, &err);
	g_clear_error(&err);

	peasy_object_peasy_plugin = plugin;

	return t != NULL;
}


/* Called by Geany before unloading the plugin.
 * Here any UI changes should be removed, memory freed and any other finalization done.
 * Be sure to leave Geany as it was before plugin_init(). */
static void
peasy_cleanup(GeanyPlugin *plugin, gpointer pdata)
{
	printf("plugin_exit\n");
}


G_MODULE_EXPORT void
geany_load_module(GeanyPlugin *plugin)
{
	plugin->info->name = _("Peasy");
	plugin->info->description = _("Provides libpeas-based plugins");
	plugin->info->version = "0.1";
	plugin->info->author = _("Thomas Martitz <kugel@rockbox.org>");
	plugin_module_make_resident(plugin);

	plugin->funcs->init = peasy_init;
	plugin->funcs->cleanup = peasy_cleanup;

	plugin->proxy_funcs->probe  = peasy_probe;
	plugin->proxy_funcs->load   = peasy_load;
	plugin->proxy_funcs->unload = peasy_unload;

	GEANY_PLUGIN_REGISTER(plugin, 225);
}
