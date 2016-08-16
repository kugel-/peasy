#if VALA_0_30 && !VALA_0_32
/* Temporary g(u)intptr definition until vapigen-0.32 is common enough */
[SimpleType]
[GIR (name = "gulong")]
[CCode (cname = "guintptr", cheader_filename = "glib.h", type_id = "G_TYPE_ULONG", marshaller_type_name = "ULONG", get_value_function = "g_value_get_ulong", set_value_function = "g_value_set_ulong", default_value = "0UL")]
[IntegerType (rank = 9)]
public struct uintptr {
	[CCode (cname = "0UL")]
	public const ulong MIN;
	[CCode (cname = "G_MAXSIZE")]
	public const ulong MAX;

	[CCode (cname = "G_GUINTPTR_FORMAT")]
	public const string FORMAT;
	[CCode (cname = "G_GINTPTR_MODIFIER")]
	public const string FORMAT_MODIFIER;

	[CCode (cname = "g_strdup_printf", instance_pos = -1)]
	public string to_string (string format = "%" + FORMAT);

	[CCode (cname = "GSIZE_TO_POINTER")]
	public void* to_pointer ();

	[CCode (cname = "MIN")]
	public static uintptr min (uintptr a, uintptr b);
	[CCode (cname = "MAX")]
	public static uintptr max (uintptr a, uintptr b);
	[CCode (cname = "CLAMP")]
	public uintptr clamp (uintptr low, uintptr high);
}

[SimpleType]
[GIR (name = "glong")]
[CCode (cname = "gintptr", cheader_filename = "glib.h", type_id = "G_TYPE_LONG", marshaller_type_name = "LONG", get_value_function = "g_value_get_long", set_value_function = "g_value_set_long", default_value = "0L")]
[IntegerType (rank = 8)]
public struct intptr {
	[CCode (cname = "G_MINSSIZE")]
	public const long MIN;
	[CCode (cname = "G_MAXSSIZE")]
	public const long MAX;

	[CCode (cname = "G_GINTPTR_FORMAT")]
	public const string FORMAT;
	[CCode (cname = "G_GINTPTR_MODIFIER")]
	public const string FORMAT_MODIFIER;

	[CCode (cname = "g_strdup_printf", instance_pos = -1)]
	public string to_string (string format = "%" + FORMAT);

	[CCode (cname = "MIN")]
	public static intptr min (intptr a, intptr b);
	[CCode (cname = "MAX")]
	public static intptr max (intptr a, intptr b);
	[CCode (cname = "CLAMP")]
	public intptr clamp (intptr low, intptr high);
}

#endif
