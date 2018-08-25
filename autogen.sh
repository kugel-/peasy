#!/bin/sh -e

mkdir -p m4
intltoolize -c -f
env LIBTOOLIZE="libtoolize --install" autoreconf -vi

echo
echo "Bootstrap finished, ready to run configure..."
echo

