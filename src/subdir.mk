CPPFLAGS-y      := -Ilib -DPEASY_LIBDIR=\""$(peasylibdir)"\"
CFLAGS-y        := $(PEAS_CFLAGS) $(GEANY_CFLAGS)
LDFLAGS-y       := -module -avoid-version -no-undefined
LIBS-y          := $(PEAS_LIBS) $(GEANY_LIBS)
DEPS-y          := lib/libpeasy.la lib/peasy.h

plugins-y       := peasy-plugin.la
