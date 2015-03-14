from gi.repository import GObject
from gi.repository import Peas


class PeasyPyTester(Peas.ExtensionBase, Peas.Activatable):
	__gtype_name = 'PeasyPyTester'

	object = GObject.property(type=GObject.Object)
	# why is this needed!?
	plugin_info = GObject.property(type=Peas.PluginInfo)

	def do_activate(self):
		print "activate!"

	def do_deactivate(self):
		print "deactivate!"

	def do_update_state(self):
		print "updated state!"
