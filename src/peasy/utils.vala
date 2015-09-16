using GLib;
using Geany;

namespace GeanyGI
{
	/* TODO: A proper UiWidgets class, but GI does not support static fields at all so
	 * it's moot (access via GeanyGI.Data) */
	public abstract class UiUtils
	{
		public static Gtk.Widget button_new_with_image(string stock_id, string text)
		{
			return Geany.Ui.button_new_with_image(stock_id, text);
		}

		public static Gtk.Widget image_menu_item_new(string stock_id, string label)
		{
				return Geany.Ui.image_menu_item_new(stock_id, label);
		}

		public static Gtk.Widget path_box_new(string? title, Gtk.FileChooserAction action, Gtk.Entry entry)
		{
			return Geany.Ui.path_box_new(title, action, entry);
		}

		public static Gtk.Widget dialog_vbox_new(Gtk.Dialog dialog)
		{
			return Geany.Ui.dialog_vbox_new(dialog);
		}

		public static Gtk.Widget frame_new_with_alignment(string label_text, out Gtk.Widget alignment)
		{
			return Geany.Ui.frame_new_with_alignment(label_text, out alignment);
		}

		public static void add_document_sensitive(Gtk.Widget widget)
		{
			Geany.Ui.add_document_sensitive(widget);
		}

		public static void menu_add_document_items(Gtk.Menu menu, Document? active, GLib.Callback cb)
		{
			Geany.Ui.menu_add_document_items(menu, active._doc, cb);
		}

		public unowned Gtk.Widget? lookup_widget(Gtk.Widget widget, string widget_name)
		{
			return Geany.Ui.lookup_widget(widget, widget_name);
		}

		public void hookup_widget(Gtk.Widget owner, Gtk.Widget widget, string name)
		{
			Geany.Ui.hookup_widget(owner, widget, name);
		}
	}
}
