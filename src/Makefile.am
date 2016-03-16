include $(top_srcdir)/initvars.mk

plugin_LTLIBRARIES       += peasy-plugin.la

peasy_plugin_la_SOURCES   = peasy-plugin.c
peasy_plugin_la_CPPFLAGS  = -I$(top_srcdir)/lib -DTYPELIBDIR=\""$(typelibdir)"\"
peasy_plugin_la_CFLAGS    = $(PEAS_CFLAGS) $(GEANY_CFLAGS)
peasy_plugin_la_LDFLAGS   = -module -avoid-version -no-undefined
peasy_plugin_la_LIBADD    = $(PEAS_LIBS) $(GEANY_LIBS) $(top_builddir)/lib/libpeasy.la
