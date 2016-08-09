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

#define PEASY_TYPE_SIGNALS (peasy_signals_get_type ())
#define PEASY_SIGNALS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_SIGNALS, PeasySignals))
#define PEASY_SIGNALS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_SIGNALS, PeasySignalsClass))
#define PEASY_IS_SIGNALS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_SIGNALS))
#define PEASY_IS_SIGNALS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_SIGNALS))
#define PEASY_SIGNALS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_SIGNALS, PeasySignalsClass))

typedef struct _PeasySignals PeasySignals;
typedef struct _PeasySignalsClass PeasySignalsClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_hash_table_unref0(var) ((var == NULL) ? NULL : (var = (g_hash_table_unref (var), NULL)))
typedef struct _PeasyObjectPrivate PeasyObjectPrivate;
typedef struct _PeasySignalsPrivate PeasySignalsPrivate;

#define PEASY_TYPE_DOCUMENT (peasy_document_get_type ())
#define PEASY_DOCUMENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_DOCUMENT, PeasyDocument))
#define PEASY_DOCUMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_DOCUMENT, PeasyDocumentClass))
#define PEASY_IS_DOCUMENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_DOCUMENT))
#define PEASY_IS_DOCUMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_DOCUMENT))
#define PEASY_DOCUMENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_DOCUMENT, PeasyDocumentClass))

typedef struct _PeasyDocument PeasyDocument;
typedef struct _PeasyDocumentClass PeasyDocumentClass;

#define PEASY_TYPE_FILETYPE (peasy_filetype_get_type ())
#define PEASY_FILETYPE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_FILETYPE, PeasyFiletype))
#define PEASY_FILETYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_FILETYPE, PeasyFiletypeClass))
#define PEASY_IS_FILETYPE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_FILETYPE))
#define PEASY_IS_FILETYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_FILETYPE))
#define PEASY_FILETYPE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_FILETYPE, PeasyFiletypeClass))

typedef struct _PeasyFiletype PeasyFiletype;
typedef struct _PeasyFiletypeClass PeasyFiletypeClass;

struct _PeasyObject {
	GObject parent_instance;
	PeasyObjectPrivate * priv;
};

struct _PeasyObjectClass {
	GObjectClass parent_class;
};

struct _PeasyObjectPrivate {
	PeasySignals* _plugin_signals;
};

struct _PeasySignals {
	PeasyObject parent_instance;
	PeasySignalsPrivate * priv;
};

struct _PeasySignalsClass {
	PeasyObjectClass parent_class;
};


extern GeanyPlugin* peasy_peasy_plugin;
GeanyPlugin* peasy_peasy_plugin = NULL;
extern PeasySignals* peasy_peasy_signals;
PeasySignals* peasy_peasy_signals = NULL;
extern GHashTable* peasy_native_abis;
static gpointer peasy_object_parent_class = NULL;
static gpointer peasy_signals_parent_class = NULL;

void plugin_signal_connect (GeanyPlugin* p, GObject* obj, const gchar* signal_name, gboolean after, GCallback cb, void* data);
GType peasy_object_get_type (void) G_GNUC_CONST;
GType peasy_signals_get_type (void) G_GNUC_CONST;
void peasy_static_init (GeanyPlugin* p);
PeasySignals* peasy_signals_new (void);
PeasySignals* peasy_signals_construct (GType object_type);
static void _g_free0_ (gpointer var);
#define PEASY_OBJECT_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), PEASY_TYPE_OBJECT, PeasyObjectPrivate))
enum  {
	PEASY_OBJECT_DUMMY_PROPERTY,
	PEASY_OBJECT_PLUGIN_SIGNALS
};
void peasy_object_signal_connect (GObject* obj, const gchar* signal_name, gboolean after, GCallback cb, void* data);
PeasyObject* peasy_object_new (void);
PeasyObject* peasy_object_construct (GType object_type);
PeasySignals* peasy_object_get_plugin_signals (PeasyObject* self);
static void peasy_object_set_plugin_signals (PeasyObject* self, PeasySignals* value);
static GObject * peasy_object_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void peasy_object_finalize (GObject* obj);
static void _vala_peasy_object_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_peasy_object_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
enum  {
	PEASY_SIGNALS_DUMMY_PROPERTY
};
static void peasy_signals_emit_new (GObject* obj, GeanyDocument* geany_doc, PeasySignals* sig);
PeasyDocument* peasy_document_new (GeanyDocument* doc);
PeasyDocument* peasy_document_construct (GType object_type, GeanyDocument* doc);
GType peasy_document_get_type (void) G_GNUC_CONST;
static void peasy_signals_emit_open (GObject* obj, GeanyDocument* geany_doc, PeasySignals* sig);
static void peasy_signals_emit_activate (GObject* obj, GeanyDocument* geany_doc, PeasySignals* sig);
static void peasy_signals_emit_reload (GObject* obj, GeanyDocument* geany_doc, PeasySignals* sig);
static void peasy_signals_emit_before_save (GObject* obj, GeanyDocument* geany_doc, PeasySignals* sig);
static void peasy_signals_emit_save (GObject* obj, GeanyDocument* geany_doc, PeasySignals* sig);
static void peasy_signals_emit_close (GObject* obj, GeanyDocument* geany_doc, PeasySignals* sig);
static void peasy_signals_emit_filetype_set (GObject* obj, GeanyDocument* geany_doc, GeanyFiletype* ft, PeasySignals* sig);
GType peasy_filetype_get_type (void) G_GNUC_CONST;
PeasyFiletype* peasy_filetype_new (GeanyFiletype* ft);
PeasyFiletype* peasy_filetype_construct (GType object_type, GeanyFiletype* ft);
static void g_cclosure_user_marshal_VOID__OBJECT_OBJECT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);


static void _g_free0_ (gpointer var) {
	var = (g_free (var), NULL);
}


void peasy_static_init (GeanyPlugin* p) {
	GeanyPlugin* _tmp0_ = NULL;
	g_return_if_fail (p != NULL);
	_tmp0_ = peasy_peasy_plugin;
	if (_tmp0_ == NULL) {
		GeanyPlugin* _tmp1_ = NULL;
		PeasySignals* _tmp2_ = NULL;
		GHashFunc _tmp3_ = NULL;
		GEqualFunc _tmp4_ = NULL;
		GHashTable* _tmp5_ = NULL;
		_tmp1_ = p;
		peasy_peasy_plugin = _tmp1_;
		_tmp2_ = peasy_signals_new ();
		_g_object_unref0 (peasy_peasy_signals);
		peasy_peasy_signals = _tmp2_;
		_tmp3_ = g_str_hash;
		_tmp4_ = g_str_equal;
		_tmp5_ = g_hash_table_new_full (_tmp3_, _tmp4_, _g_free0_, NULL);
		_g_hash_table_unref0 (peasy_native_abis);
		peasy_native_abis = _tmp5_;
	}
}


void peasy_object_signal_connect (GObject* obj, const gchar* signal_name, gboolean after, GCallback cb, void* data) {
	GeanyPlugin* _tmp0_ = NULL;
	GObject* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	gboolean _tmp3_ = FALSE;
	GCallback _tmp4_ = NULL;
	void* _tmp5_ = NULL;
	g_return_if_fail (signal_name != NULL);
	_tmp0_ = peasy_peasy_plugin;
	_tmp1_ = obj;
	_tmp2_ = signal_name;
	_tmp3_ = after;
	_tmp4_ = cb;
	_tmp5_ = data;
	plugin_signal_connect (_tmp0_, _tmp1_, _tmp2_, _tmp3_, _tmp4_, _tmp5_);
}


PeasyObject* peasy_object_construct (GType object_type) {
	PeasyObject * self = NULL;
	self = (PeasyObject*) g_object_new (object_type, NULL);
	return self;
}


PeasyObject* peasy_object_new (void) {
	return peasy_object_construct (PEASY_TYPE_OBJECT);
}


PeasySignals* peasy_object_get_plugin_signals (PeasyObject* self) {
	PeasySignals* result;
	PeasySignals* _tmp0_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->priv->_plugin_signals;
	result = _tmp0_;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void peasy_object_set_plugin_signals (PeasyObject* self, PeasySignals* value) {
	PeasySignals* _tmp0_ = NULL;
	PeasySignals* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = value;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->priv->_plugin_signals);
	self->priv->_plugin_signals = _tmp1_;
	g_object_notify ((GObject *) self, "plugin-signals");
}


static GObject * peasy_object_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	PeasyObject * self;
	PeasySignals* _tmp0_ = NULL;
	parent_class = G_OBJECT_CLASS (peasy_object_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, PEASY_TYPE_OBJECT, PeasyObject);
	_tmp0_ = peasy_peasy_signals;
	peasy_object_set_plugin_signals (self, _tmp0_);
	return obj;
}


static void peasy_object_class_init (PeasyObjectClass * klass) {
	peasy_object_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (PeasyObjectPrivate));
	G_OBJECT_CLASS (klass)->get_property = _vala_peasy_object_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_peasy_object_set_property;
	G_OBJECT_CLASS (klass)->constructor = peasy_object_constructor;
	G_OBJECT_CLASS (klass)->finalize = peasy_object_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), PEASY_OBJECT_PLUGIN_SIGNALS, g_param_spec_object ("plugin-signals", "plugin-signals", "plugin-signals", PEASY_TYPE_SIGNALS, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
}


static void peasy_object_instance_init (PeasyObject * self) {
	self->priv = PEASY_OBJECT_GET_PRIVATE (self);
}


static void peasy_object_finalize (GObject* obj) {
	PeasyObject * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, PEASY_TYPE_OBJECT, PeasyObject);
	_g_object_unref0 (self->priv->_plugin_signals);
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


static void _vala_peasy_object_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	PeasyObject * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, PEASY_TYPE_OBJECT, PeasyObject);
	switch (property_id) {
		case PEASY_OBJECT_PLUGIN_SIGNALS:
		g_value_set_object (value, peasy_object_get_plugin_signals (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_peasy_object_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	PeasyObject * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, PEASY_TYPE_OBJECT, PeasyObject);
	switch (property_id) {
		case PEASY_OBJECT_PLUGIN_SIGNALS:
		peasy_object_set_plugin_signals (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void peasy_signals_emit_new (GObject* obj, GeanyDocument* geany_doc, PeasySignals* sig) {
	PeasySignals* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	PeasyDocument* _tmp2_ = NULL;
	PeasyDocument* _tmp3_ = NULL;
	g_return_if_fail (obj != NULL);
	g_return_if_fail (geany_doc != NULL);
	g_return_if_fail (sig != NULL);
	_tmp0_ = sig;
	_tmp1_ = geany_doc;
	_tmp2_ = peasy_document_new (_tmp1_);
	_tmp3_ = _tmp2_;
	g_signal_emit_by_name (_tmp0_, "document-new", _tmp3_);
	_g_object_unref0 (_tmp3_);
}


static void peasy_signals_emit_open (GObject* obj, GeanyDocument* geany_doc, PeasySignals* sig) {
	PeasySignals* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	PeasyDocument* _tmp2_ = NULL;
	PeasyDocument* _tmp3_ = NULL;
	g_return_if_fail (obj != NULL);
	g_return_if_fail (geany_doc != NULL);
	g_return_if_fail (sig != NULL);
	_tmp0_ = sig;
	_tmp1_ = geany_doc;
	_tmp2_ = peasy_document_new (_tmp1_);
	_tmp3_ = _tmp2_;
	g_signal_emit_by_name (_tmp0_, "document-open", _tmp3_);
	_g_object_unref0 (_tmp3_);
}


static void peasy_signals_emit_activate (GObject* obj, GeanyDocument* geany_doc, PeasySignals* sig) {
	PeasySignals* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	PeasyDocument* _tmp2_ = NULL;
	PeasyDocument* _tmp3_ = NULL;
	g_return_if_fail (obj != NULL);
	g_return_if_fail (geany_doc != NULL);
	g_return_if_fail (sig != NULL);
	_tmp0_ = sig;
	_tmp1_ = geany_doc;
	_tmp2_ = peasy_document_new (_tmp1_);
	_tmp3_ = _tmp2_;
	g_signal_emit_by_name (_tmp0_, "document-activate", _tmp3_);
	_g_object_unref0 (_tmp3_);
}


static void peasy_signals_emit_reload (GObject* obj, GeanyDocument* geany_doc, PeasySignals* sig) {
	PeasySignals* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	PeasyDocument* _tmp2_ = NULL;
	PeasyDocument* _tmp3_ = NULL;
	g_return_if_fail (obj != NULL);
	g_return_if_fail (geany_doc != NULL);
	g_return_if_fail (sig != NULL);
	_tmp0_ = sig;
	_tmp1_ = geany_doc;
	_tmp2_ = peasy_document_new (_tmp1_);
	_tmp3_ = _tmp2_;
	g_signal_emit_by_name (_tmp0_, "document-reload", _tmp3_);
	_g_object_unref0 (_tmp3_);
}


static void peasy_signals_emit_before_save (GObject* obj, GeanyDocument* geany_doc, PeasySignals* sig) {
	PeasySignals* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	PeasyDocument* _tmp2_ = NULL;
	PeasyDocument* _tmp3_ = NULL;
	g_return_if_fail (obj != NULL);
	g_return_if_fail (geany_doc != NULL);
	g_return_if_fail (sig != NULL);
	_tmp0_ = sig;
	_tmp1_ = geany_doc;
	_tmp2_ = peasy_document_new (_tmp1_);
	_tmp3_ = _tmp2_;
	g_signal_emit_by_name (_tmp0_, "document-before-save", _tmp3_);
	_g_object_unref0 (_tmp3_);
}


static void peasy_signals_emit_save (GObject* obj, GeanyDocument* geany_doc, PeasySignals* sig) {
	PeasySignals* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	PeasyDocument* _tmp2_ = NULL;
	PeasyDocument* _tmp3_ = NULL;
	g_return_if_fail (obj != NULL);
	g_return_if_fail (geany_doc != NULL);
	g_return_if_fail (sig != NULL);
	_tmp0_ = sig;
	_tmp1_ = geany_doc;
	_tmp2_ = peasy_document_new (_tmp1_);
	_tmp3_ = _tmp2_;
	g_signal_emit_by_name (_tmp0_, "document-save", _tmp3_);
	_g_object_unref0 (_tmp3_);
}


static void peasy_signals_emit_close (GObject* obj, GeanyDocument* geany_doc, PeasySignals* sig) {
	PeasySignals* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	PeasyDocument* _tmp2_ = NULL;
	PeasyDocument* _tmp3_ = NULL;
	g_return_if_fail (obj != NULL);
	g_return_if_fail (geany_doc != NULL);
	g_return_if_fail (sig != NULL);
	_tmp0_ = sig;
	_tmp1_ = geany_doc;
	_tmp2_ = peasy_document_new (_tmp1_);
	_tmp3_ = _tmp2_;
	g_signal_emit_by_name (_tmp0_, "document-close", _tmp3_);
	_g_object_unref0 (_tmp3_);
}


static void peasy_signals_emit_filetype_set (GObject* obj, GeanyDocument* geany_doc, GeanyFiletype* ft, PeasySignals* sig) {
	PeasyFiletype* _tmp0_ = NULL;
	GeanyFiletype* _tmp1_ = NULL;
	PeasyFiletype* ft_ = NULL;
	PeasyFiletype* _tmp4_ = NULL;
	PeasySignals* _tmp5_ = NULL;
	GeanyDocument* _tmp6_ = NULL;
	PeasyDocument* _tmp7_ = NULL;
	PeasyDocument* _tmp8_ = NULL;
	g_return_if_fail (obj != NULL);
	g_return_if_fail (geany_doc != NULL);
	g_return_if_fail (sig != NULL);
	_tmp1_ = ft;
	if (_tmp1_ != NULL) {
		GeanyFiletype* _tmp2_ = NULL;
		PeasyFiletype* _tmp3_ = NULL;
		_tmp2_ = ft;
		_tmp3_ = peasy_filetype_new (_tmp2_);
		_g_object_unref0 (_tmp0_);
		_tmp0_ = _tmp3_;
	} else {
		_g_object_unref0 (_tmp0_);
		_tmp0_ = NULL;
	}
	_tmp4_ = _g_object_ref0 (_tmp0_);
	ft_ = _tmp4_;
	_tmp5_ = sig;
	_tmp6_ = geany_doc;
	_tmp7_ = peasy_document_new (_tmp6_);
	_tmp8_ = _tmp7_;
	g_signal_emit_by_name (_tmp5_, "document-filetype-set", _tmp8_, ft_);
	_g_object_unref0 (_tmp8_);
	_g_object_unref0 (ft_);
	_g_object_unref0 (_tmp0_);
}


PeasySignals* peasy_signals_construct (GType object_type) {
	PeasySignals * self = NULL;
	self = (PeasySignals*) peasy_object_construct (object_type);
	peasy_object_signal_connect (NULL, "document-new", FALSE, (GCallback) peasy_signals_emit_new, self);
	peasy_object_signal_connect (NULL, "document-open", FALSE, (GCallback) peasy_signals_emit_open, self);
	peasy_object_signal_connect (NULL, "document-activate", FALSE, (GCallback) peasy_signals_emit_activate, self);
	peasy_object_signal_connect (NULL, "document-reload", FALSE, (GCallback) peasy_signals_emit_reload, self);
	peasy_object_signal_connect (NULL, "document-before-save", FALSE, (GCallback) peasy_signals_emit_before_save, self);
	peasy_object_signal_connect (NULL, "document-save", FALSE, (GCallback) peasy_signals_emit_save, self);
	peasy_object_signal_connect (NULL, "document-close", FALSE, (GCallback) peasy_signals_emit_close, self);
	peasy_object_signal_connect (NULL, "document-filetype-set", FALSE, (GCallback) peasy_signals_emit_filetype_set, self);
	return self;
}


PeasySignals* peasy_signals_new (void) {
	return peasy_signals_construct (PEASY_TYPE_SIGNALS);
}


static void g_cclosure_user_marshal_VOID__OBJECT_OBJECT (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__OBJECT_OBJECT) (gpointer data1, gpointer arg_1, gpointer arg_2, gpointer data2);
	register GMarshalFunc_VOID__OBJECT_OBJECT callback;
	register GCClosure * cc;
	register gpointer data1;
	register gpointer data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 3);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__OBJECT_OBJECT) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_object (param_values + 1), g_value_get_object (param_values + 2), data2);
}


static void peasy_signals_class_init (PeasySignalsClass * klass) {
	peasy_signals_parent_class = g_type_class_peek_parent (klass);
	g_signal_new ("document_new", PEASY_TYPE_SIGNALS, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, PEASY_TYPE_DOCUMENT);
	g_signal_new ("document_open", PEASY_TYPE_SIGNALS, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, PEASY_TYPE_DOCUMENT);
	g_signal_new ("document_activate", PEASY_TYPE_SIGNALS, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, PEASY_TYPE_DOCUMENT);
	g_signal_new ("document_reload", PEASY_TYPE_SIGNALS, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, PEASY_TYPE_DOCUMENT);
	g_signal_new ("document_before_save", PEASY_TYPE_SIGNALS, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, PEASY_TYPE_DOCUMENT);
	g_signal_new ("document_save", PEASY_TYPE_SIGNALS, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, PEASY_TYPE_DOCUMENT);
	g_signal_new ("document_close", PEASY_TYPE_SIGNALS, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, PEASY_TYPE_DOCUMENT);
	g_signal_new ("document_filetype_set", PEASY_TYPE_SIGNALS, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__OBJECT_OBJECT, G_TYPE_NONE, 2, PEASY_TYPE_DOCUMENT, PEASY_TYPE_FILETYPE);
}


static void peasy_signals_instance_init (PeasySignals * self) {
}


GType peasy_signals_get_type (void) {
	static volatile gsize peasy_signals_type_id__volatile = 0;
	if (g_once_init_enter (&peasy_signals_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (PeasySignalsClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) peasy_signals_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PeasySignals), 0, (GInstanceInitFunc) peasy_signals_instance_init, NULL };
		GType peasy_signals_type_id;
		peasy_signals_type_id = g_type_register_static (PEASY_TYPE_OBJECT, "PeasySignals", &g_define_type_info, 0);
		g_once_init_leave (&peasy_signals_type_id__volatile, peasy_signals_type_id);
	}
	return peasy_signals_type_id__volatile;
}



