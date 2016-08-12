import gi
import os
import re
import sys
import pdb

from gi.repository import GObject
from gi.repository import GLib
from gi.repository import Gtk
from gi.repository import Geany
from gi.repository import GeanyScintilla
from gi.repository import Peasy

#The first form:
#       [text]{white}{vi:|vim:|ex:}[white]{options}
#
# [text]          any text or empty
# {white}         at least one blank character (<Space> or <Tab>)
# {vi:|vim:|ex:}  the string "vi:", "vim:" or "ex:"
# [white]         optional white space
# {options}       a list of option settings, separated with white space or ':',
#                 where each part between ':' is the argument for a ":set"
#                 command (can be empty)
#
# Example:
#    vi:noai:sw=3 ts=6 ~
#~ vim_com1 = re.compile("(?:vi|vim|ex):\s*(.*[a-zA-Z0-9])$")

#      The second form (this is compatible with some versions of Vi):
#        [text]{white}{vi:|vim:|ex:}[white]se[t] {options}:[text]
#
# [text]          any text or empty
# {white}         at least one blank character (<Space> or <Tab>)
# {vi:|vim:|ex:}  the string "vi:", "vim:" or "ex:"
# [white]         optional white space
# se[t]           the string "set " or "se " (note the space)
# {options}       a list of options, separated with white space, which is the
#                 argument for a ":set" command
# :               a colon
# [text]          any text or empty
#
# Example:
#    /* vim: set ai tw=75: */ ~
vim_reg = "(?:vi|vim|ex):\s*(.*)\s*"
kv_reg  = "\s|:"

class ModelineKeyFile:
    def __init__(self, datapath):
        self.path = os.path.join(datapath, "plugins", "modeline.conf")
        self.group = "preferences"
        self.kf = GLib.KeyFile.new()

    def load(self):
        try:
            return self.kf.load_from_file(self.path, GLib.KeyFileFlags.KEEP_COMMENTS)
        except Exception as e:
            if not (e.domain == "g-file-error-quark"):
                raise e
            return False

    def save(self):
        return self.kf.save_to_file(self.path)

    def set_boolean(self, key, value):
        self.kf.set_boolean(self.group, key, value)

    def get_boolean(self, key):
        return self.kf.get_boolean(self.group, key)


class Pref:
    def __init__(self, group, key, default):
        self.group = group
        self.key = key
        self.default = default
        self.value = None

    def load(self, keyfile):
        if self.value is not None:
            return self.value
        typ = type(self.default)
        if (typ == int):
            fn = keyfile.get_integer
        elif (typ == bool):
            fn = keyfile.get_boolean
        elif (typ == str):
            fn = keyfile.get_string

        self.value = self.default
        if (keyfile.has_group(self.group)):
            if (self.key in keyfile.get_keys(self.group)[0]):
                self.value = fn(self.group, self.key)

        return self.value

    def store(self, keyfile):
        typ = type(self.default)
        if (typ == int):
            fn = keyfile.set_integer
        elif (typ == bool):
            fn = keyfile.set_boolean
        elif (typ == str):
            fn = keyfile.set_string

        if (keyfile.has_group(self.group)):
            if ((self.value != self.default) or (self.key in keyfile.get_keys(self.group)[0])):
                fn(self.group, self.key, self.value)


class Modeline(Peasy.Plugin, Peasy.PluginConfigure):
    __gtype_name__ = 'Modeline'
    doc = None
    item = None
    keys = None

    def __init__(self):
        self.vim_com = re.compile(vim_reg)
        self.kv_com = re.compile(kv_reg)

    def apply_indent_type(self, editor, v):
        if (self.use_setting.value == False or editor.get_indent_prefs().detect_type):
            setattr(editor, "indent_type", v)
        return None

    def apply_indent_width(self, editor, v):
        if (self.use_setting.value == False or editor.get_indent_prefs().detect_width):
            setattr(editor, "indent_width", int(v))
        return None

    # direct attr assignment does not work in lambdas so use settattr
    procs = {
        'set'        : lambda s, editor     : None,
        'expandtab'  : lambda s, editor     : s.apply_indent_type(editor, Geany.IndentType.SPACES),
        'noexpandtab': lambda s, editor     : s.apply_indent_type(editor, Geany.IndentType.TABS),
        'wrap'       : lambda s, editor     : setattr(editor, "line_wrapping", True),
        'nowrap'     : lambda s, editor     : setattr(editor, "line_wrapping", False),
        'shiftwidth' : lambda s, editor, val: s.apply_indent_width(editor, val)
    }
    aliases = {
        'se'         : 'set',
        'set'        : 'set',
        'ne'         : 'noexpandtab',
        'noet'       : 'noexpandtab',
        'et'         : 'expandtab',
        'sw'         : 'shiftwidth',
        'tabstop'    : 'shiftwidth',
        'ts'         : 'shiftwidth',
        'softtabstop': 'shiftwidth',
        'sts'        : 'shiftwidth'
    }

    def on_match(self, line, doc):
        m = self.kv_com.split(line)
        for x in (e for e in m if e != ''):
            kv = x.split("=")
            k = kv[0]
            if (k in self.aliases):
                k = self.aliases[k]
            if (k in self.procs):
                if (len(kv) == 2):
                    self.procs[k](self, doc.editor, kv[1])
                elif (len(kv) == 1):
                    self.procs[k](self, doc.editor)
            else:
                print(_("Key %s is not supported!") % k)

    def parse_doc(self, obj, doc):
        sci = doc.editor.sci
        lexer = sci.get_lexer()
        num_lines = sci.get_line_count()
        for x in range(0, 5):
            line = sci.get_line(x)
            m = re.search(self.vim_com, line)
            if (m is None and num_lines > 5):
                line = sci.get_line(x + num_lines - 5)
                m = re.search(self.vim_com, line)
            if (m is not None):
                # Pass only in comment sections (unless the file is not highlighted at all)
                # EXCEPT that document-open and document-reload the lexer didn't run yet
                # so this actually cannot work :(
                # the code is left for reference but the lexer is set to NULL take the else path
                lexer = GeanyScintilla.SCLEX_NULL
                match = m.group(1)
                pos = m.start(0)
                if (lexer > GeanyScintilla.SCLEX_NULL and lexer < GeanyScintilla.SCLEX_AUTOMATIC):
                    if (Peasy.Highlighting.is_comment_style(lexer, sci.get_style_at(pos))):
                        self.on_match(match, doc)
                else:
                    self.on_match(match, doc)

    def do_enable(self):
        o = self.geany_plugin.geany_data.object
        o.connect("document-open",   self.parse_doc)
        o.connect("document-new",    self.parse_doc)
        o.connect("document-reload", self.parse_doc)
        o.connect("document-save",   self.parse_doc)
        self.hid = 0
        self.prefs = []
        kf = ModelineKeyFile(self.geany_plugin.geany_data.app.configdir)
        self.gen_pref("use_setting", Pref("preferences", "follow-autodetect-setting", True))
        for pref in self.prefs:
            pref.load(kf.kf)
        return True

    def do_disable(self):
        pass

    def on_dialog_response(self, dialog, resp, widget):
        widgets = widget.get_children()
        if (resp == Gtk.ResponseType.OK or resp == Gtk.ResponseType.APPLY):
            kf = ModelineKeyFile(self.geany_plugin.geany_data.app.configdir)
            kf.load()
            self.use_setting.value = widgets[0].get_active()
            self.test.value = widgets[1].get_active()
            for pref in self.prefs:
                pref.store(kf.kf)
            
            kf.save()

    def gen_pref(self, k, v):
        self.__dict__[k] = v
        self.prefs.append(v)

    def do_configure(self, dialog):
        c = Gtk.VBox.new(False, 6)
        w = Gtk.CheckButton.new_with_label(_("Follow Geany's settings for detecting indentation from the file"))
        w.set_tooltip_text(_("If enabled, indent type  and width from modeline only "+
                             "apply if Geany is set to detect these settings from the file. "+
                             "Other modeline settings apply always."))
        w.set_active(self.use_setting)
        c.pack_start(w, False, False, 6)
        dialog.connect("response", self.on_dialog_response, c)
        return c


if __name__ == '__main__':
    print("Tests...")
    vim_com = re.compile(vim_reg)
    kv_com = re.compile(kv_reg)

    s = vim_com.findall("vim: set sw=4 ts=3:")[0]
    assert (s == "set sw=4 ts=3:")
    assert (kv_com.split(s) == ["set", "sw=4", "ts=3", ""])

    s = vim_com.findall("vim:sw=4 ts=3")[0]
    assert (s == "sw=4 ts=3")
    assert (kv_com.split(s) == ["sw=4", "ts=3"])

    s = vim_com.findall("vim:sw=4:ts=3:et")[0]
    assert (s == "sw=4:ts=3:et")
    assert (kv_com.split(s) == ["sw=4", "ts=3", "et"])

    s = vim_com.findall("vim:  et noet")[0]
    assert(s == "et noet")
    assert(kv_com.split(s) == ["et", "noet"])

    s = vim_com.findall("vim:se et:noet:")[0]
    assert(s == "se et:noet:")
    assert(kv_com.split(s) == ["se", "et", "noet", ""])

    s = vim_com.findall("vim:set ts=8 et:")[0]
    assert(s == "set ts=8 et:")
    assert(kv_com.split(s) == ["set", "ts=8", "et", ""])
