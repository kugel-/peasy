dnl CHECK_MINGW - Copied from geany
dnl Checks whether we're building for MinGW, and defines appropriate stuff
dnl if it is the case.
dnl Most importantly, AM_CODITIONALs MINGW
AC_DEFUN([CHECK_MINGW],
[
	case "${host}" in
		*mingw*)
			AC_DEFINE([WIN32], [1], [we are cross compiling for WIN32])
			AM_CONDITIONAL([MINGW], true)
			;;
		*)
			AM_CONDITIONAL([MINGW], false)
			;;
	esac
])
