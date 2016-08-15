#!/bin/sh -e

intltoolize -c -f
autoreconf -vfi

echo
echo "Bootstrap finished, ready to run configure..."
echo

