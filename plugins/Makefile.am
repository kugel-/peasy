include $(top_srcdir)/initvars.mk

plugin_LTLIBRARIES += libpeasytest.la

libpeasytest_la_SOURCES = peasytest.c
libpeasytest_la_CFLAGS  = $(PEAS_CFLAGS) $(GEANY_CFLAGS) -I$(top_srcdir)/lib
libpeasytest_la_LDFLAGS = -module -avoid-version -no-undefined
libpeasytest_la_LIBADD  = $(PEAS_LIBS) $(GEANY_LIBS) $(top_builddir)/lib/libpeasy.la

dist_plugin_DATA  += peasytest.plugin \
                     console-peasy.py console-peasy.plugin \
                     modeline.py modeline.plugin \
                     peasypytest.py peasypytest.plugin \
                     goto.py goto.plugin

plugingotodatadir = $(plugindatadir)/goto
dist_plugingotodata_DATA = goto.glade
