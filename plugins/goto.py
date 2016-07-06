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
    if (substr.find("/") != -1):
        if not (substr.endswith("/")):
            substr = os.path.join(*(substr.split("/")[:-1]))
        else:
            # remove trailing /
            substr = substr[:-1]
    else:
        substr = ""
    return (prefix, substr)


# based on Geany's symbols.c
def get_icon_name(tag):
    t = tag.type
    if (t in (Geany.TMTagType.PROTOTYPE_T,
                Geany.TMTagType.METHOD_T,
                Geany.TMTagType.FUNCTION_T)):
        return "classviewer-method"
    elif (t in (Geany.TMTagType.VARIABLE_T, Geany.TMTagType.EXTERNVAR_T)):
        return "classviewer-var"
    elif (t in  (Geany.TMTagType.MACRO_T, Geany.TMTagType.MACRO_WITH_ARG_T)):
        return "classviewer-macro"
    elif (t == Geany.TMTagType.CLASS_T):
        return "classviewer-class"
    elif (t in (Geany.TMTagType.MEMBER_T, Geany.TMTagType.FIELD_T)):
        return "classviewer-member"
    elif (t in (Geany.TMTagType.TYPEDEF_T,
                Geany.TMTagType.ENUM_T,
                Geany.TMTagType.UNION_T,
                Geany.TMTagType.STRUCT_T)):
        return "classviewer-struct"
    elif (t in (Geany.TMTagType.NAMESPACE_T, Geany.TMTagType.PACKAGE_T)):
        return "classviewer-namespace";
    else:
        return "classviewer-other"

class GotoPlugin(Peasy.Plugin):
    __gtype_name__ = 'GotoPlugin'

    def pos_func(self, *args):
        alloc = args[3].get_allocation()
        win = args[3].get_window()
        tmp, x, y = win.get_origin()
        return (alloc.x + x, alloc.y + y, True)

    def get_doc_label(self, doc):
        tag = doc.get("tag")
        s = doc["doc"].file_name[len(self.prefix):]
        if (len(self.substr) > 2):
            return s.replace(self.substr, u"…")

        if (tag is not None):
            s = "%s @%s:%d" % (tag.name, s, tag.line)

        return s

    def switch_doc(self, doc):
        tag = doc.get("tag")
        if (tag is not None):
            line = tag.line
        else:
            line = doc["doc"].editor.sci.get_current_line() + 1
        Geany.navqueue_goto_line(Geany.Document.get_current(), doc["doc"], line)

    def show_docs(self, docs, widget):
        # sort to give stable list (documents_array isn't sorted)
        docs = sorted(docs, key=lambda doc: doc["doc"].display_name())
        # trivial case: only one doc to show. switch immediately
        if (len(docs) == 1):
            self.switch_doc(docs[0])
            self.dlg.close()
        elif (len(docs) > 1):
            docs_fn = [doc["doc"].display_name() for doc in docs]
            if (len(docs_fn) == len(set(docs_fn))):
                # simple case: multiple docs but unique display names
                def get_label(doc):
                    try:
                        return "%s @%s:%d" % (doc["tag"].name, doc["doc"].display_name(), doc["tag"].line)
                    except:
                        return doc["doc"].display_name()
                label_fn = get_label
            else:
                # complex case: multiple docs with, some of which have the same
                # display name. show parts of the path to distinguish
                # strategy is to hide the common prefix of each doc ellipsize
                # the longest common paths components
                self.prefix, self.substr = get_prefix_and_substring([d["doc"].file_name for d in docs])
                label_fn = lambda doc: self.get_doc_label(doc)
            m = Gtk.Menu.new()
            def add_doc(doc):
                w = Gtk.ImageMenuItem.new_with_label(label_fn(doc))
                try:
                    w.set_image(Gtk.Image.new_from_icon_name(get_icon_name(doc["tag"]), Gtk.IconSize.MENU))
                except KeyError:
                    w.set_image(Gtk.Image.new_from_gicon(doc["doc"].file_type.icon, Gtk.IconSize.MENU))
                w.connect("activate", lambda item, doc: self.switch_doc(doc), doc)
                m.append(w)
                return w
            # always select the first item for better keyboard navigation
            w = add_doc(docs[0])
            m.connect("realize", lambda menu: menu.select_item(w))
            for d in docs[1:]:
                add_doc(d)
            m.show_all()
            # grab a ref to the menu or it would be destroyed after leaving this function
            # is there a better solution??
            self.__m = m
            def on_hide(m):
                self.__m = None
            m.connect("hide", on_hide)
            m.connect("destroy", lambda m: self.dlg.close())
            m.popup(None, None, self.pos_func, widget, 0, Gtk.get_current_event_time());

    def on_def_activate(self, entry):
        docs = []
        tags = Geany.tm_workspace_find_prefix(entry.get_text(), Geany.TMParserType.NONE, 128)
        for tag in tags:
            if (tag.file and (tag.type in (Geany.TMTagType.FUNCTION_T, Geany.TMTagType.METHOD_T))):
                gd = Geany.Document.find_by_real_path(tag.file.file_name)
                docs.append({"tag" : tag, "doc" : gd})
        self.show_docs(docs, entry)

    def on_decl_activate(self, entry):
        docs = []
        tags = Geany.tm_workspace_find_prefix(entry.get_text(), Geany.TMParserType.NONE, 128)
        for tag in tags:
            if (tag.file and not (tag.type in (Geany.TMTagType.FUNCTION_T, Geany.TMTagType.METHOD_T))):
                gd = Geany.Document.find_by_real_path(tag.file.file_name)
                docs.append({"tag" : tag, "doc" : gd})
        self.show_docs(docs, entry)

    def on_file_activate(self, entry):
        docs = []
        for doc in self.geany_plugin.geany_data.documents_array:
            if (doc.display_name().startswith(entry.get_text())):
                docs.append({"doc" : doc})
        self.show_docs(docs, entry)

    def do_enable(self):
        # Gtk.Menu.popup does not work on Gtk2, hence Gtk3 only for now
        if (Gtk.check_version(3, 0, 0) is not None):
            warnings.warn("Gtk 2 is not supported by this plugin", RuntimeWarning)
            return False

        self.item = Geany.ui_image_menu_item_new(Gtk.STOCK_EXECUTE, u"Quick Tab Switch…")
        self.item.connect("activate", self.on_item_click)
        self.geany_plugin.geany_data.main_widgets.tools_menu.append(self.item)
        self.ui = Gtk.Builder.new_from_file(os.path.join(self.plugin_info.get_module_dir(), "goto", "goto.glade"))
        self.dlg = self.ui.get_object("window")
        self.dlg.set_transient_for(self.geany_plugin.geany_data.main_widgets.window)
        self.item.show_all();
        self.ui.get_object("txt_file").connect("activate", self.on_file_activate)
        self.ui.get_object("txt_def").connect("activate", self.on_def_activate)
        self.ui.get_object("txt_decl").connect("activate", self.on_decl_activate)

        self.keys = self.add_key_group("quicktabswitch", 3)
        self.keys.add_keybinding("switch_by_file", "Switch by file",
                self.item, 0, 0)
        self.keys.add_keybinding("switch_by_def", "Switch by symbol definition",
                None, 0, 0).connect("activate", lambda key, id: self.on_item_click(self.item, "txt_def"))
        self.keys.add_keybinding("switch_by_decl", "Switch by symbol declaration",
                None, 0, 0).connect("activate", lambda key, id: self.on_item_click(self.item, "txt_decl"))
        return True

    def do_disable(self):
        self.dlg.destroy()
        self.item.destroy()

    def on_item_click(self, item, focus_ = "txt_file"):
        txts = ("txt_file", "txt_def", "txt_decl")
        for e in txts:
            if (e == focus_):
                self.dlg.connect_after("show",
                    lambda dlg: dlg.set_focus(self.ui.get_object(focus_)))
            else:
                self.ui.get_object(e).get_buffer().delete_text(0, -1)
        self.dlg.run()
        self.dlg.hide()
        return True
