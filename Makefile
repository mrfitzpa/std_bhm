CXX := g++
SRC_DIR := src
BUILD_DIR := build
TARGET := bin/main

SRC_EXT := cpp
SRCS := $(shell find $(SRC_DIR) -type f -name \*.$(SRC_EXT))
OBJS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SRCS:.$(SRC_EXT)=.o))
OBJS := $(filter-out $(BUILD_DIR)/main.o, $(OBJS))

DEP_DIR := .d/$(SRC_DIR)
$(shell mkdir -p $(DEP_DIR) >/dev/null)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.Td

DEBUG := -g
OPTIMIZE_FLAG := -O2
OPENMP_FLAG := -fopenmp
CXXFLAGS := -Wall $(OPENMP_FLAG) $(OPTIMIZE_FLAG) $(DEBUG) -std=gnu++11
LIB := -larmadillo
INC := -I include

COMPILE.cc = $(CXX) $(DEPFLAGS) $(CXXFLAGS) $(INC) -c
OUTPUT_OPTION = -o $@
POSTCOMPILE = @mv -f $(DEP_DIR)/$*.Td $(DEP_DIR)/$*.d && touch $@

# Make main program
$(TARGET): $(OBJS) $(BUILD_DIR)/main.o
$(TARGET): $(OBJS) $(BUILD_DIR)/main.o
	@echo " Linking..."
	$(CXX) $^ -o $(TARGET) $(LIB) $(OPENMP_FLAG)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT) $(DEP_DIR)/%.d
	@mkdir -p $(@D)
	@mkdir -p $(DEP_DIR)$(subst $(BUILD_DIR),,$(@D))
	$(COMPILE.cc) $(OUTPUT_OPTION) $<
	$(POSTCOMPILE)


# Make test units programs
TEST_SRC_DIR := test
TEST_BUILD_DIR := build/test

TEST_SRCS := $(shell find $(TEST_SRC_DIR) -type f -name \*.$(SRC_EXT))
TEST_OBJS := $(patsubst $(TEST_SRC_DIR)/%,$(TEST_BUILD_DIR)/%,\
	$(TEST_SRCS:.$(SRC_EXT)=.o))
TEST_EXECS := $(patsubst $(TEST_SRC_DIR)/%,bin/test/%,\
	$(TEST_SRCS:.$(SRC_EXT)=))

TEST_DEP_DIR := .d/$(TEST_SRC_DIR)
$(shell mkdir -p $(TEST_DEP_DIR) >/dev/null)
TEST_DEPFLAGS = -MT $@ -MMD -MP -MF $(TEST_DEP_DIR)/$*.Td

TEST_COMPILE.cc = $(CXX) $(TEST_DEPFLAGS) $(CXXFLAGS) $(INC) -c
TEST_OUTPUT_OPTION = -o $@
TEST_POSTCOMPILE = @mv -f $(TEST_DEP_DIR)/$*.Td $(TEST_DEP_DIR)/$*.d && touch $@

test: $(TEST_EXECS)

bin/test/%: $(TEST_BUILD_DIR)/%.o $(OBJS)
bin/test/%: $(TEST_BUILD_DIR)/%.o $(OBJS)
	@mkdir -p $(@D)
	$(CXX) $^ -o $@ $(LIB) $(OPENMP_FLAG)

$(TEST_BUILD_DIR)/%.o: $(TEST_SRC_DIR)/%.$(SRC_EXT)
$(TEST_BUILD_DIR)/%.o: $(TEST_SRC_DIR)/%.$(SRC_EXT) $(TEST_DEP_DIR)/%.d
	@mkdir -p $(@D)
	@mkdir -p $(TEST_DEP_DIR)$(subst $(TEST_BUILD_DIR),,$(@D))
	$(TEST_COMPILE.cc) $(TEST_OUTPUT_OPTION) $<
	$(TEST_POSTCOMPILE)


# Create a pattern rule with an empty recipe, 
# so that make won’t fail if the dependency file doesn’t exist.
$(DEP_DIR)/%.d: ;
.PRECIOUS: $(DEP_DIR)/%.d

$(TEST_DEP_DIR)/%.d: ;
.PRECIOUS: $(TEST_DEP_DIR)/%.d


# Clean command
clean:
	@echo " Cleaning..."; 
	$(RM) -r $(BUILD_DIR) $(TARGET)
	$(RM) -r $(TEST_BUILD_DIR) bin/test
	$(RM) -r .d


# Do not auto-remove test object files
.SECONDARY: $(TEST_OBJS)

# Do not interprete 'clean' and 'test' as file targets
.PHONY: clean test


# Include dependency files in this makefile
include $(wildcard $(patsubst $(SRC_DIR)/%,$(DEP_DIR)/%.d,$(basename $(SRCS))))
include $(wildcard $(patsubst $(TEST_SRC_DIR)/%,$(TEST_DEP_DIR)/%.d,$(basename $(TEST_SRCS))))
