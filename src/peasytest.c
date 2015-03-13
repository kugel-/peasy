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

#include <gmodule.h>
#include <libpeas/peas-object-module.h>
#include <libpeas/peas-activatable.h>
#include <libpeas/peas-extension-base.h>

#include "peasytest.h"

G_MODULE_EXPORT
void peas_register_types(PeasObjectModule *mod)
{
	peas_object_module_register_extension_type(mod, PEAS_TYPE_ACTIVATABLE, PEASY_TYPE_TEST);
	printf("Success\n");
}


/*
 * NOTE: In a real plugin plugins would inherit from a GeanyPluginXXX class instead
 * of generic PeasActivatable
 **/


static void
peasy_test_finalize (GObject *object);

typedef struct _PeasyTestPrivate
{
} PeasyTestPrivate;


static void peasy_test_activate(PeasActivatable *act)
{
	printf("%s()\n");
}

static void peasy_test_deactivate(PeasActivatable *act)
{
	printf("%s()\n");
}

static void peasy_test_update_state(PeasActivatable *act)
{
	printf("%s()\n");
}

static void peasy_test_iface_init(PeasActivatableInterface *iface)
{
	iface->activate     = peasy_test_activate;
	iface->deactivate   = peasy_test_deactivate;
	iface->update_state = peasy_test_update_state;
}

G_DEFINE_TYPE_WITH_CODE (PeasyTest, peasy_test, PEAS_TYPE_EXTENSION_BASE,
	G_IMPLEMENT_INTERFACE(PEAS_TYPE_ACTIVATABLE, peasy_test_iface_init);
	G_ADD_PRIVATE(PeasyTest))

static void
peasy_test_finalize (GObject *object)
{
	G_OBJECT_CLASS (peasy_test_parent_class)->finalize (object);
}

static void
peasy_test_class_init (PeasyTestClass *klass)
{
	GObjectClass *object_class = G_OBJECT_CLASS (klass);

	object_class->finalize = peasy_test_finalize;
}

static void
peasy_test_init (PeasyTest *self)
{
}

PeasyTest *
peasy_test_new ()
{
	return g_object_new (PEASY_TYPE_TEST, NULL);
}
