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

/* plugin API, always comes first */
#include "geanyplugin.h"

#include <libpeas/peas-engine.h>

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

/* Called by Geany to initialize the plugin.
 * Note: data is the same as geany_data. */
void plugin_init(GeanyData *data)
{
	printf("plugin_init\n");
}

/* Called by Geany before unloading the plugin.
 * Here any UI changes should be removed, memory freed and any other finalization done.
 * Be sure to leave Geany as it was before plugin_init(). */
void plugin_cleanup(void)
{
	printf("plugin_exit\n");
}
