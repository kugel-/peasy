using GLib;
using Geany;

namespace Peasy
{
	public class App : Peasy.Object
	{
		public bool         debug_mode;
		public weak string  configdir;
		public weak string  datadir;
		public weak string  docdir;

		internal App()
		{
			debug_mode = peasy_plugin.geany_data.app.debug_mode;
			configdir  = peasy_plugin.geany_data.app.configdir;
			datadir    = peasy_plugin.geany_data.app.datadir;
			docdir     = peasy_plugin.geany_data.app.docdir;
		}
	}

	public class UiWidgets : Peasy.Object
	{
		public weak Gtk.Widget window;
		public weak Gtk.Widget toolbar;
		public weak Gtk.Widget sidebar_notebook;
		public weak Gtk.Widget notebook;
		public weak Gtk.Widget editor_menu;
		public weak Gtk.Widget tools_menu;
		public weak Gtk.Widget progressbar;
		public weak Gtk.Widget message_window_notebook;
		public weak Gtk.Widget project_menu;

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

	public class Data : Peasy.Object
	{
		public UiWidgets              widgets;
		/* shadow copoies because pygobject does not handle pointers-to-structs yet (unlike vala) */
		public App                    app;
		public Geany.Prefs            prefs;
		public Geany.InterfacePrefs   interface_prefs;
		public Geany.ToolPrefs        tool_prefs;
		public Geany.ToolbarPrefs     toolbar_prefs;
		public Geany.EditorPrefs      editor_prefs;
		public Geany.FilePrefs        file_prefs;
		public Geany.SearchPrefs      search_prefs;
		public Geany.TemplatePrefs    template_prefs;
		public Geany.BuildInfo        build_info;

		private void sync_prefs_static(Peasy.Data data)
		{
			data.sync_prefs();
		}

		private void sync_prefs()
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
		}

		construct
		{
			app = new App();
			widgets = new UiWidgets();
			signal_connect(null, "save-settings", true,
				(GLib.Callback) Peasy.Data.sync_prefs_static, this);
		}

		private Data()
		{
			sync_prefs();
		}

		~Data()
		{
			_instance = null;
		}

		/* singleton impl */
		private static weak Data _instance;
		public  static Data instance()
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
