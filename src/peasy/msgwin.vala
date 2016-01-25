/* Part of Geany but not in the vapi (not introspectable) */
extern void msgwin_compiler_add(int msg_color, string msg, ...);
extern void msgwin_status_add(string msg, ...);

namespace Peasy
{

public class MsgWindow : Object
{
	private MsgWindow() { }
	private static MsgWindow instance;

	public static MsgWindow getMsgWindow()
	{
		if (instance == null)
			instance  = new MsgWindow();

		return instance;
	}

	public void clear_tab(int tab)
	{
		Geany.msgwin_clear_tab(tab);
	}

	public void compiler_add(int msg_color, string msg, ...)
	{
		var ap = va_list();
		string s = msg.vprintf(ap);
		msgwin_compiler_add(msg_color, s);
	}

	public void compiler_add_string(int msg_color, string msg)
	{
		msgwin_compiler_add(msg_color, msg);
	}

	public void set_messages_dir(string messages_dir)
	{
		Geany.msgwin_set_messages_dir(messages_dir);
	}

	public void status_add(string msg, ...)
	{
		var ap = va_list();
		string s = msg.vprintf(ap);
		msgwin_status_add(s);
	}

	public void status_add_string(string msg)
	{
		msgwin_status_add(msg);
	}

	public void switch_tab (int tabnum, bool show)
	{
		Geany.msgwin_switch_tab(tabnum, show);
	}
}

}
