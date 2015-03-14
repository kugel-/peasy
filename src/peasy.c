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
#include "geanyplugin.h"

#include <libpeas/peas-engine.h>
#include <libpeas/peas-activatable.h>
#include <libpeas/peas-extension-base.h>

/* These items are set by Geany before plugin_init() is called. */
GeanyPlugin		*geany_plugin;
GeanyData		*geany_data;
GeanyFunctions	*geany_functions;

/* Check that the running Geany supports the plugin API version used below, and check
 * for binary compatibility. */
PLUGIN_VERSION_CHECK(224)

/* All plugins must set name, description, version and author. */
PLUGIN_SET_INFO(
	_("Peasy"),
	_("Provides libpeas-based plugins"),
	"0.1" ,
	_("Thomas Martitz <kugel@rockbox.org>")
)

static gchar *get_mod_name(const gchar *filename)
{
	gchar *basename = g_path_get_basename(filename);
	/* strip extension */
	gchar *p = strrchr(basename, '.');
	*p = 0;
	return basename;
}

gboolean peasy_probe(const gchar *filename, gpointer proxy_data)
{
	gboolean result;
	PeasEngine *peas = (PeasEngine *) proxy_data;
	gchar *modname = get_mod_name(filename);
	result = peas_engine_get_plugin_info(peas, modname) != NULL;
	g_free(modname);
	return result;
}

void peas_proxy_set_info(PluginInfo *info, gpointer pdata)
{
	PeasPluginInfo *info_;
	g_object_get(PEAS_ACTIVATABLE(pdata), "plugin-info", &info_, NULL);
	info->name = peas_plugin_info_get_name(info_);
	info->description = peas_plugin_info_get_description(info_);
	info->version = peas_plugin_info_get_version(info_);
	info->author = peas_plugin_info_get_authors(info_)[0];
}

gint peas_proxy_version_check(gint abi_ver, gpointer pdata)
{
	return GEANY_API_VERSION;
}

void peas_proxy_init(GeanyData *data, gpointer pdata)
{
	printf("Hello Peas!\n"); 
	peas_activatable_activate(PEAS_ACTIVATABLE(pdata));
}

GtkWidget* peas_proxy_configure(GtkDialog *dialog, gpointer pdata)
{
}

void peas_proxy_configure_single(GtkWidget *parent, gpointer pdata)
{
}

void peas_proxy_help(gpointer pdata)
{
}

void peas_proxy_cleanup(gpointer pdata)
{
	printf("Bye Peas!\n");
	peas_activatable_deactivate(PEAS_ACTIVATABLE(pdata));
}

gboolean peasy_load(GeanyPlugin *plugin, const gchar *filename, gpointer proxy_data, PluginHooks *hooks, gpointer *plugin_data)
{
	printf("%s() %s\n", __func__, filename);
	PeasEngine *peas = (PeasEngine *) proxy_data;
	gchar *modname = get_mod_name(filename);
	gboolean loaded;
	PeasPluginInfo *info = peas_engine_get_plugin_info(peas, modname);
	PeasExtension *obj;
	g_free(modname);

	if (!modname)
		printf("error\n");

	loaded = peas_engine_load_plugin(peas, info);
	if (!loaded)
		return FALSE;

	if (!peas_engine_provides_extension(peas, info, PEAS_TYPE_ACTIVATABLE))
		return FALSE;

	hooks->version_check = peas_proxy_version_check;
	hooks->set_info = peas_proxy_set_info;
	hooks->init = peas_proxy_init;
	hooks->cleanup = peas_proxy_cleanup;

	obj = peas_engine_create_extension(peas, info, PEAS_TYPE_ACTIVATABLE, NULL);
	if (!info)
		printf("error\n");
	g_object_get(obj, "plugin-info", &info, NULL);
	if (!info)
		printf("error 2\n");

	/* TODO: perform ABI check */

	*plugin_data = obj;
	return TRUE;
}
void peasy_unload(GeanyPlugin *plugin, gpointer proxy_data, gpointer plugin_data)
{
	printf("%s()\n", __func__);
	PeasEngine *peas = (PeasEngine *) proxy_data;
	PeasExtension *obj = PEAS_EXTENSION(plugin_data);
	PeasPluginInfo *info;
	g_object_get(obj, "plugin-info", &info, NULL);
	peas_engine_unload_plugin(peas, info);
}

/* Called by Geany to initialize the plugin.
 * Note: data is the same as geany_data. */
void plugin_init(GeanyData *data)
{
	const gchar *extensions[] = { "plugin", NULL };
	PluxyHooks hooks = {
		.probe  = peasy_probe,
		.load   = peasy_load,
		.unload = peasy_unload,
	};
	PeasEngine *peas = peas_engine_get_default();
	plugin_register_proxy(geany_plugin, extensions, &hooks, sizeof(hooks), peas);

	peas_engine_enable_loader(peas, "python");

	peas_engine_add_search_path(peas, GEANY_PLUGINDIR, data->app->datadir);

	plugin_module_make_resident(geany_plugin);
}

/* Called by Geany before unloading the plugin.
 * Here any UI changes should be removed, memory freed and any other finalization done.
 * Be sure to leave Geany as it was before plugin_init(). */
void plugin_cleanup(void)
{
	printf("plugin_exit\n");
}
