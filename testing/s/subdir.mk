extra-libs           := libs_s

libs_s-dir           := $(libdir)
libs_s-y             := libshl.la libshl2.la

libshl.la-y          := s.c
libshl.la-dir        := $(prefix)/tmp/lib

libshl2.la-y         := s2.c
libshl2.la-DEPS-y    := a/libx.la
libshl2.la-LDFLAGS-y := -no-undefined

headers-y            := s.h
