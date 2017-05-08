import os
import traceback

from gi.repository import Gdk
from gi.repository import Gtk
from gi.repository import GLib
from gi.repository import Peasy
from gi.repository import Geany
from gi.repository import GeanyScintilla

_ = Peasy.gettext

INDIC_MARK = "%cursor%"
INDIC_TOKEN = 10

class BackendBase:
    def probe(self, line, style):
        return style == self._style and line.startswith(self.docstart)

    def make_doc(self, tag):
        #~ s = self.docstart + "\n"
        s = "%s\n%s\n" % (INDIC_MARK, self.doccont)
        args = self.get_args(tag)
        if (args):
            for arg in args:
                s += "%s @param %s %s\n" % (self.doccont, arg, INDIC_MARK)
        retval = self.get_return(tag)
        if (retval):
            s += "%s @return \n" % (self.doccont)
        s += self.docend

        # calculate jump locations
        ret = list()
        # index and offset are in char points
        # but we want to return byte offsets for scintilla
        offset = 0
        while True:
            index = s[offset:].find(INDIC_MARK)
            if (index < 0):
                break
            ret.append(len(s[0:offset+index].encode()))
            offset += index + len(INDIC_MARK)
        return (s, ret)

class BackendC(BackendBase):
    # attributes starting with _ are read-only (cannot be overridden through
    # backends.conf
    _name     = "C/C++"
    _lexer    = GeanyScintilla.SCLEX_CPP
    _style    = GeanyScintilla.SCE_C_COMMENTDOC
    prefix    = "@"
    docstart  = "/**"
    doccont   = " *"
    docend    = " **/"

    def get_args(self, tag):
        # "(int a, char * b, sturct Foo *c)" -> ["int a","char * b", "struct Foo *c"]
        args = tag.arglist.strip("()").split(",")
        if (len(args) == 0):
            return None
        if (len(args) == 1 and (args[0] == "void" or args == "")):
            return None
        # ["int a","char * b", "struct Foo *c"] -> ["a", "b", "c"]
        args = [arg.split()[-1].strip("*") for arg in args]
        return args

    def get_return(self, tag):
        if tag.var_type == "void":
            return None
        return tag.var_type

class BackendPython(BackendBase):
    # attributes starting with _ are read-only (cannot be overridden through
    # backends.conf
    _name     = "Python"
    _lexer    = GeanyScintilla.SCLEX_PYTHON
    _style    = GeanyScintilla.SCE_P_COMMENTBLOCK
    prefix    = "@"
    docstart  = "##"
    doccont   = "#"
    docend    = ""

    def get_args(self, tag):
        # "(arg1, arg2 = 1, *args, **kwargs)" -> ["arg1, "arg2 = 1", "*args", "**kwargs"]
        args = tag.arglist.strip("()").split(",")
        if (len(args) == 0):
            return None
        # ["arg1, "arg2 = 1", "*args", "**kwargs"] -> ["arg1, "arg2 = 1", "args", "kwargs"]
        args = [arg.lstrip("* ") for arg in args]
        # ["arg1, "arg2 = 1", "*args", "**kwargs"] -> ["arg1", "arg2", "args", "kwargs"]
        args = [arg.split("=")[0].rstrip() for arg in args]
        return args

    def get_return(self, tag):
        # tagmanager doesnt parse return statements
        return True


def create_backend(key_file, group):
    if (group == "C"):
        back = BackendC()
    elif (group == "Python"):
        back = BackendPython()
    else:
        return None

    # Override backend defaults
    keys, cnt = key_file.get_keys(group)
    for key in keys:
        if (key[0] != "_" and hasattr(back, key)):
            setattr(back, key, key_file.get_string(group, key))
    return back

def load_backends(key_file_name):
    all_backends = list()
    key_file = GLib.KeyFile.new()
    try:
        key_file.load_from_file(key_file_name, GLib.KeyFileFlags.NONE)
        grps, cnt = key_file.get_groups()
        for grp in grps:
            back = create_backend(key_file, grp)
            if (back is not None):
                all_backends.append(back)
    except Exception as e:
        if not (e.domain == "g-file-error-quark"):
            raise e
    return all_backends

class DoxygenHelper(Peasy.Plugin, Peasy.PluginConfigure):

    def __init__(self):
        self.cnt = 0
        self.doc_added = False
        self.back = None
        self.tag = None

    def get_next_tag(self, doc, line):
        if (not doc.has_tags):
            return None
        tags = []
        next = None
        for tag in doc.tm_file.tags_array:
            if (tag.line >= line and (next is None or tag.line < next.line)):
                next = tag
        return next

    def pos_func(self, *args):
        sci = args[3]
        alloc = args[3].get_allocation()
        win = args[3].get_window()
        tmp, wx, wy = win.get_origin()
        line = sci.get_current_line()
        pos = sci.get_position_from_line(line)
        x = sci.send_message(GeanyScintilla.SCI_POINTXFROMPOSITION, 0, pos)
        y = sci.send_message(GeanyScintilla.SCI_POINTYFROMPOSITION, 0, pos)
        return (wx + alloc.x + x, wy + alloc.y + y, True)

    def next_jump_loc(self, sci, pos):
        val = sci.send_message(GeanyScintilla.SCI_INDICATORVALUEAT, INDIC_TOKEN, pos)
        # check if we're within a jump loc, and move out if necessary
        if (val):
            start = sci.send_message(GeanyScintilla.SCI_INDICATOREND, INDIC_TOKEN, pos)
            end = sci.send_message(GeanyScintilla.SCI_INDICATOREND, INDIC_TOKEN, start)
        else:
            end = sci.send_message(GeanyScintilla.SCI_INDICATOREND, INDIC_TOKEN, pos)

        if (end == sci.get_length()):
            end = 0
        return end

    def insert_doc_snippet(self, editor, text):
        sci = editor.sci
        pos = sci.get_current_position()
        editor.insert_snippet(pos, text.replace("\n ", "\n"))

    def insert_doc(self, editor):
        sci = editor.sci
        buf, jump_locs = self.back.make_doc(self.tag)
        # Eventually we'll just make use of Geany's snippet support
        if (False):
            self.insert_doc_snippet(editor, buf)
            return

        placeholder = u"…"
        length_diff = len(INDIC_MARK.encode()) - len(placeholder.encode())
        for loc in range(0, len(jump_locs)):
            buf = buf.replace(INDIC_MARK, placeholder, 1)
            for loc_ in range(loc+1, len(jump_locs)):
                jump_locs[loc_] -= length_diff

        # Insert fixed text
        editor.insert_text_block(buf, sci.get_current_position(), 0, 0, 0)
        sci.send_message(GeanyScintilla.SCI_INDICSETSTYLE, INDIC_TOKEN, GeanyScintilla.INDIC_DOTBOX)
        sci.indicator_set(INDIC_TOKEN)

        # Set an indicator for each jump location
        pos = sci.get_current_position()
        for i in jump_locs:
            if i == 0:
                sci.set_selection_start(pos+i)
                sci.set_selection_end(pos+i+len(placeholder.encode()))
            else:
                sci.send_message(GeanyScintilla.SCI_INDICATORFILLRANGE, pos+i, len(placeholder.encode()))

    def on_key(self, widget, ev, editor):
        sci = editor.sci
        if (ev.keyval == Gdk.KEY_Return):
            sci.event(ev)
            self.insert_doc(editor)
            widget.popdown()
            return True
        if (ev.keyval == Gdk.KEY_space):
            sci.event(ev)
            self.insert_doc(editor)
            widget.popdown()
            return True
        return False

    def create_popup(self, editor):
        m = Gtk.Menu.new()
        w = Gtk.ImageMenuItem.new_with_label(_("Create Doxygen comment for %s" % self.tag.name))
        m.append(w)
        m.connect("key-press-event", self.on_key, editor)
        m.show_all()
        m.popup(None, None, self.pos_func, editor.sci, 0, Gtk.get_current_event_time())

    def on_editor_notify(self, object, editor, notif):
        sci = editor.sci
        code = notif.nmhdr.code
        self.cnt += 1
        lexer = sci.get_lexer()
        back = next((back for back in self.backends if (back._lexer == lexer)), None)
        if (back is None):
            return False
        if (code == GeanyScintilla.SCN_CHARADDED):
            self.doc_added = False
            line_num = sci.get_current_line()
            if (chr(notif.ch) == back.docstart[0]):
                self.tag = self.get_next_tag(editor.document, line_num)
            if (chr(notif.ch) == back.docstart[-1]):
                buf = sci.get_line(line_num).rstrip("\n")
                if (buf == back.docstart):
                    self.doc_added = True
        elif (code == GeanyScintilla.SCN_MODIFIED and self.doc_added):
            if not (notif.modificationType & GeanyScintilla.SC_MOD_CHANGESTYLE):
                return False
            # workaround for duplicated sci notifies
            self.doc_added = False
            line_num = sci.get_current_line()
            start = sci.get_position_from_line(line_num)
            lexer = sci.get_lexer()
            style = sci.get_style_at(start)
            line = sci.get_line(line_num)
            if (back.probe(line, style)):
                empty_comment = True
                while True:
                    line_num += 1
                    buf = sci.get_line(line_num)
                    if (buf.find(back.docend) != -1):
                        break
                    if (buf.strip() != back.doccont.strip()):
                        #~ empty_comment = False
                        line_num -= 1
                        break
                if empty_comment:
                    if self.tag:
                        self.back = back
                        self.create_popup(editor)

        return False

    def on_item_click(self):
        pos = 0
        doc = Geany.Document.get_current()
        sci = doc.editor.sci
        pos = self.next_jump_loc(sci, sci.get_current_position())
        if (pos <= 0):
            return False
        sci.indicator_set(INDIC_TOKEN)
        sci.indicator_clear(pos, len(u"…".encode()))
        sci.set_selection_start(pos);
        sci.set_selection_end(pos + len(u"…".encode()));
        return True

    def on_edit_templates_activate(self):
        dlg = self.ui.get_object("dlg_templates")
        dlg.set_transient_for(self.geany_plugin.geany_data.main_widgets.window)
        self.ui.get_object("dlg_templates").show_all()

    def on_edit_templates_clicked(self, btn):
        self.on_edit_templates_activate()

    def on_lang_changed(self, cb_lang):
        lang = cb_lang.get_active()
        back = self.backends[lang]
        entry = self.ui.get_object("txt_start")
        entry.set_text(back.docstart)
        entry = self.ui.get_object("txt_cont")
        entry.set_text(back.doccont)
        entry = self.ui.get_object("txt_end")
        entry.set_text(back.docend)
        entry = self.ui.get_object("txt_prefix")
        entry.set_text(back.prefix)

    def setup_templates_dialog(self):
        dlg = self.ui.get_object("dlg_templates")
        dlg.connect("response", lambda dlg, response_id: print(str(response_id)))
        dlg.set_transient_for(self.geany_plugin.geany_data.main_widgets.window)
        self.ui.get_object("b_templates_cancel").connect("clicked", lambda btn: dlg.response(Gtk.ResponseType.CANCEL))
        self.ui.get_object("b_templates_ok").connect("clicked", lambda btn: dlg.response(Gtk.ResponseType.OK))
        self.ui.get_object("b_templates_apply").connect("clicked", lambda btn: dlg.response(Gtk.ResponseType.APPLY))
        # Scintilla for the edit pane
        sci_edit = GeanyScintilla.ScintillaObject.new()
        for style in range(0, GeanyScintilla.STYLE_MAX):
            sci_edit.set_font(style, self.geany_plugin.geany_data.interface_prefs.editor_font, 9)
        self.ui.get_object("al_edit").add(sci_edit)
        # Scintilla for the preview pane
        sci_preview = GeanyScintilla.ScintillaObject.new()
        for style in range(0, GeanyScintilla.STYLE_MAX):
            sci_preview.set_font(style, self.geany_plugin.geany_data.interface_prefs.editor_font, 9)
        self.ui.get_object("al_preview").add(sci_preview)
        self.ui.get_object("cb_lang").connect("changed", self.on_lang_changed)

    def populate_templates_dialog(self):
        cb_lang = self.ui.get_object("cb_lang")
        for back in self.backends:
            cb_lang.append_text(back._name)
        cb_lang.set_active(0)

    def do_configure(self, dialog):
        widget = self.ui.get_object("b_configure")
        #~ dialog.connect("response", self.on_dialog_response, btn)
        return widget

    def do_enable(self):
        o = self.geany_plugin.geany_data.object
        self.ui = Gtk.Builder.new()
        self.ui.set_translation_domain("peasy")
        self.ui.add_from_file(os.path.join(self.plugin_info.get_module_dir(), "doxygen-helper", "doxygen-helper.glade"))
        self.ui.get_object("b_edit_templates").connect("clicked", self.on_edit_templates_clicked)
        self.setup_templates_dialog()
        # Eventually we'll just make use of Geany's snippet support
        # then we need no separate keybinding
        if (True):
            self.keys = self.add_key_group("doxygen-helper", 3)
            self.keys.add_keybinding("next jump loc", _("Go to next cursor position"),
                None, 0, 0).connect("activate", lambda key, id: self.on_item_click())
            self.keys.add_keybinding("edit templates", _("Open Template Editor"),
                None, 0, 0).connect("activate", lambda key, id: self.on_edit_templates_activate())
        datapath = self.geany_plugin.geany_data.app.configdir
        kf_dir = os.path.join(datapath, "plugins", "doxygen-helper")
        try:
            os.makedirs(kf_dir)
        except OSError as e:
            if (e.errno != os.errno.EEXIST):
                return False

        try:
            self.backends = load_backends(os.path.join(kf_dir, "backends.conf"))
            self.populate_templates_dialog()
            o.connect("editor-notify", self.on_editor_notify)
        except Exception as e:
            print("Python exception: " + str(e))
            traceback.print_last()
            return False
        return True

    def do_disable(self):
        pass
