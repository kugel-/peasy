

from gi.repository import Gdk
from gi.repository import Gtk
from gi.repository import Peasy
from gi.repository import Geany
from gi.repository import GeanyScintilla

_ = Peasy.gettext

INDIC_MARK = "xxx"

class BackendBase:
    def probe(self, line, style):
        return style == self.style and line.startswith(self.docstart)

    def make_doc(self, tag):
        #~ s = self.docstart + "\n"
        s = "\n%s\n" % (self.doccont)
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
        offset = 0
        while True:
            index = s[offset:].find(INDIC_MARK)
            if (index < 0):
                break
            ret.append(offset + index)
            offset += index + len(INDIC_MARK)
        return (s, ret)

class BackendC(BackendBase):
    style     = GeanyScintilla.SCE_C_COMMENTDOC
    docstart  = "/**"
    doccont   = " *"
    docend    = " **/"

    def get_args(self, tag):
        # "(int a, char * b, sturct Foo *c)" -> ["int a","char * b", "struct Foo *c"]
        args = tag.arglist.strip("()").split(",")
        if len(args) == 1 and (args[0] == "void" or args == ""):
            return None
        # ["int a","char * b", "struct Foo *c"] -> ["a", "b", "c"]
        args = [arg.split()[-1].strip("*") for arg in args]
        return args

    def get_return(self, tag):
        if tag.var_type == "void":
            return None
        return tag.var_type

class DoxygenHelper(Peasy.Plugin):

    backends = dict()
    backends[GeanyScintilla.SCLEX_CPP] = BackendC()

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

    def insert_doc(self, sci):
        pos = sci.get_current_position()
        buf, jump_locs = self.back.make_doc(self.tag)
        buflen = len(buf)
        # TODO use editor_insert_text_block
        sci.insert_text(pos, buf)
        sci.set_current_position(pos, False)
        print(str(jump_locs))

    def on_key(self, widget, ev, sci):
        if (ev.keyval == Gdk.KEY_Return):
            sci.event(ev)
            self.insert_doc(sci)
            widget.popdown()
            return True
        if (ev.keyval == Gdk.KEY_space):
            sci.event(ev)
            self.insert_doc(sci)
            widget.popdown()
            return True
        return False

    def create_popup(self, sci):
        print("new mneu");
        m = Gtk.Menu.new()
        w = Gtk.ImageMenuItem.new_with_label(_("Create Doxygen comment for %s" % self.tag.name))
        m.append(w)
        m.connect("key-press-event", self.on_key, sci)
        m.show_all()
        m.popup(None, None, self.pos_func, sci, 0, Gtk.get_current_event_time())

    def on_editor_notify(self, object, editor, notif):
        sci = editor.sci
        code = notif.nmhdr.code
        self.cnt += 1
        lexer = sci.get_lexer()
        back = self.backends.get(lexer)
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
            # workaround for duplicated  again duplicated sci notifies
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
                        self.create_popup(sci)

        return False

    def do_enable(self):
        o = self.geany_plugin.geany_data.object
        o.connect("editor-notify", self.on_editor_notify)
        return True

    def do_disable(self):
        pass
