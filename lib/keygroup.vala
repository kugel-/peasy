using Geany;

namespace Peasy
{

public class KeyBinding : GLib.Object
{
	public unowned Geany.KeyBinding geany_binding;
	/* defined in C due to use of accumulator
	 *  public signal bool activate(int id); */
	private KeyGroup m_group;

	/* virtual so that a pointer in the class structure is emitted, C code uses that
	 * as default signal handler for activate */
	public virtual bool default_handler(int id)
	{
		/* By returning false the KeyGroup's handler will be invoked (if we even get to here) */
		return false;
	}

	private bool geany_handler(Geany.KeyBinding item, uint id)
	{
		bool ret = false;
		GLib.Signal.emit_by_name(this, "activate", id, &ret);
		/* Geany won't execute the group callback since a item callback is attached, evne if
		 * taht returns FALSE. */
		if (!ret)
			GLib.Signal.emit_by_name(this.m_group, "activate", id, &ret);
		return ret;
	}

	internal KeyBinding(KeyGroup kb_group, int index, int def_key, Gdk.ModifierType def_mod,
	                    string name, string label, Gtk.MenuItem? menu_item)
	{
		geany_binding =
			Geany.keybindings_set_item_full(kb_group.geany_group, index, def_key, def_mod, name,
			label, menu_item, this.geany_handler);
		m_group = kb_group;
	}

	internal KeyBinding.from_geany(KeyGroup kb_group, Geany.KeyBinding kb_item)
	{
		geany_binding = kb_item;
		m_group = kb_group;
	}

	extern static void setup_signal_activate();
	static construct
	{
		setup_signal_activate();
	}
}

public class KeyGroup : GLib.Object
{
	public unowned Geany.KeyGroup geany_group;
	/* defined in C code due to use of accumulator
	 * public signal bool activate(int id); */
	private int index;
	GLib.List<weak KeyBinding> m_items;

	/* virtual so that a pointer in the class structure is emitted, C code uses that
	 * as default signal handler for activate */
	public virtual bool default_handler(int id)
	{
		/* By returning false Geany's will eventually run gtk accelerators, if any */
		return false;
	}

	internal KeyGroup.from_geany(Geany.KeyGroup kb_group)
	{
		geany_group = kb_group;
		index = 0;
	}

	public KeyBinding? add_keybinding(string name, string label, Gtk.MenuItem? menu_item,
	                                  int def_key, Gdk.ModifierType def_mod)
	{
		KeyBinding item = new KeyBinding(this, index, def_key, def_mod, name, label, menu_item);
		index += 1;
		m_items.append(item);
		return item;
	}

	public KeyBinding? add_keybinding_with_id(string name, string label, Gtk.MenuItem? menu_item,
	                                          int def_key, Gdk.ModifierType def_mod, int id)
	{
		return new KeyBinding(this, id, def_key, def_mod, name, label, menu_item);
	}

	public KeyBinding get_item(int id)
	{
		unowned Geany.KeyBinding item = Geany.keybindings_get_item(geany_group, id);
		GLib.return_val_if_fail(item != null, null);
		return new KeyBinding.from_geany(this, item);
	}

	extern static void setup_signal_activate();
	static construct
	{
		setup_signal_activate();
	}
}

}
