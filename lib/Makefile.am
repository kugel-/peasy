include $(top_srcdir)/initvars.mk

if MINGW
SHLIB                    = libpeasy-0.dll
else
SHLIB                    = libpeasy.so.0
endif

lib_LTLIBRARIES         += libpeasy.la

libpeasy_la_VALASOURCES  = \
    plugin.vala            \
    document.vala          \
    editor.vala            \
    peasyobject.vala       \
    filetype.vala          \
    keygroup.vala          \
    tags.vala

libpeasy_la_SOURCES      = \
    $(libpeasy_la_VALASOURCES) \
    keygroup_c.c           \
    plugin_c.c

libpeasy_la_VALAFLAGS    = --pkg libpeas-1.0 --pkg geany-1.0 --pkg geany-scintilla-1.0 \
                           --pkg posix                                                 \
                           --vapidir $(top_builddir)/api --girdir $(top_builddir)/api  \
                           --library libpeasy                                          \
                           --gir=Peasy-0.1.gir --vapi=libpeasy-0.1.vapi                \
                           --disable-version-header -H peasy.h                         \
                           --shared-library=$(SHLIB)
libpeasy_la_CFLAGS       = $(GTK_CFLAGS) $(PEAS_CFLAGS) $(GEANY_CFLAGS)
libpeasy_la_LDFLAGS      = -no-undefined -version 0:0:0
libpeasy_la_LIBADD       = $(GTK_LIBS) $(GEANY_LIBS)

libpeasy_la_vala.stamp: $(top_srcdir)/api/geany-1.0.vapi $(top_srcdir)/api/geany-1.0.deps
libpeasy_la_vala.stamp: $(top_srcdir)/api/geany-scintilla-tmp-1.0.vapi $(top_srcdir)/api/geany-scintilla-tmp-1.0.deps
Peasy-0.1.gir: libpeasy.la
libpeasy-0.1.vapi: libpeasy.la

gir_DATA               += Peasy-0.1.gir
typelib_DATA           += Peasy-0.1.typelib
vapi_DATA              += libpeasy-0.1.vapi

EXTRA_DIST             += Peasy-0.1.gir libpeasy-0.1.vapi
BUILT_SOURCES          += $(libpeasy_la_VALASOURCES:.vala=.c)
CLEANFILES             += $(gir_DATA) $(typelib_DATA)

INTROSPECTION_COMPILER_ARGS += --includedir=$(top_builddir)/api

if HAVE_INTROSPECTION
include $(INTROSPECTION_MAKEFILE)
endif

valaclean:
	$(MAKE) clean
	(cd $(srcdir); rm -f $(BUILT_SOURCES) *_vala.stamp)
