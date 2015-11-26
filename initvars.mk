CLEANFILES              =
noinst_PROGRAMS         =
lib_LTLIBRARIES         =
plugin_LTLIBRARIES      =

plugindir               = @GEANY_PLUGINDIR@
plugindatadir           = @GEANY_PLUGINDIR@
geany_includedir        = @GEANY_INCLUDEDIR@/geany

girdir                  = $(datadir)/gir-1.0
gir_DATA                =
dist_gir_DATA           =
vapidir                 = $(datadir)/vala/vapi
vapi_DATA               =
dist_vapi_DATA          =
typelibdir              = $(libdir)/girepository-1.0
typelib_DATA            =
dist_typelib_DATA       =
dist_plugin_DATA        =

INTROSPECTION_COMPILER_ARGS = --includedir=$(girdir)

if HAVE_INTROSPECTION
include $(INTROSPECTION_MAKEFILE)
endif
