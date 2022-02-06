extra-data           := quickswitchdata doxyhelperdata
extra-gen            := desktop

define desktop_rule
$(OUTDIR)$(1): CMD = $$(MSGFMT) --desktop -d $(src)po
$(OUTDIR)$(1): $(SRCDIR)$(call getsrc,$(1))
$(OUTDIR)$(1): $(OUTDIR)$(call getcmdfile,$(1))
$(OUTDIR)$(1): $(addprefix $(SRCDIR),$(wildcard po/*.po))
endef

define desktop_recipe
$(OUTDIR)%.plugin: $(SRCDIR)%.plugin.desktop.in $(wildcard $(src)po/*.po)
	$$(call printcmd,GEN,$$@)
	$$(Q)$$(CMD) --template $$< -o $$@
endef

.SUFFIXES: .plugin .plugin.desktop.in

desktop-suffix       := .plugin.desktop.in

CFLAGS-y             := $(PEAS_CFLAGS) $(GEANY_CFLAGS) -Ilib
LDFLAGS-y            := -module -avoid-version -no-undefined
LIBS-y               := $(PEAS_LIBS) $(GEANY_LIBS)
DEPS-y               := lib/libpeasy.la

quickswitchdata-dir  := $(plugindatadir)/quickswitch
quickswitchdata-y    := quickswitch.glade

doxyhelperdata-dir   := $(plugindatadir)/doxygen-helper
doxyhelperdata-y     := doxygen-helper.glade

plugins-y            := libpeasytest.la

libpeasytest.la-y      := peasytest.c
libpeasytest.la-DEPS-y := lib/peasy.h

PYTHON_PLUGINS       := console-peasy.py  \
                        doxygen-helper.py  \
                        modeline.py  \
                        peasypytest.py  \
                        quickswitch.py

PLUGIN_INFO          := peasytest.plugin
PLUGIN_INFO          += peasyluatest.plugin
PLUGIN_INFO          += $(PYTHON_PLUGINS:.py=.plugin)

plugindata-y         := $(PLUGIN_INFO)
plugindata-y         += peasyluatest.lua $(PYTHON_PLUGINS)

desktop-y            := $(PLUGIN_INFO)
