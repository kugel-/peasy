from __future__ import print_function

import gi
gi.require_version('Peas', '1.0')

from gi.repository import GObject
from gi.repository import Peas
from gi.repository import Peasy

class PeasyPyTester(Peasy.Plugin, Peasy.PluginHelp):
	__gtype_name = 'PeasyPyTester'

	object = GObject.property(type=GObject.Object)
	# why is this needed!?
	plugin_info = GObject.property(type=Peas.PluginInfo)
	doc = None


	def on_closed(self, d):
		print(d.props.display_name + " closed")
		self.doc = None

	def do_enable(self):
		print("enable: Hello from " + self.props.plugin_info.get_name() + "!")
		self.doc = Peasy.Document.new_file("foo")
		self.doc.connect("closing", self.on_closed)
		return True

	def do_disable(self):
		print("disable!")
		if (self.doc):
			print("valid: " + str(self.doc.props.is_valid))
			self.doc.close()

	def do_help(self):
		print("Helpl!!")
