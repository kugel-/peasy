/* msgwin.c generated by valac, the Vala compiler
 * generated from msgwin.vala, do not modify */

/* Part of Geany but not in the vapi (not introspectable) */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <geanyplugin.h>
#include <stdarg.h>


#define PEASY_TYPE_OBJECT (peasy_object_get_type ())
#define PEASY_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_OBJECT, PeasyObject))
#define PEASY_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_OBJECT, PeasyObjectClass))
#define PEASY_IS_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_OBJECT))
#define PEASY_IS_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_OBJECT))
#define PEASY_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_OBJECT, PeasyObjectClass))

typedef struct _PeasyObject PeasyObject;
typedef struct _PeasyObjectClass PeasyObjectClass;
typedef struct _PeasyObjectPrivate PeasyObjectPrivate;

#define PEASY_TYPE_MSG_WINDOW (peasy_msg_window_get_type ())
#define PEASY_MSG_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_MSG_WINDOW, PeasyMsgWindow))
#define PEASY_MSG_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_MSG_WINDOW, PeasyMsgWindowClass))
#define PEASY_IS_MSG_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_MSG_WINDOW))
#define PEASY_IS_MSG_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_MSG_WINDOW))
#define PEASY_MSG_WINDOW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_MSG_WINDOW, PeasyMsgWindowClass))

typedef struct _PeasyMsgWindow PeasyMsgWindow;
typedef struct _PeasyMsgWindowClass PeasyMsgWindowClass;
typedef struct _PeasyMsgWindowPrivate PeasyMsgWindowPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

struct _PeasyObject {
	GObject parent_instance;
	PeasyObjectPrivate * priv;
};

struct _PeasyObjectClass {
	GObjectClass parent_class;
};

struct _PeasyMsgWindow {
	PeasyObject parent_instance;
	PeasyMsgWindowPrivate * priv;
};

struct _PeasyMsgWindowClass {
	PeasyObjectClass parent_class;
};


static gpointer peasy_msg_window_parent_class = NULL;
static PeasyMsgWindow* peasy_msg_window_instance;
static PeasyMsgWindow* peasy_msg_window_instance = NULL;

void msgwin_compiler_add (gint msg_color, const gchar* msg, ...);
void msgwin_status_add (const gchar* msg, ...);
GType peasy_object_get_type (void) G_GNUC_CONST;
GType peasy_msg_window_get_type (void) G_GNUC_CONST;
enum  {
	PEASY_MSG_WINDOW_DUMMY_PROPERTY
};
static PeasyMsgWindow* peasy_msg_window_new (void);
static PeasyMsgWindow* peasy_msg_window_construct (GType object_type);
PeasyObject* peasy_object_new (void);
PeasyObject* peasy_object_construct (GType object_type);
PeasyMsgWindow* peasy_msg_window_getMsgWindow (void);
void peasy_msg_window_clear_tab (PeasyMsgWindow* self, gint tab);
void peasy_msg_window_compiler_add (PeasyMsgWindow* self, gint msg_color, const gchar* msg, ...);
void peasy_msg_window_compiler_add_string (PeasyMsgWindow* self, gint msg_color, const gchar* msg);
void peasy_msg_window_set_messages_dir (PeasyMsgWindow* self, const gchar* messages_dir);
void peasy_msg_window_status_add (PeasyMsgWindow* self, const gchar* msg, ...);
void peasy_msg_window_status_add_string (PeasyMsgWindow* self, const gchar* msg);
void peasy_msg_window_switch_tab (PeasyMsgWindow* self, gint tabnum, gboolean show);
static void peasy_msg_window_finalize (GObject* obj);


static PeasyMsgWindow* peasy_msg_window_construct (GType object_type) {
	PeasyMsgWindow * self = NULL;
	self = (PeasyMsgWindow*) peasy_object_construct (object_type);
	return self;
}


static PeasyMsgWindow* peasy_msg_window_new (void) {
	return peasy_msg_window_construct (PEASY_TYPE_MSG_WINDOW);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


PeasyMsgWindow* peasy_msg_window_getMsgWindow (void) {
	PeasyMsgWindow* result = NULL;
	PeasyMsgWindow* _tmp0_ = NULL;
	PeasyMsgWindow* _tmp2_ = NULL;
	PeasyMsgWindow* _tmp3_ = NULL;
	_tmp0_ = peasy_msg_window_instance;
	if (_tmp0_ == NULL) {
		PeasyMsgWindow* _tmp1_ = NULL;
		_tmp1_ = peasy_msg_window_new ();
		_g_object_unref0 (peasy_msg_window_instance);
		peasy_msg_window_instance = _tmp1_;
	}
	_tmp2_ = peasy_msg_window_instance;
	_tmp3_ = _g_object_ref0 (_tmp2_);
	result = _tmp3_;
	return result;
}


void peasy_msg_window_clear_tab (PeasyMsgWindow* self, gint tab) {
	gint _tmp0_ = 0;
	g_return_if_fail (self != NULL);
	_tmp0_ = tab;
	msgwin_clear_tab (_tmp0_);
}


void peasy_msg_window_compiler_add (PeasyMsgWindow* self, gint msg_color, const gchar* msg, ...) {
	va_list ap = {0};
	gchar* s = NULL;
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	gint _tmp2_ = 0;
	g_return_if_fail (self != NULL);
	g_return_if_fail (msg != NULL);
	va_start (ap, msg);
	_tmp0_ = msg;
	_tmp1_ = g_strdup_vprintf (_tmp0_, ap);
	s = _tmp1_;
	_tmp2_ = msg_color;
	msgwin_compiler_add (_tmp2_, s, NULL);
	_g_free0 (s);
	va_end (ap);
}


void peasy_msg_window_compiler_add_string (PeasyMsgWindow* self, gint msg_color, const gchar* msg) {
	gint _tmp0_ = 0;
	const gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (msg != NULL);
	_tmp0_ = msg_color;
	_tmp1_ = msg;
	msgwin_compiler_add (_tmp0_, _tmp1_, NULL);
}


void peasy_msg_window_set_messages_dir (PeasyMsgWindow* self, const gchar* messages_dir) {
	const gchar* _tmp0_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (messages_dir != NULL);
	_tmp0_ = messages_dir;
	msgwin_set_messages_dir (_tmp0_);
}


void peasy_msg_window_status_add (PeasyMsgWindow* self, const gchar* msg, ...) {
	va_list ap = {0};
	gchar* s = NULL;
	const gchar* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (msg != NULL);
	va_start (ap, msg);
	_tmp0_ = msg;
	_tmp1_ = g_strdup_vprintf (_tmp0_, ap);
	s = _tmp1_;
	msgwin_status_add (s, NULL);
	_g_free0 (s);
	va_end (ap);
}


void peasy_msg_window_status_add_string (PeasyMsgWindow* self, const gchar* msg) {
	const gchar* _tmp0_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (msg != NULL);
	_tmp0_ = msg;
	msgwin_status_add (_tmp0_, NULL);
}


void peasy_msg_window_switch_tab (PeasyMsgWindow* self, gint tabnum, gboolean show) {
	gint _tmp0_ = 0;
	gboolean _tmp1_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = tabnum;
	_tmp1_ = show;
	msgwin_switch_tab (_tmp0_, _tmp1_);
}


static void peasy_msg_window_class_init (PeasyMsgWindowClass * klass) {
	peasy_msg_window_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = peasy_msg_window_finalize;
}


static void peasy_msg_window_instance_init (PeasyMsgWindow * self) {
}


static void peasy_msg_window_finalize (GObject* obj) {
	PeasyMsgWindow * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, PEASY_TYPE_MSG_WINDOW, PeasyMsgWindow);
	G_OBJECT_CLASS (peasy_msg_window_parent_class)->finalize (obj);
}


GType peasy_msg_window_get_type (void) {
	static volatile gsize peasy_msg_window_type_id__volatile = 0;
	if (g_once_init_enter (&peasy_msg_window_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (PeasyMsgWindowClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) peasy_msg_window_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PeasyMsgWindow), 0, (GInstanceInitFunc) peasy_msg_window_instance_init, NULL };
		GType peasy_msg_window_type_id;
		peasy_msg_window_type_id = g_type_register_static (PEASY_TYPE_OBJECT, "PeasyMsgWindow", &g_define_type_info, 0);
		g_once_init_leave (&peasy_msg_window_type_id__volatile, peasy_msg_window_type_id);
	}
	return peasy_msg_window_type_id__volatile;
}


