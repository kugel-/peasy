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
plugin.c-VALAFLAGS-y    := --disable-version-header -H lib/peasy.h
plugin.c-VALAFLAGS-y    += --library libpeasy --gir=lib/Peasy-0.0.gir
plugin.c-VALAFLAGS-y    += --vapi=lib/libpeasy-0.1.vapi

vala-y                  := $(VALAFILES:.vala=.c)

get_fast_vapi = $(addprefix $(srcdir),$(patsubst %.vala,%.vapi,$(filter-out $2,$1)))

plugin.c-y              := plugin.vala
plugin.c-FAST_VAPI-y    := $(call get_fast_vapi,$(VALAFILES),plugin.vala)
plugin.c-DEPS-y         := api/geany-1.0.vapi api/geany-scintilla-1.0.vapi
document.c-y            := document.vala
document.c-FAST_VAPI-y  := $(call get_fast_vapi,$(VALAFILES),document.vala)
document.c-DEPS-y       := api/geany-1.0.vapi api/geany-scintilla-1.0.vapi
editor.c-y              := editor.vala
editor.c-FAST_VAPI-y    := $(call get_fast_vapi,$(VALAFILES),editor.vala)
editor.c-DEPS-y         := api/geany-1.0.vapi api/geany-scintilla-1.0.vapi
peasyobject.c-y         := peasyobject.vala
peasyobject.c-FAST_VAPI-y := $(call get_fast_vapi,$(VALAFILES),peasyobject.vala)
peasyobject.c-DEPS-y    := api/geany-1.0.vapi api/geany-scintilla-1.0.vapi
filetype.c-y            := filetype.vala
filetype.c-FAST_VAPI-y  := $(call get_fast_vapi,$(VALAFILES),filetype.vala)
filetype.c-DEPS-y       := api/geany-1.0.vapi api/geany-scintilla-1.0.vapi
keygroup.c-y            := keygroup.vala
keygroup.c-FAST_VAPI-y  := $(call get_fast_vapi,$(VALAFILES),keygroup.vala)
keygroup.c-DEPS-y       := api/geany-1.0.vapi api/geany-scintilla-1.0.vapi
tags.c-y                := tags.vala
tags.c-FAST_VAPI-y      := $(call get_fast_vapi,$(VALAFILES),tags.vala)
tags.c-DEPS-y           := api/geany-1.0.vapi api/geany-scintilla-1.0.vapi

byproduct-y             := peasy.h Peasy-0.0.gir libpeasy-0.1.vapi
peasy.h-y               := plugin.c
Peasy-0.0.gir-y         := plugin.c
libpeasy-0.1.vapi-y     := plugin.c

libpeasy.la-y := keygroup_c.c
libpeasy.la-y += plugin_c.c
libpeasy.la-y += $(VALAFILES:.vala=.c)
libpeasy.la-y += peasy.h

# workaround some buggy versions of valac that generate incorrect
# GIR for callbacks. See https://gitlab.gnome.org/GNOME/vala/-/issues/1167
sed-y         := Peasy-0.1.gir
Peasy-0.1.gir-y := Peasy-0.0.gir
Peasy-0.1.gir-SED_SCRIPT-y := '/<callback/{:a;N;/<\/callback\>/!ba;s/instance-parameter/parameter/g}'
Peasy-0.1.gir-SED_SCRIPT-y += 's/version="0.0"/version="0.1"/'

typelib-y     := Peasy-0.1.typelib
typelibdata-y := Peasy-0.1.typelib
