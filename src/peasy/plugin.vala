namespace Peasy
{

public interface PluginConfigure
{
	public abstract Gtk.Widget configure(Gtk.Dialog parent);
}

public interface PluginHelp
{
	public abstract void help();
}


public abstract class Plugin: Object, PluginIface
{
	public abstract bool enable();
	public abstract void disable();

	public unowned Geany.Plugin geany_plugin { construct set; public get; }
	public Data                 data = Data.instance();

	private Plugin()
	{
	}

	public KeyGroup add_key_group(string section_name, size_t count)
	{
		unowned Geany.KeyGroup kb_group = geany_plugin.set_key_group_full(section_name, count, null);
		GLib.return_val_if_fail(kb_group != null, null);
		return new KeyGroup.from_geany(kb_group);
	}

	public Project? get_project()
	{
		if (peasy_plugin.geany_data.app.project != null)
			return new Project.from_geany(peasy_plugin.geany_data.app.project);

		return null;
	}
}

public interface PluginIface: GLib.Object
{
	public abstract unowned Geany.Plugin geany_plugin { construct set; public get; }
}

}
