/* document.c generated by valac, the Vala compiler
 * generated from document.vala, do not modify */


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

#define PEASY_TYPE_DOCUMENT (peasy_document_get_type ())
#define PEASY_DOCUMENT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_DOCUMENT, PeasyDocument))
#define PEASY_DOCUMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_DOCUMENT, PeasyDocumentClass))
#define PEASY_IS_DOCUMENT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_DOCUMENT))
#define PEASY_IS_DOCUMENT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_DOCUMENT))
#define PEASY_DOCUMENT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_DOCUMENT, PeasyDocumentClass))

typedef struct _PeasyDocument PeasyDocument;
typedef struct _PeasyDocumentClass PeasyDocumentClass;
typedef struct _PeasyDocumentPrivate PeasyDocumentPrivate;

#define PEASY_TYPE_EDITOR (peasy_editor_get_type ())
#define PEASY_EDITOR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_EDITOR, PeasyEditor))
#define PEASY_EDITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_EDITOR, PeasyEditorClass))
#define PEASY_IS_EDITOR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_EDITOR))
#define PEASY_IS_EDITOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_EDITOR))
#define PEASY_EDITOR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_EDITOR, PeasyEditorClass))

typedef struct _PeasyEditor PeasyEditor;
typedef struct _PeasyEditorClass PeasyEditorClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _Block1Data Block1Data;
#define _g_ptr_array_unref0(var) ((var == NULL) ? NULL : (var = (g_ptr_array_unref (var), NULL)))

#define PEASY_TYPE_FILETYPE (peasy_filetype_get_type ())
#define PEASY_FILETYPE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_FILETYPE, PeasyFiletype))
#define PEASY_FILETYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_FILETYPE, PeasyFiletypeClass))
#define PEASY_IS_FILETYPE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_FILETYPE))
#define PEASY_IS_FILETYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_FILETYPE))
#define PEASY_FILETYPE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_FILETYPE, PeasyFiletypeClass))

typedef struct _PeasyFiletype PeasyFiletype;
typedef struct _PeasyFiletypeClass PeasyFiletypeClass;
typedef struct _PeasyFiletypePrivate PeasyFiletypePrivate;

#define PEASY_TYPE_SIGNALS (peasy_signals_get_type ())
#define PEASY_SIGNALS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_SIGNALS, PeasySignals))
#define PEASY_SIGNALS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_SIGNALS, PeasySignalsClass))
#define PEASY_IS_SIGNALS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_SIGNALS))
#define PEASY_IS_SIGNALS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_SIGNALS))
#define PEASY_SIGNALS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_SIGNALS, PeasySignalsClass))

typedef struct _PeasySignals PeasySignals;
typedef struct _PeasySignalsClass PeasySignalsClass;

struct _PeasyObject {
	GObject parent_instance;
	PeasyObjectPrivate * priv;
};

struct _PeasyObjectClass {
	GObjectClass parent_class;
};

struct _PeasyDocument {
	PeasyObject parent_instance;
	PeasyDocumentPrivate * priv;
	PeasyEditor* editor;
	GeanyDocument* _doc;
};

struct _PeasyDocumentClass {
	PeasyObjectClass parent_class;
};

struct _Block1Data {
	int _ref_count_;
	GPtrArray* docs;
};

struct _PeasyFiletype {
	PeasyObject parent_instance;
	PeasyFiletypePrivate * priv;
	GeanyFiletype* _ft;
};

struct _PeasyFiletypeClass {
	PeasyObjectClass parent_class;
};


static gpointer peasy_document_parent_class = NULL;
extern GeanyPlugin* peasy_peasy_plugin;

GType peasy_object_get_type (void) G_GNUC_CONST;
GType peasy_document_get_type (void) G_GNUC_CONST;
GType peasy_editor_get_type (void) G_GNUC_CONST;
enum  {
	PEASY_DOCUMENT_DUMMY_PROPERTY,
	PEASY_DOCUMENT_CHANGED,
	PEASY_DOCUMENT_ENCODING,
	PEASY_DOCUMENT_IS_VALID,
	PEASY_DOCUMENT_HAS_BOM,
	PEASY_DOCUMENT_HAS_TAGS,
	PEASY_DOCUMENT_ID,
	PEASY_DOCUMENT_DISPLAY_NAME
};
GPtrArray* peasy_document_all_documents (void);
static Block1Data* block1_data_ref (Block1Data* _data1_);
static void block1_data_unref (void * _userdata_);
static void _g_object_unref0_ (gpointer var);
static void __lambda4_ (Block1Data* _data1_, GeanyDocument* doc);
PeasyDocument* peasy_document_new (GeanyDocument* doc);
PeasyDocument* peasy_document_construct (GType object_type, GeanyDocument* doc);
static void ___lambda4__gfunc (gconstpointer data, gpointer self);
PeasyObject* peasy_object_new (void);
PeasyObject* peasy_object_construct (GType object_type);
PeasyEditor* peasy_editor_new_create (PeasyDocument* doc);
PeasyEditor* peasy_editor_construct_create (GType object_type, PeasyDocument* doc);
GType peasy_filetype_get_type (void) G_GNUC_CONST;
PeasyDocument* peasy_document_new_new_file (const gchar* utf8_filename, PeasyFiletype* ft, const gchar* text);
PeasyDocument* peasy_document_construct_new_file (GType object_type, const gchar* utf8_filename, PeasyFiletype* ft, const gchar* text);
PeasyDocument* peasy_document_new_from_file (const gchar* locale_filename, gboolean readonly, PeasyFiletype* ft, const gchar* forced_enc);
PeasyDocument* peasy_document_construct_from_file (GType object_type, const gchar* locale_filename, gboolean readonly, PeasyFiletype* ft, const gchar* forced_enc);
PeasyDocument* peasy_document_get_current (void);
gboolean peasy_document_close (PeasyDocument* self);
gboolean peasy_document_get_is_valid (PeasyDocument* self);
gboolean peasy_document_save (PeasyDocument* self, gboolean force);
gboolean peasy_document_save_as (PeasyDocument* self, const gchar* file_name);
gboolean peasy_document_reload (PeasyDocument* self, const gchar* forced_enc);
gboolean peasy_document_get_changed (PeasyDocument* self);
void peasy_document_set_changed (PeasyDocument* self, gboolean value);
const gchar* peasy_document_get_encoding (PeasyDocument* self);
void peasy_document_set_encoding (PeasyDocument* self, const gchar* value);
gboolean peasy_document_get_has_bom (PeasyDocument* self);
gboolean peasy_document_get_has_tags (PeasyDocument* self);
guint peasy_document_get_id (PeasyDocument* self);
gchar* peasy_document_get_display_name (PeasyDocument* self);
static GObject * peasy_document_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
GType peasy_signals_get_type (void) G_GNUC_CONST;
PeasySignals* peasy_object_get_plugin_signals (PeasyObject* self);
static void _peasy_document___lambda6_ (PeasyDocument* self, PeasyDocument* doc);
static void __peasy_document___lambda6__peasy_signals_document_close (PeasySignals* _sender, PeasyDocument* doc, gpointer self);
static void _peasy_document___lambda7_ (PeasyDocument* self, PeasyDocument* doc);
static void __peasy_document___lambda7__peasy_signals_document_reload (PeasySignals* _sender, PeasyDocument* doc, gpointer self);
static void _peasy_document___lambda8_ (PeasyDocument* self, PeasyDocument* doc);
static void __peasy_document___lambda8__peasy_signals_document_activate (PeasySignals* _sender, PeasyDocument* doc, gpointer self);
static void _peasy_document___lambda9_ (PeasyDocument* self, PeasyDocument* doc);
static void __peasy_document___lambda9__peasy_signals_document_before_save (PeasySignals* _sender, PeasyDocument* doc, gpointer self);
static void _peasy_document___lambda10_ (PeasyDocument* self, PeasyDocument* doc);
static void __peasy_document___lambda10__peasy_signals_document_save (PeasySignals* _sender, PeasyDocument* doc, gpointer self);
static void _peasy_document___lambda11_ (PeasyDocument* self, PeasyDocument* doc, PeasyFiletype* ft);
static void __peasy_document___lambda11__peasy_signals_document_filetype_set (PeasySignals* _sender, PeasyDocument* doc, PeasyFiletype* old_ft, gpointer self);
static void peasy_document_finalize (GObject* obj);
static void _vala_peasy_document_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void _vala_peasy_document_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);


static Block1Data* block1_data_ref (Block1Data* _data1_) {
	g_atomic_int_inc (&_data1_->_ref_count_);
	return _data1_;
}


static void block1_data_unref (void * _userdata_) {
	Block1Data* _data1_;
	_data1_ = (Block1Data*) _userdata_;
	if (g_atomic_int_dec_and_test (&_data1_->_ref_count_)) {
		_g_ptr_array_unref0 (_data1_->docs);
		g_slice_free (Block1Data, _data1_);
	}
}


static void _g_object_unref0_ (gpointer var) {
	(var == NULL) ? NULL : (var = (g_object_unref (var), NULL));
}


static void __lambda4_ (Block1Data* _data1_, GeanyDocument* doc) {
	GeanyDocument* _tmp0_ = NULL;
	gboolean _tmp1_ = FALSE;
	g_return_if_fail (doc != NULL);
	_tmp0_ = doc;
	_tmp1_ = _tmp0_->is_valid;
	if (_tmp1_) {
		GeanyDocument* _tmp2_ = NULL;
		PeasyDocument* _tmp3_ = NULL;
		_tmp2_ = doc;
		_tmp3_ = peasy_document_new (_tmp2_);
		g_ptr_array_add (_data1_->docs, _tmp3_);
	}
}


static void ___lambda4__gfunc (gconstpointer data, gpointer self) {
	__lambda4_ (self, (GeanyDocument*) data);
}


static gpointer _g_ptr_array_ref0 (gpointer self) {
	return self ? g_ptr_array_ref (self) : NULL;
}


GPtrArray* peasy_document_all_documents (void) {
	GPtrArray* result = NULL;
	Block1Data* _data1_;
	GPtrArray* _tmp0_ = NULL;
	GeanyPlugin* _tmp1_ = NULL;
	GeanyData* _tmp2_ = NULL;
	GPtrArray* _tmp3_ = NULL;
	GPtrArray* _tmp4_ = NULL;
	_data1_ = g_slice_new0 (Block1Data);
	_data1_->_ref_count_ = 1;
	_tmp0_ = g_ptr_array_new_with_free_func (_g_object_unref0_);
	_data1_->docs = _tmp0_;
	_tmp1_ = peasy_peasy_plugin;
	_tmp2_ = _tmp1_->geany_data;
	_tmp3_ = _tmp2_->documents_array;
	g_ptr_array_foreach (_tmp3_, ___lambda4__gfunc, _data1_);
	_tmp4_ = _g_ptr_array_ref0 (_data1_->docs);
	result = _tmp4_;
	block1_data_unref (_data1_);
	_data1_ = NULL;
	return result;
}


PeasyDocument* peasy_document_construct (GType object_type, GeanyDocument* doc) {
	PeasyDocument * self = NULL;
	GeanyDocument* _tmp0_ = NULL;
	PeasyEditor* _tmp1_ = NULL;
	g_return_val_if_fail (doc != NULL, NULL);
	self = (PeasyDocument*) peasy_object_construct (object_type);
	_tmp0_ = doc;
	self->_doc = _tmp0_;
	_tmp1_ = peasy_editor_new_create (self);
	_g_object_unref0 (self->editor);
	self->editor = _tmp1_;
	return self;
}


PeasyDocument* peasy_document_new (GeanyDocument* doc) {
	return peasy_document_construct (PEASY_TYPE_DOCUMENT, doc);
}


PeasyDocument* peasy_document_construct_new_file (GType object_type, const gchar* utf8_filename, PeasyFiletype* ft, const gchar* text) {
	PeasyDocument * self = NULL;
	GeanyFiletype* gft = NULL;
	PeasyFiletype* _tmp0_ = NULL;
	const gchar* _tmp3_ = NULL;
	GeanyFiletype* _tmp4_ = NULL;
	const gchar* _tmp5_ = NULL;
	GeanyDocument* _tmp6_ = NULL;
	PeasyEditor* _tmp7_ = NULL;
	self = (PeasyDocument*) peasy_object_construct (object_type);
	gft = NULL;
	_tmp0_ = ft;
	if (_tmp0_ != NULL) {
		PeasyFiletype* _tmp1_ = NULL;
		GeanyFiletype* _tmp2_ = NULL;
		_tmp1_ = ft;
		_tmp2_ = _tmp1_->_ft;
		gft = _tmp2_;
	}
	_tmp3_ = utf8_filename;
	_tmp4_ = gft;
	_tmp5_ = text;
	_tmp6_ = document_new_file (_tmp3_, _tmp4_, _tmp5_);
	self->_doc = _tmp6_;
	_tmp7_ = peasy_editor_new_create (self);
	_g_object_unref0 (self->editor);
	self->editor = _tmp7_;
	return self;
}


PeasyDocument* peasy_document_new_new_file (const gchar* utf8_filename, PeasyFiletype* ft, const gchar* text) {
	return peasy_document_construct_new_file (PEASY_TYPE_DOCUMENT, utf8_filename, ft, text);
}


PeasyDocument* peasy_document_construct_from_file (GType object_type, const gchar* locale_filename, gboolean readonly, PeasyFiletype* ft, const gchar* forced_enc) {
	PeasyDocument * self = NULL;
	GeanyFiletype* gft = NULL;
	PeasyFiletype* _tmp0_ = NULL;
	const gchar* _tmp3_ = NULL;
	gboolean _tmp4_ = FALSE;
	GeanyFiletype* _tmp5_ = NULL;
	const gchar* _tmp6_ = NULL;
	GeanyDocument* _tmp7_ = NULL;
	PeasyEditor* _tmp8_ = NULL;
	g_return_val_if_fail (locale_filename != NULL, NULL);
	self = (PeasyDocument*) peasy_object_construct (object_type);
	gft = NULL;
	_tmp0_ = ft;
	if (_tmp0_ != NULL) {
		PeasyFiletype* _tmp1_ = NULL;
		GeanyFiletype* _tmp2_ = NULL;
		_tmp1_ = ft;
		_tmp2_ = _tmp1_->_ft;
		gft = _tmp2_;
	}
	_tmp3_ = locale_filename;
	_tmp4_ = readonly;
	_tmp5_ = gft;
	_tmp6_ = forced_enc;
	_tmp7_ = document_open_file (_tmp3_, _tmp4_, _tmp5_, _tmp6_);
	self->_doc = _tmp7_;
	_tmp8_ = peasy_editor_new_create (self);
	_g_object_unref0 (self->editor);
	self->editor = _tmp8_;
	return self;
}


PeasyDocument* peasy_document_new_from_file (const gchar* locale_filename, gboolean readonly, PeasyFiletype* ft, const gchar* forced_enc) {
	return peasy_document_construct_from_file (PEASY_TYPE_DOCUMENT, locale_filename, readonly, ft, forced_enc);
}


PeasyDocument* peasy_document_get_current (void) {
	PeasyDocument* result = NULL;
	GeanyDocument* _tmp0_ = NULL;
	PeasyDocument* _tmp1_ = NULL;
	_tmp0_ = document_get_current ();
	_tmp1_ = peasy_document_new (_tmp0_);
	result = _tmp1_;
	return result;
}


gboolean peasy_document_close (PeasyDocument* self) {
	gboolean result = FALSE;
	gboolean _tmp0_ = FALSE;
	gboolean _tmp1_ = FALSE;
	GeanyDocument* _tmp2_ = NULL;
	gboolean _tmp3_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = peasy_document_get_is_valid (self);
	_tmp1_ = _tmp0_;
	if (!_tmp1_) {
		result = TRUE;
		return result;
	}
	_tmp2_ = self->_doc;
	_tmp3_ = document_close (_tmp2_);
	result = _tmp3_;
	return result;
}


gboolean peasy_document_save (PeasyDocument* self, gboolean force) {
	gboolean result = FALSE;
	GeanyDocument* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	gboolean _tmp2_ = FALSE;
	gboolean _tmp3_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->_doc;
	g_return_val_if_fail (_tmp0_ != NULL, FALSE);
	_tmp1_ = self->_doc;
	_tmp2_ = force;
	_tmp3_ = document_save_file (_tmp1_, _tmp2_);
	result = _tmp3_;
	return result;
}


gboolean peasy_document_save_as (PeasyDocument* self, const gchar* file_name) {
	gboolean result = FALSE;
	GeanyDocument* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	gboolean _tmp3_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->_doc;
	g_return_val_if_fail (_tmp0_ != NULL, FALSE);
	_tmp1_ = self->_doc;
	_tmp2_ = file_name;
	_tmp3_ = document_save_file_as (_tmp1_, _tmp2_);
	result = _tmp3_;
	return result;
}


gboolean peasy_document_reload (PeasyDocument* self, const gchar* forced_enc) {
	gboolean result = FALSE;
	GeanyDocument* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	gboolean _tmp3_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->_doc;
	g_return_val_if_fail (_tmp0_ != NULL, FALSE);
	_tmp1_ = self->_doc;
	_tmp2_ = forced_enc;
	_tmp3_ = document_reload_force (_tmp1_, _tmp2_);
	result = _tmp3_;
	return result;
}


gboolean peasy_document_get_changed (PeasyDocument* self) {
	gboolean result;
	GeanyDocument* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	gboolean _tmp2_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->_doc;
	g_return_val_if_fail (_tmp0_ != NULL, FALSE);
	_tmp1_ = self->_doc;
	_tmp2_ = _tmp1_->changed;
	result = _tmp2_;
	return result;
}


void peasy_document_set_changed (PeasyDocument* self, gboolean value) {
	GeanyDocument* _tmp0_ = NULL;
	gboolean _tmp1_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->_doc;
	_tmp1_ = value;
	document_set_text_changed (_tmp0_, _tmp1_);
	g_object_notify ((GObject *) self, "changed");
}


const gchar* peasy_document_get_encoding (PeasyDocument* self) {
	const gchar* result;
	GeanyDocument* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->_doc;
	g_return_val_if_fail (_tmp0_ != NULL, "");
	_tmp1_ = self->_doc;
	_tmp2_ = _tmp1_->encoding;
	result = _tmp2_;
	return result;
}


void peasy_document_set_encoding (PeasyDocument* self, const gchar* value) {
	GeanyDocument* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->_doc;
	_tmp1_ = value;
	document_set_encoding (_tmp0_, _tmp1_);
	g_object_notify ((GObject *) self, "encoding");
}


gboolean peasy_document_get_is_valid (PeasyDocument* self) {
	gboolean result;
	GeanyDocument* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	gboolean _tmp2_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->_doc;
	if (_tmp0_ == NULL) {
		result = FALSE;
		return result;
	}
	_tmp1_ = self->_doc;
	_tmp2_ = _tmp1_->is_valid;
	result = _tmp2_;
	return result;
}


gboolean peasy_document_get_has_bom (PeasyDocument* self) {
	gboolean result;
	GeanyDocument* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	gboolean _tmp2_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->_doc;
	g_return_val_if_fail (_tmp0_ != NULL, FALSE);
	_tmp1_ = self->_doc;
	_tmp2_ = _tmp1_->has_bom;
	result = _tmp2_;
	return result;
}


gboolean peasy_document_get_has_tags (PeasyDocument* self) {
	gboolean result;
	GeanyDocument* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	gboolean _tmp2_ = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	_tmp0_ = self->_doc;
	g_return_val_if_fail (_tmp0_ != NULL, FALSE);
	_tmp1_ = self->_doc;
	_tmp2_ = _tmp1_->has_tags;
	result = _tmp2_;
	return result;
}


guint peasy_document_get_id (PeasyDocument* self) {
	guint result;
	GeanyDocument* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	guint _tmp2_ = 0U;
	g_return_val_if_fail (self != NULL, 0U);
	_tmp0_ = self->_doc;
	g_return_val_if_fail (_tmp0_ != NULL, 0);
	_tmp1_ = self->_doc;
	_tmp2_ = _tmp1_->id;
	result = _tmp2_;
	return result;
}


gchar* peasy_document_get_display_name (PeasyDocument* self) {
	gchar* result;
	GeanyDocument* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->_doc;
	g_return_val_if_fail (_tmp0_ != NULL, NULL);
	_tmp1_ = self->_doc;
	_tmp2_ = document_get_basename_for_display (_tmp1_, -1);
	result = _tmp2_;
	return result;
}


static void _peasy_document___lambda6_ (PeasyDocument* self, PeasyDocument* doc) {
	PeasyDocument* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	GeanyDocument* _tmp2_ = NULL;
	g_return_if_fail (doc != NULL);
	_tmp0_ = doc;
	_tmp1_ = _tmp0_->_doc;
	_tmp2_ = self->_doc;
	if (_tmp1_ == _tmp2_) {
		g_signal_emit_by_name (self, "closing");
	}
}


static void __peasy_document___lambda6__peasy_signals_document_close (PeasySignals* _sender, PeasyDocument* doc, gpointer self) {
	_peasy_document___lambda6_ ((PeasyDocument*) self, doc);
}


static void _peasy_document___lambda7_ (PeasyDocument* self, PeasyDocument* doc) {
	PeasyDocument* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	GeanyDocument* _tmp2_ = NULL;
	g_return_if_fail (doc != NULL);
	_tmp0_ = doc;
	_tmp1_ = _tmp0_->_doc;
	_tmp2_ = self->_doc;
	if (_tmp1_ == _tmp2_) {
		g_signal_emit_by_name (self, "reloaded");
	}
}


static void __peasy_document___lambda7__peasy_signals_document_reload (PeasySignals* _sender, PeasyDocument* doc, gpointer self) {
	_peasy_document___lambda7_ ((PeasyDocument*) self, doc);
}


static void _peasy_document___lambda8_ (PeasyDocument* self, PeasyDocument* doc) {
	PeasyDocument* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	GeanyDocument* _tmp2_ = NULL;
	g_return_if_fail (doc != NULL);
	_tmp0_ = doc;
	_tmp1_ = _tmp0_->_doc;
	_tmp2_ = self->_doc;
	if (_tmp1_ == _tmp2_) {
		g_signal_emit_by_name (self, "activate");
	}
}


static void __peasy_document___lambda8__peasy_signals_document_activate (PeasySignals* _sender, PeasyDocument* doc, gpointer self) {
	_peasy_document___lambda8_ ((PeasyDocument*) self, doc);
}


static void _peasy_document___lambda9_ (PeasyDocument* self, PeasyDocument* doc) {
	PeasyDocument* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	GeanyDocument* _tmp2_ = NULL;
	g_return_if_fail (doc != NULL);
	_tmp0_ = doc;
	_tmp1_ = _tmp0_->_doc;
	_tmp2_ = self->_doc;
	if (_tmp1_ == _tmp2_) {
		g_signal_emit_by_name (self, "before-save");
	}
}


static void __peasy_document___lambda9__peasy_signals_document_before_save (PeasySignals* _sender, PeasyDocument* doc, gpointer self) {
	_peasy_document___lambda9_ ((PeasyDocument*) self, doc);
}


static void _peasy_document___lambda10_ (PeasyDocument* self, PeasyDocument* doc) {
	PeasyDocument* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	GeanyDocument* _tmp2_ = NULL;
	g_return_if_fail (doc != NULL);
	_tmp0_ = doc;
	_tmp1_ = _tmp0_->_doc;
	_tmp2_ = self->_doc;
	if (_tmp1_ == _tmp2_) {
		g_signal_emit_by_name (self, "saved");
	}
}


static void __peasy_document___lambda10__peasy_signals_document_save (PeasySignals* _sender, PeasyDocument* doc, gpointer self) {
	_peasy_document___lambda10_ ((PeasyDocument*) self, doc);
}


static void _peasy_document___lambda11_ (PeasyDocument* self, PeasyDocument* doc, PeasyFiletype* ft) {
	PeasyDocument* _tmp0_ = NULL;
	GeanyDocument* _tmp1_ = NULL;
	GeanyDocument* _tmp2_ = NULL;
	g_return_if_fail (doc != NULL);
	_tmp0_ = doc;
	_tmp1_ = _tmp0_->_doc;
	_tmp2_ = self->_doc;
	if (_tmp1_ == _tmp2_) {
		PeasyFiletype* _tmp3_ = NULL;
		_tmp3_ = ft;
		g_signal_emit_by_name (self, "filetype-set", _tmp3_);
	}
}


static void __peasy_document___lambda11__peasy_signals_document_filetype_set (PeasySignals* _sender, PeasyDocument* doc, PeasyFiletype* old_ft, gpointer self) {
	_peasy_document___lambda11_ ((PeasyDocument*) self, doc, old_ft);
}


static GObject * peasy_document_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	PeasyDocument * self;
	PeasySignals* _tmp0_ = NULL;
	PeasySignals* _tmp1_ = NULL;
	PeasySignals* _tmp2_ = NULL;
	PeasySignals* _tmp3_ = NULL;
	PeasySignals* _tmp4_ = NULL;
	PeasySignals* _tmp5_ = NULL;
	PeasySignals* _tmp6_ = NULL;
	PeasySignals* _tmp7_ = NULL;
	PeasySignals* _tmp8_ = NULL;
	PeasySignals* _tmp9_ = NULL;
	PeasySignals* _tmp10_ = NULL;
	PeasySignals* _tmp11_ = NULL;
	parent_class = G_OBJECT_CLASS (peasy_document_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, PEASY_TYPE_DOCUMENT, PeasyDocument);
	_tmp0_ = peasy_object_get_plugin_signals ((PeasyObject*) self);
	_tmp1_ = _tmp0_;
	g_signal_connect_object (_tmp1_, "document-close", (GCallback) __peasy_document___lambda6__peasy_signals_document_close, self, 0);
	_tmp2_ = peasy_object_get_plugin_signals ((PeasyObject*) self);
	_tmp3_ = _tmp2_;
	g_signal_connect_object (_tmp3_, "document-reload", (GCallback) __peasy_document___lambda7__peasy_signals_document_reload, self, 0);
	_tmp4_ = peasy_object_get_plugin_signals ((PeasyObject*) self);
	_tmp5_ = _tmp4_;
	g_signal_connect_object (_tmp5_, "document-activate", (GCallback) __peasy_document___lambda8__peasy_signals_document_activate, self, 0);
	_tmp6_ = peasy_object_get_plugin_signals ((PeasyObject*) self);
	_tmp7_ = _tmp6_;
	g_signal_connect_object (_tmp7_, "document-before-save", (GCallback) __peasy_document___lambda9__peasy_signals_document_before_save, self, 0);
	_tmp8_ = peasy_object_get_plugin_signals ((PeasyObject*) self);
	_tmp9_ = _tmp8_;
	g_signal_connect_object (_tmp9_, "document-save", (GCallback) __peasy_document___lambda10__peasy_signals_document_save, self, 0);
	_tmp10_ = peasy_object_get_plugin_signals ((PeasyObject*) self);
	_tmp11_ = _tmp10_;
	g_signal_connect_object (_tmp11_, "document-filetype-set", (GCallback) __peasy_document___lambda11__peasy_signals_document_filetype_set, self, 0);
	return obj;
}


static void peasy_document_class_init (PeasyDocumentClass * klass) {
	peasy_document_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->get_property = _vala_peasy_document_get_property;
	G_OBJECT_CLASS (klass)->set_property = _vala_peasy_document_set_property;
	G_OBJECT_CLASS (klass)->constructor = peasy_document_constructor;
	G_OBJECT_CLASS (klass)->finalize = peasy_document_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), PEASY_DOCUMENT_CHANGED, g_param_spec_boolean ("changed", "changed", "changed", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PEASY_DOCUMENT_ENCODING, g_param_spec_string ("encoding", "encoding", "encoding", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PEASY_DOCUMENT_IS_VALID, g_param_spec_boolean ("is-valid", "is-valid", "is-valid", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PEASY_DOCUMENT_HAS_BOM, g_param_spec_boolean ("has-bom", "has-bom", "has-bom", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PEASY_DOCUMENT_HAS_TAGS, g_param_spec_boolean ("has-tags", "has-tags", "has-tags", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PEASY_DOCUMENT_ID, g_param_spec_uint ("id", "id", "id", 0, G_MAXUINT, 0U, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), PEASY_DOCUMENT_DISPLAY_NAME, g_param_spec_string ("display-name", "display-name", "display-name", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
	g_signal_new ("closing", PEASY_TYPE_DOCUMENT, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
	g_signal_new ("reloaded", PEASY_TYPE_DOCUMENT, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
	g_signal_new ("activate", PEASY_TYPE_DOCUMENT, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
	g_signal_new ("before_save", PEASY_TYPE_DOCUMENT, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
	g_signal_new ("saved", PEASY_TYPE_DOCUMENT, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
	g_signal_new ("filetype_set", PEASY_TYPE_DOCUMENT, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, PEASY_TYPE_FILETYPE);
}


static void peasy_document_instance_init (PeasyDocument * self) {
}


static void peasy_document_finalize (GObject* obj) {
	PeasyDocument * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, PEASY_TYPE_DOCUMENT, PeasyDocument);
	_g_object_unref0 (self->editor);
	G_OBJECT_CLASS (peasy_document_parent_class)->finalize (obj);
}


GType peasy_document_get_type (void) {
	static volatile gsize peasy_document_type_id__volatile = 0;
	if (g_once_init_enter (&peasy_document_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (PeasyDocumentClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) peasy_document_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PeasyDocument), 0, (GInstanceInitFunc) peasy_document_instance_init, NULL };
		GType peasy_document_type_id;
		peasy_document_type_id = g_type_register_static (PEASY_TYPE_OBJECT, "PeasyDocument", &g_define_type_info, 0);
		g_once_init_leave (&peasy_document_type_id__volatile, peasy_document_type_id);
	}
	return peasy_document_type_id__volatile;
}


static void _vala_peasy_document_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	PeasyDocument * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, PEASY_TYPE_DOCUMENT, PeasyDocument);
	switch (property_id) {
		case PEASY_DOCUMENT_CHANGED:
		g_value_set_boolean (value, peasy_document_get_changed (self));
		break;
		case PEASY_DOCUMENT_ENCODING:
		g_value_set_string (value, peasy_document_get_encoding (self));
		break;
		case PEASY_DOCUMENT_IS_VALID:
		g_value_set_boolean (value, peasy_document_get_is_valid (self));
		break;
		case PEASY_DOCUMENT_HAS_BOM:
		g_value_set_boolean (value, peasy_document_get_has_bom (self));
		break;
		case PEASY_DOCUMENT_HAS_TAGS:
		g_value_set_boolean (value, peasy_document_get_has_tags (self));
		break;
		case PEASY_DOCUMENT_ID:
		g_value_set_uint (value, peasy_document_get_id (self));
		break;
		case PEASY_DOCUMENT_DISPLAY_NAME:
		g_value_take_string (value, peasy_document_get_display_name (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void _vala_peasy_document_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	PeasyDocument * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (object, PEASY_TYPE_DOCUMENT, PeasyDocument);
	switch (property_id) {
		case PEASY_DOCUMENT_CHANGED:
		peasy_document_set_changed (self, g_value_get_boolean (value));
		break;
		case PEASY_DOCUMENT_ENCODING:
		peasy_document_set_encoding (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}



