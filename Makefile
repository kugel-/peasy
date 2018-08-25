include autoconf.mk
include initvars.mk

include gen-vala.mk
include gen-gir.mk
include gen-vapigen.mk
include kmake/gen-sed.mk
include kmake/gen-cat.mk

KM_CPPFLAGS += -I.

extra-libs              = plugins
plugins-dir             = $(plugindir)
plugins-suffix          = .c

extra-data              = plugindata
plugindata-dir          = $(plugindatadir)

dist-y                 := AUTHORS COPYING ChangeLog INSTALL NEWS README.md
dist-y                 += autoconf.mk.in autogen.sh configure.ac
dist-y                 += gen-gir.mk gen-vala.mk gen-vapigen.mk initvars.mk
dist-y                 += m4/geany.m4 m4/gtk.m4 m4/mingw.m4 m4/vapigen.m4
dist-y                 += Makefile

# Generated files
dist-y                 += configure
dist-y                 += config.h.in
dist-y                 += m4/intltool.m4
dist-y                 += m4/libtool.m4
dist-y                 += m4/ltoptions.m4
dist-y                 += m4/ltsugar.m4
dist-y                 += m4/ltversion.m4
dist-y                 += m4/lt~obsolete.m4
dist-y                 += build-aux/config.guess
dist-y                 += build-aux/config.sub
dist-y                 += build-aux/install-sh
dist-y                 += build-aux/ltmain.sh

distclean-y            := autoconf.mk
distclean-y            += config.h config.log config.status
distclean-y            += $(wildcard autom4te.cache/*)

include kmake/kmake.mk
