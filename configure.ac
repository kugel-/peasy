dnl Process this file with autoconf to produce a configure script.

AC_PREREQ([2.60])

AC_INIT([peasy],[0.1],[kugel@rockbox.org])
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
AM_PROG_VALAC(0.29.3)

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

PKG_CHECK_MODULES([GEANY], [geany >= 1.24])
AC_SUBST([GEANY_CFLAGS])
AC_SUBST([GEANY_LIBS])

geany_prefix=`$PKG_CONFIG --variable prefix geany`
GEANY_PLUGINDIR="$geany_prefix/lib/geany"
GEANY_VAPIDIR="$geany_prefix/share/vala/vapi"
AC_SUBST([GEANY_PLUGINDIR])
AC_SUBST([GEANY_VAPIDIR])
AC_DEFINE_UNQUOTED([GEANY_PLUGINDIR],["$GEANY_PLUGINDIR"],[Path to Geany plugin])

GEANY_INCLUDEDIR=`$PKG_CONFIG --variable includedir geany`
AC_SUBST([GEANY_INCLUDEDIR])

VAPIGEN_CHECK

AC_CONFIG_FILES([
	Makefile
	src/Makefile
	src/peasy/Makefile])
AC_OUTPUT
