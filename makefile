# root
# |- build
# |- include
# |- src
# |- tests
# directory structure vars
I_DIR=include
SRC_DIR=src
SRC_TEST_DIR=tests
BUILD_DIR=build
OBJ_DIR=$(BUILD_DIR)/obj
OBJ_DEBUG_DIR=$(BUILD_DIR)/objdebug
BIN_DIR=$(BUILD_DIR)

# default file extension
# SRC_EXT=C cc cpp CPP c++ cp cxx c # if you have multiple extensions at src/
SRC_EXT=cc
# H_EXT=H h++ hh hxx hpp

# remove command
rm=rm -Rf

# list all dirs directly inside the include dir
INCLUDES=$(sort $(dir $(wildcard $(foreach d,$(I_DIR),$d/*/))))

### Main program (TODO: fix the object file creation)
# SOURCES=$(foreach e,$(SRC_EXT),$(wildcard $(SRC_DIR)/*.$e)) # if you have multiple extensions at src/
# list all source files inside src folder
# SOURCES=$(shell find $(SRC_DIR) -type f)
# creates a list of .o files using the files names from src
# OBJECTS=$(shell basename $(SOURCES))
# OBJECTS_DEBUG=$(SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DEBUG_DIR)/%.o)

### Unit tests (TODO: fix the object file creation)
# list all source files inside test folder
# SOURCES_TEST=$(shell find $(SRC_DIR) -type f) $(shell find $(SRC_TEST_DIR) -type f)
# SOURCES_TEST:=$(filter-out main.cc, $(SOURCES_TEST))

### Main files
MAIN=$(SRC_DIR)/main.cc
MAIN_TEST=$(SRC_TEST_DIR)/tests.cc

# compiler options and flags
CC=g++
CFLAGS=$(foreach d,$(INCLUDES),-I$d) -std=c++17 -Wall
CC_DEBUG_FLAGS=$(CFLAGS) -ggdb

# linker options and flags
LINKER=g++
LFLAGS=$(foreach d,$(INCLUDES),-I$d) -Wall -lm
L_DEBUG_LFLAGS=$(LFLAGS) -ggdb

# exe files
OUT_TEST=$(BIN_DIR)/test.out
OUT_MAIN=$(BIN_DIR)/main.out
OUT_MAIN_DEBUG=$(BIN_DIR)/main_debug.out
OUT_TEST_DEBUG=$(BIN_DIR)/test_debug.out

# possible calls for make
.PHONY: clean debug run

# default call
doit: build

# creates the build dir
prep:
	@mkdir -p $(BUILD_DIR) $(OBJ_DIR) $(OBJ_DEBUG_DIR) $(BIN_DIR)

# clear the build dir
clean:
	@$(rm) $(wildcard $(BIN_DIR)/*)
	@echo "Cleaned build dir"

# rules for the run command
run:
	./$(OUT_MAIN)

run-debug:
	./$(OUT_MAIN_DEBUG)

run-test:
	./$(OUT_TEST) -r compact  -d yes

run-test-debug:
	./$(OUT_TEST_DEBUG) -r compact  -d yes

# rule for the default call
def: build

# rules for the builds
build: prep $(OUT_MAIN)
build-debug: prep $(OUT_DEBUG)
build-test-debug: prep $(OUT_TEST_DEBUG)
build-test: prep $(OUT_TEST)

$(OUT_MAIN): $(MAIN)
	@$(CC) $(MAIN) $(CFLAGS) -o $@
	@echo "==== [Main] Compiled complete ===="

$(OUT_DEBUG): $(MAIN)
	@$(CC) $(MAIN) $(CFLAGS) $(CC_DEBUG_FLAGS) -o $@
	@echo "==== [Debug][Main] Compiled complete ===="

$(OUT_TEST_DEBUG): $(MAIN_TEST)
	@$(CC) $(MAIN_TEST) $(CFLAGS) $(CC_DEBUG_FLAGS) -o $@
	@echo "==== [Debug][Tests] Compiled complete ===="

$(OUT_TEST): $(MAIN_TEST)
	@$(CC) $(MAIN_TEST) $(CFLAGS) $(CC_DEBUG_FLAGS) -o $@
	@echo "==== [Tests] Compiled complete ===="
