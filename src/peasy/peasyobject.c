/* peasyobject.c generated by valac, the Vala compiler
 * generated from peasyobject.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <geanyplugin.h>
#include <stdlib.h>
#include <string.h>


#define PEASY_TYPE_OBJECT (peasy_object_get_type ())
#define PEASY_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_OBJECT, PeasyObject))
#define PEASY_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_OBJECT, PeasyObjectClass))
#define PEASY_IS_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_OBJECT))
#define PEASY_IS_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_OBJECT))
#define PEASY_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_OBJECT, PeasyObjectClass))

typedef struct _PeasyObject PeasyObject;
typedef struct _PeasyObjectClass PeasyObjectClass;
typedef struct _PeasyObjectPrivate PeasyObjectPrivate;

struct _PeasyObject {
	GObject parent_instance;
	PeasyObjectPrivate * priv;
};

struct _PeasyObjectClass {
	GObjectClass parent_class;
};


static gpointer peasy_object_parent_class = NULL;
extern GeanyPlugin* peasy_object_peasy_plugin;
GeanyPlugin* peasy_object_peasy_plugin = NULL;

void plugin_signal_connect (GeanyPlugin* p, GObject* obj, const gchar* signal_name, gboolean after, GCallback cb, void* data);
GType peasy_object_get_type (void) G_GNUC_CONST;
enum  {
	PEASY_OBJECT_DUMMY_PROPERTY
};
void peasy_object_signal_connect (GObject* obj, const gchar* signal_name, gboolean after, GCallback cb, void* data);
PeasyObject* peasy_object_new (void);
PeasyObject* peasy_object_construct (GType object_type);
static void peasy_object_finalize (GObject* obj);


void peasy_object_signal_connect (GObject* obj, const gchar* signal_name, gboolean after, GCallback cb, void* data) {
	GObject* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	gboolean _tmp2_ = FALSE;
	GCallback _tmp3_ = NULL;
	void* _tmp4_ = NULL;
	g_return_if_fail (signal_name != NULL);
	_tmp0_ = obj;
	_tmp1_ = signal_name;
	_tmp2_ = after;
	_tmp3_ = cb;
	_tmp4_ = data;
	plugin_signal_connect (peasy_object_peasy_plugin, _tmp0_, _tmp1_, _tmp2_, _tmp3_, _tmp4_);
}


PeasyObject* peasy_object_construct (GType object_type) {
	PeasyObject * self = NULL;
	self = (PeasyObject*) g_object_new (object_type, NULL);
	return self;
}


PeasyObject* peasy_object_new (void) {
	return peasy_object_construct (PEASY_TYPE_OBJECT);
}


static void peasy_object_class_init (PeasyObjectClass * klass) {
	peasy_object_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = peasy_object_finalize;
}


static void peasy_object_instance_init (PeasyObject * self) {
}


static void peasy_object_finalize (GObject* obj) {
	PeasyObject * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, PEASY_TYPE_OBJECT, PeasyObject);
	G_OBJECT_CLASS (peasy_object_parent_class)->finalize (obj);
}


GType peasy_object_get_type (void) {
	static volatile gsize peasy_object_type_id__volatile = 0;
	if (g_once_init_enter (&peasy_object_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (PeasyObjectClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) peasy_object_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PeasyObject), 0, (GInstanceInitFunc) peasy_object_instance_init, NULL };
		GType peasy_object_type_id;
		peasy_object_type_id = g_type_register_static (G_TYPE_OBJECT, "PeasyObject", &g_define_type_info, 0);
		g_once_init_leave (&peasy_object_type_id__volatile, peasy_object_type_id);
	}
	return peasy_object_type_id__volatile;
}


