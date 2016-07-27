namespace Peasy
{

/* defined in C because we can't access LOCALEDIR in vala code (can we?) */
public extern unowned string get_locale_dir();
public extern unowned string gettext(string msgid);

/* GEANY_API_VERSION is not in the .vapi :( */
private extern bool do_check_abi(int abi);

/* instantiated in Peasy.static_init() */
protected GLib.HashTable<string, int> native_abis;

/**
 * Function that native plugins must call in their peas_register_types().
 *
 * @param mod The ObjectModule passed to peas_register_types() by libpeas
 * @param abi_ver The ABI version the plugin was compiled against,
 *                 simple pass GEANY_API_VERSION.
 *
 * @return true if the ABI check has passed, false otherwise. Do not
 *          proceed calling peas_object_module_register_extension_type()
 *          on false.
 */
public bool check_abi(Peas.ObjectModule mod, int abi_ver)
{
    if (!do_check_abi(abi_ver))
    {
        native_abis.replace(mod.module_name.dup(), abi_ver);
        return false;
    }

    return true;
}

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
