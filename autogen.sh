#!/bin/sh -e

intltoolize -c -f
autoreconf -vf

echo
echo "Bootstrap finished, ready to run configure..."
echo

