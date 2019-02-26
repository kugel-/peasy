subdir-y     := 1/

bin-y        := x y

x-y          := x.c
x-y          += ../a.c

y-y          := y.c
y-DEPS-y     := a/a.c

libs-y       := liby.la
