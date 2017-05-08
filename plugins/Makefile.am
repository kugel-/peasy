include $(top_srcdir)/initvars.mk

plugin_LTLIBRARIES += libpeasytest.la

libpeasytest_la_SOURCES = peasytest.c
libpeasytest_la_CFLAGS  = $(PEAS_CFLAGS) $(GEANY_CFLAGS) -I$(top_srcdir)/lib
libpeasytest_la_LDFLAGS = -module -avoid-version -no-undefined
libpeasytest_la_LIBADD  = $(PEAS_LIBS) $(GEANY_LIBS) $(top_builddir)/lib/libpeasy.la

PLUGIN_INFO      = peasytest.plugin \
                   console-peasy.plugin \
                   doxygen-helper.plugin \
                   modeline.plugin \
                   peasyluatest.plugin \
                   peasypytest.plugin \
                   quickswitch.plugin

plugin_DATA     += $(PLUGIN_INFO)

dist_plugin_DATA+= console-peasy.py  \
                   doxygen-helper.py  \
                   modeline.py  \
                   peasyluatest.lua  \
                   peasypytest.py  \
                   quickswitch.py

EXTRA_DIST += ${PLUGIN_INFO:.plugin=.plugin.desktop.in}

pluginquickswitchdatadir = $(plugindatadir)/quickswitch
dist_pluginquickswitchdata_DATA = quickswitch.glade

doxyhelperdatadir = $(plugindatadir)/doxygen-helper
dist_doxyhelperdata_DATA = doxygen-helper.glade

SUFFIXES = .plugin .plugin.desktop.in
# TODO: wildcard dependency on *.po in a portable fashion
$(PLUGIN_INFO): $(INTLTOOL_MERGE) $(top_srcdir)/po/de.po

CLEANFILES += $(PLUGIN_INFO)

.plugin.desktop.in.plugin:
	$(INTLTOOL_V_MERGE)LC_ALL=C $(INTLTOOL_MERGE)     \
			$(INTLTOOL_V_MERGE_OPTIONS) -d -u -c           \
			$(top_builddir)/po/.intltool-merge-cache       \
			$(top_srcdir)/po $< $@
