#!/bin/bash

aclocal --install
libtoolize --install --copy
autoheader
autoconf
