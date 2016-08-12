dnl Process this file with autoconf to produce a configure script.

AC_PREREQ([2.60])

AC_INIT([peasy],[0.2],[kugel@rockbox.org])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([src/peasy-plugin.c])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([1.11 -Wall parallel-tests subdir-objects])
AC_CONFIG_HEADERS([config.h])

m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

AM_PROG_AR
AC_PROG_CC
AC_PROG_CC_C99
AM_PROG_CC_C_O
AC_PROG_INSTALL
AM_PROG_LIBTOOL
AM_PROG_VALAC([0.30])
AC_PROG_MKDIR_P

IT_PROG_INTLTOOL([0.40.0])
AC_SUBST([GETTEXT_PACKAGE], ["peasy"])
AC_DEFINE([GETTEXT_PACKAGE], ["peasy"], [Gettext package.])

GP_CHECK_GTK_VERSION

gtk_modules="$GP_GTK_PACKAGE >= $GP_GTK_VERSION"
PKG_CHECK_MODULES([GTK], [$gtk_modules])
AC_SUBST([GTK_CFLAGS])
AC_SUBST([GTK_LIBS])

gir_modules="gobject-introspection-1.0 >= 1.39.0"
PKG_CHECK_MODULES([GIR], [$gir_modules])
AC_SUBST([DEPENDENCIES], [$gir_modules])
AC_SUBST([GIR_CFLAGS])
AC_SUBST([GIR_LIBS])
GOBJECT_INTROSPECTION_REQUIRE(1.39.0)

PKG_CHECK_MODULES([PEAS], [libpeas-1.0 >= 1.12.0])
AC_SUBST([PEAS_CFLAGS])
AC_SUBST([PEAS_LIBS])

GP_CHECK_GEANY([1.28])

# double eval since datarootdir is usually defined as ${prefix}/share
LOCALEDIR=$(eval echo $(eval echo $localedir))
AC_SUBST([LOCALEDIR])
AC_DEFINE_UNQUOTED([LOCALEDIR],["$LOCALEDIR"],[Where to install translations])

GOBJECT_INTROSPECTION_CHECK([1.30.0])
VAPIGEN_CHECK([0.31])

AM_PATH_PYTHON([2.7])
AC_ARG_WITH([pyoverridesdir],
    AS_HELP_STRING([--with-pyoverridesdir=PATH], [Path to install pygobjet override bindings for Geany (auto = Automatically detect) [default=auto]]),
    [pyoverridesdir="$withval"],
    [if echo $prefix | grep -q "^/home" ; then
        _pyexecdir=$(echo $prefix | sed -e 's,\(/home/[[^/]]*\).*,\1/.local,')
        _suffix=$(echo $pyexecdir | sed -e 's,\${exec_prefix}/,,')
        pyexecdir="$_pyexecdir/$_suffix"
        AC_MSG_NOTICE([Automatically detected $pyexecdir for installing local python modules])
    fi
    pyoverridesdir="$pyexecdir/gi/overrides"])

AC_MSG_NOTICE([Installing pygobjet override bindings for Geany to $pyoverridesdir])
AC_SUBST(pyoverridesdir)

AC_CONFIG_FILES([
	Makefile
	api/Makefile
	api/geany-1.0.deps
	api/geany-scintilla-1.0.deps
	lib/Makefile
	plugins/Makefile
	po/Makefile.in
	src/Makefile])
AC_OUTPUT
