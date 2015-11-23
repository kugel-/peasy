using GLib;

namespace Peasy
{
	public class Filetype : Peasy.Object
	{
		/* properties */
		public int        id           { get { return _ft.id; } }
		public string     extension    { get { return _ft.extension; } }
		public string     name         { get { return _ft.name; } }
		public string     title        { get { return _ft.title; } }
		public string     display_name { get { return _ft._get_display_name(); } }
		public string?    mime_type    { get { return _ft.mime_type; } }
		public GLib.Icon? icon         { get { return _ft.icon; } }


		public static GenericArray<Filetype> all_filetypes()
		{
			GenericArray<Filetype> fts = new GenericArray<Filetype>();
			geany_plugin.geany_data.filetypes_array.foreach((ft) => {
				fts.add(new Filetype(ft));
			});
			return fts;
		}

		/* constructors */
		internal Filetype(Geany.Filetype ft)
		{
			_ft = ft;
		}

		/* filetypes are pre-allocated by geany */
		public static Filetype? get_by_id (Geany.FiletypeID id)
		{
			unowned Geany.Filetype? ft = Geany.Filetype.index(id);
			if (ft == null)
				return null;

			return new Filetype(ft);
		}

		public static Filetype? get_by_name (string name)
		{
			unowned Geany.Filetype? ft = Geany.Filetype.lookup_by_name(name);
			if (ft == null)
				return null;

			return new Filetype(ft);
		}

		public static Filetype detect_from_file(string filename)
		{
			return new Filetype(Geany.Filetype.lookup_by_name(filename));
		}

		/* internal fields
		 * must be last due to bug in vala's gir generation */

		/* this is the actual GeanyFiletype instance */
		internal unowned Geany.Filetype _ft;
	}
}
