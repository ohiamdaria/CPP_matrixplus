# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.24.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.24.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/dashakoroleva/Desktop/CPP_matrixplus/dublicate

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/dashakoroleva/Desktop/CPP_matrixplus/dublicate

# Include any dependencies generated for this target.
include CMakeFiles/tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tests.dir/flags.make

CMakeFiles/tests.dir/test/test_functions.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/test/test_functions.cpp.o: test/test_functions.cpp
CMakeFiles/tests.dir/test/test_functions.cpp.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/dashakoroleva/Desktop/CPP_matrixplus/dublicate/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tests.dir/test/test_functions.cpp.o"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/test/test_functions.cpp.o -MF CMakeFiles/tests.dir/test/test_functions.cpp.o.d -o CMakeFiles/tests.dir/test/test_functions.cpp.o -c /Users/dashakoroleva/Desktop/CPP_matrixplus/dublicate/test/test_functions.cpp

CMakeFiles/tests.dir/test/test_functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/test/test_functions.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/dashakoroleva/Desktop/CPP_matrixplus/dublicate/test/test_functions.cpp > CMakeFiles/tests.dir/test/test_functions.cpp.i

CMakeFiles/tests.dir/test/test_functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/test/test_functions.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/dashakoroleva/Desktop/CPP_matrixplus/dublicate/test/test_functions.cpp -o CMakeFiles/tests.dir/test/test_functions.cpp.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/test/test_functions.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

tests: CMakeFiles/tests.dir/test/test_functions.cpp.o
tests: CMakeFiles/tests.dir/build.make
tests: s21_matrix_oop.a
tests: /opt/homebrew/lib/libgtest_main.a
tests: /opt/homebrew/lib/libgtest.a
tests: CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/dashakoroleva/Desktop/CPP_matrixplus/dublicate/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tests.dir/build: tests
.PHONY : CMakeFiles/tests.dir/build

CMakeFiles/tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tests.dir/clean

CMakeFiles/tests.dir/depend:
	cd /Users/dashakoroleva/Desktop/CPP_matrixplus/dublicate && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/dashakoroleva/Desktop/CPP_matrixplus/dublicate /Users/dashakoroleva/Desktop/CPP_matrixplus/dublicate /Users/dashakoroleva/Desktop/CPP_matrixplus/dublicate /Users/dashakoroleva/Desktop/CPP_matrixplus/dublicate /Users/dashakoroleva/Desktop/CPP_matrixplus/dublicate/CMakeFiles/tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tests.dir/depend
