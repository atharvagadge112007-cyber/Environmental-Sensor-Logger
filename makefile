
# C compiler
CC = gcc

# C++ compiler
CXX = g++

# Compiler flags
CFLAGS = -Wall -Wextra -Wpedantic -Iinclude -g
CXXFLAGS = -Wall -Wextra -Wpedantic -Iinclude -g -std=c++17

# Google Test libraries
GTEST_LIBS = -lgtest -lgtest_main -pthread

# Folders
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

# C source files used by the application
APP_SOURCES = $(SRC_DIR)/main.c \
              $(SRC_DIR)/sensor.c \
              $(SRC_DIR)/validation.c \
              $(SRC_DIR)/file_handler.c \
              $(SRC_DIR)/report.c

# C source files used by Google Tests
MODULE_SOURCES = $(SRC_DIR)/sensor.c \
                 $(SRC_DIR)/validation.c \
                 $(SRC_DIR)/file_handler.c \
                 $(SRC_DIR)/report.c

# Object files
APP_OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(APP_SOURCES))

MODULE_OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(MODULE_SOURCES))

TEST_SOURCES = $(wildcard $(TEST_DIR)/*.cpp)

# Default target
all: app run_tests

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile C source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build application
app: $(APP_OBJECTS)
	$(CC) $(APP_OBJECTS) -o environmental_logger

# Build Google Test executable
run_tests: $(MODULE_OBJECTS) $(TEST_SOURCES)
	$(CXX) $(CXXFLAGS) $(TEST_SOURCES) $(MODULE_OBJECTS) -o run_tests $(GTEST_LIBS)

# Run application
run: app
	./environmental_logger

# Run Google Tests
test: run_tests
	./run_tests

# Remove generated files
clean:
	rm -rf $(BUILD_DIR) environmental_logger run_tests

# Targets that are not actual files
.PHONY: all run test clean
