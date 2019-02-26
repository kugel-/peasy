
AC_PREREQ([2.60])
AC_INIT([foobar],[0.1])

AC_CONFIG_SRCDIR([autoconf.mk.in])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AC_DEFUN([KMAKE_COND], [
    if $2 ; then
        TMP_Y=y
        TMP_N=n
    else
        TMP_Y=n
        TMP_N=y
    fi
    TMP=$(printf "%s=%s\n%s=%s\n" $1 $TMP_Y NOT_$1 $TMP_N)
    AC_SUBST([$1_COND],[$TMP])
])

LT_INIT

AC_CONFIG_HEADERS([config.h])

AC_PROG_CC
AC_PROG_INSTALL

KMAKE_COND([HAVE_FOO],[true])

AC_CONFIG_FILES([autoconf.mk Makefile])

AC_OUTPUT
