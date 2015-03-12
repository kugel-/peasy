dnl Process this file with autoconf to produce a configure script.

AC_PREREQ([2.60])

AC_INIT([peasy],[0.1],[kugel@rockbox.org])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_SRCDIR([src/peasy.c])
AC_CONFIG_MACRO_DIR([m4])
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

AC_CONFIG_FILES([Makefile src/Makefile])
AC_OUTPUT
