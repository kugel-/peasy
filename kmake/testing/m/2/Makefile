.PHONY: all clean install install-strip dist

all: tool

distclean clean:
	rm -f tool

install install-strip:
	cp tool $(DESTDIR)/tmp

dist:
	mkdir -p $(DISTDIR)
	cp tool.c $(DISTDIR)
