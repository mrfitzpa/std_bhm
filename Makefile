# /std_bhm/Makefile

# -----------------------------------------------------------------------

# This is a generic makefile that can be used to make a given list
# of target files and automatically generate link dependencies for
# for efficient compilations.
#
# This makefile is a modified version of that made by Alexander Kl"aser:
# "https://lear.inrialpes.fr/people/klaeser/downloads
# /genericMakefile/generic.mk".

# -----------------------------------------------------------------------


# Set some standard directories
INCLUDE_DIR := include
SRC_DIR := src
TEST_DIR := test
BUILD_DIR := build
BIN_DIR := bin
D_DEP_DIR := .d
L_DEP_DIR := .l

# Set file extensions
SRC_EXT := cpp
OBJ_EXT := o
D_DEP_EXT := d
L_DEP_EXT := l

# Set the binaries that have to be built
TEST_SRCS := $(shell find $(TEST_DIR) -type f -name \*.$(SRC_EXT))
TARGETS := main $(TEST_SRCS:.$(SRC_EXT)=)

# Set compiler
CXX := g++

# Library directories
LIB_DIRS :=

# Set which libraries are used by which executable
LD_LIBS_ED_1D = $(subst /ed_1d/,-larmadillo,$(findstring /ed_1d/,$*))
LD_LIBS_LANCZOS = $(subst /lanczos/,-larmadillo,$(findstring /lanczos/,$*))
LD_LIBS = $(sort $(LD_LIBS_ED_1D) $(LD_LIBS_LANCZOS))

# Set some flags and compiler/linker specific commands
DEBUG := -g
OPTIMIZE_FLAG := -O2
OPENMP_FLAG := -fopenmp
INC := -I $(INCLUDE_DIR)
CXX_FLAGS := -Wall $(OPENMP_FLAG) $(OPTIMIZE_FLAG) $(DEBUG) -std=gnu++11 $(INC)

# Set the path for the dependency tool
DEP_TOOL = ./dep_tool.py

# All .l include files (.l files are the link dependency files)
INCLUDES := $(addprefix $(L_DEP_DIR)/,$(TARGETS:=.l))



#
# Some general rules
#

.PHONY: all clean
.SECONDARY: $(D_DEP_DIR)/main.$(D_DEP_EXT) \
	$(addprefix $(D_DEP_DIR)/,$(TEST_SRCS:.$(SRC_EXT)=.$(D_DEP_EXT)))
#.PRECIOUS: $(D_DEP_DIR)/%.(D_DEP_EXT)

all: $(BIN_DIR) $(BUILD_DIR) $(addprefix $(BIN_DIR)/,$(TARGETS))
	@echo "=== done ==="

$(INCLUDES): $(L_DEP_DIR) $(D_DEP_DIR)

clean:
	@echo "=== cleaning up ==="
	@rm -rf $(BUILD_DIR)
	@rm -rf $(BIN_DIR)
	@rm -rf $(D_DEP_DIR)
	@rm -rf $(L_DEP_DIR)

$(BUILD_DIR) $(BIN_DIR) $(L_DEP_DIR) $(D_DEP_DIR):
	@echo "=== Creating directory: $@ ==="
	@mkdir -p $@



#
# Rules for creating dependency files
#

# Generate .d dependency files, which list the dependencies of .cpp files
# on other files
$(D_DEP_DIR)/%.$(D_DEP_EXT): $(SRC_DIR)/%.$(SRC_EXT)
	@echo "=== Creating .d dependency file: $@ ==="
	@test -e $(dir $@) || mkdir -p $(dir $@)
	$(CXX) $(CXX_FLAGS) -MM -MT $(BUILD_DIR)/$*.$(OBJ_EXT) \
	-MT $@ -MF $@ $<

$(D_DEP_DIR)/$(TEST_DIR)/%.$(D_DEP_EXT): $(TEST_DIR)/%.$(SRC_EXT)
	@echo "=== Creating .d dependency file: $@ ==="
	@test -e $(dir $@) || mkdir -p $(dir $@)
	$(CXX) $(CXX_FLAGS) -MM -MT $(BUILD_DIR)/$(TEST_DIR)/$*.$(OBJ_EXT) \
	-MT $@ -MF $@ $<



# Generate .l dependency files, which list the link dependencies of the target
# file in question
$(L_DEP_DIR)/%.$(L_DEP_EXT): $(D_DEP_DIR)/%.$(D_DEP_EXT)
	@echo "=== Creating .l dependency file: $@ ==="
	@test -e $(dir $@) || mkdir -p $(dir $@)
	$(DEP_TOOL) $(BIN_DIR)/$* $@ $(D_DEP_DIR) $(BUILD_DIR) $(SRC_DIR) \
	$(INCLUDE_DIR) $< > $@



#
# Rules for compiling and linking
#

# Compiling
$(BUILD_DIR)/%.$(OBJ_EXT): $(SRC_DIR)/%.$(SRC_EXT)
	@echo "=== Compiling: $@ ==="
	@test -e $(dir $@) || mkdir -p $(dir $@)
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

$(BUILD_DIR)/$(TEST_DIR)/%.$(OBJ_EXT): $(TEST_DIR)/%.$(SRC_EXT)
	@echo "=== Compiling: $@ ==="
	@test -e $(dir $@) || mkdir -p $(dir $@)
	$(CXX) $(CXX_FLAGS) -c -o $@ $<



# Linking: link dependencies are defined in the .l files
$(BIN_DIR)/%:
	@echo "=== Linking: $@ ==="
	@test -e $(dir $@) || mkdir -p $(dir $@)
	@rm -f $@
	$(CXX) $(LD_FLAGS) -o $@ $(filter %.o, $^) $(LD_LIBS) $(OPENMP_FLAG)

# Some empty recipes
%: %.o
%.h: ;
%.hpp: ;
%.c: ;
%.cpp: ;



#
# Include dependency files
#

ifneq ($(MAKECMDGOALS),clean)
-include $(INCLUDES)
endif
