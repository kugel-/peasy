/* peasy-0.1.vapi generated by valac, do not modify. */

namespace Peasy {
	[CCode (cheader_filename = "peasy.h")]
	public class Document : Peasy.Object {
		public Peasy.Editor editor;
		public weak Geany.Document? geany_doc;
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
		public weak Geany.Editor geany_editor;
		public GeanyScintilla.ScintillaObject sci;
		public Editor ();
		public string? get_word_at (int pos, string? wordchars = null);
		public bool goto (int pos, bool mark = false);
		public Peasy.IndentType indent_type { get; set; }
		public int indent_width { get; set; }
	}
	[CCode (cheader_filename = "peasy.h")]
	public class Filetype : Peasy.Object {
		public static GLib.GenericArray<Peasy.Filetype> all_filetypes ();
	}
	[CCode (cheader_filename = "peasy.h")]
	public class KeyBinding : GLib.Object {
		public weak Geany.KeyBinding geany_binding;
		public virtual bool default_handler (int id);
	}
	[CCode (cheader_filename = "peasy.h")]
	public class KeyGroup : GLib.Object {
		public weak Geany.KeyGroup geany_group;
		public KeyGroup ();
		public Peasy.KeyBinding? add_keybinding (string name, string label, Gtk.MenuItem? menu_item, int def_key, Gdk.ModifierType def_mod);
		public Peasy.KeyBinding? add_keybinding_with_id (string name, string label, Gtk.MenuItem? menu_item, int def_key, Gdk.ModifierType def_mod, int id);
		public virtual bool default_handler (int id);
		public Peasy.KeyBinding get_item (int id);
	}
	[CCode (cheader_filename = "peasy.h")]
	public class Object : GLib.Object {
		public Object ();
		protected static void signal_connect (GLib.Object? obj, string signal_name, bool after, GLib.Callback cb, void* data);
		public Peasy.Signals plugin_signals { get; private set; }
	}
	[CCode (cheader_filename = "peasy.h")]
	public abstract class Plugin : Peasy.Object, Peasy.PluginIface {
		public weak Geany.Plugin geany_plugin;
		public Peasy.KeyGroup add_key_group (string section_name, size_t count);
		public abstract void disable ();
		public abstract bool enable ();
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
	public interface PluginConfigure {
		public abstract Gtk.Widget configure (Gtk.Dialog parent);
	}
	[CCode (cheader_filename = "peasy.h")]
	public interface PluginHelp {
		public abstract void help ();
	}
	[CCode (cheader_filename = "peasy.h")]
	public interface PluginIface : GLib.Object {
	}
	[CCode (cheader_filename = "peasy.h")]
	public enum IndentType {
		TABS,
		SPACES,
		BOTH
	}
	[CCode (cheader_filename = "peasy.h")]
	public static weak Geany.Plugin peasy_plugin;
	[CCode (cheader_filename = "peasy.h")]
	public static Peasy.Signals peasy_signals;
	[CCode (cheader_filename = "peasy.h")]
	public static void static_init (Geany.Plugin p);
}
