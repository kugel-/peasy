using Geany;

namespace Peasy
{
	public class Document : Peasy.Object
	{
		/* fields */
		private        bool    owns_doc;
		public         Editor  editor;
		/* there is no proper introsepection for static fields, workaround with singleton */
		private static Signals signals_;

		public static Signals signals()
		{
			return signals_;
		}

		public static GenericArray<Document> all_documents()
		{
			GenericArray<Document> docs = new GenericArray<Document>();
			peasy_plugin.geany_data.documents_array.foreach((doc) => {
				if (doc.is_valid)
					docs.add(new Document(doc));
			});
			return docs;
		}
#if 0
		/* properties */
		public bool is_readonly
		{
			get
			{
				return _doc.readonly;
			}
			set
			{
				_doc.editor.sci.send_message(Scintilla.SCI_SETREADONLY, value?1:0, 0);
				_doc.readonly = value;
			}
		}
#endif

		public bool changed
		{
			get { GLib.return_val_if_fail(_doc != null, false); return _doc.changed; }
			set { _doc.set_text_changed(value); }
		}

		public string encoding
		{
			get { GLib.return_val_if_fail(_doc != null, ""); return _doc.encoding; }
			set { _doc.set_encoding(value); }
		}

		public bool   is_valid      { get { if (_doc != null) return false; return _doc.is_valid; } }
		public bool   has_bom       { get { GLib.return_val_if_fail(_doc != null, false); return _doc.has_bom; } }
		public bool   has_tags      { get { GLib.return_val_if_fail(_doc != null, false); return _doc.has_tags; } }
		public uint   id            { get { GLib.return_val_if_fail(_doc != null, 0); return _doc.id; } }
		public string display_name  { owned get { GLib.return_val_if_fail(_doc != null, null); return _doc.get_basename_for_display(-1); } }
#if 0
		public Scintilla.Object sci { get { return _doc.editor.sci; }}
#endif
		/* signals */
		public signal void closed();
		public signal void reloaded();
		public signal void activate();
		public signal void before_save();
		public signal void saved();
		public signal void filetype_set(Filetype? old_ft);

		private static void emit_closed(GLib.Object obj, Geany.Document* geany_doc, Peasy.Document doc)
		{
			if ((Geany.Document*)doc._doc == geany_doc)
				doc.closed();
		}

		private static void emit_reloaded(GLib.Object obj, Geany.Document* geany_doc, Peasy.Document doc)
		{
			if ((Geany.Document*)doc._doc == geany_doc)
				doc.reloaded();
		}

		private static void emit_activate(GLib.Object obj, Geany.Document *geany_doc, Peasy.Document doc)
		{
			if ((Geany.Document*)doc._doc == geany_doc)
				doc.activate();
		}

		private static void emit_before_save(GLib.Object obj, Geany.Document *geany_doc, Peasy.Document doc)
		{
			if ((Geany.Document*)doc._doc == geany_doc)
				doc.before_save();
		}

		private static void emit_saved(GLib.Object obj, Geany.Document *geany_doc, Peasy.Document doc)
		{
			if ((Geany.Document*)doc._doc == geany_doc)
				doc.saved();
		}

		private static void emit_filetype_set(GLib.Object obj, Geany.Document *geany_doc, Geany.Filetype? ft, Peasy.Document doc)
		{
			if ((Geany.Document*)doc._doc == geany_doc)
			{
				/* can signal with ft == null, e.g. during Geany.Document.new_file() */
				Peasy.Filetype gi_ft = ft != null ? Filetype.get_by_id(ft.id) : null;
				doc.filetype_set(gi_ft);
			}
		}

		/* constructors */
		construct
		{
			signal_connect(null, "document-close", true,
				(GLib.Callback) Peasy.Document.emit_closed, this);
			signal_connect(null, "document-reload", true,
				(GLib.Callback) Peasy.Document.emit_reloaded, this);
			signal_connect(null, "document-activate", true,
				(GLib.Callback) Peasy.Document.emit_activate, this);
			signal_connect(null, "document-before-save", true,
				(GLib.Callback) Peasy.Document.emit_before_save, this);
			signal_connect(null, "document-save", true,
				(GLib.Callback) Peasy.Document.emit_saved, this);
			signal_connect(null, "document-filetype-set", true,
				(GLib.Callback) Peasy.Document.emit_filetype_set, this);
		}

		static construct
		{
			signals_ = new Signals();
		}

		internal Document(Geany.Document doc)
		{
			_doc = doc;
			editor = new Peasy.Editor.create(this);
			/* this only gets the reference to the current doc, must not close on
			 * destruction (note that GeanyDocument is not reference counted) */
			owns_doc = false;
		}

		public Document.new_file(string? utf8_filename = null,
								 Peasy.Filetype? ft = null,
								 string? text = null)
		{
			unowned Geany.Filetype? gft = null;
			if (ft != null)
				gft = ft._ft;
			_doc = Geany.Document.new_file(utf8_filename, gft, text);
			editor = new Peasy.Editor.create(this);
			owns_doc = true;
		}
		public Document.from_file(string locale_filename, bool readonly = false,
								  Filetype? ft = null, string? forced_enc = null)
		{
			unowned Geany.Filetype? gft = null;
			if (ft != null)
				gft = ft._ft;
			_doc = Geany.Document.open_file(locale_filename, readonly, gft, forced_enc);
			editor = new Peasy.Editor.create(this);
			owns_doc = true;
		}

		public static Document? get_current()
		{
			return new Document(Geany.Document.get_current());
		}

		/* destructor */
		~Document()
		{
			if (owns_doc)
			{
				if (!close())
				{
					/* force close if user didnt save */
					changed = false;
					close();
				}
			}
		}

		public bool close()
		{
			/* on shutdown it might be closed before the plugin can close it in the cleanup method */
			if (! is_valid)
				return true;
			owns_doc = !_doc.close();
			_doc = null;
			return !owns_doc;
		}

		public bool save(bool force = false)
		{
			GLib.return_val_if_fail(_doc != null, false);
			return _doc.save_file(force);
		}

		public bool save_as(string? file_name = null)
		{
			GLib.return_val_if_fail(_doc != null, false);
			return _doc.save_file_as(file_name);
		}

		public bool reload(string? forced_enc = null)
		{
			GLib.return_val_if_fail(_doc != null, false);
			return _doc.reload_force(forced_enc);
		}

		/* just wraps Geany.object signals */
		public class Signals : GLib.Object
		{
			public signal void create(Document doc);
			private static void emit_create(GLib.Object obj, Geany.Document geany_doc, Peasy.Document.Signals sig)
			{
				sig.create(new Document(geany_doc));
			}

			public signal void open(Document doc);
			private static void emit_open(GLib.Object obj, Geany.Document geany_doc, Peasy.Document.Signals sig)
			{
				sig.open(new Document(geany_doc));
			}

			public signal void activate(Document doc);
			private static void emit_activate(GLib.Object obj, Geany.Document geany_doc, Peasy.Document.Signals sig)
			{
				sig.activate(new Document(geany_doc));
			}

			public signal void reloaded(Document doc);
			private static void emit_reloaded(GLib.Object obj, Geany.Document geany_doc, Peasy.Document.Signals sig)
			{
				sig.reloaded(new Document(geany_doc));
			}

			public signal void before_save(Document doc);
			private static void emit_before_save(GLib.Object obj, Geany.Document geany_doc, Peasy.Document.Signals sig)
			{
				sig.before_save(new Document(geany_doc));
			}

			public signal void saved(Document doc);
			private static void emit_saved(GLib.Object obj, Geany.Document geany_doc, Peasy.Document.Signals sig)
			{
				sig.saved(new Document(geany_doc));
			}

			public signal void close(Document doc);
			private static void emit_close(GLib.Object obj, Geany.Document geany_doc, Peasy.Document.Signals sig)
			{
				sig.close(new Document(geany_doc));
			}

			public signal void filetype_set(Document doc, Filetype? old_ft);
			private static void emit_filetype_set(GLib.Object obj, Geany.Document geany_doc, Geany.Filetype? ft, Peasy.Document.Signals sig)
			{
				/* can signal with ft == null, e.g. during Geany.Document.new_file() */
				Peasy.Filetype ft_ = ft != null ? Filetype.get_by_id(ft.id) : null;
				sig.filetype_set(new Document(geany_doc), ft_);
			}

			construct
			{
				signal_connect(null, "document-new", true,
					(GLib.Callback) Peasy.Document.Signals.emit_create, this);
				signal_connect(null, "document-open", true,
					(GLib.Callback) Peasy.Document.Signals.emit_open, this);
				signal_connect(null, "document-activate", true,
					(GLib.Callback) Peasy.Document.Signals.emit_activate, this);
				signal_connect(null, "document-reload", true,
					(GLib.Callback) Peasy.Document.Signals.emit_reloaded, this);
				signal_connect(null, "document-before-save", true,
					(GLib.Callback) Peasy.Document.Signals.emit_before_save, this);
				signal_connect(null, "document-save", true,
					(GLib.Callback) Peasy.Document.Signals.emit_saved, this);
				signal_connect(null, "document-close", true,
					(GLib.Callback) Peasy.Document.Signals.emit_close, this);
				signal_connect(null, "document-filetype-set", true,
					(GLib.Callback) Peasy.Document.Signals.emit_filetype_set, this);
			}
		}

		/* internal fields
		 * must be last due to bug in vala's gir generation */

		/* this is the actual GeanyDocument instance */
		internal unowned Geany.Document? _doc;
	}
}
