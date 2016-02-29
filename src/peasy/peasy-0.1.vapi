/* peasy-0.1.vapi generated by valac, do not modify. */

namespace Peasy {
	[CCode (cheader_filename = "peasy.h")]
	public class App : Peasy.Object {
		public weak string configdir;
		public weak string datadir;
		public bool debug_mode;
		public weak string docdir;
		public App ();
	}
	[CCode (cheader_filename = "peasy.h")]
	public class Data : Peasy.Object {
		public Peasy.App app;
		public weak Geany.EditorPrefs editor_prefs;
		public weak Geany.FilePrefs file_prefs;
		public weak Geany.InterfacePrefs interface_prefs;
		public weak Geany.Prefs prefs;
		public weak Geany.SearchPrefs search_prefs;
		public weak Geany.TemplatePrefs template_prefs;
		public weak Geany.ToolPrefs tool_prefs;
		public weak Geany.ToolbarPrefs toolbar_prefs;
		public Peasy.UiWidgets widgets;
		public static Peasy.Data instance ();
	}
	[CCode (cheader_filename = "peasy.h")]
	public class Document : Peasy.Object {
		public Peasy.Editor editor;
		public static GLib.GenericArray<Peasy.Document> all_documents ();
		public bool close ();
		public Document.from_file (string locale_filename, bool readonly = false, Peasy.Filetype? ft = null, string? forced_enc = null);
		public static Peasy.Document? get_current ();
		public Document.new_file (string? utf8_filename = null, Peasy.Filetype? ft = null, string? text = null);
		public bool reload (string? forced_enc = null);
		public bool save (bool force = false);
		public bool save_as (string? file_name = null);
		public bool changed { get; set; }
		public string display_name { owned get; }
		public string encoding { get; set; }
		public bool has_bom { get; }
		public bool has_tags { get; }
		public uint id { get; }
		public bool is_valid { get; }
		public signal void activate ();
		public signal void before_save ();
		public signal void closing ();
		public signal void filetype_set (Peasy.Filetype? old_ft);
		public signal void reloaded ();
		public signal void saved ();
	}
	[CCode (cheader_filename = "peasy.h")]
	public class Editor : GLib.Object {
		public weak Peasy.Document document;
		public GeanyScintilla.ScintillaObject sci;
		public Editor ();
		public string? get_word_at (int pos, string? wordchars = null);
		public bool goto (int pos, bool mark = false);
		public void indicator_clear (Geany.Indicator indic);
		public void indicator_set_on_line (Geany.Indicator indic, int line);
		public void indicator_set_on_range (Geany.Indicator indic, int start, int end);
		public bool auto_indent { get; }
		public Peasy.IndentType indent_type { get; set; }
		public int indent_width { get; set; }
		public bool line_breaking { get; }
		public bool line_wrapping { get; }
	}
	[CCode (cheader_filename = "peasy.h")]
	public class Filetype : Peasy.Object {
		public static GLib.GenericArray<Peasy.Filetype> all_filetypes ();
		public static Peasy.Filetype detect_from_file (string filename);
		public static Peasy.Filetype? get_by_id (Geany.FiletypeID id);
		public static Peasy.Filetype? get_by_name (string name);
		public string display_name { get; }
		public string extension { get; }
		public GLib.Icon? icon { get; }
		public int id { get; }
		public string? mime_type { get; }
		public string name { get; }
		public string title { get; }
	}
	[CCode (cheader_filename = "peasy.h")]
	[Compact]
	public class Highlighting {
		public static Geany.LexerStyle get_lexer_style (Peasy.Filetype ft, int style);
		public static bool is_code_style (int lexer, int style);
		public static bool is_comment_style (int lexer, int style);
		public static bool is_string_style (int lexer, int style);
	}
	[CCode (cheader_filename = "peasy.h")]
	public class KeyBinding : GLib.Object {
		public virtual bool default_handler (int id);
	}
	[CCode (cheader_filename = "peasy.h")]
	public class KeyGroup : GLib.Object {
		public KeyGroup ();
		public Peasy.KeyBinding? add_keybinding (string name, string label, Gtk.MenuItem? menu_item, int def_key, Gdk.ModifierType def_mod);
		public Peasy.KeyBinding? add_keybinding_with_id (string name, string label, Gtk.MenuItem? menu_item, int def_key, Gdk.ModifierType def_mod, int id);
		public virtual bool default_handler (int id);
		public Peasy.KeyBinding get_item (int id);
	}
	[CCode (cheader_filename = "peasy.h")]
	public class MsgWindow : Peasy.Object {
		public void clear_tab (int tab);
		public void compiler_add (int msg_color, string msg, ...);
		public void compiler_add_string (int msg_color, string msg);
		public static Peasy.MsgWindow getMsgWindow ();
		public void set_messages_dir (string messages_dir);
		public void status_add (string msg, ...);
		public void status_add_string (string msg);
		public void switch_tab (int tabnum, bool show);
	}
	[CCode (cheader_filename = "peasy.h")]
	public class Object : GLib.Object {
		public Object ();
		protected static void signal_connect (GLib.Object? obj, string signal_name, bool after, GLib.Callback cb, void* data);
		public Peasy.Signals plugin_signals { get; private set; }
	}
	[CCode (cheader_filename = "peasy.h")]
	public abstract class Plugin : Peasy.Object, Peasy.PluginIface {
		public Peasy.Data data;
		public Peasy.KeyGroup add_key_group (string section_name, size_t count);
		public abstract void disable ();
		public abstract bool enable ();
		public Peasy.Project? get_project ();
	}
	[CCode (cheader_filename = "peasy.h")]
	public class Project : Peasy.Object {
		public Project ();
		public string base_path { get; private set; }
		public string description { get; private set; }
		public string file_name { get; private set; }
		public string[] file_patterns { get; private set; }
		public string name { get; private set; }
		public int pure { get; set; }
	}
	[CCode (cheader_filename = "peasy.h")]
	public class Signals : Peasy.Object {
		protected Signals ();
		public signal void document_activate (Peasy.Document doc);
		public signal void document_before_save (Peasy.Document doc);
		public signal void document_close (Peasy.Document doc);
		public signal void document_filetype_set (Peasy.Document doc, Peasy.Filetype? old_ft);
		public signal void document_new (Peasy.Document doc);
		public signal void document_open (Peasy.Document doc);
		public signal void document_reload (Peasy.Document doc);
		public signal void document_save (Peasy.Document doc);
	}
	[CCode (cheader_filename = "peasy.h")]
	public class UiUtils : GLib.Object {
		public UiUtils ();
		public static void add_document_sensitive (Gtk.Widget widget);
		public static Gtk.Widget button_new_with_image (string stock_id, string text);
		public static Gtk.Widget dialog_vbox_new (Gtk.Dialog dialog);
		public static Gtk.Widget image_menu_item_new (string stock_id, string label);
		public unowned Gtk.Widget? lookup_widget (Gtk.Widget widget, string widget_name);
		public static Gtk.Widget path_box_new (string? title, Gtk.FileChooserAction action, Gtk.Entry entry);
	}
	[CCode (cheader_filename = "peasy.h")]
	public class UiWidgets : Peasy.Object {
		public weak Gtk.Widget editor_menu;
		public weak Gtk.Widget message_window_notebook;
		public weak Gtk.Widget notebook;
		public weak Gtk.Widget progressbar;
		public weak Gtk.Widget project_menu;
		public weak Gtk.Widget sidebar_notebook;
		public weak Gtk.Widget toolbar;
		public weak Gtk.Widget tools_menu;
		public weak Gtk.Widget window;
		public UiWidgets ();
	}
	[CCode (cheader_filename = "peasy.h")]
	public interface PluginConfigure {
		public abstract Gtk.Widget configure (Gtk.Dialog parent);
	}
	[CCode (cheader_filename = "peasy.h")]
	public interface PluginHelp {
		public abstract void help ();
	}
	[CCode (cheader_filename = "peasy.h")]
	public interface PluginIface : GLib.Object {
		public abstract Geany.Plugin geany_plugin { get; set construct; }
	}
	[CCode (cheader_filename = "peasy.h")]
	public enum AutoIndent {
		NONE,
		BASIC,
		CURRENTCHARS,
		MATCHBRACES
	}
	[CCode (cheader_filename = "peasy.h")]
	public enum IndentType {
		TABS,
		SPACES,
		BOTH
	}
	[CCode (cheader_filename = "peasy.h")]
	public enum Indicator {
		ERROR,
		SEARCH
	}
	[CCode (cheader_filename = "peasy.h")]
	public static weak Geany.Plugin peasy_plugin;
	[CCode (cheader_filename = "peasy.h")]
	public static Peasy.Signals peasy_signals;
	[CCode (cheader_filename = "peasy.h")]
	public static void static_init (Geany.Plugin p);
}