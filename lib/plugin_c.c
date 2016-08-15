#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <geanyplugin.h>

const gchar *peasy_get_locale_dir()
{
    return LOCALEDIR;
}

const gchar *peasy_gettext(const gchar *msgid)
{
    return g_dgettext(GETTEXT_PACKAGE, msgid);
}

gboolean peasy_do_check_abi(gint abi_ver)
{
    return abi_ver == GEANY_ABI_VERSION;
}
