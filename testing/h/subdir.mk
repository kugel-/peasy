bin-y := h1 h2
cat-y := h2.h

h2.h-y := h1.h

h1-CPPFLAGS-y := -DH=\"h1.h\"
h1-y := h.c h1.h

h2-CPPFLAGS-y := -DH=\"h2.h\"
h2-y := h.c h2.h
