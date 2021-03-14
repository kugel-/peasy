extra-gen   += cat

define cat_rule
$(OUTDIR)$(1): $(SRCDIR)$(call getsrc,$(1))
endef

define cat_recipe
$(addprefix $(OUTDIR),$(1)):
	$$(call printcmd,GEN,$$@)
	$$(AT)mkdir -p $$(dir $$@)
	$$(Q)cat $$^ > $$@ || rm -f $$@
endef
