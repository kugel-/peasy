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
#include "peasy.h"

#include <gmodule.h>
#include <libpeas/peas-object-module.h>
#include <libpeas/peas-activatable.h>
#include <libpeas/peas-extension-base.h>


#define PEASY_TYPE_TEST			(peasy_test_get_type ())
#define PEASY_TEST(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_TEST, PeasyTest))
#define PEASY_TEST_CONST(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_TEST, PeasyTest const))
#define PEASY_TEST_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_TEST, PeasyTestClass))
#define PEASY_IS_TEST(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_TEST))
#define PEASY_IS_TEST_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_TEST))
#define PEASY_TEST_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_TEST, PeasyTestClass))

typedef struct _PeasyTest	PeasyTest;
typedef struct _PeasyTestClass	PeasyTestClass;

struct _PeasyTest
{
	PeasyPlugin parent;
};

struct _PeasyTestClass
{
	PeasyPluginClass parent_class;
};

GType peasy_test_get_type (void) G_GNUC_CONST;
PeasyTest *peasy_test_new (void);

static void
peasy_test_finalize (GObject *object);

typedef struct _PeasyTestPrivate
{
	int dummy;
} PeasyTestPrivate;


static gboolean peasy_test_enable(PeasyPlugin *self)
{
	printf("%s(): Hello from %s!\n", __func__, self->geany_plugin->info->name);

	return TRUE;
}


static void peasy_test_disable(PeasyPlugin *self)
{
	printf("%s()\n", __func__);
}

G_DEFINE_TYPE_WITH_CODE (PeasyTest, peasy_test, PEASY_TYPE_PLUGIN,
	G_IMPLEMENT_INTERFACE(PEASY_TYPE_PLUGIN_IFACE, NULL);
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

	klass->parent_class.enable = peasy_test_enable;
	klass->parent_class.disable = peasy_test_disable;

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


G_MODULE_EXPORT
void peas_register_types(PeasObjectModule *mod)
{
	peas_object_module_register_extension_type(mod, PEASY_TYPE_PLUGIN_IFACE, PEASY_TYPE_TEST);
}
