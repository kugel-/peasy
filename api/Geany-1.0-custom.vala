
namespace Geany {
	[CCode (cheader_filename = "geanyplugin.h")]
	public delegate bool init(Plugin p, void *pdata);
	[CCode (cheader_filename = "geanyplugin.h")]
	public delegate void cleanup(Plugin p, void *pdata);
	[CCode (cheader_filename = "geanyplugin.h")]
	public delegate void help(Plugin p, void *pdata);
	[CCode (cheader_filename = "geanyplugin.h")]
	public delegate Gtk.Widget configure(Plugin p, Gtk.Dialog parent, void *pdata);
	[CCode (cheader_filename = "geanyplugin.h")]
	public delegate int probe(Plugin proxy, string filename, void *pdata);
	[CCode (cheader_filename = "geanyplugin.h")]
	public delegate void load(Plugin proxy, Plugin inferior, void **proxy_data, void *pdata);
	[CCode (cheader_filename = "geanyplugin.h")]
	public delegate void unload(Plugin proxy, Plugin inferior, void *proxy_data, void *pdata);
}
