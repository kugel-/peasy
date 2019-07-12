libs-y      := libpeasy.la

SHLIB-y        := libpeasy.so.0
SHLIB-$(MINGW) := libpeasy-0.dll

VALAFLAGS-y    := --pkg libpeas-1.0 --pkg posix --pkg gtk+-3.0
VALAFLAGS-y    += --girdir api
VALAFLAGS-y    += --target-glib=2.48
VALAFLAGS-y    += --shared-library=$(SHLIB-y)

INTROSPECTION_COMPILER_ARGS-y := --includedir api

CFLAGS-y    := $(GTK_CFLAGS) $(PEAS_CFLAGS) $(GEANY_CFLAGS)
LDFLAGS-y   := -no-undefined
LIBS-y      := $(GTK_LIBS) $(GEANY_LIBS)

VALAFILES     := plugin.vala
VALAFILES     += document.vala
VALAFILES     += editor.vala
VALAFILES     += peasyobject.vala
VALAFILES     += filetype.vala
VALAFILES     += keygroup.vala
VALAFILES     += tags.vala

# Generate secondary outputs only once, not for all .vala files
plugin.c-VALAFLAGS-y    := --disable-version-header -H $(objdir)peasy.h
plugin.c-VALAFLAGS-y    += --library libpeasy --gir=$(objdir)Peasy-0.1.gir
plugin.c-VALAFLAGS-y    += --vapi=$(objdir)libpeasy-0.1.vapi

vala-y                  := $(VALAFILES:.vala=.c)

plugin.c-y              := $(VALAFILES)
plugin.c-DEPS-y         := api/geany-1.0.vapi api/geany-scintilla-1.0.vapi
document.c-y            := $(VALAFILES)
document.c-DEPS-y       := api/geany-1.0.vapi api/geany-scintilla-1.0.vapi
editor.c-y              := $(VALAFILES)
editor.c-DEPS-y         := api/geany-1.0.vapi api/geany-scintilla-1.0.vapi
peasyobject.c-y         := $(VALAFILES)
peasyobject.c-DEPS-y    := api/geany-1.0.vapi api/geany-scintilla-1.0.vapi
filetype.c-y            := $(VALAFILES)
filetype.c-DEPS-y       := api/geany-1.0.vapi api/geany-scintilla-1.0.vapi
keygroup.c-y            := $(VALAFILES)
keygroup.c-DEPS-y       := api/geany-1.0.vapi api/geany-scintilla-1.0.vapi
tags.c-y                := $(VALAFILES)
tags.c-DEPS-y           := api/geany-1.0.vapi api/geany-scintilla-1.0.vapi

byproduct-y             := peasy.h Peasy-0.1.gir libpeasy-0.1.vapi
peasy.h-y               := plugin.c
Peasy-0.1.gir-y         := plugin.c
libpeasy-0.1.vapi-y     := plugin.c

libpeasy.la-y := keygroup_c.c
libpeasy.la-y += plugin_c.c
libpeasy.la-y += $(VALAFILES:.vala=.c)
libpeasy.la-y += peasy.h

typelib-y     := Peasy-0.1.typelib
typelibdata-y := Peasy-0.1.typelib
