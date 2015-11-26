
#include "peasy.h"

/* Copied from a valac generated marshaller */
static void cclosure_marshal_BOOLEAN__INT (GClosure * closure,
                                             GValue * return_value,
                                             guint n_param_values,
                                             const GValue * param_values,
                                             gpointer invocation_hint,
                                             gpointer marshal_data)
{
	typedef gboolean (*GMarshalFunc_BOOLEAN__INT) (gpointer data1, gint arg_1, gpointer data2);
	register GMarshalFunc_BOOLEAN__INT callback;
	register GCClosure * cc;
	register gpointer data1;
	register gpointer data2;
	gboolean v_return;
	cc = (GCClosure *) closure;
	g_return_if_fail (return_value != NULL);
	g_return_if_fail (n_param_values == 2);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_BOOLEAN__INT) (marshal_data ? marshal_data : cc->callback);
	v_return = callback (data1, g_value_get_int (param_values + 1), data2);
	g_value_set_boolean (return_value, v_return);
}


void peasy_key_binding_setup_signal_activate(void)
{
	g_signal_new("activate", PEASY_TYPE_KEY_BINDING, G_SIGNAL_RUN_LAST,
		offsetof(PeasyKeyBindingClass, default_handler),
		g_signal_accumulator_true_handled,
		NULL, cclosure_marshal_BOOLEAN__INT,
		G_TYPE_BOOLEAN, 1, G_TYPE_INT);
}


void peasy_key_group_setup_signal_activate(void)
{
	g_signal_new("activate", PEASY_TYPE_KEY_GROUP, G_SIGNAL_RUN_LAST,
		offsetof(PeasyKeyGroupClass, default_handler),
		g_signal_accumulator_true_handled,
		NULL, cclosure_marshal_BOOLEAN__INT,
		G_TYPE_BOOLEAN, 1, G_TYPE_INT);
}
