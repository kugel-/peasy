using GLib;
using Geany;

namespace Peasy
{
	public class App : Object
	{
		public bool            debug_mode;
		public unowned string  configdir;
		public unowned string  datadir;
		public unowned string  docdir;

		construct
		{
			debug_mode = peasy_plugin.geany_data.app.debug_mode;
			configdir  = peasy_plugin.geany_data.app.configdir;
			datadir    = peasy_plugin.geany_data.app.datadir;
			docdir     = peasy_plugin.geany_data.app.docdir;
		}
	}

	public class UiWidgets : Object
	{
		public unowned Gtk.Widget window;
		public unowned Gtk.Widget toolbar;
		public unowned Gtk.Widget sidebar_notebook;
		public unowned Gtk.Widget notebook;
		public unowned Gtk.Widget editor_menu;
		public unowned Gtk.Widget tools_menu;
		public unowned Gtk.Widget progressbar;
		public unowned Gtk.Widget message_window_notebook;
		public unowned Gtk.Widget project_menu;

		public UiWidgets()
		{
			window                  = peasy_plugin.geany_data.main_widgets.window;
			toolbar                 = peasy_plugin.geany_data.main_widgets.toolbar;
			sidebar_notebook        = peasy_plugin.geany_data.main_widgets.sidebar_notebook;
			notebook                = peasy_plugin.geany_data.main_widgets.notebook;
			editor_menu             = peasy_plugin.geany_data.main_widgets.editor_menu;
			tools_menu              = peasy_plugin.geany_data.main_widgets.tools_menu;
			progressbar             = peasy_plugin.geany_data.main_widgets.progressbar;
			message_window_notebook = peasy_plugin.geany_data.main_widgets.message_window_notebook;
			project_menu            = peasy_plugin.geany_data.main_widgets.project_menu;
		}
	}

	public class Data : Object
	{
		/* shadow copoies because pygobject does not handle pointers-to-structs yet (unlike vala) */
		public UiWidgets                      widgets;
		public App                            app;
		public unowned Geany.Prefs            prefs;
		public unowned Geany.InterfacePrefs   interface_prefs;
		public unowned Geany.ToolPrefs        tool_prefs;
		public unowned Geany.ToolbarPrefs     toolbar_prefs;
		public unowned Geany.EditorPrefs      editor_prefs;
		public unowned Geany.FilePrefs        file_prefs;
		public unowned Geany.SearchPrefs      search_prefs;
		public unowned Geany.TemplatePrefs    template_prefs;
		public unowned Geany.BuildInfo        build_info;

		private Data()
		{
			prefs = peasy_plugin.geany_data.prefs;
			interface_prefs = peasy_plugin.geany_data.interface_prefs;
			tool_prefs = peasy_plugin.geany_data.tool_prefs;
			toolbar_prefs = peasy_plugin.geany_data.toolbar_prefs;
			editor_prefs = peasy_plugin.geany_data.editor_prefs;
			file_prefs = peasy_plugin.geany_data.file_prefs;
			search_prefs = peasy_plugin.geany_data.search_prefs;
			template_prefs = peasy_plugin.geany_data.template_prefs;
			build_info = peasy_plugin.geany_data.build_info;
			app = new App();
			widgets = new UiWidgets();
		}

		/* singleton impl */
		private static Data _instance;
		public static Data instance()
		{
			Data _d;
			if (_instance == null)
			{
				/* vala doesn't let me do this is in a single expression */
				_d = new Data();
				_instance = _d;
			}
			return _instance;
		}
	}
}
