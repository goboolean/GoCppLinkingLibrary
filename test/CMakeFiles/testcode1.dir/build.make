# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jepetolee/GoCppLinkingLibrary/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jepetolee/GoCppLinkingLibrary/test

# Include any dependencies generated for this target.
include CMakeFiles/testcode1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/testcode1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/testcode1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testcode1.dir/flags.make

CMakeFiles/testcode1.dir/TestTechnicalIndicator.cpp.o: CMakeFiles/testcode1.dir/flags.make
CMakeFiles/testcode1.dir/TestTechnicalIndicator.cpp.o: TestTechnicalIndicator.cpp
CMakeFiles/testcode1.dir/TestTechnicalIndicator.cpp.o: CMakeFiles/testcode1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jepetolee/GoCppLinkingLibrary/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testcode1.dir/TestTechnicalIndicator.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/testcode1.dir/TestTechnicalIndicator.cpp.o -MF CMakeFiles/testcode1.dir/TestTechnicalIndicator.cpp.o.d -o CMakeFiles/testcode1.dir/TestTechnicalIndicator.cpp.o -c /home/jepetolee/GoCppLinkingLibrary/test/TestTechnicalIndicator.cpp

CMakeFiles/testcode1.dir/TestTechnicalIndicator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testcode1.dir/TestTechnicalIndicator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jepetolee/GoCppLinkingLibrary/test/TestTechnicalIndicator.cpp > CMakeFiles/testcode1.dir/TestTechnicalIndicator.cpp.i

CMakeFiles/testcode1.dir/TestTechnicalIndicator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testcode1.dir/TestTechnicalIndicator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jepetolee/GoCppLinkingLibrary/test/TestTechnicalIndicator.cpp -o CMakeFiles/testcode1.dir/TestTechnicalIndicator.cpp.s

# Object files for target testcode1
testcode1_OBJECTS = \
"CMakeFiles/testcode1.dir/TestTechnicalIndicator.cpp.o"

# External object files for target testcode1
testcode1_EXTERNAL_OBJECTS =

testcode1: CMakeFiles/testcode1.dir/TestTechnicalIndicator.cpp.o
testcode1: CMakeFiles/testcode1.dir/build.make
testcode1: /home/jepetolee/libtorch/lib/libc10.so
testcode1: /home/jepetolee/libtorch/lib/libkineto.a
testcode1: libtechindicator.so
testcode1: libBaseFunctionz.so
testcode1: /home/jepetolee/libtorch/lib/libtorch.so
testcode1: /home/jepetolee/libtorch/lib/libc10.so
testcode1: /home/jepetolee/libtorch/lib/libc10.so
testcode1: /home/jepetolee/libtorch/lib/libkineto.a
testcode1: CMakeFiles/testcode1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jepetolee/GoCppLinkingLibrary/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testcode1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testcode1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testcode1.dir/build: testcode1
.PHONY : CMakeFiles/testcode1.dir/build

CMakeFiles/testcode1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testcode1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testcode1.dir/clean

CMakeFiles/testcode1.dir/depend:
	cd /home/jepetolee/GoCppLinkingLibrary/test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jepetolee/GoCppLinkingLibrary/test /home/jepetolee/GoCppLinkingLibrary/test /home/jepetolee/GoCppLinkingLibrary/test /home/jepetolee/GoCppLinkingLibrary/test /home/jepetolee/GoCppLinkingLibrary/test/CMakeFiles/testcode1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testcode1.dir/depend

