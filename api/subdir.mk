extra-data                       := girdata vapidata pyoverrides

GTK_GIR = Gtk-$(GP_GTK_VERSION_MAJOR).0

GIR_SCANFLAGS-y                   = --accept-unprefixed
GIR_SCANFLAGS-y                  += --c-include=geanyplugin.h
GIR_SCANFLAGS-y                  += --external-library
GIR_LIB-y                        := geany
GIR_CFLAGS-y                     := $(GTK_CFLAGS) -DG_IR_SCANNING $(GEANY_CFLAGS)

VAPIGEN_DEPS-y                   := gio-2.0 gtk+-3.0
VAPIGEN_GIRDIRS-y                := $(objdir)
VAPIGEN_VAPIDIRS-y               := $(objdir)
VAPIGEN_METADATADIRS-y           := $(srcdir)
INTROSPECTION_COMPILER_ARGS-y    := --includedir $(objdir)

sed-y                            := geany-sciwrappers-gtkdoc-tmp.h geany-gtkdoc-tmp.h
sed-y                            += GeanyScintilla-1.0.gir Geany-1.0.gir

# workaround buggy debian packages that forgot to ship the headers
# luckily currently there are only two relevant API versions affected
# 235 used by Debian 10 and Ubuntu 18.04, and 239 used by Debian 11 and
# Ubuntu 20.04-21.04. hyperair says from now on the packages are fixed.
ifeq ($(wildcard $(geany_includedir)/gtkdoc/geany-gtkdoc.h),)
# fallback to shipped headers
API_V := $(shell echo GEANY_API_VERSION | cpp $(GEANY_CFLAGS) -include plugindata.h - | tail -n1)
$(info INFO: Using fallback headers from $(srcdir)gtkdoc_h/$(API_V))
geany_gtkdoc_h     := gtkdoc_h/$(API_V)/geany-gtkdoc.h
geany_sci_gtkdoc_h := gtkdoc_h/$(API_V)/geany-sciwrappers-gtkdoc.h
else
geany_gtkdoc_h     := $(geany_includedir)/gtkdoc/geany-gtkdoc.h
geany_sci_gtkdoc_h := $(geany_includedir)/gtkdoc/geany-sciwrappers-gtkdoc.h
endif

geany-sciwrappers-gtkdoc-tmp.h-y := $(geany_sci_gtkdoc_h)
geany-sciwrappers-gtkdoc-tmp.h-SED_SCRIPT-y := 's,sci_,scintilla_object__GI__MARK_,g'

geany-gtkdoc-tmp.h-y             := $(geany_gtkdoc_h)
geany-gtkdoc-tmp.h-SED_SCRIPT-y  := 's,\(document_\)new\(_file\),\1_GI__WORKAROUNDNEW_\2,g'

gir-y                            := GeanyScintilla-1.0-tmp.gir Geany-1.0-tmp.gir

GeanyScintilla-1.0-tmp.gir-y                  := $(geany_includedir)/scintilla/Sci_Position.h
GeanyScintilla-1.0-tmp.gir-y                  += $(geany_includedir)/scintilla/Scintilla.h
GeanyScintilla-1.0-tmp.gir-y                  += $(geany_includedir)/scintilla/ScintillaWidget.h
GeanyScintilla-1.0-tmp.gir-y                  += $(geany_includedir)/scintilla/SciLexer.h
GeanyScintilla-1.0-tmp.gir-y                  += geany-sciwrappers-gtkdoc-tmp.h
GeanyScintilla-1.0-tmp.gir-GIR_NAMESPACE-y    := GeanyScintilla
GeanyScintilla-1.0-tmp.gir-GIR_VERSION-y      := 1.0
GeanyScintilla-1.0-tmp.gir-GIR_INCLUDES-y     := $(GTK_GIR) GLib-2.0 GObject-2.0
GeanyScintilla-1.0-tmp.gir-GIR_CFLAGS-y       := -include gtk/gtk.h -Dsptr_t=gintptr -Duptr_t=guintptr -Dptrdiff_t=gintptr

Geany-1.0-tmp.gir-y                  := geany-gtkdoc-tmp.h
Geany-1.0-tmp.gir-y                  += GeanyScintilla-1.0.gir
Geany-1.0-tmp.gir-GIR_NAMESPACE-y    := Geany
Geany-1.0-tmp.gir-GIR_VERSION-y      := 1.0
Geany-1.0-tmp.gir-GIR_INCLUDES-y     := $(GTK_GIR) GLib-2.0 GObject-2.0
Geany-1.0-tmp.gir-GIR_CFLAGS-y       := -DScintillaObject=GeanyScintillaScintillaObject
Geany-1.0-tmp.gir-GIR_SCANFLAGS-y    := --include-uninstalled=$(objdir)GeanyScintilla-1.0.gir

GeanyScintilla-1.0.gir-y             := GeanyScintilla-1.0-tmp.gir
GeanyScintilla-1.0.gir-SED_SCRIPT-y  := 's,scintilla_object__GI__MARK_,sci_,g'
GeanyScintilla-1.0.gir-SED_SCRIPT-y  += 's,_GI__MARK_,,g'
Geany-1.0.gir-y                      := Geany-1.0-tmp.gir
Geany-1.0.gir-SED_SCRIPT-y           := 's,GeanyScintillaScintillaObject,ScintillaObject,g'
Geany-1.0.gir-SED_SCRIPT-y           += 's,_GI__WORKAROUNDNEW_,new,g'

girdata-dir                          := $(datadir)/gir-1.0
girdata-y                            := GeanyScintilla-1.0.gir Geany-1.0.gir

typelib-y                            := Geany-1.0.typelib GeanyScintilla-1.0.typelib

typelibdata-y                        := Geany-1.0.typelib GeanyScintilla-1.0.typelib

pyoverrides-y                        := pyoverrides/Geany.py pyoverrides/__init__.py
pyoverrides-dir                      := $(peasylibdir)/python/gi/overrides

vapigen-y                            := geany-1.0.vapi geany-scintilla-tmp-1.0.vapi
geany-1.0.vapi-y                     := Geany-1.0.gir Geany-1.0-custom.vala
geany-scintilla-tmp-1.0.vapi-y       := GeanyScintilla-1.0.gir

sed-y                                += geany-1.0.deps geany-scintilla-tmp-1.0.deps

geany-1.0.deps-y                     := geany-1.0.deps.in
geany-1.0.deps-SED_SCRIPT-y          := s,@GP_GLIB_PACKAGE@,$(GP_GLIB_PACKAGE),
geany-1.0.deps-SED_SCRIPT-y          += s,@GP_GTK_PACKAGE@,$(GP_GTK_PACKAGE),

geany-scintilla-tmp-1.0.deps-y       := geany-scintilla-tmp-1.0.deps.in
geany-scintilla-tmp-1.0.deps-SED_SCRIPT-y := s,@GP_GLIB_PACKAGE@,$(GP_GLIB_PACKAGE),
geany-scintilla-tmp-1.0.deps-SED_SCRIPT-y += s,@GP_GTK_PACKAGE@,$(GP_GTK_PACKAGE),

cat-y                                := geany-scintilla-1.0.deps geany-scintilla-1.0.vapi

geany-scintilla-1.0.deps-y           := geany-scintilla-tmp-1.0.deps
geany-scintilla-1.0.vapi-y           := gintptr.vapi geany-scintilla-tmp-1.0.vapi

vapidata-y                           := geany-1.0.vapi geany-scintilla-1.0.vapi
vapidata-y                           += geany-1.0.deps geany-scintilla-1.0.deps
vapidata-dir                         := $(vapidir)

api/geany-scintilla-tmp-1.0.vapi: api/geany-scintilla-1.0.deps
api/geany-1.0.vapi: api/geany-scintilla-1.0.vapi api/geany-1.0.deps

dist-y                               := Geany-1.0.metadata
# Fix up dist targets for files generated by configure
dist-y                               += geany-1.0.deps.in geany-scintilla-tmp-1.0.deps.in
nodist-y                             += geany-1.0.deps geany-scintilla-tmp-1.0.deps

distclean-y                          := geany-1.0.deps geany-scintilla-tmp-1.0.deps
