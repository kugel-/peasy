#!/bin/sh -e

intltoolize -c -f
autoreconf -vi

echo
echo "Bootstrap finished, ready to run configure..."
echo

