/* peasy.h generated by valac, the Vala compiler, do not modify */


#ifndef __SRC_PEASY_PEASY_H__
#define __SRC_PEASY_PEASY_H__

#include <glib.h>
#include <geanyplugin.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gio/gio.h>
#include <gdk/gdk.h>

G_BEGIN_DECLS


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
typedef struct _PeasyObjectPrivate PeasyObjectPrivate;
typedef struct _PeasySignalsPrivate PeasySignalsPrivate;

#define PEASY_TYPE_PLUGIN_CONFIGURE (peasy_plugin_configure_get_type ())
#define PEASY_PLUGIN_CONFIGURE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_PLUGIN_CONFIGURE, PeasyPluginConfigure))
#define PEASY_IS_PLUGIN_CONFIGURE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_PLUGIN_CONFIGURE))
#define PEASY_PLUGIN_CONFIGURE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), PEASY_TYPE_PLUGIN_CONFIGURE, PeasyPluginConfigureIface))

typedef struct _PeasyPluginConfigure PeasyPluginConfigure;
typedef struct _PeasyPluginConfigureIface PeasyPluginConfigureIface;

#define PEASY_TYPE_PLUGIN_HELP (peasy_plugin_help_get_type ())
#define PEASY_PLUGIN_HELP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_PLUGIN_HELP, PeasyPluginHelp))
#define PEASY_IS_PLUGIN_HELP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_PLUGIN_HELP))
#define PEASY_PLUGIN_HELP_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), PEASY_TYPE_PLUGIN_HELP, PeasyPluginHelpIface))

typedef struct _PeasyPluginHelp PeasyPluginHelp;
typedef struct _PeasyPluginHelpIface PeasyPluginHelpIface;

#define PEASY_TYPE_PLUGIN_IFACE (peasy_plugin_iface_get_type ())
#define PEASY_PLUGIN_IFACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_PLUGIN_IFACE, PeasyPluginIface))
#define PEASY_IS_PLUGIN_IFACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_PLUGIN_IFACE))
#define PEASY_PLUGIN_IFACE_GET_INTERFACE(obj) (G_TYPE_INSTANCE_GET_INTERFACE ((obj), PEASY_TYPE_PLUGIN_IFACE, PeasyPluginIfaceIface))

typedef struct _PeasyPluginIface PeasyPluginIface;
typedef struct _PeasyPluginIfaceIface PeasyPluginIfaceIface;

#define PEASY_TYPE_PLUGIN (peasy_plugin_get_type ())
#define PEASY_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_PLUGIN, PeasyPlugin))
#define PEASY_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_PLUGIN, PeasyPluginClass))
#define PEASY_IS_PLUGIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_PLUGIN))
#define PEASY_IS_PLUGIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_PLUGIN))
#define PEASY_PLUGIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_PLUGIN, PeasyPluginClass))

typedef struct _PeasyPlugin PeasyPlugin;
typedef struct _PeasyPluginClass PeasyPluginClass;
typedef struct _PeasyPluginPrivate PeasyPluginPrivate;

#define PEASY_TYPE_KEY_GROUP (peasy_key_group_get_type ())
#define PEASY_KEY_GROUP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_KEY_GROUP, PeasyKeyGroup))
#define PEASY_KEY_GROUP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_KEY_GROUP, PeasyKeyGroupClass))
#define PEASY_IS_KEY_GROUP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_KEY_GROUP))
#define PEASY_IS_KEY_GROUP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_KEY_GROUP))
#define PEASY_KEY_GROUP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_KEY_GROUP, PeasyKeyGroupClass))

typedef struct _PeasyKeyGroup PeasyKeyGroup;
typedef struct _PeasyKeyGroupClass PeasyKeyGroupClass;

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

#define PEASY_TYPE_FILETYPE (peasy_filetype_get_type ())
#define PEASY_FILETYPE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_FILETYPE, PeasyFiletype))
#define PEASY_FILETYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_FILETYPE, PeasyFiletypeClass))
#define PEASY_IS_FILETYPE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_FILETYPE))
#define PEASY_IS_FILETYPE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_FILETYPE))
#define PEASY_FILETYPE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_FILETYPE, PeasyFiletypeClass))

typedef struct _PeasyFiletype PeasyFiletype;
typedef struct _PeasyFiletypeClass PeasyFiletypeClass;
typedef struct _PeasyFiletypePrivate PeasyFiletypePrivate;
typedef struct _PeasyEditorPrivate PeasyEditorPrivate;
typedef struct _PeasyHighlighting PeasyHighlighting;

#define PEASY_TYPE_APP (peasy_app_get_type ())
#define PEASY_APP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_APP, PeasyApp))
#define PEASY_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_APP, PeasyAppClass))
#define PEASY_IS_APP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_APP))
#define PEASY_IS_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_APP))
#define PEASY_APP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_APP, PeasyAppClass))

typedef struct _PeasyApp PeasyApp;
typedef struct _PeasyAppClass PeasyAppClass;
typedef struct _PeasyAppPrivate PeasyAppPrivate;

#define PEASY_TYPE_UI_WIDGETS (peasy_ui_widgets_get_type ())
#define PEASY_UI_WIDGETS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_UI_WIDGETS, PeasyUiWidgets))
#define PEASY_UI_WIDGETS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_UI_WIDGETS, PeasyUiWidgetsClass))
#define PEASY_IS_UI_WIDGETS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_UI_WIDGETS))
#define PEASY_IS_UI_WIDGETS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_UI_WIDGETS))
#define PEASY_UI_WIDGETS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_UI_WIDGETS, PeasyUiWidgetsClass))

typedef struct _PeasyUiWidgets PeasyUiWidgets;
typedef struct _PeasyUiWidgetsClass PeasyUiWidgetsClass;
typedef struct _PeasyUiWidgetsPrivate PeasyUiWidgetsPrivate;

#define PEASY_TYPE_DATA (peasy_data_get_type ())
#define PEASY_DATA(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_DATA, PeasyData))
#define PEASY_DATA_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_DATA, PeasyDataClass))
#define PEASY_IS_DATA(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_DATA))
#define PEASY_IS_DATA_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_DATA))
#define PEASY_DATA_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_DATA, PeasyDataClass))

typedef struct _PeasyData PeasyData;
typedef struct _PeasyDataClass PeasyDataClass;
typedef struct _PeasyDataPrivate PeasyDataPrivate;

#define PEASY_TYPE_UI_UTILS (peasy_ui_utils_get_type ())
#define PEASY_UI_UTILS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_UI_UTILS, PeasyUiUtils))
#define PEASY_UI_UTILS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_UI_UTILS, PeasyUiUtilsClass))
#define PEASY_IS_UI_UTILS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_UI_UTILS))
#define PEASY_IS_UI_UTILS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_UI_UTILS))
#define PEASY_UI_UTILS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_UI_UTILS, PeasyUiUtilsClass))

typedef struct _PeasyUiUtils PeasyUiUtils;
typedef struct _PeasyUiUtilsClass PeasyUiUtilsClass;
typedef struct _PeasyUiUtilsPrivate PeasyUiUtilsPrivate;

#define PEASY_TYPE_KEY_BINDING (peasy_key_binding_get_type ())
#define PEASY_KEY_BINDING(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), PEASY_TYPE_KEY_BINDING, PeasyKeyBinding))
#define PEASY_KEY_BINDING_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), PEASY_TYPE_KEY_BINDING, PeasyKeyBindingClass))
#define PEASY_IS_KEY_BINDING(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PEASY_TYPE_KEY_BINDING))
#define PEASY_IS_KEY_BINDING_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), PEASY_TYPE_KEY_BINDING))
#define PEASY_KEY_BINDING_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), PEASY_TYPE_KEY_BINDING, PeasyKeyBindingClass))

typedef struct _PeasyKeyBinding PeasyKeyBinding;
typedef struct _PeasyKeyBindingClass PeasyKeyBindingClass;
typedef struct _PeasyKeyBindingPrivate PeasyKeyBindingPrivate;
typedef struct _PeasyKeyGroupPrivate PeasyKeyGroupPrivate;

struct _PeasyObject {
	GObject parent_instance;
	PeasyObjectPrivate * priv;
};

struct _PeasyObjectClass {
	GObjectClass parent_class;
};

struct _PeasySignals {
	PeasyObject parent_instance;
	PeasySignalsPrivate * priv;
};

struct _PeasySignalsClass {
	PeasyObjectClass parent_class;
};

struct _PeasyPluginConfigureIface {
	GTypeInterface parent_iface;
	GtkWidget* (*configure) (PeasyPluginConfigure* self, GtkDialog* parent);
};

struct _PeasyPluginHelpIface {
	GTypeInterface parent_iface;
	void (*help) (PeasyPluginHelp* self);
};

struct _PeasyPluginIfaceIface {
	GTypeInterface parent_iface;
	GeanyPlugin* (*get_geany_plugin) (PeasyPluginIface* self);
	void (*set_geany_plugin) (PeasyPluginIface* self, GeanyPlugin* value);
};

struct _PeasyPlugin {
	PeasyObject parent_instance;
	PeasyPluginPrivate * priv;
};

struct _PeasyPluginClass {
	PeasyObjectClass parent_class;
	gboolean (*enable) (PeasyPlugin* self);
	void (*disable) (PeasyPlugin* self);
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

struct _PeasyFiletype {
	PeasyObject parent_instance;
	PeasyFiletypePrivate * priv;
	GeanyFiletype* _ft;
};

struct _PeasyFiletypeClass {
	PeasyObjectClass parent_class;
};

struct _PeasyEditor {
	GObject parent_instance;
	PeasyEditorPrivate * priv;
	PeasyDocument* document;
	GeanyEditor* _editor;
};

struct _PeasyEditorClass {
	GObjectClass parent_class;
};

struct _PeasyHighlighting {
	int dummy;
};

struct _PeasyApp {
	PeasyObject parent_instance;
	PeasyAppPrivate * priv;
	gboolean debug_mode;
	const gchar* configdir;
	const gchar* datadir;
	const gchar* docdir;
};

struct _PeasyAppClass {
	PeasyObjectClass parent_class;
};

struct _PeasyUiWidgets {
	PeasyObject parent_instance;
	PeasyUiWidgetsPrivate * priv;
	GtkWidget* window;
	GtkWidget* toolbar;
	GtkWidget* sidebar_notebook;
	GtkWidget* notebook;
	GtkWidget* editor_menu;
	GtkWidget* tools_menu;
	GtkWidget* progressbar;
	GtkWidget* message_window_notebook;
	GtkWidget* project_menu;
};

struct _PeasyUiWidgetsClass {
	PeasyObjectClass parent_class;
};

struct _PeasyData {
	PeasyObject parent_instance;
	PeasyDataPrivate * priv;
	PeasyUiWidgets* widgets;
	PeasyApp* app;
	GeanyPrefs* prefs;
	GeanyInterfacePrefs* interface_prefs;
	GeanyToolPrefs* tool_prefs;
	GeanyToolbarPrefs* toolbar_prefs;
	GeanyEditorPrefs* editor_prefs;
	GeanyFilePrefs* file_prefs;
	GeanySearchPrefs* search_prefs;
	GeanyTemplatePrefs* template_prefs;
	GeanyBuildInfo* build_info;
};

struct _PeasyDataClass {
	PeasyObjectClass parent_class;
};

struct _PeasyUiUtils {
	GObject parent_instance;
	PeasyUiUtilsPrivate * priv;
};

struct _PeasyUiUtilsClass {
	GObjectClass parent_class;
};

struct _PeasyKeyBinding {
	GObject parent_instance;
	PeasyKeyBindingPrivate * priv;
	GeanyKeyBinding* _kb_item;
};

struct _PeasyKeyBindingClass {
	GObjectClass parent_class;
	gboolean (*default_handler) (PeasyKeyBinding* self, gint id);
};

struct _PeasyKeyGroup {
	GObject parent_instance;
	PeasyKeyGroupPrivate * priv;
	GeanyKeyGroup* _kb_group;
};

struct _PeasyKeyGroupClass {
	GObjectClass parent_class;
	gboolean (*default_handler) (PeasyKeyGroup* self, gint id);
};


extern GeanyPlugin* peasy_peasy_plugin;
GType peasy_object_get_type (void) G_GNUC_CONST;
GType peasy_signals_get_type (void) G_GNUC_CONST;
extern PeasySignals* peasy_peasy_signals;
void peasy_static_init (GeanyPlugin* p);
void peasy_object_signal_connect (GObject* obj, const gchar* signal_name, gboolean after, GCallback cb, void* data);
PeasyObject* peasy_object_new (void);
PeasyObject* peasy_object_construct (GType object_type);
PeasySignals* peasy_object_get_plugin_signals (PeasyObject* self);
PeasySignals* peasy_signals_new (void);
PeasySignals* peasy_signals_construct (GType object_type);
GType peasy_plugin_configure_get_type (void) G_GNUC_CONST;
GtkWidget* peasy_plugin_configure_configure (PeasyPluginConfigure* self, GtkDialog* parent);
GType peasy_plugin_help_get_type (void) G_GNUC_CONST;
void peasy_plugin_help_help (PeasyPluginHelp* self);
GType peasy_plugin_iface_get_type (void) G_GNUC_CONST;
GType peasy_plugin_get_type (void) G_GNUC_CONST;
gboolean peasy_plugin_enable (PeasyPlugin* self);
void peasy_plugin_disable (PeasyPlugin* self);
GType peasy_key_group_get_type (void) G_GNUC_CONST;
PeasyKeyGroup* peasy_plugin_add_key_group (PeasyPlugin* self, const gchar* section_name, gsize count);
GeanyPlugin* peasy_plugin_iface_get_geany_plugin (PeasyPluginIface* self);
void peasy_plugin_iface_set_geany_plugin (PeasyPluginIface* self, GeanyPlugin* value);
GType peasy_document_get_type (void) G_GNUC_CONST;
GType peasy_editor_get_type (void) G_GNUC_CONST;
GPtrArray* peasy_document_all_documents (void);
GType peasy_filetype_get_type (void) G_GNUC_CONST;
PeasyDocument* peasy_document_new_new_file (const gchar* utf8_filename, PeasyFiletype* ft, const gchar* text);
PeasyDocument* peasy_document_construct_new_file (GType object_type, const gchar* utf8_filename, PeasyFiletype* ft, const gchar* text);
PeasyDocument* peasy_document_new_from_file (const gchar* locale_filename, gboolean readonly, PeasyFiletype* ft, const gchar* forced_enc);
PeasyDocument* peasy_document_construct_from_file (GType object_type, const gchar* locale_filename, gboolean readonly, PeasyFiletype* ft, const gchar* forced_enc);
PeasyDocument* peasy_document_get_current (void);
gboolean peasy_document_close (PeasyDocument* self);
gboolean peasy_document_save (PeasyDocument* self, gboolean force);
gboolean peasy_document_save_as (PeasyDocument* self, const gchar* file_name);
gboolean peasy_document_reload (PeasyDocument* self, const gchar* forced_enc);
gboolean peasy_document_get_changed (PeasyDocument* self);
void peasy_document_set_changed (PeasyDocument* self, gboolean value);
const gchar* peasy_document_get_encoding (PeasyDocument* self);
void peasy_document_set_encoding (PeasyDocument* self, const gchar* value);
gboolean peasy_document_get_is_valid (PeasyDocument* self);
gboolean peasy_document_get_has_bom (PeasyDocument* self);
gboolean peasy_document_get_has_tags (PeasyDocument* self);
guint peasy_document_get_id (PeasyDocument* self);
gchar* peasy_document_get_display_name (PeasyDocument* self);
GPtrArray* peasy_filetype_all_filetypes (void);
PeasyFiletype* peasy_filetype_get_by_id (GeanyFiletypeID id);
PeasyFiletype* peasy_filetype_get_by_name (const gchar* name);
PeasyFiletype* peasy_filetype_detect_from_file (const gchar* filename);
gint peasy_filetype_get_id (PeasyFiletype* self);
const gchar* peasy_filetype_get_extension (PeasyFiletype* self);
const gchar* peasy_filetype_get_name (PeasyFiletype* self);
const gchar* peasy_filetype_get_title (PeasyFiletype* self);
const gchar* peasy_filetype_get_display_name (PeasyFiletype* self);
const gchar* peasy_filetype_get_mime_type (PeasyFiletype* self);
GIcon* peasy_filetype_get_icon (PeasyFiletype* self);
gchar* peasy_editor_get_word_at (PeasyEditor* self, gint pos, const gchar* wordchars);
gboolean peasy_editor_goto (PeasyEditor* self, gint pos, gboolean mark);
void peasy_editor_indicator_clear (PeasyEditor* self, GeanyIndicator indic);
void peasy_editor_indicator_set_on_line (PeasyEditor* self, GeanyIndicator indic, gint line);
void peasy_editor_indicator_set_on_range (PeasyEditor* self, GeanyIndicator indic, gint start, gint end);
PeasyEditor* peasy_editor_new (void);
PeasyEditor* peasy_editor_construct (GType object_type);
gboolean peasy_editor_get_auto_indent (PeasyEditor* self);
GeanyIndentType peasy_editor_get_indent_type (PeasyEditor* self);
void peasy_editor_set_indent_type (PeasyEditor* self, GeanyIndentType value);
gboolean peasy_editor_get_line_breaking (PeasyEditor* self);
void peasy_highlighting_free (PeasyHighlighting* self);
gboolean peasy_highlighting_is_string_style (gint lexer, gint style);
gboolean peasy_highlighting_is_comment_style (gint lexer, gint style);
gboolean peasy_highlighting_is_code_style (gint lexer, gint style);
void peasy_highlighting_get_lexer_style (PeasyFiletype* ft, gint style, GeanyLexerStyle* result);
GType peasy_app_get_type (void) G_GNUC_CONST;
PeasyApp* peasy_app_new (void);
PeasyApp* peasy_app_construct (GType object_type);
GType peasy_ui_widgets_get_type (void) G_GNUC_CONST;
PeasyUiWidgets* peasy_ui_widgets_new (void);
PeasyUiWidgets* peasy_ui_widgets_construct (GType object_type);
GType peasy_data_get_type (void) G_GNUC_CONST;
PeasyData* peasy_data_instance (void);
GType peasy_ui_utils_get_type (void) G_GNUC_CONST;
GtkWidget* peasy_ui_utils_button_new_with_image (const gchar* stock_id, const gchar* text);
GtkWidget* peasy_ui_utils_image_menu_item_new (const gchar* stock_id, const gchar* label);
GtkWidget* peasy_ui_utils_path_box_new (const gchar* title, GtkFileChooserAction action, GtkEntry* entry);
GtkWidget* peasy_ui_utils_dialog_vbox_new (GtkDialog* dialog);
void peasy_ui_utils_add_document_sensitive (GtkWidget* widget);
GtkWidget* peasy_ui_utils_lookup_widget (PeasyUiUtils* self, GtkWidget* widget, const gchar* widget_name);
PeasyUiUtils* peasy_ui_utils_new (void);
PeasyUiUtils* peasy_ui_utils_construct (GType object_type);
GType peasy_key_binding_get_type (void) G_GNUC_CONST;
gboolean peasy_key_binding_default_handler (PeasyKeyBinding* self, gint id);
gboolean peasy_key_group_default_handler (PeasyKeyGroup* self, gint id);
PeasyKeyBinding* peasy_key_group_add_keybinding (PeasyKeyGroup* self, const gchar* name, const gchar* label, GtkMenuItem* menu_item, gint def_key, GdkModifierType def_mod);
PeasyKeyBinding* peasy_key_group_add_keybinding_with_id (PeasyKeyGroup* self, const gchar* name, const gchar* label, GtkMenuItem* menu_item, gint def_key, GdkModifierType def_mod, gint id);
PeasyKeyBinding* peasy_key_group_get_item (PeasyKeyGroup* self, gint id);
PeasyKeyGroup* peasy_key_group_new (void);
PeasyKeyGroup* peasy_key_group_construct (GType object_type);


G_END_DECLS

#endif
