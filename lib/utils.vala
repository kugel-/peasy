using GLib;
using Geany;

namespace Peasy
{
    /* TODO: A proper UiWidgets class, but GI does not support static fields at all so
     * it's moot (access via GeanyGI.Data) */
    public class UiUtils : GLib.Object
    {
        public static Gtk.Widget button_new_with_image(string stock_id, string text)
        {
            return Geany.UiUtils.button_new_with_image(stock_id, text);
        }

        public static Gtk.Widget image_menu_item_new(string stock_id, string label)
        {
                return Geany.UiUtils.image_menu_item_new(stock_id, label);
        }

        public static Gtk.Widget path_box_new(string? title, Gtk.FileChooserAction action, Gtk.Entry entry)
        {
            return Geany.UiUtils.path_box_new(title, action, entry);
        }

        public static Gtk.Widget dialog_vbox_new(Gtk.Dialog dialog)
        {
            return Geany.UiUtils.dialog_vbox_new(dialog);
        }

//~         public static Gtk.Widget frame_new_with_alignment(string label_text, out Gtk.Widget alignment)
//~         {
//~             return Geany.UiUtils.frame_new_with_alignment(label_text, out alignment);
//~         }

        public static void add_document_sensitive(Gtk.Widget widget)
        {
            Geany.UiUtils.add_document_sensitive(widget);
        }

//~         public static void menu_add_document_items(Gtk.Menu menu, Document? active, GLib.Callback cb)
//~         {
//~             Geany.UiUtils.menu_add_document_items(menu, active._doc, cb);
//~         }

        public unowned Gtk.Widget? lookup_widget(Gtk.Widget widget, string widget_name)
        {
            return Geany.UiUtils.lookup_widget(widget, widget_name);
        }

//~         public void hookup_widget(Gtk.Widget owner, Gtk.Widget widget, string name)
//~         {
//~             Geany.UiUtils.hookup_widget(owner, widget, name);
//~         }
    }
}
