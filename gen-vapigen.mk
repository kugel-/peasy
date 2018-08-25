extra-gen          += vapigen

extra-flags        += VAPIGEN_METADATADIRS VAPIGEN_VAPIDIRS
extra-flags        += VAPIGEN_GIRDIRS VAPIGEN_DEPS

define vapigen_rule
$(OUTDIR)$(1): VAPIGEN_METADATADIRS = $(call getvar,$(1),VAPIGEN_METADATADIRS)
$(OUTDIR)$(1): VAPIGEN_VAPIDIRS = $(call getvar,$(1),VAPIGEN_VAPIDIRS)
$(OUTDIR)$(1): VAPIGEN_GIRDIRS = $(call getvar,$(1),VAPIGEN_GIRDIRS)
$(OUTDIR)$(1): VAPIGEN_DEPS = $(call getvar,$(1),VAPIGEN_DEPS)
$(OUTDIR)$(1): CMD = $$(addprefix --metadatadirs=,$$(VAPIGEN_METADATADIRS)) \
                     $$(addprefix --vapidir=,$$(VAPIGEN_VAPIDIRS)) \
                     $$(addprefix --girdir=,$$(VAPIGEN_GIRDIRS)) \
                     $$(addprefix --pkg=,$$(VAPIGEN_DEPS)) \
                     --library=$$(basename $(1))
$(OUTDIR)$(1): $(call getsrc,$(1))
$(OUTDIR)$(1): $(OUTDIR)$(call getcmdfile,$(1))
endef

define vapigen_recipe
$(addprefix $(OUTDIR),$(1)):
	$$(call printcmd,VAPIGEN,$$@)
	$$(Q)$$(VAPIGEN) $$(CMD) $$(call getsrc,$$@)
	$$(QQ)touch $$@
endef

