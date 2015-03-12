plugindir = @GEANY_PLUGINDIR@

plugin_LTLIBRARIES = peasy.la

peasy_la_SOURCES = peasy.c
peasy_la_CFLAGS  = @PEAS_CFLAGS@ @GEANY_CFLAGS@
peasy_la_LDFLAGS = -module -avoid-version -no-undefined
peasy_la_LIBADD  = @PEAS_LIBS@ @GEANY_LIBS@
