extra-gen   += vala
extra-flags += VALAFLAGS FAST_VAPI

define vala_rule
cleanfiles += $(addprefix $(OUTDIR),$(1:.c=.vapi))

$(OUTDIR)$(1): FAPI = $(addprefix $(OUTDIR),$(call getvar,$(1),FAST_VAPI))
$(OUTDIR)$(1): VALAFLAGS = $(call getvar,$(1),VALAFLAGS)
$(OUTDIR)$(1): CMD = $(addprefix --directory=,$(OUTDIR)) $$(VALAFLAGS)
$(OUTDIR)$(1): $(call getsrc,$(1))
$(OUTDIR)$(1): $(addprefix $(OUTDIR),$(call getvar,$(1),FAST_VAPI))
$(OUTDIR)$(1): $(filter %.vapi,$(call getsrc,$(1)))
$(OUTDIR)$(1): $(OUTDIR)$(call getcmdfile,$(1))
endef

define vala_recipe
# an extra recipe to generate "fast vapi" files for --use-fast-vapi
$(OUTDIR)%.vapi: %.vala
	$$(call printcmd,GEN,$$@)
	$$(AT)mkdir -p $$(@D)
	$$(Q)$(VALAC) --fast-vapi=$$@ $$<
	$$(AT)touch $$@

$(addprefix $(OUTDIR),$(1)):
	$$(call printcmd,VALAC,$$@)
	$$(AT)mkdir -p $$(@D)
	$$(Q)$$(VALAC) $$(CMD) -C $$(filter %.vala,$$^) \
		$$(addprefix --use-fast-vapi=,$$(filter $$(FAPI),$$^)) \
		$$(filter-out $$(FAPI),$$(filter %.vapi,$$^))
	$$(AT)touch $$@
endef

vala-suffix := .vala

.SUFFIXES: vala vapi
