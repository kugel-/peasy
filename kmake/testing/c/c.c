#include <stdio.h>

#include "a/a.h"

#ifdef REQUIRE_CLANG
#ifndef __clang__
#error "Must use clang"
#endif
#endif

int main() { foo(); }
