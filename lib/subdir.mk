libs-y      := libpeasy.la

SHLIB-y        := libpeasy.so.0
SHLIB-$(MINGW) := libpeasy-0.dll

VALAFLAGS-y    := --pkg libpeas-1.0 --pkg geany-1.0
VALAFLAGS-y    += --pkg geany-scintilla-1.0 --pkg posix
VALAFLAGS-y    += --vapidir api --girdir api
VALAFLAGS-y    += --target-glib=2.48
VALAFLAGS-y    += --shared-library=$(SHLIB-y)

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

fast_vapi-y             := $(VALAFILES:.vala=.vapi)

vala-y                  := $(VALAFILES:.vala=.c)

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
