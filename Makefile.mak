# Compiler and flags
CXX := g++
INCLUDE := -Iinclude

# Build configuration
CONFIG ?= Debug
ifeq ($(CONFIG),Debug)
    CXXFLAGS := -Wall -Wextra -std=c++20 -ggdb -O0
    OBJ_DIR := obj/Debug
    BIN_DIR := bin/Debug
else ifeq ($(CONFIG),Release)
    CXXFLAGS := -Wall -Wextra -std=c++20 -O2
    OBJ_DIR := obj/Release
    BIN_DIR := bin/Release
else
    CXXFLAGS := -Wall -Wextra -std=c++20 -ggdb -O0
    OBJ_DIR := obj/Debug
    BIN_DIR := bin/Debug
endif

LDFLAGS :=

# Directories
SRC_DIR := src
INCLUDE_DIR := include

# Output
EXECUTABLE := $(BIN_DIR)/main

# Source files
SOURCES := $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/Text/*.cpp)
OBJECTS := $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS := $(OBJECTS:.o=.d)

# Default target
.PHONY: all
all: $(EXECUTABLE)

# Configuration-specific targets
.PHONY: Debug
Debug: CONFIG := Debug
Debug: clean $(EXECUTABLE)

.PHONY: Release
Release: CONFIG := Release
Release: clean $(EXECUTABLE)

# Link executable
$(EXECUTABLE): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(OBJECTS) $(LDFLAGS) -o $@

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR) $(OBJ_DIR)/Text
	$(CXX) $(CXXFLAGS) $(INCLUDE) -MMD -MP -c $< -o $@

# Create directories
$(BIN_DIR) $(OBJ_DIR) $(OBJ_DIR)/Text:
	mkdir -p $@

# Include dependency files
-include $(DEPS)

# Clean targets
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: distclean
distclean: clean
	rm -f $(EXECUTABLE)

# Run the program
.PHONY: run
run: $(EXECUTABLE)
	./$(EXECUTABLE)

# Help target
.PHONY: help
help:
	@echo "Available targets:"
	@echo "  all       - Build the project (default)"
	@echo "  run       - Build and run the program"
	@echo "  clean     - Remove object files and binary"
	@echo "  distclean - Remove all generated files"
	@echo "  help      - Display this help message"
