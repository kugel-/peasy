
namespace Peasy
{
	[Compact]
	public class Highlighting
	{

		public static bool is_string_style(int lexer, int style)
		{
			return Geany.Highlighting.is_string_style(lexer, style);
		}

		public static bool is_comment_style(int lexer, int style)
		{
			return Geany.Highlighting.is_comment_style(lexer, style);
		}

		public static bool is_code_style(int lexer, int style)
		{
			return Geany.Highlighting.is_code_style(lexer, style);
		}

#if 0
		public static void apply_filetype_styles(Filetype ft, Scintilla.Object sci)
		{
			Geany.Highlighting.set_styles(sci, ft._ft);
		}
#endif

		public static Geany.LexerStyle get_lexer_style(Filetype ft, int style)
		{
			Geany.LexerStyle? ret = Geany.Highlighting.get_style(ft._ft.id, style);
			return (Geany.LexerStyle) ret;
		}

		/* No objects allowed */
		private Highlighting() {}
	}
}
