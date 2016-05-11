using Geany;

namespace Peasy
{
    public enum IndentType
    {
        TABS = Geany.IndentType.TABS,
        SPACES = Geany.IndentType.SPACES,
        BOTH = Geany.IndentType.BOTH,
    }

    public class Editor : GLib.Object
    {
        /* this is the actual GeanyEditor instance */
        public unowned Geany.Editor geany_editor;
        /* weak reference to avoid cyclic reference */
        public GeanyScintilla.ScintillaObject sci;

        /* Properties */
        public IndentType indent_type {
            get { return (IndentType)(int)geany_editor.get_indent_prefs().type; }
            set { geany_editor.set_indent_type((Geany.IndentType)(int)value); }
        }

        public int indent_width {
            get { return geany_editor.get_indent_prefs().width; }
            set { geany_editor.set_indent_width(value); }
        }

        /* This constructor is specifically for Peasy.Document, analogous to editor_create() */
        internal Editor.create(Document doc)
        {
            geany_editor = doc.geany_doc.editor;
            sci = geany_editor.sci;
        }

        public string? get_word_at(int pos, string? wordchars = null)
        {
            return geany_editor.get_word_at_pos(pos, wordchars);
        }

        public bool goto(int pos, bool mark = false)
        {
            return geany_editor.goto_pos(pos, mark);
        }
    }
}
