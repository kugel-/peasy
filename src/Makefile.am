plugindir = @GEANY_PLUGINDIR@
plugindatadir = @GEANY_PLUGINDIR@

plugin_LTLIBRARIES = peasy.la libpeasytest.la

peasy_la_SOURCES = peasy.c
peasy_la_CFLAGS  = @PEAS_CFLAGS@ @GEANY_CFLAGS@
peasy_la_LDFLAGS = -module -avoid-version -no-undefined
peasy_la_LIBADD  = @PEAS_LIBS@ @GEANY_LIBS@

libpeasytest_la_SOURCES = peasytest.c
libpeasytest_la_CFLAGS  = @PEAS_CFLAGS@ @GEANY_CFLAGS@
libpeasytest_la_LDFLAGS = -module -avoid-version -no-undefined
libpeasytest_la_LIBADD  = @PEAS_LIBS@ @GEANY_LIBS@

nobase_dist_plugin_DATA = peasytest.plugin
