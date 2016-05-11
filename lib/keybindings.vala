using Geany;
using Geany.Keybindings;

namespace GeanyGI
{
    public delegate bool KeyGroupHandler(KeyGroup group, uint key_id);
    public delegate bool KeyHandler(KeyBinding key, uint key_id);

    public class KeyGroup : GLib.Object
    {
        /* Fields */
        private unowned Geany.KeyGroup _group;
        private GLib.List<KeyBinding> m_keys;
        private KeyGroupHandler m_cb;

        /* Properties */
        public string label { get; private set; }
        public string name  { get; private set; }

        public KeyGroup(string name, string label, int key_count, owned KeyGroupHandler? cb = null)
        {
            this.name = name;
            this.label = label;
            if (cb != null)
            {
                m_cb = (owned) cb;
                _group = Geany.Keybindings.set_group_with_handler(null, this.name, this.label, key_count,
                        (_g, _kid) => { return m_cb(this, _kid); });
            }
            else
                _group = Geany.Keybindings.set_group_with_handler(null, this.name, this.label, key_count, null);
        }

        ~KeyGroup()
        {
            _group.free_group();
            _group = null;
        }

        public void add_keybinding(KeyBinding key, int key_id)
        {
            /* may be null for group handler */
            unowned Geany.KeyHandler cb = null;
            /* do not use a lambda here, this way we can register an instance method of KeyBinding
             * from this place */
            if (key.m_cb != null)
                cb = key.cb_wrapper;
            /* NOTE: This is prone for cyclic references:
             * We grab a ref to the KeyBinding instance here, while the plugin probably has a ref
             * to this KeyGroup instance. Now, if the plugin passes an instance method to the 
             * KeyBinding, the KeyBinding gets a ref to the plugin, and the circle is perfect.
             * The solution is either not to pass an instance method or manually unref in the
             * plugin's cleanup method. */
            key._key = _group.add_item_with_handler(key_id, cb,
                       0, 0, key.m_name, key.m_label, null);
            m_keys.append(key);
        }
    }

    /* FIXME: This should ideally be GLib.InitiallyUnowned instead, because it's meant to be
     * added with KeyGroup.add_keybinding(), but this isn't properly handled by valac yet
     * (_sink() immediately after object allocation, and normal _ref() before GList<>.append) */
    public class KeyBinding : GLib.Object
    {
        internal unowned Geany.KeyBinding _key;
        internal string                   m_name;
        internal string                   m_label;
        internal KeyHandler               m_cb;

        internal bool cb_wrapper(Geany.KeyBinding key, uint key_id)
        {
            return m_cb(this, key_id);
        }

        public KeyBinding(string name, string label, owned KeyHandler? cb = null)
        {
            m_name = name;
            m_label = label;
            if (cb != null)
                m_cb = (owned) cb;
        }
    }
}
