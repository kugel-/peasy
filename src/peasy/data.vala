using GLib;
using Geany;

namespace Peasy
{
	public class App : Peasy.Object
	{
		public bool            debug_mode;
		public unowned string  configdir;
		public unowned string  datadir;
		public unowned string  docdir;

		internal App()
		{
			debug_mode = geany_plugin.geany_data.app.debug_mode;
			configdir  = geany_plugin.geany_data.app.configdir;
			datadir    = geany_plugin.geany_data.app.datadir;
			docdir     = geany_plugin.geany_data.app.docdir;
		}
	}

	public class UiWidgets : Peasy.Object
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
			window                  = geany_plugin.geany_data.main_widgets.window;
			toolbar                 = geany_plugin.geany_data.main_widgets.toolbar;
			sidebar_notebook        = geany_plugin.geany_data.main_widgets.sidebar_notebook;
			notebook                = geany_plugin.geany_data.main_widgets.notebook;
			editor_menu             = geany_plugin.geany_data.main_widgets.editor_menu;
			tools_menu              = geany_plugin.geany_data.main_widgets.tools_menu;
			progressbar             = geany_plugin.geany_data.main_widgets.progressbar;
			message_window_notebook = geany_plugin.geany_data.main_widgets.message_window_notebook;
			project_menu            = geany_plugin.geany_data.main_widgets.project_menu;
		}
	}

	public class Data : Peasy.Object
	{
		public UiWidgets                      widgets;
		/* shadow copoies because pygobject does not handle pointers-to-structs yet (unlike vala) */
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
			prefs = geany_plugin.geany_data.prefs;
			interface_prefs = geany_plugin.geany_data.interface_prefs;
			tool_prefs = geany_plugin.geany_data.tool_prefs;
			toolbar_prefs = geany_plugin.geany_data.toolbar_prefs;
			editor_prefs = geany_plugin.geany_data.editor_prefs;
			file_prefs = geany_plugin.geany_data.file_prefs;
			search_prefs = geany_plugin.geany_data.search_prefs;
			template_prefs = geany_plugin.geany_data.template_prefs;
			build_info = geany_plugin.geany_data.build_info;
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
