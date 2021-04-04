dnl Process this file with autoconf to produce a configure script.

AC_PREREQ([2.60])

AC_INIT([peasy],[0.11],[kugel@rockbox.org])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([src/peasy-plugin.c])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])

AC_SUBST([PACKAGE],[$PACKAGE_NAME])
AC_SUBST([VERSION],[$PACKAGE_VERSION])

LT_INIT

AC_PROG_INSTALL
AC_PROG_MKDIR_P

AC_PROG_CC
AM_PROG_CC_C_O
AM_PROG_VALAC([0.30],[],[AC_MSG_ERROR([suitable valac is required])])

IT_PROG_INTLTOOL([0.40.0])
AC_SUBST([GETTEXT_PACKAGE], ["peasy"])
AC_DEFINE([GETTEXT_PACKAGE], ["peasy"], [Gettext package.])

AC_SUBST([install_sh], ["`pwd`/build-aux/install-sh"])

GP_CHECK_GEANY([1.28])
GP_CHECK_GTK_VERSION
CHECK_MINGW

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

AM_GLIB_DEFINE_LOCALEDIR([LOCALEDIR])

GOBJECT_INTROSPECTION_CHECK([1.30.0])
VAPIGEN_CHECK([0.32])

AM_PATH_PYTHON([2.7])

AC_CONFIG_FILES([
	autoconf.mk
	api/geany-1.0.deps
	api/geany-scintilla-tmp-1.0.deps
	po/Makefile.in])
AC_OUTPUT
