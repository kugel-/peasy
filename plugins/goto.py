import os
import gi
import warnings

gi.require_version('Peas', '1.0')

from gi.repository import Geany
from gi.repository import Peasy
from gi.repository import Gtk
from gi.repository import Peas

# http://stackoverflow.com/a/2894073
def long_substr(data):
    substr = ''
    if len(data) > 1 and len(data[0]) > 0:
        for i in range(len(data[0])):
            for j in range(len(data[0])-i+1):
                if j > len(substr) and all(data[0][i:i+j] in x for x in data):
                    substr = data[0][i:i+j]
    return substr


def get_prefix_and_substring(paths):
    prefix = os.path.commonprefix(paths)
    if not (prefix.endswith("/")):
        prefix = os.path.join("/", *(prefix.split("/")[:-1])) + "/"
    substr = long_substr([path[len(prefix):] for path in paths])
    if not (substr.endswith("/")):
        substr = os.path.join(*(substr.split("/")[:-1]))
    else:
        # remove trailing /
        substr = substr[:-1]
    return (prefix, substr)

class GotoPlugin(Peasy.Plugin):
    __gtype_name__ = 'GotoPlugin'

    def pos_func(self, *args):
        alloc = args[3].get_allocation()
        win = args[3].get_window()
        tmp, x, y = win.get_origin()
        return (alloc.x + x, alloc.y + y, True)

    def get_doc_label(self, doc):
        s = doc.file_name[len(self.prefix):]
        if (len(self.substr) > 2):
            return s.replace(self.substr, u"…")
        return s

    def show_docs(self, docs, widget):
        # sort to give stable list (documents_array isn't sorted)
        docs = sorted(docs, key=lambda doc: doc.display_name())
        # trivial case: only one doc to show. switch immediately
        if (len(docs) == 1):
            docs[0].show_tab()
            self.dlg.close()
        else:
            docs_fn = [doc.display_name() for doc in docs]
            if (len(docs_fn) == len(set(docs_fn))):
                # simple case: multiple docs but unique display names
                label_fn = lambda doc: doc.display_name()
            else:
                # complex case: multiple docs with, some of which have the same
                # display name. show parts of the path to distinguish
                # strategy is to hide the common prefix of each doc ellipsize
                # the longest common paths components
                self.prefix, self.substr = get_prefix_and_substring([d.file_name for d in docs])
                label_fn = lambda doc: self.get_doc_label(doc)
            m = Gtk.Menu.new()
            def add_doc(doc):
                w = Gtk.ImageMenuItem.new_with_label(label_fn(doc))
                w.set_image(Gtk.Image.new_from_gicon(doc.file_type.icon, Gtk.IconSize.MENU))
                w.connect("activate", lambda item, doc: doc.show_tab(), doc)
                m.append(w)
                return w
            # always select the first item for better keyboard navigation
            w = add_doc(docs[0])
            m.connect("realize", lambda menu: menu.select_item(w))
            for d in docs[1:]:
                add_doc(d)
            w.set_image(Gtk.Image.new_from_gicon(docs[0].file_type.icon, Gtk.IconSize.MENU))
            m.show_all()
            m.popup(None, None, self.pos_func, widget, 0, Gtk.get_current_event_time());
            m.connect("destroy", lambda w: self.dlg.close())

    def on_def_activate(self, entry):
        print("hello")
        tags = Geany.tm_workspace_find(entry.get_text(), None, Geany.TMTagType.MAX_T, Geany.TMTagAttrType.NONE_T, Geany.TMParserType.C)
        self.dlg.close()

    def on_decl_activate(self, entry):
        pass

    def on_file_activate(self, entry):
        docs = []
        for doc in self.geany_plugin.geany_data.documents_array:
            if (doc.display_name().startswith(entry.get_text())):
                docs.append(doc)
        self.show_docs(docs, entry)

    def do_enable(self):
        # Gtk.Menu.popup does not work on Gtk2, hence Gtk3 only for now
        if (gi.repository.Gtk.check_version(3, 0, 0) is not None):
            warnings.warn("Gtk 2 is not supported by this plugin", RuntimeWarning)
            return False

        self.item = Geany.ui_image_menu_item_new(Gtk.STOCK_EXECUTE, "Goto ...")
        self.item.connect("activate", self.on_item_click)
        self.geany_plugin.geany_data.main_widgets.tools_menu.append(self.item)
        self.ui = Gtk.Builder.new_from_file(os.path.join(self.plugin_info.get_module_dir(), "goto", "goto.glade"))
        self.dlg = self.ui.get_object("window")
        self.dlg.set_transient_for(self.geany_plugin.geany_data.main_widgets.window)
        self.item.show_all();
        self.ui.get_object("txt_def").connect("activate", self.on_def_activate)
        self.ui.get_object("txt_decl").connect("activate", self.on_decl_activate)
        self.ui.get_object("txt_file").connect("activate", self.on_file_activate)

        self.keys = self.add_key_group("quicktabswitch", 3)
        self.keys.add_keybinding("switch_by_file", "Switch by file",
                self.item, 0, 0)
        self.keys.add_keybinding("switch_by_def", "Switch by symbol definition",
                None, 0, 0).connect("activate", lambda key, id: self.on_item_click(self.item, id))
        self.keys.add_keybinding("switch_by_decl", "Switch by symbol declaration",
                None, 0, 0).connect("activate", lambda key, id: self.on_item_click(self.item, id))
        return True

    def do_disable(self):
        self.dlg.destroy()
        self.item.destroy()

    def on_item_click(self, item, focus_ = 0):
        focus = self.ui.get_object(("txt_file", "txt_def", "txt_decl")[focus_])
        print(repr(focus))
        self.dlg.connect_after("show", lambda dlg: dlg.set_focus(focus))
        self.dlg.run()
        self.dlg.hide()
        return True
