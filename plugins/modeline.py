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
    vim_com1 = re.compile("(?:vi|vim|ex):\s*(.*[a-zA-Z0-9])$")

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
    vim_com2 = re.compile("(?:vi|vim|ex):\s?se[t\s]?\s*(.*):")
    kv_com  = re.compile("([^:\s]*)[:\s]")

    # direct property assignment does not work in lambdas
    procs = {
        'expandtab'  : lambda editor     : setattr(editor, "indent_type", Geany.IndentType.SPACES),
        'noexpandtab': lambda editor     : setattr(editor, "indent_type", Geany.IndentType.TABS),
        'wrap'       : lambda editor     : setattr(editor, "line_wrapping", True),
        'nowrap'     : lambda editor     : setattr(editor, "line_wrapping", False),
        'shiftwidth' : lambda editor, val: setattr(editor, "indent_width", int(val))
    }
    aliases = {
        'et'         : 'expandtab',
        'sw'         : 'shiftwidth',
        'tabstop'    : 'shiftwidth',
        'ts'         : 'shiftwidth',
        'softtabstop': 'shiftwidth',
        'sts'        : 'shiftwidth'
    }

    def on_match(self, line, doc):
        print("on_match")
        m = re.findall(self.kv_com, line)
        for x in m:
            kv = x.split("=")
            try:
                k = self.aliases[kv[0]] if kv[0] in self.aliases else kv[0]
                if self.procs[k]:
                    if (len(kv) == 2):
                        v = kv[1]
                        self.procs[k](doc.editor, v)
                        print ("%s=%s" % (k,v))
                    elif (len(kv) == 1):
                        self.procs[k](doc.editor)
                        print (k)
            except KeyError:
                # unknown vim key, ignore
                continue
            except TypeError:
                sys.stderr.write("invalid modeline at " + str(kv))
                # probably invalid modeline, e.g. when a value was given to a non-value option
                return

    def parse_doc(self, obj, doc):
        sci = doc.editor.sci
        lexer = sci.get_lexer()
        num_lines = sci.get_line_count()
        for x in range(0, 5):
            line = sci.get_line(x)
            m = re.search(self.vim_com2, line)
            if (m is None):
                m = re.search(self.vim_com1, line)
            if (m is None and num_lines > 5):
                line = sci.get_line(x + num_lines - 5)
                m = re.search(self.vim_com2, line)
                if (m is None):
                    m = re.search(self.vim_com1, line)
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
        self.gen_pref("test", Pref("preferences", "test", True))
        for pref in self.prefs:
            pref.load(kf.kf)
        return True

    def do_disable(self):
        pass

    def on_dialog_response(self, dialog, resp, widget):
        widgets = widget.get_children()
        if (resp == Gtk.ResponseType.OK or resp == Gtk.ResponseType.APPLY):
            kf = ModelineKeyFile(self.data.app.configdir)
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
        w = Gtk.CheckButton.new_with_label("Follow Geany's autodetect setting")
        w.set_active(self.use_setting)
        c.pack_start(w, False, False, 6)
        w = Gtk.CheckButton.new_with_label("Test")
        w.set_active(self.test)
        c.pack_start(w, False, False, 6)
        dialog.connect("response", self.on_dialog_response, c)
        return c
