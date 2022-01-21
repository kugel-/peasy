include autoconf.mk
include initvars.mk

include gen-vala.mk
include gen-gir.mk
include gen-vapigen.mk
include kmake/gen-sed.mk
include kmake/gen-cat.mk

export INTROSPECTION_SCANNER

KM_CPPFLAGS += -I.

extra-libs              = plugins
plugins-dir             = $(plugindir)
plugins-suffix          = .c

peasylibdir            := $(plugindir)/peasy

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
dist-y                 += m4/codeset.m4
dist-y                 += m4/extern-inline.m4
dist-y                 += m4/fcntl-o.m4
dist-y                 += m4/gettext.m4
dist-y                 += m4/glibc21.m4
dist-y                 += m4/glibc2.m4
dist-y                 += m4/iconv.m4
dist-y                 += m4/intdiv0.m4
dist-y                 += m4/intldir.m4
dist-y                 += m4/intl.m4
dist-y                 += m4/intlmacosx.m4
dist-y                 += m4/intmax.m4
dist-y                 += m4/inttypes_h.m4
dist-y                 += m4/inttypes-pri.m4
dist-y                 += m4/lcmessage.m4
dist-y                 += m4/lib-ld.m4
dist-y                 += m4/lib-link.m4
dist-y                 += m4/lib-prefix.m4
dist-y                 += m4/libtool.m4
dist-y                 += m4/lock.m4
dist-y                 += m4/longlong.m4
dist-y                 += m4/lt~obsolete.m4
dist-y                 += m4/ltoptions.m4
dist-y                 += m4/ltsugar.m4
dist-y                 += m4/ltversion.m4
dist-y                 += m4/nls.m4
dist-y                 += m4/po.m4
dist-y                 += m4/printf-posix.m4
dist-y                 += m4/progtest.m4
dist-y                 += m4/size_max.m4
dist-y                 += m4/stdint_h.m4
dist-y                 += m4/threadlib.m4
dist-y                 += m4/uintmax_t.m4
dist-y                 += m4/visibility.m4
dist-y                 += m4/wchar_t.m4
dist-y                 += m4/wint_t.m4
dist-y                 += m4/xsize.m4
dist-y                 += build-aux/config.guess
dist-y                 += build-aux/config.sub
dist-y                 += build-aux/config.rpath
dist-y                 += build-aux/install-sh
dist-y                 += build-aux/ltmain.sh

distclean-y            := autoconf.mk
distclean-y            += config.h config.log config.status
distclean-y            += $(wildcard autom4te.cache/*)

include kmake/kmake.mk
