DEPS-y := a/liba.a s/libshl2.la
LIBS-y := -lc

bin-y  := e esh

esh-DEPS-y := a/libx.la
esh-LIBS-y := -lz
