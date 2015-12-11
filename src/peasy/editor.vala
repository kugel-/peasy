using Geany;

namespace Peasy
{
	public enum IndentType
	{
		TABS = Geany.IndentType.TABS,
		SPACES = Geany.IndentType.SPACES,
		BOTH = Geany.IndentType.BOTH,
	}

	public enum AutoIndent
	{
		NONE = Geany.AutoIndent.NONE,
		BASIC = Geany.AutoIndent.BASIC,
		CURRENTCHARS = Geany.AutoIndent.CURRENTCHARS,
		MATCHBRACES = Geany.AutoIndent.MATCHBRACES,
	}

	public enum Indicator
	{
		ERROR = Geany.Indicator.ERROR,
		SEARCH = Geany.Indicator.SEARCH,
	}

	public class Editor : GLib.Object
	{
		/* weak reference to avoid cyclic reference */
		public weak Document   document;
		public GeanyScintilla.ScintillaObject sci;

		/* Properties */
		public bool line_wrapping {
			get { return _editor.line_wrapping; }
#if 0
			set { _editor.set_line_wrapping(value); }
#endif
		}

		public bool auto_indent {
			get { return _editor.auto_indent; }
			/* no setter defined */
		}
		public IndentType indent_type {
			get { return (IndentType)(int)_editor.indent_type; }
			set { _editor.set_indent_type((Geany.IndentType)(int)value); }
		}

		public bool line_breaking {
			get { return _editor.line_breaking; }
			/* editor_set_line_wrapping() is not in the plugin api */
		}

		public int indent_width {
			get { return _editor.indent_width; }
			set { _editor.set_indent_width(value); }
		}

		/* This constructor is specifically for GeanyGI.Document, analogous to editor_create() */
		internal Editor.create(Peasy.Document doc)
		{
			_editor = doc._doc.editor;
			document = doc;
			sci = _editor.sci;
		}

		public string? get_word_at(int pos, string? wordchars = null)
		{
			return _editor.get_word_at_pos(pos, wordchars);
		}

		public bool goto(int pos, bool mark = false)
		{
			return _editor.goto_pos(pos, mark);
		}

		public void indicator_clear(Geany.Indicator indic)
		{
			_editor.indicator_clear(indic);
		}
		public void indicator_set_on_line(Geany.Indicator indic, int line)
		{
			_editor.indicator_set_on_line(indic, line);
		}
		public void indicator_set_on_range(Geany.Indicator indic, int start, int end)
		{
			_editor.indicator_set_on_range(indic, start, end);
		}

		/* internal fields
		 * must be last due to bug in vala's gir generation */

		/* this is the actual GeanyEditor instance */
		internal unowned Geany.Editor _editor;
	}
}
