include $(top_srcdir)/initvars.mk

INTROSPECTION_GIRS     += Geany-1.0-pre.gir GeanyScintilla-1.0-pre.gir
SCANNERFLAGS            = --accept-unprefixed --c-include=geanyplugin.h
SCANNERFLAGS           += --program-arg=--introspection-dump=$(srcdir)/get-type.txt,$(builddir)/get-type.out

GTK_GIR = Gtk-@GP_GTK_VERSION_MAJOR@.0

Geany_1_0_pre_gir_NAMESPACE    = Geany
Geany_1_0_pre_gir_VERSION      = 1.0
Geany_1_0_pre_gir_INCLUDES     = $(GTK_GIR) GLib-2.0 GObject-2.0
Geany_1_0_pre_gir_CFLAGS       = $(GTK_CFLAGS) -DG_IR_SCANNING $(GEANY_CFLAGS)
Geany_1_0_pre_gir_CFLAGS      += -DScintillaObject=GeanyScintillaScintillaObject
Geany_1_0_pre_gir_LIBS         = $(geany_libdir)/libgeany.la
Geany_1_0_pre_gir_FILES        = geany-gtkdoc-tmp.h
Geany_1_0_pre_gir_SCANNERFLAGS = $(SCANNERFLAGS) --include-uninstalled=GeanyScintilla-1.0.gir

GeanyScintilla_1_0_pre_gir_NAMESPACE = GeanyScintilla
GeanyScintilla_1_0_pre_gir_VERSION   = 1.0
GeanyScintilla_1_0_pre_gir_INCLUDES  = $(GTK_GIR) GLib-2.0 GObject-2.0
GeanyScintilla_1_0_pre_gir_CFLAGS    = $(GTK_CFLAGS) -DG_IR_SCANNING $(GEANY_CFLAGS) -include gtk/gtk.h
GeanyScintilla_1_0_pre_gir_LIBS      = $(geany_libdir)/libgeany.la
GeanyScintilla_1_0_pre_gir_FILES     = $(geany_includedir)/scintilla/ScintillaWidget.h \
									   $(geany_includedir)/scintilla/Scintilla.h \
									   $(geany_includedir)/scintilla/SciLexer.h \
									   geany-sciwrappers-gtkdoc-tmp.h
GeanyScintilla_1_0_pre_gir_SCANNERFLAGS = $(SCANNERFLAGS)

VAPIGEN_VAPIS          += geany-1.0.vapi geany-scintilla-1.0.vapi

geany_1_0_vapi_METADATADIRS    = %D%
geany_1_0_vapi_GIR             = Geany-1.0.gir
geany_1_0_vapi_FILES           = $(geany_1_0_vapi_GIR) Geany-1.0-custom.vala
geany_1_0_vapi_VAPIDIRS        = $(builddir)/%D%

geany_scintilla_1_0_vapi_METADATADIRS = %D%
geany_scintilla_1_0_vapi_GIR          = GeanyScintilla-1.0.gir
geany_scintilla_1_0_vapi_FILES        = $(geany_scintilla_1_0_vapi_GIR)

gir_DATA               += Geany-1.0.gir GeanyScintilla-1.0.gir
typelib_DATA           += Geany-1.0.typelib GeanyScintilla-1.0.typelib
dist_vapi_DATA         += geany-1.0.vapi geany-scintilla-1.0.vapi
vapi_DATA              += geany-1.0.deps geany-scintilla-1.0.deps

geany-sciwrappers-gtkdoc-tmp.h: $(geany_includedir)/gtkdoc/geany-sciwrappers-gtkdoc.h
	$(AM_V_GEN)$(SED) \
		-e 's,sci_,scintilla_object__GI__MARK_,g' \
		$< > $@ || rm -f $@

geany-gtkdoc-tmp.h:  $(geany_includedir)/gtkdoc/geany-gtkdoc.h
	$(AM_V_GEN) $(SED) \
		-e 's,\(document_\)new\(_file\),\1_GI__WORKAROUNDNEW_\2,g' \
		$< > $@ || rm -rf $@

GeanyScintilla-1.0.gir: GeanyScintilla-1.0-pre.gir
	$(AM_V_GEN) $(SED) \
		-e 's,scintilla_object__GI__MARK_,sci_,g' \
		-e 's,_GI__MARK_,,g' \
		$< > $@ || rm -f $@

Geany-1.0.gir: Geany-1.0-pre.gir
	$(AM_V_GEN) $(SED) \
		-e 's,GeanyScintillaScintillaObject,ScintillaObject,g' \
		-e 's,_GI__WORKAROUNDNEW_,new,g' \
		$< > $@ || rm -f $@

Geany-1.0-pre.gir: GeanyScintilla-1.0.gir

geany-scintilla-1.0.vapi: geany-scintilla-1.0.deps
geany-1.0.vapi: geany-scintilla-1.0.vapi geany-1.0.deps

all-local: $(gir_DATA) $(typelib_DATA) $(vapi_DATA) $(dist_vapi_DATA)

CLEANFILES             += $(gir_DATA) $(typelib_DATA)
CLEANFILES             += Geany-1.0-pre.gir GeanyScintilla-1.0-pre.gir
CLEANFILES             += geany-sciwrappers-gtkdoc-tmp.h geany-gtkdoc-tmp.h

pyoverrides_DATA       += Geany.py

if HAVE_INTROSPECTION
include $(INTROSPECTION_MAKEFILE)
endif

if ENABLE_VAPIGEN
-include $(VAPIGEN_MAKEFILE)
endif
