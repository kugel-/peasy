using Geany;

namespace Peasy
{
	public class Document : Peasy.Object
	{
		/* fields */
		public         Editor  editor;

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

		public bool   is_valid      { get { if (_doc == null) return false; return _doc.is_valid; } }
		public bool   has_bom       { get { GLib.return_val_if_fail(_doc != null, false); return _doc.has_bom; } }
		public bool   has_tags      { get { GLib.return_val_if_fail(_doc != null, false); return _doc.has_tags; } }
		public uint   id            { get { GLib.return_val_if_fail(_doc != null, 0); return _doc.id; } }
		public string display_name  { owned get { GLib.return_val_if_fail(_doc != null, null); return _doc.get_basename_for_display(-1); } }
#if 0
		public Scintilla.Object sci { get { return _doc.editor.sci; }}
#endif
		/* signals */
		public signal void closing();
		public signal void reloaded();
		public signal void activate();
		public signal void before_save();
		public signal void saved();
		public signal void filetype_set(Filetype? old_ft);

		/* constructors */
		construct
		{
			plugin_signals.document_close.connect((doc) => { if (doc._doc == this._doc) this.closing(); });
			plugin_signals.document_reload.connect((doc) => { if (doc._doc == this._doc) this.reloaded(); });
			plugin_signals.document_activate.connect((doc) => { if (doc._doc == this._doc) this.activate(); });
			plugin_signals.document_before_save.connect((doc) => { if (doc._doc == this._doc) this.before_save(); });
			plugin_signals.document_save.connect((doc) => { if (doc._doc == this._doc) this.saved(); });
			plugin_signals.document_filetype_set.connect((doc, ft) => { if (doc._doc == this._doc) this.filetype_set(ft); });
		}

		internal Document(Geany.Document doc)
		{
			_doc = doc;
			editor = new Peasy.Editor.create(this);
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
		}
		public Document.from_file(string locale_filename, bool readonly = false,
								  Filetype? ft = null, string? forced_enc = null)
		{
			unowned Geany.Filetype? gft = null;
			if (ft != null)
				gft = ft._ft;
			_doc = Geany.Document.open_file(locale_filename, readonly, gft, forced_enc);
			editor = new Peasy.Editor.create(this);
		}

		public static Document? get_current()
		{
			return new Document(Geany.Document.get_current());
		}

		/* destructor */
		~Document()
		{
		}

		public bool close()
		{
			/* on shutdown it might be closed before the plugin can close it in the cleanup method */
			if (! is_valid)
				return true;
			return _doc.close();
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

		/* internal fields
		 * must be last due to bug in vala's gir generation */

		/* this is the actual GeanyDocument instance */
		internal unowned Geany.Document? _doc;
	}
}
