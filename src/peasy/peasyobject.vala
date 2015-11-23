
extern void plugin_signal_connect(Geany.Plugin p, GLib.Object? obj, string signal_name,
						  bool after, GLib.Callback cb, void *data);

namespace Peasy
{
public class Object : GLib.Object
{
	protected static weak Geany.Plugin geany_plugin;
	protected static void signal_connect(GLib.Object? obj, string signal_name,
								  bool after, GLib.Callback cb, void *data)
	{
		plugin_signal_connect(geany_plugin, obj, signal_name, after, cb, data);
	}

	private static Signals _plugin;
	public static Signals peasy_signals()
	{
		if (_plugin == null)
			_plugin = new Signals();
		return _plugin;
	}
}


public class Signals : Object
{
	/* just wraps Geany.object signals */
	public signal void document_new(Document doc);
	private static void emit_new(GLib.Object obj, Geany.Document geany_doc, Peasy.Signals sig)
	{
		sig.document_new(new Document(geany_doc));
	}

	public signal void document_open(Document doc);
	private static void emit_open(GLib.Object obj, Geany.Document geany_doc, Peasy.Signals sig)
	{
		sig.document_open(new Document(geany_doc));
	}

	public signal void document_activate(Document doc);
	private static void emit_activate(GLib.Object obj, Geany.Document geany_doc, Peasy.Signals sig)
	{
		sig.document_activate(new Document(geany_doc));
	}

	public signal void document_reload(Document doc);
	private static void emit_reload(GLib.Object obj, Geany.Document geany_doc, Peasy.Signals sig)
	{
		sig.document_reload(new Document(geany_doc));
	}

	public signal void document_before_save(Document doc);
	private static void emit_before_save(GLib.Object obj, Geany.Document geany_doc, Peasy.Signals sig)
	{
		sig.document_before_save(new Document(geany_doc));
	}

	public signal void document_save(Document doc);
	private static void emit_save(GLib.Object obj, Geany.Document geany_doc, Peasy.Signals sig)
	{
		sig.document_save(new Document(geany_doc));
	}

	public signal void document_close(Document doc);
	private static void emit_close(GLib.Object obj, Geany.Document geany_doc, Peasy.Signals sig)
	{
		sig.document_close(new Document(geany_doc));
	}

	public signal void document_filetype_set(Document doc, Filetype? old_ft);
	private static void emit_filetype_set(GLib.Object obj, Geany.Document geany_doc, Geany.Filetype? ft, Peasy.Signals sig)
	{
		/* can signal with ft == null, e.g. during Geany.Document.new_file() */
		Peasy.Filetype ft_ = ft != null ? Filetype.get_by_id(ft.id) : null;
		sig.document_filetype_set(new Document(geany_doc), ft_);
	}

	protected Signals()
	{
		signal_connect(null, "document-new", false,
			(GLib.Callback) Peasy.Signals.emit_new, this);
		signal_connect(null, "document-open", false,
			(GLib.Callback) Peasy.Signals.emit_open, this);
		signal_connect(null, "document-activate", false,
			(GLib.Callback) Peasy.Signals.emit_activate, this);
		signal_connect(null, "document-reload", false,
			(GLib.Callback) Peasy.Signals.emit_reload, this);
		signal_connect(null, "document-before-save", false,
			(GLib.Callback) Peasy.Signals.emit_before_save, this);
		signal_connect(null, "document-save", false,
			(GLib.Callback) Peasy.Signals.emit_save, this);
		signal_connect(null, "document-close", false,
			(GLib.Callback) Peasy.Signals.emit_close, this);
		signal_connect(null, "document-filetype-set", false,
			(GLib.Callback) Peasy.Signals.emit_filetype_set, this);
	}
}

}
