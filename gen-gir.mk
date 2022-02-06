extra-gen          += gir typelib

extra-flags        += GIR_NAMESPACE GIR_VERSION GIR_SCANFLAGS
extra-flags        += GIR_INCLUDES GIR_CFLAGS GIR_LIB
extra-flags        += INTROSPECTION_COMPILER_ARGS

ifeq ($(INTROSPECTION_SCANNER),)
$(error INTROSPECTION_SCANNER is not set)
endif

ifeq ($(INTROSPECTION_COMPILER),)
$(error INTROSPECTION_COMPILER is not set)
endif

define gir_rule
$(OUTDIR)$(1): GIR_NAMESPACE = $(call getvar,$(1),GIR_NAMESPACE)
$(OUTDIR)$(1): GIR_SCANFLAGS = $(call getvar,$(1),GIR_SCANFLAGS)
$(OUTDIR)$(1): GIR_VERSION = $(call getvar,$(1),GIR_VERSION)
$(OUTDIR)$(1): GIR_INCLUDES = $(call getvar,$(1),GIR_INCLUDES)
$(OUTDIR)$(1): GIR_CFLAGS = $(call getvar,$(1),GIR_CFLAGS)
$(OUTDIR)$(1): GIR_LIB = $(call getvar,$(1),GIR_LIB)
$(OUTDIR)$(1): CMD = --namespace $$(GIR_NAMESPACE) \
                     --nsversion $$(GIR_VERSION) \
                     --libtool '$$(LIBTOOL)' \
                     --library $$(GIR_LIB) \
                     $$(addprefix --include=,$$(GIR_INCLUDES)) \
                     $$(GIR_SCANFLAGS) \
                     --cflags-begin $$(GIR_CFLAGS) --cflags-end
$(OUTDIR)$(1): $(call getsrc,$(1))
$(OUTDIR)$(1): $(OUTDIR)$(call getcmdfile,$(1))
endef

define gir_recipe
$(addprefix $(OUTDIR),$(1)):
	$$(call printcmd,GISCAN,$$@)
	$$(Q)LDFLAGS="$$(GEANY_LIBS)" CC=gcc \
		$(INTROSPECTION_SCANNER) $(if $(Q),--quiet) $$(CMD) $$^ --output $$@
endef

define typelib_rule
$(OUTDIR)$(1): INTROSPECTION_COMPILER_ARGS = $(call getvar,$(1),INTROSPECTION_COMPILER_ARGS)
$(OUTDIR)$(1): CMD = $$(INTROSPECTION_COMPILER_ARGS)
$(OUTDIR)$(1): $(call getsrc,$(1))
$(OUTDIR)$(1): $(OUTDIR)$(call getcmdfile,$(1))
endef


define typelib_recipe
$(addprefix $(OUTDIR),$(1)):
	$$(call printcmd,GICOMP,$$@)
	$$(Q)$$(INTROSPECTION_COMPILER) $$(INTROSPECTION_COMPILER_ARGS) $$< -o $$@
endef

typelib-suffix            := .gir
