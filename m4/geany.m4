AC_DEFUN([_GP_GEANY_LIBDIR],
[
    AC_REQUIRE([PKG_PROG_PKG_CONFIG])
    AC_ARG_WITH([geany-plugindir],
        AC_HELP_STRING([--with-geany-plugindir=PATH],
            [Set plugin installation path [[default=auto]]]),
        [geanypluginsdir=${withval}],
        [geanypluginsdir=$(${PKG_CONFIG} --variable=libdir geany)/geany])
])

dnl GP_GEANY_PKG_CONFIG_PATH_PUSH
dnl Updates PKG_CONFIG_PATH to include the appropriate directory to match
dnl --with-geany-plugindir option. This is useful when calling PKG_CONFIG on
dnl the geany package but should be avoided for any other package. Note:
dnl This assumes geanyplugindir looks like $some_prefix/lib/geany, thus
dnl $some_prefix/lib/pkgconfig is set. This doesn't work when geanyplugindir
dnl points to $HOME/.config/geany/plugins but this doesn't hurt as
dnl $HOME/.config/geany/pkgconfig is really unlikely to even exist.
dnl Call GP_GEANY_PKG_CONFIG_PATH_POP to undo the action
AC_DEFUN([GP_GEANY_PKG_CONFIG_PATH_PUSH],
[
    AC_REQUIRE([_GP_GEANY_LIBDIR])
    export PKG_CONFIG_PATH="$geanypluginsdir/../pkgconfig:$PKG_CONFIG_PATH"
])

dnl GP_GEANY_PKG_CONFIG_PATH_POP
dnl Undoes what GP_GEANY_PKG_CONFIG_PATH_PUSH did
AC_DEFUN([GP_GEANY_PKG_CONFIG_PATH_POP],
[
    AC_REQUIRE([_GP_GEANY_LIBDIR])
    export PKG_CONFIG_PATH="${PKG_CONFIG_PATH#*:}"
    test -z "${PKG_CONFIG_PATH}" && unset PKG_CONFIG_PATH
])

AC_DEFUN([GP_CHECK_GEANY],
[
    AC_REQUIRE([PKG_PROG_PKG_CONFIG])

    GP_GEANY_PKG_CONFIG_PATH_PUSH

    PKG_CHECK_MODULES([GEANY], [geany >= $1])
    GEANY_VERSION=$(${PKG_CONFIG} --modversion geany)
    AC_SUBST([GEANY_VERSION])

    GEANY_INCLUDEDIR=`$PKG_CONFIG --variable includedir geany`
    AC_SUBST([GEANY_INCLUDEDIR])

    GEANY_DATADIR=`$PKG_CONFIG --variable datadir geany`
    AC_SUBST([GEANY_DATADIR])

    GEANY_LIBDIR=`$PKG_CONFIG --variable libdir geany`
    AC_SUBST([GEANY_LIBDIR])

    AC_SUBST([GEANY_PLUGINDIR],[$geanypluginsdir])
    AC_DEFINE_UNQUOTED([GEANY_PLUGINDIR],["$GEANY_PLUGINDIR"],[Path to Geany plugin])

    GP_GEANY_PKG_CONFIG_PATH_POP
])
