extra-gen   += fast_vapi vala
extra-flags += VALAFLAGS

define fast_vapi_rule
$(OUTDIR)$(1): PRINTCMD = GEN
$(OUTDIR)$(1): $(SRCDIR)$(call getsrc,$(1))
endef

define fast_vapi_recipe
%.vapi: %.vala
	$$(call printcmd,GEN,$$@)
	$$(Q)$(VALAC) --fast-vapi=$$@ $$<
	$$(AT)touch $$@
endef

fast_vapi-suffix := .vala

define vala_rule
$(OUTDIR)$(1): VALAFLAGS = $(call getvar,$(1),VALAFLAGS)
$(OUTDIR)$(1): PRINTCMD = GEN
$(OUTDIR)$(1): CMD = $$(VALAFLAGS)
$(OUTDIR)$(1): $(SRCDIR)$(call getsrc,$(1))
$(OUTDIR)$(1): $(OUTDIR)$(call getcmdfile,$(1))
endef

define vapi_dep
$(1): $(patsubst %.c,%.vapi,$(2))

endef

define vala_recipe
# creates
# 1.c: 2.vapi 3.vapi
# 2.c: 1.vapi 3.vapi
# 3.c: 1.vapi 2.vapi
$(foreach f,$(1),$(call vapi_dep,$(f),$(filter-out $(f),$(1))))

%.c: %.vala
	$$(call printcmd,VALAC,$$@)
	$$(Q)$$(VALAC) $$(VALAFLAGS) -C $$(filter %.vala,$$^) $$(addprefix --use-fast-vapi=,$$(filter %.vapi,$$^))
	$$(AT)touch $$@
endef

vala-suffix := .vala

.SUFFIXES: vala vapi
