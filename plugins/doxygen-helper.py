import os
import traceback
import copy

from gi.repository import Gdk
from gi.repository import Gtk
from gi.repository import GLib
from gi.repository import Peasy
from gi.repository import Geany
from gi.repository import GeanyScintilla

_ = Peasy.gettext

INDIC_MARK = "%cursor%"
INDIC_TOKEN = 10

def SSM(sci, opcode, arg0, arg1):
    sci.send_message(opcode, arg0, arg1)

##
# Mimics a TMTag such that we can generate the preview from
#
class ExampleTag:
    def __init__(self, arglist, var_type, decl_fmt):
        self.arglist = arglist
        self.var_type = var_type
        self.decl = decl_fmt.format(var_type, arglist)

class BackendBase:
    template = """
$params

$return
"""

    def probe(self, line, style):
        return style == self._style and line.startswith(self.docstart)

    def make_preview(self):
        docs = self.make_doc(self._example).replace("%cursor%", u"…")
        return self.docstart + docs +"\n"+ self._example.decl

    def make_doc(self, tag):
        template = self.template
        # replace tokens in the template with doxygen commands
        # special case for $params which must be duplicated for each arg
        args = self.get_args(tag)
        lines = template.split("\n")
        doc = [" "]
        mark = " " + INDIC_MARK
        for line in lines:
            if (line.find("$params") >= 0):
                for arg in args:
                    new = line.replace("$params", self.prefix + "param " + arg + mark)
                    doc.append(self.doccont + " " + new)
            elif (line.find("$retval") >= 0):
                new = line.replace("$retval", self.prefix + "retval" + mark)
                doc.append(self.doccont + " " + new)
                doc.append(self.doccont + " " + new)
            else:
                new = line.replace("$return", self.prefix + "return" + mark)
                new = new.replace("$brief", self.prefix + "brief" + mark)
                new = new.replace("$detail", self.prefix + "detail" + mark)
                if len(new) > 0:
                    doc.append(self.doccont + " " + new)
                else:
                    doc.append(self.doccont)
        doc.append(self.docend)
        return ("\n".join(doc))

class BackendC(BackendBase):
    # attributes starting with _ are read-only (cannot be overridden through
    # backends.conf
    _name     = "C/C++"
    _ft       = "C++"
    _grp      = "C"
    _lexer    = GeanyScintilla.SCLEX_CPP
    _style    = GeanyScintilla.SCE_C_COMMENTDOC
    _example  = ExampleTag("(int arg1, char *arg2)", "int", "{0} example{1};")
    prefix    = "@"
    docstart  = "/**"
    doccont   = " **"
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
    _ft       = "Python"
    _grp      = "Python"
    _lexer    = GeanyScintilla.SCLEX_PYTHON
    _style    = GeanyScintilla.SCE_P_COMMENTBLOCK
    _example  = ExampleTag("(arg1, arg2 = 1, *args)", "", "def example{1}:\n  pass")
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


def store_backend(key_file, back):
    group = back._grp
    changed = 0
    if (group == "C"):
        cls = BackendC
    elif (group == "Python"):
        cls = BackendPython
    for attrib in ("prefix", "docstart", "doccont", "docend", "template"):
        try:
            old = key_file.get_string(group, attrib)
        except GLib.Error as e:
            if (e.domain != "g-key-file-error-quark"):
                raise e
            old = getattr(cls, attrib)
        if (getattr(back, attrib) != old):
            key_file.set_string(group, attrib, getattr(back, attrib))
            changed += 1
    return changed

def save_backends(key_file_name, all_backends):
    key_file = GLib.KeyFile.new()
    key_file.load_from_file(key_file_name, GLib.KeyFileFlags.NONE)
    changed = 0
    for back in all_backends:
        changed += store_backend(key_file, back)
    if (changed > 0):
        key_file.save_to_file(key_file_name);

class DoxygenHelper(Peasy.Plugin, Peasy.PluginConfigure):

    def __init__(self):
        self.cnt = 0
        self.timeout_handle = 0
        self.doc_added = False
        self.back = None
        self.tag = None
        self.key_file = None

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

    def insert_doc(self, editor, initial_nl):
        sci = editor.sci
        buf = ""
        initial_cursor = 0
        if initial_nl:
            buf += "\n" + self.back.doccont
            initial_cursor = len(self.back.doccont)
        buf += self.back.make_doc(self.tag)
        # Eventually we'll just make use of Geany's snippet support
        if (False):
            self.insert_doc_snippet(editor, buf)
            return

        placeholder = u"…"
        placeholder_nbytes = len(placeholder.encode())
        byte_loc = 0
        start = 0
        jump_locs = list()
        while (True):
            off = buf.find(INDIC_MARK, start)
            if (off == -1):
                break
            buf = buf.replace(INDIC_MARK, placeholder, 1)
            # Scintilla indicates must be specified in bytes
            byte_loc += len(buf[start:off].encode())
            jump_locs.append(byte_loc)
            start = off

        # Insert fixed text
        editor.insert_text_block(buf, sci.get_current_position(), initial_cursor, 0, 0)
        sci.send_message(GeanyScintilla.SCI_INDICSETSTYLE, INDIC_TOKEN, GeanyScintilla.INDIC_DOTBOX)
        sci.indicator_set(INDIC_TOKEN)

        # Set an indicator for each jump location
        pos = sci.get_current_position() - initial_cursor
        for i in jump_locs:
            if i == 0:
                sci.set_selection_start(pos+i)
                sci.set_selection_end(pos+i+placeholder_nbytes)
            else:
                sci.send_message(GeanyScintilla.SCI_INDICATORFILLRANGE, pos+i, placeholder_nbytes)

    def on_key(self, widget, ev, editor):
        sci = editor.sci
        if (ev.keyval == Gdk.KEY_Return):
            self.insert_doc(editor, True)
            widget.popdown()
            return True
        if (ev.keyval == Gdk.KEY_space):
            sci.event(ev)
            self.insert_doc(editor, False)
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
        self.populate_templates_dialog()
        dlg.show_all()

    def on_edit_templates_clicked(self, btn):
        self.on_edit_templates_activate()

    def update_preview(self, back):
        self.sci_preview.send_message(GeanyScintilla.SCI_SETREADONLY, 0, 0)
        self.sci_preview.set_text(back.make_preview())
        self.sci_preview.send_message(GeanyScintilla.SCI_SETREADONLY, 1, 0)

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
        Geany.highlighting_set_styles(self.sci_preview, Geany.filetypes_lookup_by_name(back._ft))
        self.sci_edit.set_text(back.template)
        self.update_preview(back)


    def on_refresh_preview_timeout(self):
        cb_lang = self.ui.get_object("cb_lang")
        #~ back = copy.copy(self.backends[cb_lang.get_active()])
        back = copy.copy(self.backends[cb_lang.get_active()])
        back.template = self.sci_edit.get_contents(-1)
        self.update_preview(back)
        self.timeout_handle = 0
        return False

    def on_sci_edit_notify(self, sci, scn, notif):
        code = notif.nmhdr.code
        if (code == GeanyScintilla.SCN_CHARADDED
                or code == GeanyScintilla.SCN_MODIFIED):
            if (self.timeout_handle != 0):
                GLib.source_remove(self.timeout_handle)
            self.timeout_handle = GLib.timeout_add(50, self.on_refresh_preview_timeout)

    def on_response(self, dlg, response_id):
        if (response_id in (Gtk.ResponseType.OK, Gtk.ResponseType.APPLY)):
            cb_lang = self.ui.get_object("cb_lang")
            lang = cb_lang.get_active()
            back = self.backends[lang]
            back.docstart = self.ui.get_object("txt_start").get_text()
            back.doccont = self.ui.get_object("txt_cont").get_text()
            back.docend = self.ui.get_object("txt_end").get_text()
            back.prefix = self.ui.get_object("txt_prefix").get_text()
            back.template = self.sci_edit.get_contents(-1)
            save_backends(self.key_file, self.backends)
            if (response_id == Gtk.ResponseType.OK):
                dlg.hide()
        elif (response_id in (Gtk.ResponseType.CANCEL, Gtk.ResponseType.DELETE_EVENT)):
            dlg.hide()

    def setup_templates_dialog(self):
        dlg = self.ui.get_object("dlg_templates")
        # never delete, hide in on_response()
        dlg.connect("delete-event", lambda dlg, ev: True)
        dlg.connect("response", self.on_response)
        dlg.set_transient_for(self.geany_plugin.geany_data.main_widgets.window)
        self.ui.get_object("b_templates_cancel").connect("clicked", lambda btn: dlg.response(Gtk.ResponseType.CANCEL))
        self.ui.get_object("b_templates_ok").connect("clicked", lambda btn: dlg.response(Gtk.ResponseType.OK))
        self.ui.get_object("b_templates_apply").connect("clicked", lambda btn: dlg.response(Gtk.ResponseType.APPLY))
        self.ui.get_object("cb_lang").connect("changed", self.on_lang_changed)
        # Scintilla for the edit pane
        self.sci_edit = GeanyScintilla.ScintillaObject.new()
        self.ui.get_object("al_edit").add(self.sci_edit)
        self.sci_edit.connect("sci-notify", self.on_sci_edit_notify)
        # Scintilla for the preview pane
        self.sci_preview = GeanyScintilla.ScintillaObject.new()
        self.ui.get_object("al_preview").add(self.sci_preview)
        # Setup Scintilla widgets
        font_name, size = self.geany_plugin.geany_data.interface_prefs.editor_font.split()
        for sci in (self.sci_edit, self.sci_preview):
            sci.send_message(GeanyScintilla.SCI_SETCODEPAGE, GeanyScintilla.SC_CP_UTF8, 0)
            for style in range(0, GeanyScintilla.STYLE_MAX):
                sci.set_font(style, "!" + font_name, int(size))

    def populate_templates_dialog(self):
        cb_lang = self.ui.get_object("cb_lang")
        for back in self.backends:
            cb_lang.append_text(back._name)
        cb_lang.set_active(0)
        self.on_lang_changed(cb_lang)

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
        self.key_file = os.path.join(kf_dir, "backends.conf")
        try:
            os.makedirs(kf_dir)
        except OSError as e:
            if (e.errno != os.errno.EEXIST):
                return False

        try:
            self.backends = load_backends(self.key_file)
            o.connect("editor-notify", self.on_editor_notify)
        except Exception as e:
            print("Python exception: " + str(e))
            traceback.print_last()
            return False
        return True

    def do_disable(self):
        pass
