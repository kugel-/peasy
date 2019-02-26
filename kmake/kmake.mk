.DEFAULT_GOAL := all

FORCE: ;

AT = @
ifeq ($(V),2)
QQ :=
Q  :=
else ifeq ($(V),1)
QQ := @
Q  :=
else
QQ := @
Q  := @
endif

# LTTAG, COMPILE and LINK are set in per-target rules
CC              := $(CROSS_COMPILE)$(CC)
CXX             := $(CROSS_COMPILE)$(CXX)
AR              := $(CROSS_COMPILE)$(AR)
STRIP           ?= $(CROSS_COMPILE)strip
RM              ?= rm -f
LIBTOOL         ?= libtool
INSTALL_PROGRAM ?= install

LIBTOOL_COMPILE  = $(LIBTOOL) $(if $(Q),--silent) --tag $(LTTAG) --mode=compile $(COMPILE)
LIBTOOL_LINK     = $(LIBTOOL) $(if $(Q),--silent) --tag $(LTTAG) --mode=link $(LINK)
LIBTOOL_RM       = $(LIBTOOL) $(if $(Q),--silent) --mode=clean $(RM)
LIBTOOL_INSTALL  = $(LIBTOOL) $(if $(Q),--silent) --mode=install $(INSTALL_PROGRAM)

DEFAULT_SUFFIX  ?= .c
DEFAULT_DRIVER  ?= "sh -c"

STRIPWD         ?=

# adds a traling slash to $(1), unless it already ends with a slash
ensure_slash     = $(or $(filter %/,$(1)),$(1)/)

ifneq ($(S),)
SRCDIR := $(call ensure_slash,$(S))
endif

ifneq ($(O),)
OUTDIR := $(call ensure_slash,$(O))
endif

ifneq ($(M),)
PARTDIR := $(call ensure_slash,$(M))
endif

ifneq ($(D),)
DISTDIR := $(abspath $(D))
endif

KMAKEDIR := $(filter-out ./,$(dir $(lastword $(MAKEFILE_LIST))))

define clearvar
$(1)-y :=

endef

define clearvars
# clear each $xx-y
$(foreach v,$(prog_vars) $(lib_vars) $(data_vars),$(call clearvar,$(v)))
$(foreach v,$(test_vars) $(gen_vars),$(call clearvar,$(v)))
$(foreach v,clean distclean dist nodist submake,$(call clearvar,$(v)))
$(foreach v,$(flag_names) $(aflag_names),$(call clearvar,$(v)))
extra-progs :=
extra-libs :=
extra-data :=
endef

subdir-y      ?= .
prefix        ?= /usr/local/
prefix_s      := $(call ensure_slash,$(prefix))
bindir        ?= $(prefix_s)bin
sbindir       ?= $(prefix_s)sbin
libdir        ?= $(prefix_s)lib
datadir       ?= $(prefix_s)share
sysconfdir    ?= $(prefix_s)etc
includedir    ?= $(prefix_s)include

prog_vars     := bin sbin noinstprogs
prog_vars     += $(extra-progs)
lib_vars      := libs noinstlibs
lib_vars      += $(extra-libs)
data_vars     := data sysconf headers
data_vars     += $(extra-data)
test_vars     := tests testscripts
test_vars     += $(extra-tests)
gen_vars      := byproduct
gen_vars      += $(extra-gen)
flag_names    := CPPFLAGS CFLAGS CXXFLAGS LDFLAGS
flag_names    += $(extra-flags)
aflag_names   := DEPS LIBS
aflag_names   += $(extra-append-flags)
prop_names    := dir suffix driver compiler
prop_names    += $(extra-properties)

bin-dir       := $(bindir)
bin-suffix    := $(DEFAULT_SUFFIX)
sbin-dir      := $(sbindir)
sbin-suffix   := $(DEFAULT_SUFFIX)
libs-dir      := $(libdir)
libs-suffix   := $(DEFAULT_SUFFIX)
data-dir      := $(datadir)
sysconf-dir   := $(sysconfdir)
headers-dir   := $(includedir)
tests-suffix  := $(DEFAULT_SUFFIX)
tests-driver  := $(DEFAULT_DRIVER)
testscripts-driver  := $(DEFAULT_DRIVER)
noinstprogs-dir     := noinst
noinstprogs-suffix  := $(DEFAULT_SUFFIX)
noinstlibs-dir      := noinst
noinstlibs-suffix   := $(DEFAULT_SUFFIX)

all_dist      := $(KMAKEDIR)kmake.mk $(KMAKEDIR)process-subdir.mk
all_dist      += $(KMAKEDIR)gen-sed.mk $(KMAKEDIR)gen-cat.mk
all_dist      += $(KMAKEDIR)README

DISTDIR       ?= $(abspath $(or $(and $(PACKAGE_NAME),$(PACKAGE_VERSION),$(PACKAGE_NAME)-$(PACKAGE_VERSION)),dist-dir))
ifneq ($(filter-out /%,$(DISTDIR)),)
$(error DISTDIR must be absolute, actual is $(DISTDIR))
endif
DISTDIR       := $(call ensure_slash,$(DISTDIR))


KM_CPPFLAGS ?= -I. $(if $(SRCDIR),-I$(SRCDIR))
KM_CFLAGS   ?= -O2 -g
KM_CXXFLAGS ?= -O2 -g

define inc_subdir
srcdir := $(filter-out .,$(1))
objdir := $(OUTDIR)$$(srcdir)
include $(KMAKEDIR)process-subdir.mk
endef

# cpp and hdr lists based on Automake
cppexts := .c++ .cc .cpp .cxx .C
cpppats := $(addprefix %,$(cppexts))
hdrexts := .h .H .hxx .h++ .hh .hpp .inc
hdrpats := $(addprefix %,$(hdrexts))
objexts := .la .a .lo .o
objpats := $(addprefix %,$(objexts))

# reverses the list in $(1), using recursion
reverse = $(strip $(if $(word 2,$(1)),$(call reverse,$(wordlist 2,$(words $(1)),$(1)))) $(firstword $(1)))
# prepend $(dir $(1)) to $(2), except if it's './' or $(2) is an absolute path
addpath = $(patsubst $(dir $(1))/%,/%,$(addprefix $(filter-out ./,$(dir $(1))),$(2)))

varname = $(foreach x,$(1),$(notdir $(x)))

# call with $(1) = single src file, $(2) = target varname
# inserts the target varname between the path to the source file
# and its filename, and removes the extension
# e.g. $(1) = a/b/c.c $(2) = liba.a => a/b/liba.a-c
prefixtarget = $(call addpath,$(1),$(2)-$(basename $(call varname,$(1))))

getvar = $($(call varname,$(1))$(if $(2),-$(2))-y)
getprop = $($(call varname,$(1))-$(2))
# call with $(1) = target (incl. extension)
getdefsrc = $(if $(call getprop,$(1),suffix),$(basename $(call varname,$(1)))$(call getprop,$(1),suffix))
# call with $(1) = target (incl. extension)
getysrc = $(call addpath,$(1),$(or $(filter-out $(objpats),$(call getvar,$(1))),$(call getdefsrc,$(1))))
# call with $(1) = target (incl. extension)
getsrc = $(strip $(call getysrc,$(1)) $(filter-out $(objpats),$(call getvar,$(1),DEPS)))
# call with $(1) = target (incl. extension)
getsrc_c = $(strip $(filter-out $(hdrpats),$(call getsrc,$(1))))
# call with $(1) = target (incl. extension)
getdeps = $(call addpath,$(1),$(call getvar,$(1))) $(call getvar,$(1),DEPS)
# call with $(1) = target (incl. extension)
getobjdeps = $(filter $(objpats),$(call getdeps,$(1)))
# call with $(1) = target (incl. extension)
gethdrdeps = $(filter $(hdrpats),$(call getdeps,$(1)))
# call with $(1) = target (incl. extension)
getobjext = $(if $(filter %.la,$(1)),lo,o)
# call with $(1) = single src file, $(2) = target varname
getobjbase = $(call prefixtarget,$(1),$(2))
# call with $(1) = single src file, $(2) = target (incl. extension)
getobjfile = $(call getobjbase,$(1),$(call varname,$(2))).$(call getobjext,$(2))
# call with $(1) = target (incl. extension)
# Note this is returns empty if the target has no source files, since it is
# assumed the target already exists (allows to place scripts in $foo-y)
getobj = $(strip $(foreach src,$(call getsrc_c,$(1)),$(call getobjfile,$(src),$(1))) $(call getobjdeps,$(1)))
# call with $(1) = list of source files
is_cxx = $(filter $(cpppats),$(1))
# call with $(1) = target (incl. extension)
is_lib = $(filter %.la %.a,$(1))
# call with $(1) = list of source files, $(2) = target (incl. extension)
# returns CXX if one or more C++ files are found, else CC
getcc = $(or $($(call varname,$(2))-compiler),$(if $(call is_cxx,$(1)),$(CXX),$(CC)))
# call with $(1) = target (incl. extension)
# returns the LTTAG flag, or CXX if one or more C++ files are found, else CC
getlttag = $(or $($(call varname,$(1))-libtooltag),$(if $(call is_cxx,$(call getsrc,$(1))),CXX),CC)
# call with $(1) = target (incl. extension)
getdepsdir = $(dir $(1)).deps/
# call with $(1) = target (incl. extension)
# Note this is returns empty if the target has no source files, since it is
# assumed the target already exists (allows to place scripts in $foo-y)
getoldcmdfile = $(call getdepsdir,$(1))$(notdir $(1)).oldcmd
getcmdfile = $(call getdepsdir,$(1))$(notdir $(1)).cmd
getdepfile = $(call getdepsdir,$(1))$(notdir $(1)).dep
getdepopt = -MD -MP -MF$(call getdepfile,$(1)) -MQ$(1)
# returns empty if $(1) and $(1) are the same
# works lists (strings containing spaces) as well
strneq = $(subst $(1),,$(2))$(subst $(2),,$(1))
# returns x if $(1) and $(1) are the same
streq = $(if $(call strneq,$(1),$(2)),,x)

ALL_PROGS  = $(foreach v,$(prog_vars),$(all_$(v)))
ALL_LIBS   = $(foreach v,$(lib_vars),$(all_$(v)))
ALL_DATA   = $(foreach v,$(data_vars),$(all_$(v)))
ALL_GEN    = $(foreach v,$(gen_vars),$(all_$(v)))
ALL_TESTS  = $(foreach v,$(test_vars),$(all_$(v)))

# Prepend variable $(2)-y to $(1)-(2)-y
# e.g. prepend CFLAGS-y to libfoo-CFLAGS-y
define _prepend_flags
$(1)-$(2)-y := $(call getvar,$(2)) $(call getvar,$(1),$(2))
endef
prepend_flags = $(eval $(call _prepend_flags,$(call varname,$(1)),$(2)))

# Append variable $(2)-y to $(1)-(2)
# e.g. prepend LIBS-y to libfoo-LIBS-y
define _append_flags
$(1)-$(2)-y := $(call getvar,$(1),$(2)) $(call getvar,$(2))
endef
append_flags = $(eval $(call _append_flags,$(call varname,$(1)),$(2)))

# https://stackoverflow.com/a/47927343/5126486: Insert a new-line in a Makefile $(foreach ) loop
define newline =


endef

define setvpath
$(if $(2),$(foreach f,$(1),vpath $(f) $(2)$(newline)))
endef

# Call with $1: object file, $2: src file, $3: target that $1 is part of
define obj_rule
cleanfiles += $(OUTDIR)$(1)
cleanfiles += $(OUTDIR)$(call getdepfile,$(1))
cleanfiles += $(OUTDIR)$(call getcmdfile,$(1))
cleanfiles += $(OUTDIR)$(call getoldcmdfile,$(1))

# Use X := X Y notation to append to *FLAGS. For some reason,  += leads to
# KM_LDFLAGS of one target leaking to other targets. I couldn't reproduce it
# with a simplified Makefile yet but I think it's a bug in GNU make
$(OUTDIR)$(1): KM_CPPFLAGS := $(KM_CPPFLAGS) $(KM_CPPFLAGS_$(if $(call is_lib,$(3)),LIB,PROG)) $(call getvar,$(3),CPPFLAGS)
$(OUTDIR)$(1): KM_CFLAGS   := $(KM_CFLAGS)   $(KM_CFLAGS_$(if $(call is_lib,$(3)),LIB,PROG))   $(call getvar,$(3),CFLAGS)
$(OUTDIR)$(1): KM_CXXFLAGS := $(KM_CXXFLAGS) $(KM_CXXFLAGS_$(if $(call is_lib,$(3)),LIB,PROG)) $(call getvar,$(3),CXXFLAGS)
$(OUTDIR)$(1): COMPILE_FLAGS = $(if $(call is_cxx,$(2)),$$(KM_CXXFLAGS) $$(CXXFLAGS),$$(KM_CFLAGS) $(CFLAGS))
$(OUTDIR)$(1): PRINTCMD = $(if $(call is_cxx,$(2)),CXX,CC)
$(OUTDIR)$(1): LTTAG = $(call getlttag,$(2))
$(OUTDIR)$(1): COMPILE = $(call getcc,$(2),$(3))
$(OUTDIR)$(1): CMD = $$(COMPILE) $$(KM_CPPFLAGS) $$(CPPFLAGS) $$(COMPILE_FLAGS)
$(OUTDIR)$(1): PATTERN = %$(suffix $(2))
$(OUTDIR)$(1): $(2)
$(OUTDIR)$(1): $(OUTDIR)$(call getcmdfile,$(1))
# avoid a normal dependency for headers, those come through .dep files
# but ensure generated headers are generated first
$(OUTDIR)$(1): | $(call gethdrdeps,$(3))

$(call setvpath,$(1),$(OUTDIR))
endef

define rpath_rule
# carefully avoid -rpath for static libraries or libtool convinience libraries
$(OUTDIR)$(1): RPATH = $(and $(filter %.la,$(1)),$(filter-out noinst,$(call getprop,$(1),dir)),-rpath $(call getprop,$(1),dir))
endef

define prog_rule
# if a target has no objects, it is assumed to be a script that does
# not need to be built (as it cannot be built anyway)
cleanfiles += $(if $(call getobj,$(1)),$(OUTDIR)$(1))
cleanfiles += $(if $(call getobj,$(1)),$(OUTDIR)$(call getcmdfile,$(1)))
cleanfiles += $(if $(call getobj,$(1)),$(OUTDIR)$(call getoldcmdfile,$(1)))

$(OUTDIR)$(1): KM_LDFLAGS := $(KM_LDFLAGS) $(KM_LDFLAGS_$(if $(call is_lib,$(1)),LIB,PROG)) $(call getvar,$(1),LDFLAGS)
$(OUTDIR)$(1): PRINTCMD = $(if $(call is_cxx,$(call getsrc,$(1))),CXXLD,CCLD)
$(OUTDIR)$(1): LTTAG = $(call getlttag,$(1))
$(OUTDIR)$(1): LINK = $(call getcc,$(call getsrc,$(1)),$(1))
$(OUTDIR)$(1): CMD = $$(COMPILE) $$(RPATH) $$(KM_LDFLAGS) $$(LDFLAGS) -- $(call getvar,$(1),LIBS)
$(OUTDIR)$(1): PATTERN = $(addprefix %,$(sort $(suffix $(call getobj,$(1)))))
$(OUTDIR)$(1): $(call getobj,$(1))
$(OUTDIR)$(1): $(if $(call getobj,$(1)),$(OUTDIR)$(call getcmdfile,$(1)))

$(call setvpath,$(1) $(call gethdrdeps,$(1)),$(OUTDIR))

$(call varname,$(1))-obj += $(call getobj,$(1))

$(foreach f,$(call getsrc_c,$(1)),$(call obj_rule,$(call getobjfile,$(f),$(1)),$(f),$(1))$(newline))
endef

define test_rule
run-test-$(call varname,$(1)): $(1)
run-test-$(call varname,$(1)): FORCE
endef

define byproduct_rule
$(OUTDIR)$(1): $(call getsrc,$(1))
endef
define byproduct_recipe
endef

define gen_rule
cleanfiles += $(addprefix $(OUTDIR),$(all_$(1)))
cleanfiles += $(addprefix $(OUTDIR),$(foreach f,$(all_$(1)),$(call getcmdfile,$(f))))
cleanfiles += $(addprefix $(OUTDIR),$(foreach f,$(all_$(1)),$(call getoldcmdfile,$(f))))

$(foreach f,$(all_$(1)),$(call $(1)_rule,$(f))$(newline))

$(call $(1)_recipe,$(all_$(1)))

$(call setvpath,$(all_$(1)),$(OUTDIR))
endef

define inherit_props
$(foreach t,$(all_$(1)),$(foreach s,$(prop_names),$(if $($(1)-$(s)),$(call varname,$(t))-$(s) ?= $($(1)-$(s))$(newline))))
endef

$(foreach dir,$(subdir-y),$(eval $(call inc_subdir,$(dir))))
$(foreach v,$(gen_vars) $(test_vars) $(prog_vars) $(lib_vars) $(data_vars),$(eval $(call inherit_props,$(v))))
$(foreach prog,$(ALL_LIBS) $(ALL_PROGS) $(ALL_TESTS),$(eval $(call prog_rule,$(prog))))
$(foreach test,$(ALL_TESTS),$(eval $(call test_rule,$(test))))
$(foreach v,$(gen_vars),$(eval $(call gen_rule,$(v))))
$(foreach lib,$(ALL_LIBS),$(eval $(call rpath_rule,$(lib))))

changedir = $(if $(OUTDIR),cd $(OUTDIR))
stripwd = $(if $(STRIPWD),$(patsubst $(OUTDIR)%,%,$(1)),$(1))
printcmd = $(if $(Q),@printf "  %-8s%s\n" "$(1)" "$(call stripwd,$(2))")

# usually kmake targets should complete before any recursive make call:
# by definition kmake must have updated its targets before recursion
# so that those sub-Makefiles can depeend on kmake-created files
# However, the order reverses for clean targets because otherwise
# kmake would already delete files while sub-Makefiles still need them
sub_targets = all install install-strip dist
sub_targets_pre = clean distclean

.PHONY: FORCE all libs progs data generated check clean
.PHONY: dist distclean
.PHONY: install install-progs install-libs install-data install-strip
.PHONY: submakes $(addprefix submakes-,$(sub_targets) $(sub_targets_pre))
.PHONY: km-all km-clean km-check km-install km-install-strip
.PHONY: km-dist km-distclean

run-test-%:
	$(Q)driver=$($(call varname,$*)-driver); name=$*; test=$<; $$driver $$test $(KM_CHECKFLAGS) ; \
	if [ $$? = 0 ]; then echo PASS: $$test; else echo FAIL: $$test; fi

# PARTDIR restricts the selected targets to a given directory (partial build)
libs: $(filter $(PARTDIR)%,$(ALL_LIBS))
progs: $(filter $(PARTDIR)%,$(ALL_PROGS))
data: $(filter $(PARTDIR)%,$(ALL_DATA))
generated: $(filter $(PARTDIR)%,$(ALL_GEN))
submakes: submakes-all

# It's crucial that submakes-% depends on km-% if all_submake becomes
# empty due to the PARTDIR filter, otherwise all (etc.) has nothing to do
define submake_rule_dir
submake-$(1)-$(2): TARGET = $(1)
submake-$(1)-$(2): DIR = $(2)
submake-$(1)-$(2): SUBMAKE = $$(dir $$(or $$(wildcard $(OUTDIR)$$(DIR)Makefile),$$(DIR)Makefile))
submake-$(1)-$(2): DDIR := $$(DISTDIR)$(2)

ifeq ($(1),dist)
$$(DISTDIR)$(2): ; $(Q)mkdir -p $$@

submake-dist-$(2): | $$(DISTDIR)$(2)
endif

.PHONY: submake-$(1)-$(2)
submake-$(1)-$(2):
	$(call printcmd,MAKE,$$(SUBMAKE))
	$(Q)$$(MAKE) -C $$(SUBMAKE) $$(TARGET) $(if $(filter dist,$(1)),DISTDIR=$$(DDIR))

endef

# all -> submakes-all -> submake-all-% -> km-all
# (or all -> submakes-all -> km-all if all_submake is empty)
define submake_rule
.PHONY: submakes-$(1)
$(1): submakes-$(1)
submakes-$(1): $(or $(addprefix submake-$(1)-,$(filter $(PARTDIR)%,$(all_submake))),km-$(1))
$(foreach d,$(all_submake),submake-$(1)-$(d): km-$(1)$(newline))

$(foreach d,$(all_submake),$(call submake_rule_dir,$(1),$(d))$(newline))
endef

# clean -> km-clean -> submakes-clean -> reversed submake-clean-%
# (or clean -> km-clean -> submakes-clean if all_submake is empty)
define submake_rule_pre
.PHONY: submakes-$(1)
$(1): km-$(1)
km-$(1): submakes-$(1)
$(foreach d,$(call reverse,$(filter $(PARTDIR)%,$(all_submake))),submakes-$(1): submake-$(1)-$(d)$(newline))

$(foreach d,$(all_submake),$(call submake_rule_dir,$(1),$(d))$(newline))
endef

# no $(newline) here!
$(foreach t,$(sub_targets),$(eval $(call submake_rule,$(t))))
$(foreach t,$(sub_targets_pre),$(eval $(call submake_rule_pre,$(t))))

km-all: libs progs data

km-check: $(addprefix run-test-,$(call varname,$(filter $(PARTDIR)%,$(ALL_TESTS))))
check: km-check

km-clean:
	$(call printcmd,RM,$(filter-out %.dep %.cmd %.oldcmd,$(cleanfiles)) $(addprefix $(OUTDIR),$(all_clean)))
	$(Q)$(LIBTOOL_RM) $(filter-out %.dep %.cmd %.oldcmd,$(cleanfiles)) $(addprefix $(OUTDIR),$(all_clean))
	$(QQ)$(LIBTOOL_RM) $(filter %.dep %.cmd %.oldcmd,$(cleanfiles))

km-distclean: km-clean
	$(if $(all_distclean),$(call printcmd,RM,$(addprefix $(OUTDIR),$(all_distclean))))
	$(Q)$(LIBTOOL_RM) $(addprefix $(OUTDIR),$(all_distclean))

km-install: install-libs install-progs install-data
km-install-strip: LIBTOOL_INSTALL += $(STRIPOPT)
km-install-strip: install

# Installation dir is given by the -dir property. But, being a property,
# it can be overridden per target. We must respect a potentially disparate
# installation dir, falling back to installing targets individually, if this
# is detected. Normally all targets of a var can be installed at once.
install_all = mkdir -p $(DESTDIR)$(2);$(LIBTOOL_INSTALL) $(1) $(DESTDIR)$(2)
install_one = $(foreach t,$(1),mkdir -p $(DESTDIR)$(or $(call getprop,$(t),dir),$(error $(t)-dir must be specified)); $(LIBTOOL_INSTALL) $(t) $(DESTDIR)$(call getprop,$(t),dir);)
install_none =

get_n_dirs = $(words $(sort $(foreach t,$(1),$(or $(call getprop,$(t),dir),x))))
get_install = install_$(if $(1),$(or $(word $(call get_n_dirs,$(1)),all),one),none)
filter_noinst = $(foreach t,$(1),$(if $(filter-out noinst,$(call getprop,$(t),dir)),$(t)))

$(addprefix install-lib-,$(lib_vars)): install-lib-%: FORCE
	$(eval LA_LIBS := $(filter %.la,$(addprefix $(OUTDIR),$(call filter_noinst,$(all_$*)))))
	$(if $(LA_LIBS),$(call printcmd,INSTALL,$(LA_LIBS)))
	$(Q)$(call $(call get_install,$(LA_LIBS)),$(LA_LIBS),$($*-dir))

install-libs: STRIPOPT = -s
install-libs: $(addprefix install-lib-,$(lib_vars))

$(addprefix install-prog-,$(prog_vars)): install-prog-%: FORCE
	$(eval PROGS := $(addprefix $(OUTDIR),$(call filter_noinst,$(all_$*))))
	$(if $(PROGS),$(call printcmd,INSTALL,$(PROGS)))
	$(Q)$(call $(call get_install,$(PROGS)),$(PROGS),$($*-dir))

install-progs: STRIPOPT = -s --strip-program=$(STRIP)
install-progs: $(addprefix install-prog-,$(prog_vars))

$(addprefix install-data-,$(data_vars)): LIBTOOL_INSTALL += -m 0644
$(addprefix install-data-,$(data_vars)): install-data-%: FORCE
	$(if $(all_$*),$(call printcmd,INSTALL,$(addprefix $(SRCDIR),$(all_$*))))
	$(Q)$(call $(call get_install,$(all_$*)),$(addprefix $(SRCDIR),$(all_$*)),$($*-dir))

install-data: $(addprefix install-data-,$(data_vars))

# We have to use $(shell) for mkdir so that make executes it before other make
# (especially $(file)), as the recipe is all make functions.
# Also we have to make sure that we don't end up with an empty recipe,
# so we set a fallback to : (shell no-op)
# Finally, we must ensure .cmd is created iff it doesn't exist, even if any of
# CMD and OLDCMD is empty, so we write at least one character (; is appended)
$(OUTDIR)%.cmd: FORCE
	$(AT)$(shell mkdir -p $(dir $@))
	$(eval L_OBJ := $(call addpath,$(subst .deps/$(notdir $*),,$*),$(notdir $*)))
	$(eval L_CMD := $(strip $(CMD));)
	$(QQ)$(if $(call strneq,$(OLDCMD),$(L_CMD)),$(file >$(OUTDIR)$*.oldcmd,$$(OUTDIR)$(L_OBJ): OLDCMD = $(L_CMD)))
	$(QQ)$(if $(call strneq,$(OLDCMD),$(L_CMD)),touch $@,:)

# Use PATTERN in the object file recipes instead of $^/$+ as-is since it's
# allowed to specify additional dependencies in make-style (e.g. "foo-bar.lo: foo.h")
# so the prerequisites may be polluted with non-source files. PATTERN
# is generated from the files listed in $var-y (except headers).
# Likewise for linked binaries, the prerequisites may contain unexpected
# extra files (at least .cmd, but maybe a linker script too).

# prevent %.o to become a fallback rule for any file
all_obj = $(filter %.o,$(cleanfiles))
$(all_obj): $(OUTDIR)%.o:
	$(call printcmd,$(PRINTCMD),$@)
	$(AT)mkdir -p $(dir $@)/.deps
	$(Q)$(COMPILE) $(call getdepopt,$@) $(KM_CPPFLAGS) $(CPPFLAGS) $(COMPILE_FLAGS) -c -o $@ $(filter $(PATTERN),$^)

# prevent %.lo to become a fallback rule for any file
all_lobj = $(filter %.lo,$(cleanfiles))
$(all_lobj): $(OUTDIR)%.lo:
	$(call printcmd,$(PRINTCMD),$@)
	$(AT)mkdir -p $(dir $@)/.deps
	$(Q)$(LIBTOOL_COMPILE) $(call getdepopt,$@) $(KM_CPPFLAGS) $(CPPFLAGS) $(COMPILE_FLAGS) -c -o $@ $(filter $(PATTERN),$^)

$(addprefix $(OUTDIR),$(filter %.la,$(ALL_LIBS))):
	$(call printcmd,$(PRINTCMD),$@)
	$(AT)mkdir -p $(dir $@)
	$(Q)$(LIBTOOL_LINK) $(RPATH) $(KM_LDFLAGS) $(LDFLAGS) -o $@ $(filter $(PATTERN),$+) $(call getvar,$(@),LIBS)

$(addprefix $(OUTDIR),$(filter %.a,$(ALL_LIBS))):
	$(call printcmd,AR,$@)
	$(AT)mkdir -p $(dir $@)
	$(Q)$(AR) rcs $@ $(filter $(PATTERN),$+)

$(addprefix $(OUTDIR),$(ALL_PROGS) $(ALL_TESTS)):
	$(call printcmd,$(PRINTCMD),$@)
	$(AT)mkdir -p $(dir $@)
	$(Q)$(if $(filter %.la %.lo,$+),$(LIBTOOL_LINK),$(LINK)) $(KM_LDFLAGS) $(LDFLAGS) -o $@ $(filter $(PATTERN),$+) $(call getvar,$(@),LIBS)

.SUFFIXES: $(objexts) .mk .dep .cmd .oldcmd

# Gather all files list in any $var-y except if that's known to be generated
get_distfiles = $(filter-out $(ALL_GEN),$(foreach t,$(filter-out $(ALL_GEN),$(ALL_PROGS) $(ALL_LIBS) $(ALL_DATA) $(ALL_TESTS)) $(ALL_GEN),$(or $(call getysrc,$(t)),$(t))))

$(DISTDIR):
	$(Q)mkdir -p $@

# external files (outside of $(SRCDIR)) are not distributed, this
# also ensures make dist creates no filers outside of $(DISTDIR)
root := $(abspath $(or $(SRCDIR),.))
filter_external = $(foreach f,$(1),$(if $(findstring $(root),$(abspath $(f))),$(f)))

km-dist: $(filter-out $(all_nodist),$(call get_distfiles,$(i)) $(all_dist)) | $(DISTDIR)
	$(if $(Q),,$(AT)echo $(filter-out $(call filter_external,$^),$^) | xargs -r echo "skipped " >&2)
	$(call printcmd,CP,$(call filter_external,$^))
	$(Q)cp -p --parents -t $(DISTDIR) $(call filter_external,$^)


DIST_SUFFIXES := xz gz bz2
DIST_FOLDER   := $(notdir $(abspath $(DISTDIR)))

.SUFFIXES: $(addprefix .,$(DIST_SUFFIXES))

$(addprefix dist-,$(DIST_SUFFIXES)): dist-%: $(DIST_FOLDER).tar.%

$(DIST_FOLDER).tar.xz: COMP=J
$(DIST_FOLDER).tar.gz: COMP=z
$(DIST_FOLDER).tar.bz2: COMP=z
$(addprefix $(DIST_FOLDER).tar.,$(DIST_SUFFIXES)): dist
	$(call printcmd,TAR,$@)
	$(Q)rm -f $@
	$(Q)tar -c$(COMP) -f $@ $(DIST_FOLDER)

-include $(filter %.dep,$(cleanfiles))
-include $(filter %.oldcmd,$(cleanfiles))
