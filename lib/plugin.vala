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

    public unowned Geany.Plugin geany_plugin;

    private Plugin()
    {
    }

    public KeyGroup add_key_group(string section_name, size_t count)
    {
        unowned Geany.KeyGroup kb_group = geany_plugin.set_key_group_full(section_name, count, null);
        GLib.return_val_if_fail(kb_group != null, null);
        return new KeyGroup.from_geany(kb_group);
    }
}

public interface PluginIface: GLib.Object
{
}

}
