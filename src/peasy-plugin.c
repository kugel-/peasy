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
#include <libpeas/peas-object-module.h>

#include "peasy.h"

typedef struct PluginContext {
    PeasEngine     *engine;
    PeasPluginInfo *info;
    PeasyPlugin    *plugin;
}
PluginContext;

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

static gboolean is_native_plugin(const gchar *filename)
{
    /* It would be slightly more reliable to check against the plugin's
     * loader but libpeas doesn't provide that */
    return g_str_has_suffix(filename, "." G_MODULE_SUFFIX);
}

static gboolean
peas_proxy_init(GeanyPlugin *plugin, gpointer pdata)
{
    PluginContext *ctx = pdata;
    PeasExtension *obj;

    obj = peas_engine_create_extension(ctx->engine, ctx->info, PEASY_TYPE_PLUGIN_IFACE, NULL);
    if (PEASY_IS_PLUGIN(obj)) {
        ctx->plugin = (PeasyPlugin *) obj;
        ctx->plugin->geany_plugin = plugin;
        if (peasy_plugin_enable(PEASY_PLUGIN(ctx->plugin)))
            return TRUE;

        g_object_unref(ctx->plugin);
        ctx->plugin = NULL;
    }
    else if (obj != NULL) {
        g_warning("Error: Type %s implements PeasyPluginIface but does not inherit from PeasyPlugin",
            g_type_name(G_TYPE_FROM_INSTANCE(obj)));
    }

    return FALSE;
}


static GtkWidget *
peas_proxy_configure(GeanyPlugin *plugin, GtkDialog *dialog, gpointer pdata)
{
    PluginContext *ctx = pdata;

    return peasy_plugin_configure_configure(PEASY_PLUGIN_CONFIGURE(ctx->plugin), dialog);
}


static void
peas_proxy_help(GeanyPlugin *plugin, gpointer pdata)
{
    PluginContext *ctx = pdata;

    peasy_plugin_help_help(PEASY_PLUGIN_HELP(ctx->plugin));
}


static void
peas_proxy_cleanup(GeanyPlugin *plugin, gpointer pdata)
{
    PluginContext *ctx = pdata;

    peasy_plugin_disable(PEASY_PLUGIN(ctx->plugin));

    g_object_unref(ctx->plugin);
    ctx->plugin = NULL;
}

#define MAKE_OP(op) (op[0] | ((op[1] << 8)))
#define EQ          ( '='  | ( '='  << 8))
#define NE          ( '!'  | ( '='  << 8))
#define GT          ( '>'  | (  0  << 8))
#define GE          ( '>'  | ( '='  << 8))
#define LT          ( '<'  | (  0  << 8))
#define LE          ( '<'  | ( '='  << 8))

#define ENCODE_VERSION(major, minor, micro) \
    ((major) * 10000000 + (minor) * 1000 + (micro))

static gboolean
do_check_compatibility(const gchar *requirements)
{
    /* We support checking library requirements
     * via the key X-Peasy-Requires in .plugin files. Currently
     * only gtk2, gtk3 and glib2 can be checked. */
    gchar *p, **strv;
    gint is_compatible = 1;
    gint i = 0;

    strv = g_strsplit_set(requirements, ",;", -1);

    while ((p = strv[i++]))
    {
        gint  any_is_compatible = 0;
        gchar *q, **or_strv = g_strsplit(p, "|", -1);
        int j = 0;

        while ((q = or_strv[j++]))
        {
            gchar  pkg[32], op[4], version[16];
            gint   imajor, iminor, imicro, iversion;
            gint   libversion = 0;
            gint   result = 0;

            while (g_ascii_isspace(*q))
                q++;

            /* string is expected to of the form
             * <pkg-config name> <op> <version>
             * pkg-config name: one of glib2 or gtk
             * (more could be added but the library must provide a runtime
             * version check but we'd probably need to link that lib)
             * op: one of >, >=, ==, <, <<, !=
             * version: format major.minor.micro
             */

            if (sscanf(q, "%31s %3s %15s", pkg, op, version) != 3)
            {
                g_warning("malformed requirement string \"%s\"\n", q);
                break;
            }

            switch (sscanf(version, "%d.%d.%d", &imajor, &iminor, &imicro))
            {
                case 1:
                    iminor = 0;
                    /* fall through */
                case 2:
                    imicro = 0;
                    /* fall through */
                case 3:
                    break;
                default:
                    g_warning("malformed version string \"%s\"\n", version);
                    continue;
            }
            iversion = ENCODE_VERSION(imajor, iminor, imicro);

            if (g_str_equal(pkg, "gtk2") || (g_str_equal(pkg, "gtk3")))
            {   /* major must match (gtk >= 2.24 must not pass for gtk3). This
                 * results in "incompatible" even if the op is != which may
                 * sound illogical but is convinient. */
                if (gtk_major_version != imajor)
                    continue;

                libversion = ENCODE_VERSION(gtk_major_version,
                                            gtk_minor_version,
                                            gtk_micro_version);
            }
            else if (g_str_equal(pkg, "glib2"))
            {   /* Current glib must match the pkg, same gotcha as for gtk */
                if (glib_major_version != imajor)
                    continue;
                libversion = ENCODE_VERSION(glib_major_version,
                                            glib_minor_version,
                                            glib_micro_version);
            }
            else
            {
                g_warning("unknown pkg \"%s\"\n", pkg);
                continue;
            }
            switch (MAKE_OP(op))
            {
                case EQ: result = libversion == iversion; break;
                case NE: result = libversion != iversion; break;
                case GT: result = libversion  > iversion; break;
                case GE: result = libversion >= iversion; break;
                case LT: result = libversion  < iversion; break;
                case LE: result = libversion <= iversion; break;
                default:
                    g_warning("malformed comparison \"%s\"\n", op);
                    continue;
            }
            any_is_compatible = any_is_compatible || result;
        }
        is_compatible = is_compatible && any_is_compatible;
        g_strfreev(or_strv);
    }
    g_strfreev(strv);

    return is_compatible;
}


static gboolean
check_compatibility(PeasPluginInfo *info)
{
    const char *s = peas_plugin_info_get_external_data(info, "X-Peasy-Requires");
    if (EMPTY(s))
        return TRUE;

    if (!do_check_compatibility(s))
    {
        printf("Plugin \"%s\" has unmet requirements! It requires:\n  \"%s\"\n",
                peas_plugin_info_get_name(info), s);
        return FALSE;
    }
    return TRUE;
}


static gboolean
check_key_present(PeasPluginInfo *info, const gchar *key)
{
    if (!peas_plugin_info_get_external_data(info, key))
    {
        g_warning("Plugin \"%s\" is not compatible with Peasy.\n"
                  "It lacks the %s specification in the .plugin file.\n",
                  peas_plugin_info_get_name(info), key);
        return FALSE;
    }
    return TRUE;
}


static gint
peasy_probe(GeanyPlugin *plugin, const gchar *filename, gpointer pdata)
{
    gint ret = PROXY_IGNORED;
    PeasEngine *peas = (PeasEngine *) pdata;
    gchar *modname = get_mod_name(filename);
    PeasPluginInfo *info = peas_engine_get_plugin_info(peas, modname);
    if (info != NULL)
    {
        /* We only *load* .plugin files, however we are
         * responsible for the corresponding code as well (so
         * we match for any file which has a corresponding .plugin file).
         *
         * Additionally, we check some compatibility: The plugin
         * can specifiy requirements using the X-Peasy-Requires key.
         * This is optional. We also check against Geany's specific
         * API version. The X-Peasy-API key is required for all
         * plugins, and must be lower or equal to Geany's reported API.
         * The actual API compatibility test is performed by Geany
         * (along with an ABI check for native plugins).
         * */
        ret = PROXY_MATCHED;
        if (!g_strrstr(filename, ".plugin"))
            ret |= PROXY_NOLOAD;
        else if (!check_compatibility(info))
            ret |= PROXY_NOLOAD;
        else if (!check_key_present(info, "X-Peasy-API"))
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
    PluginContext *ctx;
    gint api, abi;
    const gchar *str;
    guint64 val;

    if (!info)
        return NULL;

    loaded = peas_engine_load_plugin(peas, info);
    if (!loaded)
        return NULL;

    if (!peas_engine_provides_extension(peas, info, PEASY_TYPE_PLUGIN_IFACE))
        goto unload;

    inferior->info->name = peas_plugin_info_get_name(info);
    inferior->info->description = peas_plugin_info_get_description(info);
    inferior->info->version = peas_plugin_info_get_version(info);
    inferior->info->author = peas_plugin_info_get_authors(info)[0];

    inferior->funcs->init = peas_proxy_init;
    inferior->funcs->cleanup = peas_proxy_cleanup;

    if (peas_engine_provides_extension(peas, info, PEASY_TYPE_PLUGIN_CONFIGURE))
        inferior->funcs->configure = peas_proxy_configure;
    if (peas_engine_provides_extension(peas, info, PEASY_TYPE_PLUGIN_HELP))
        inferior->funcs->help = peas_proxy_help;

    ctx = g_new(PluginContext, 1);
    ctx->info = info;
    ctx->engine = peas;

    str = peas_plugin_info_get_external_data(info, "X-Peasy-API");
    val = g_ascii_strtoull(str, NULL, 10);
    api = MIN(val, G_MAXINT);

    if (is_native_plugin(filename))
    {   /* The true ABI must be exposed by calling peasy_check_abi()
           inside peas_register_types(). */
        if (!g_hash_table_contains(peasy_native_abis, modname)) {
            g_warning("Plugin \"%s\" not loaded because of unknown ABI!", inferior->info->name);
            goto unload;
        }
        abi = GPOINTER_TO_INT(g_hash_table_lookup(peasy_native_abis, modname));
    }
    else
    {   /* for scripts the abi is not applicable */
        abi = GEANY_ABI_VERSION;
    }
    /* register the plugin using api and abi values provided by inferior */
    if (geany_plugin_register_full(inferior, GEANY_API_VERSION, api, abi, ctx, g_free))
        return info;

unload:
    g_hash_table_remove(peasy_native_abis, modname);
    peas_engine_unload_plugin(peas, info);
    return NULL;
}


static void
peasy_unload(GeanyPlugin *plugin, GeanyPlugin *inferior, gpointer proxy_data, gpointer pdata)
{
    PeasEngine *peas = pdata;
    PeasPluginInfo *info = proxy_data;
    const gchar *modname = peas_plugin_info_get_module_name(info);

    g_hash_table_remove(peasy_native_abis, modname);
    peas_engine_unload_plugin(peas, info);
}


/* Called by Geany to initialize the plugin */
static gboolean
peasy_init(GeanyPlugin *plugin, gpointer pdata)
{
    const gchar *extensions[] = { "plugin", G_MODULE_SUFFIX, NULL };
    PeasEngine *peas = peas_engine_get_default();
    GError *err = NULL;
    GITypelib *t;
    static gchar pypath[256];
    const gchar *envp;

    /* Workaround for libpeas < 1.17 which blindly pops sys.path[0] which
     * happens to be /usr/lib/pythonX.Y containing standard modules. It is
     * fixed in libpeas 1.18 and later */
    envp =  g_getenv("PYTHONPATH");
    if (!envp)
    {
        g_strlcpy(pypath, "/__DUMMY_PATH_FOR_WORKAROUND__", sizeof(pypath));
        g_setenv("PYTHONPATH", pypath, TRUE);
    }
    else if (!g_strstr_len(envp, -1, "__DUMMY_PATH_FOR_WORKAROUND__"))
    {
        g_snprintf(pypath, sizeof(pypath), "/__DUMMY_PATH_FOR_WORKAROUND__:%s", envp);
        g_setenv("PYTHONPATH", pypath, TRUE);
    }

    peas_engine_enable_loader(peas, "python3");
#ifdef G_OS_WIN32
    {
        /* TODO: export and use utils_resource_dir() */
        gchar *prefix = g_win32_get_package_installation_directory_of_module(NULL);
        gchar *plugindir = g_build_filename(prefix, "lib", "geany", NULL);
        peas_engine_add_search_path(peas, plugindir, plugin->geany_data->app->datadir);
        g_free(prefix);
        g_free(plugindir);
    }
#else
    peas_engine_add_search_path(peas, GEANY_PLUGINDIR, plugin->geany_data->app->datadir);
#endif
    peas_engine_add_search_path(peas, plugin->geany_data->prefs->custom_plugin_path, plugin->geany_data->app->datadir);

    if (strncmp(TYPELIBDIR, "/usr/lib", 8))
        g_irepository_prepend_search_path(TYPELIBDIR);

    t = g_irepository_require(NULL, "Peasy", NULL, 0, &err);
    if (err)
    {
        g_warning("peasy failed to initialize: %s", err->message);
        g_object_unref(peas);
        t = NULL;
    }
    else
    {
        peasy_static_init(plugin);
        geany_plugin_set_data(plugin, peas, g_object_unref);
        geany_plugin_register_proxy(plugin, extensions);
        plugin_module_make_resident(plugin);
    }

    g_clear_error(&err);

    return t != NULL;
}


/* Called by Geany before unloading the plugin.
 * Here any UI changes should be removed, memory freed and any other finalization done.
 * Be sure to leave Geany as it was before plugin_init(). */
static void
peasy_cleanup(GeanyPlugin *plugin, gpointer pdata)
{
}

G_MODULE_EXPORT void
geany_load_module(GeanyPlugin *plugin)
{
    main_locale_init(LOCALEDIR, GETTEXT_PACKAGE);

    plugin->info->name = "Peasy";
    plugin->info->description = _("Provides libpeas-based plugins.");
    plugin->info->version = "0.2";
    plugin->info->author = "Thomas Martitz <kugel@rockbox.org>";

    plugin->funcs->init = peasy_init;
    plugin->funcs->cleanup = peasy_cleanup;

    plugin->proxy_funcs->probe  = peasy_probe;
    plugin->proxy_funcs->load   = peasy_load;
    plugin->proxy_funcs->unload = peasy_unload;

    GEANY_PLUGIN_REGISTER(plugin, 225);
}
