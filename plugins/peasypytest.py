from __future__ import print_function

import gettext
import gi
gi.require_version('Peas', '1.0')

from gi.repository import GObject
from gi.repository import Peas
from gi.repository import Peasy
from gi.repository import Geany

gettext.bindtextdomain("peasy", "/home/kugel/dev/geany.git/build-linux/dest/share/locale")
gettext.textdomain("peasy")
_ = gettext.gettext

class PeasyPyTester(Peasy.Plugin, Peasy.PluginHelp):
    __gtype_name = 'PeasyPyTester'

    object = GObject.property(type=GObject.Object)
    # why is this needed!?
    plugin_info = GObject.property(type=Peas.PluginInfo)
    doc = None


    def on_closed(self, obj, d):
        print(d.display_name() + " closed")
        self.doc = None

    def do_enable(self):
        print("do_enable: " + gettext.dgettext("peasy", "Hello from %s!") % self.props.plugin_info.get_name())
        self.doc = Geany.Document.new_file("foo")
        self.geany_plugin.geany_data.object.connect("document-close", self.on_closed)
        return True

    def do_disable(self):
        print("do_disable: " + _("%s says bye!") % self.props.plugin_info.get_name())
        if (self.doc and self.doc.is_valid):
            self.doc.close()

    def do_help(self):
        print("Help!!")
