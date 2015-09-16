from __future__ import print_function

from gi.repository import GObject
from gi.repository import Peas
from gi.repository import Peasy

class PeasyPyTester(Peas.ExtensionBase, Peas.Activatable):
	__gtype_name = 'PeasyPyTester'

	object = GObject.property(type=GObject.Object)
	# why is this needed!?
	plugin_info = GObject.property(type=Peas.PluginInfo)
	doc = None


	def on_closed(self, d):
		print(d.props.display_name + " closed")
		self.doc = None

	def do_activate(self):
		print("activate!")
		self.doc = Peasy.Document.new_file("foo")
		self.doc.connect("closed", self.on_closed)

	def do_deactivate(self):
		print("deactivate!")
		if (self.doc):
			self.doc.close()

	def do_update_state(self):
		print("updated state!")
