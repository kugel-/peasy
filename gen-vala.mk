extra-gen   += vala
extra-flags += VALAFLAGS

define vala_rule
cleanfiles += $(1:.c=.vapi)
$(1)_fapis = $(patsubst %.vala,%.vapi,$(filter %.vala,$(filter-out $(1:.c=.vala),$(call getsrc,$(1)))))

$(OUTDIR)$(1): FAST_VAPIS = $$($(1)_fapis)
$(OUTDIR)$(1): VALAFLAGS = $(call getvar,$(1),VALAFLAGS)
$(OUTDIR)$(1): VAPI_DEPS = $(filter %.vapi,$(call getsrc,$(1)))
$(OUTDIR)$(1): CMD = $$(VALAFLAGS)
$(OUTDIR)$(1): $(filter $(1:.c=.vala),$(call getsrc,$(1)))
$(OUTDIR)$(1): $$($(1)_fapis) $(filter %.vapi,$(call getsrc,$(1)))
$(OUTDIR)$(1): $(OUTDIR)$(call getcmdfile,$(1))
endef

define vala_recipe
# an extra recipe to generate "fast vapi" files for --use-fast-vapi
%.vapi: %.vala
	$$(call printcmd,GEN,$$@)
	$$(Q)$(VALAC) --fast-vapi=$$@ $$<
	$$(AT)touch $$@

%.c: %.vala
	$$(call printcmd,VALAC,$$@)
	$$(Q)$$(VALAC) $$(CMD) -C $$(filter %.vala,$$^) $$(addprefix --use-fast-vapi=$(OUTDIR),$$(FAST_VAPIS)) $$(VAPI_DEPS)
	$$(AT)touch $$@
endef

vala-suffix := .vala

.SUFFIXES: vala vapi
