/* keygroup.c generated by valac, the Vala compiler
 * generated from keygroup.vala, do not modify */


#include <glib.h>
#include <glib-object.h>
#include <geanyplugin.h>
#include <gdk/gdk.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>


#define PEASY_TYPE_KEY_BINDING (peasy_key_binding_get_type ())
#define PEASY_KEY_BINDING(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_KEY_BINDING, PeasyKeyBinding))
#define PEASY_KEY_BINDING_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_KEY_BINDING, PeasyKeyBindingClass))
#define PEASY_IS_KEY_BINDING(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_KEY_BINDING))
#define PEASY_IS_KEY_BINDING_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_KEY_BINDING))
#define PEASY_KEY_BINDING_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_KEY_BINDING, PeasyKeyBindingClass))

typedef struct _PeasyKeyBinding PeasyKeyBinding;
typedef struct _PeasyKeyBindingClass PeasyKeyBindingClass;
typedef struct _PeasyKeyBindingPrivate PeasyKeyBindingPrivate;

#define PEASY_TYPE_KEY_GROUP (peasy_key_group_get_type ())
#define PEASY_KEY_GROUP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_KEY_GROUP, PeasyKeyGroup))
#define PEASY_KEY_GROUP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_KEY_GROUP, PeasyKeyGroupClass))
#define PEASY_IS_KEY_GROUP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_KEY_GROUP))
#define PEASY_IS_KEY_GROUP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_KEY_GROUP))
#define PEASY_KEY_GROUP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_KEY_GROUP, PeasyKeyGroupClass))

typedef struct _PeasyKeyGroup PeasyKeyGroup;
typedef struct _PeasyKeyGroupClass PeasyKeyGroupClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _PeasyKeyGroupPrivate PeasyKeyGroupPrivate;
#define _g_list_free0(var) ((var == NULL) ? NULL : (var = (g_list_free (var), NULL)))

struct _PeasyKeyBinding {
	GObject parent_instance;
	PeasyKeyBindingPrivate * priv;
	GeanyKeyBinding* geany_binding;
};

struct _PeasyKeyBindingClass {
	GObjectClass parent_class;
	gboolean (*default_handler) (PeasyKeyBinding* self, gint id);
};

struct _PeasyKeyBindingPrivate {
	PeasyKeyGroup* m_group;
};

struct _PeasyKeyGroup {
	GObject parent_instance;
	PeasyKeyGroupPrivate * priv;
	GeanyKeyGroup* geany_group;
};

struct _PeasyKeyGroupClass {
	GObjectClass parent_class;
	gboolean (*default_handler) (PeasyKeyGroup* self, gint id);
};

struct _PeasyKeyGroupPrivate {
	gint index;
	GList* m_items;
};


static gpointer peasy_key_binding_parent_class = NULL;
static gpointer peasy_key_group_parent_class = NULL;

GType peasy_key_binding_get_type (void) G_GNUC_CONST;
GType peasy_key_group_get_type (void) G_GNUC_CONST;
#define PEASY_KEY_BINDING_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), PEASY_TYPE_KEY_BINDING, PeasyKeyBindingPrivate))
enum  {
	PEASY_KEY_BINDING_DUMMY_PROPERTY
};
gboolean peasy_key_binding_default_handler (PeasyKeyBinding* self, gint id);
static gboolean peasy_key_binding_real_default_handler (PeasyKeyBinding* self, gint id);
static gboolean peasy_key_binding_geany_handler (PeasyKeyBinding* self, GeanyKeyBinding* item, guint id);
PeasyKeyBinding* peasy_key_binding_new (PeasyKeyGroup* kb_group, gint index, gint def_key, GdkModifierType def_mod, const gchar* name, const gchar* label, GtkMenuItem* menu_item);
PeasyKeyBinding* peasy_key_binding_construct (GType object_type, PeasyKeyGroup* kb_group, gint index, gint def_key, GdkModifierType def_mod, const gchar* name, const gchar* label, GtkMenuItem* menu_item);
static gboolean _peasy_key_binding_geany_handler_geany_key_binding_func (GeanyKeyBinding* key, guint key_id, gpointer self);
PeasyKeyBinding* peasy_key_binding_new_from_geany (PeasyKeyGroup* kb_group, GeanyKeyBinding* kb_item);
PeasyKeyBinding* peasy_key_binding_construct_from_geany (GType object_type, PeasyKeyGroup* kb_group, GeanyKeyBinding* kb_item);
void peasy_key_binding_setup_signal_activate (void);
static void peasy_key_binding_finalize (GObject * obj);
#define PEASY_KEY_GROUP_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), PEASY_TYPE_KEY_GROUP, PeasyKeyGroupPrivate))
enum  {
	PEASY_KEY_GROUP_DUMMY_PROPERTY
};
gboolean peasy_key_group_default_handler (PeasyKeyGroup* self, gint id);
static gboolean peasy_key_group_real_default_handler (PeasyKeyGroup* self, gint id);
PeasyKeyGroup* peasy_key_group_new_from_geany (GeanyKeyGroup* kb_group);
PeasyKeyGroup* peasy_key_group_construct_from_geany (GType object_type, GeanyKeyGroup* kb_group);
PeasyKeyBinding* peasy_key_group_add_keybinding (PeasyKeyGroup* self, const gchar* name, const gchar* label, GtkMenuItem* menu_item, gint def_key, GdkModifierType def_mod);
PeasyKeyBinding* peasy_key_group_add_keybinding_with_id (PeasyKeyGroup* self, const gchar* name, const gchar* label, GtkMenuItem* menu_item, gint def_key, GdkModifierType def_mod, gint id);
PeasyKeyBinding* peasy_key_group_get_item (PeasyKeyGroup* self, gint id);
void peasy_key_group_setup_signal_activate (void);
PeasyKeyGroup* peasy_key_group_new (void);
PeasyKeyGroup* peasy_key_group_construct (GType object_type);
static void peasy_key_group_finalize (GObject * obj);


static gboolean peasy_key_binding_real_default_handler (PeasyKeyBinding* self, gint id) {
	gboolean result = FALSE;
	result = FALSE;
	return result;
}


gboolean peasy_key_binding_default_handler (PeasyKeyBinding* self, gint id) {
	g_return_val_if_fail (self != NULL, FALSE);
	return PEASY_KEY_BINDING_GET_CLASS (self)->default_handler (self, id);
}


static gboolean peasy_key_binding_geany_handler (PeasyKeyBinding* self, GeanyKeyBinding* item, guint id) {
	gboolean result = FALSE;
	gboolean ret = FALSE;
	guint _tmp0_;
	gboolean _tmp1_;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (item != NULL, FALSE);
	ret = FALSE;
	_tmp0_ = id;
	g_signal_emit_by_name (self, "activate", _tmp0_, &ret, NULL);
	_tmp1_ = ret;
	if (!_tmp1_) {
		PeasyKeyGroup* _tmp2_;
		guint _tmp3_;
		_tmp2_ = self->priv->m_group;
		_tmp3_ = id;
		g_signal_emit_by_name (_tmp2_, "activate", _tmp3_, &ret, NULL);
	}
	result = ret;
	return result;
}


static gboolean _peasy_key_binding_geany_handler_geany_key_binding_func (GeanyKeyBinding* key, guint key_id, gpointer self) {
	gboolean result;
	result = peasy_key_binding_geany_handler ((PeasyKeyBinding*) self, key, key_id);
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


PeasyKeyBinding* peasy_key_binding_construct (GType object_type, PeasyKeyGroup* kb_group, gint index, gint def_key, GdkModifierType def_mod, const gchar* name, const gchar* label, GtkMenuItem* menu_item) {
	PeasyKeyBinding * self = NULL;
	PeasyKeyGroup* _tmp0_;
	GeanyKeyGroup* _tmp1_;
	gint _tmp2_;
	gint _tmp3_;
	GdkModifierType _tmp4_;
	const gchar* _tmp5_;
	const gchar* _tmp6_;
	GtkMenuItem* _tmp7_;
	GeanyKeyBinding* _tmp8_;
	PeasyKeyGroup* _tmp9_;
	PeasyKeyGroup* _tmp10_;
	g_return_val_if_fail (kb_group != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (label != NULL, NULL);
	self = (PeasyKeyBinding*) g_object_new (object_type, NULL);
	_tmp0_ = kb_group;
	_tmp1_ = _tmp0_->geany_group;
	_tmp2_ = index;
	_tmp3_ = def_key;
	_tmp4_ = def_mod;
	_tmp5_ = name;
	_tmp6_ = label;
	_tmp7_ = menu_item;
	_tmp8_ = keybindings_set_item_full (_tmp1_, (gsize) _tmp2_, (guint) _tmp3_, _tmp4_, _tmp5_, _tmp6_, (GtkWidget*) _tmp7_, _peasy_key_binding_geany_handler_geany_key_binding_func, g_object_ref (self), g_object_unref);
	self->geany_binding = _tmp8_;
	_tmp9_ = kb_group;
	_tmp10_ = _g_object_ref0 (_tmp9_);
	_g_object_unref0 (self->priv->m_group);
	self->priv->m_group = _tmp10_;
	return self;
}


PeasyKeyBinding* peasy_key_binding_new (PeasyKeyGroup* kb_group, gint index, gint def_key, GdkModifierType def_mod, const gchar* name, const gchar* label, GtkMenuItem* menu_item) {
	return peasy_key_binding_construct (PEASY_TYPE_KEY_BINDING, kb_group, index, def_key, def_mod, name, label, menu_item);
}


PeasyKeyBinding* peasy_key_binding_construct_from_geany (GType object_type, PeasyKeyGroup* kb_group, GeanyKeyBinding* kb_item) {
	PeasyKeyBinding * self = NULL;
	GeanyKeyBinding* _tmp0_;
	PeasyKeyGroup* _tmp1_;
	PeasyKeyGroup* _tmp2_;
	g_return_val_if_fail (kb_group != NULL, NULL);
	g_return_val_if_fail (kb_item != NULL, NULL);
	self = (PeasyKeyBinding*) g_object_new (object_type, NULL);
	_tmp0_ = kb_item;
	self->geany_binding = _tmp0_;
	_tmp1_ = kb_group;
	_tmp2_ = _g_object_ref0 (_tmp1_);
	_g_object_unref0 (self->priv->m_group);
	self->priv->m_group = _tmp2_;
	return self;
}


PeasyKeyBinding* peasy_key_binding_new_from_geany (PeasyKeyGroup* kb_group, GeanyKeyBinding* kb_item) {
	return peasy_key_binding_construct_from_geany (PEASY_TYPE_KEY_BINDING, kb_group, kb_item);
}


static void peasy_key_binding_class_init (PeasyKeyBindingClass * klass) {
	peasy_key_binding_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (PeasyKeyBindingPrivate));
	((PeasyKeyBindingClass *) klass)->default_handler = (gboolean (*) (PeasyKeyBinding *, gint)) peasy_key_binding_real_default_handler;
	G_OBJECT_CLASS (klass)->finalize = peasy_key_binding_finalize;
	peasy_key_binding_setup_signal_activate ();
}


static void peasy_key_binding_instance_init (PeasyKeyBinding * self) {
	self->priv = PEASY_KEY_BINDING_GET_PRIVATE (self);
}


static void peasy_key_binding_finalize (GObject * obj) {
	PeasyKeyBinding * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, PEASY_TYPE_KEY_BINDING, PeasyKeyBinding);
	_g_object_unref0 (self->priv->m_group);
	G_OBJECT_CLASS (peasy_key_binding_parent_class)->finalize (obj);
}


GType peasy_key_binding_get_type (void) {
	static volatile gsize peasy_key_binding_type_id__volatile = 0;
	if (g_once_init_enter (&peasy_key_binding_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (PeasyKeyBindingClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) peasy_key_binding_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PeasyKeyBinding), 0, (GInstanceInitFunc) peasy_key_binding_instance_init, NULL };
		GType peasy_key_binding_type_id;
		peasy_key_binding_type_id = g_type_register_static (G_TYPE_OBJECT, "PeasyKeyBinding", &g_define_type_info, 0);
		g_once_init_leave (&peasy_key_binding_type_id__volatile, peasy_key_binding_type_id);
	}
	return peasy_key_binding_type_id__volatile;
}


static gboolean peasy_key_group_real_default_handler (PeasyKeyGroup* self, gint id) {
	gboolean result = FALSE;
	result = FALSE;
	return result;
}


gboolean peasy_key_group_default_handler (PeasyKeyGroup* self, gint id) {
	g_return_val_if_fail (self != NULL, FALSE);
	return PEASY_KEY_GROUP_GET_CLASS (self)->default_handler (self, id);
}


PeasyKeyGroup* peasy_key_group_construct_from_geany (GType object_type, GeanyKeyGroup* kb_group) {
	PeasyKeyGroup * self = NULL;
	GeanyKeyGroup* _tmp0_;
	g_return_val_if_fail (kb_group != NULL, NULL);
	self = (PeasyKeyGroup*) g_object_new (object_type, NULL);
	_tmp0_ = kb_group;
	self->geany_group = _tmp0_;
	self->priv->index = 0;
	return self;
}


PeasyKeyGroup* peasy_key_group_new_from_geany (GeanyKeyGroup* kb_group) {
	return peasy_key_group_construct_from_geany (PEASY_TYPE_KEY_GROUP, kb_group);
}


PeasyKeyBinding* peasy_key_group_add_keybinding (PeasyKeyGroup* self, const gchar* name, const gchar* label, GtkMenuItem* menu_item, gint def_key, GdkModifierType def_mod) {
	PeasyKeyBinding* result = NULL;
	PeasyKeyBinding* item = NULL;
	gint _tmp0_;
	gint _tmp1_;
	GdkModifierType _tmp2_;
	const gchar* _tmp3_;
	const gchar* _tmp4_;
	GtkMenuItem* _tmp5_;
	PeasyKeyBinding* _tmp6_;
	gint _tmp7_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (label != NULL, NULL);
	_tmp0_ = self->priv->index;
	_tmp1_ = def_key;
	_tmp2_ = def_mod;
	_tmp3_ = name;
	_tmp4_ = label;
	_tmp5_ = menu_item;
	_tmp6_ = peasy_key_binding_new (self, _tmp0_, _tmp1_, _tmp2_, _tmp3_, _tmp4_, _tmp5_);
	item = _tmp6_;
	_tmp7_ = self->priv->index;
	self->priv->index = _tmp7_ + 1;
	self->priv->m_items = g_list_append (self->priv->m_items, item);
	result = item;
	return result;
}


PeasyKeyBinding* peasy_key_group_add_keybinding_with_id (PeasyKeyGroup* self, const gchar* name, const gchar* label, GtkMenuItem* menu_item, gint def_key, GdkModifierType def_mod, gint id) {
	PeasyKeyBinding* result = NULL;
	gint _tmp0_;
	gint _tmp1_;
	GdkModifierType _tmp2_;
	const gchar* _tmp3_;
	const gchar* _tmp4_;
	GtkMenuItem* _tmp5_;
	PeasyKeyBinding* _tmp6_;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (label != NULL, NULL);
	_tmp0_ = id;
	_tmp1_ = def_key;
	_tmp2_ = def_mod;
	_tmp3_ = name;
	_tmp4_ = label;
	_tmp5_ = menu_item;
	_tmp6_ = peasy_key_binding_new (self, _tmp0_, _tmp1_, _tmp2_, _tmp3_, _tmp4_, _tmp5_);
	result = _tmp6_;
	return result;
}


PeasyKeyBinding* peasy_key_group_get_item (PeasyKeyGroup* self, gint id) {
	PeasyKeyBinding* result = NULL;
	GeanyKeyBinding* item = NULL;
	GeanyKeyGroup* _tmp0_;
	gint _tmp1_;
	GeanyKeyBinding* _tmp2_;
	PeasyKeyBinding* _tmp3_;
	g_return_val_if_fail (self != NULL, NULL);
	_tmp0_ = self->geany_group;
	_tmp1_ = id;
	_tmp2_ = keybindings_get_item (_tmp0_, (gsize) _tmp1_);
	item = _tmp2_;
	g_return_val_if_fail (item != NULL, NULL);
	_tmp3_ = peasy_key_binding_new_from_geany (self, item);
	result = _tmp3_;
	return result;
}


PeasyKeyGroup* peasy_key_group_construct (GType object_type) {
	PeasyKeyGroup * self = NULL;
	self = (PeasyKeyGroup*) g_object_new (object_type, NULL);
	return self;
}


PeasyKeyGroup* peasy_key_group_new (void) {
	return peasy_key_group_construct (PEASY_TYPE_KEY_GROUP);
}


static void peasy_key_group_class_init (PeasyKeyGroupClass * klass) {
	peasy_key_group_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (PeasyKeyGroupPrivate));
	((PeasyKeyGroupClass *) klass)->default_handler = (gboolean (*) (PeasyKeyGroup *, gint)) peasy_key_group_real_default_handler;
	G_OBJECT_CLASS (klass)->finalize = peasy_key_group_finalize;
	peasy_key_group_setup_signal_activate ();
}


static void peasy_key_group_instance_init (PeasyKeyGroup * self) {
	self->priv = PEASY_KEY_GROUP_GET_PRIVATE (self);
}


static void peasy_key_group_finalize (GObject * obj) {
	PeasyKeyGroup * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, PEASY_TYPE_KEY_GROUP, PeasyKeyGroup);
	_g_list_free0 (self->priv->m_items);
	G_OBJECT_CLASS (peasy_key_group_parent_class)->finalize (obj);
}


GType peasy_key_group_get_type (void) {
	static volatile gsize peasy_key_group_type_id__volatile = 0;
	if (g_once_init_enter (&peasy_key_group_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (PeasyKeyGroupClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) peasy_key_group_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (PeasyKeyGroup), 0, (GInstanceInitFunc) peasy_key_group_instance_init, NULL };
		GType peasy_key_group_type_id;
		peasy_key_group_type_id = g_type_register_static (G_TYPE_OBJECT, "PeasyKeyGroup", &g_define_type_info, 0);
		g_once_init_leave (&peasy_key_group_type_id__volatile, peasy_key_group_type_id);
	}
	return peasy_key_group_type_id__volatile;
}



