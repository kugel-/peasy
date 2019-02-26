bin-y := g g1

g-y := dummy.c
g-y += g.c

vpath $(srcdir)g.c $(OUTDIR)
$(objdir)g.c: $(srcdir)g.c.in
	$(call printcmd,GEN,$@)
	$(Q)sed -e 's,_MAIN_,main,g' $< > $@.tmp && mv $@.tmp $@

clean-y := g.c

sed-y := g1.c

g1.c-SED_SCRIPT-y := 's,_MAIN_,main,g'
