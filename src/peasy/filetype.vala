using GLib;

namespace Peasy
{
	public class Filetype : Peasy.Object
	{
		/* this is the actual GeanyFiletype instance */
		internal unowned Geany.Filetype geany_ft;

		/* properties */
		public static GenericArray<Filetype> all_filetypes()
		{
			GenericArray<Filetype> fts = new GenericArray<Filetype>();
			peasy_plugin.geany_data.filetypes_array.foreach((ft) => {
				fts.add(new Filetype(ft));
			});
			return fts;
		}

		/* constructors */
		internal Filetype(Geany.Filetype ft)
		{
			geany_ft = ft;
		}
	}
}
