#include <stdio.h>

#include "s/s.h"
#include "a/libx.h"

/* liby.la */
extern int x(void);

int main() { x(); bar(); libx(); }
