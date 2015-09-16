
extern void plugin_signal_connect(ref Geany.Plugin p, GLib.Object? obj, string signal_name,
						  bool after, GLib.Callback cb, void *data);

namespace Peasy
{
public class Object : GLib.Object
{
	protected static unowned Geany.Plugin? peasy_plugin;
	protected static void signal_connect(GLib.Object? obj, string signal_name,
								  bool after, GLib.Callback cb, void *data)
	{
		plugin_signal_connect(ref peasy_plugin, obj, signal_name, after, cb, data);
	}
}
}
