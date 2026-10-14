CXX = g++
CXXFLAGS = -std=c++23 -Wall -Wextra -pthread
LDFLAGS = -lgtest -lgtest_main -pthread

# =====================================================================
# COMMON SOURCE FILES
# Core implementation files shared across your project. 
# As you create new .cpp implementation files, add them here.
# =====================================================================
COMMON_SRC = Connection.cpp Date.cpp

# Automatically find all files ending in _test.cpp
TEST_SRC_FILES = $(wildcard *_test.cpp)
TEST_EXECUTABLES = $(TEST_SRC_FILES:.cpp=)

all:
	@echo "Please specify a test to run (e.g., 'make run-connection', 'make run-json'), or use 'make run_all'."

# Pattern rule to build tests using COMMON_SRC and an optional EXTRA file
%_test: %_test.cpp $(COMMON_SRC)
	$(CXX) $(CXXFLAGS) $< $(COMMON_SRC) $(EXTRA) -o $@ $(LDFLAGS)

# Target to run a specific test by name, matching the prefix before _test.cpp
run-%: %_test
	./$<

# Target to run every test file found in the folder
run_all: $(TEST_EXECUTABLES)
	@echo "========================================"
	@echo "Running all test suites in the folder..."
	@echo "========================================"
	@for exec in $(TEST_EXECUTABLES); do \
		echo "[RUNNING] Test Suite: $$exec"; \
		./$$exec || exit 1; \
	done
	@echo "passed all tests"

clean:
	rm -f $(TEST_EXECUTABLES)

.PHONY: all clean run_all run-%

