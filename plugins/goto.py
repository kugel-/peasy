import os
from gi.repository import Geany
from gi.repository import Peasy
from gi.repository import Gtk

class GotoPlugin(Peasy.Plugin):
    __gtype_name__ = 'GotoPlugin'

    def do_enable(self):
        self.item = Geany.ui_image_menu_item_new(Gtk.STOCK_EXECUTE, "Goto ...")
        self.item.connect("activate", self.on_item_click)
        self.geany_plugin.geany_data.main_widgets.tools_menu.append(self.item)
        self.ui = Gtk.Builder.new_from_file(os.path.join(self.plugin_info.get_module_dir(), "goto", "goto.glade")).get_object("window")
        self.item.show_all();
        return True

    def do_disable(self):
        self.item.destroy()


    def on_item_click(self, item):
        self.ui.run()
