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
include CMakeFiles/BaseFunctionz.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BaseFunctionz.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BaseFunctionz.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BaseFunctionz.dir/flags.make

CMakeFiles/BaseFunctionz.dir/home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.cpp.o: CMakeFiles/BaseFunctionz.dir/flags.make
CMakeFiles/BaseFunctionz.dir/home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.cpp.o: /home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.cpp
CMakeFiles/BaseFunctionz.dir/home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.cpp.o: CMakeFiles/BaseFunctionz.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jepetolee/GoCppLinkingLibrary/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BaseFunctionz.dir/home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BaseFunctionz.dir/home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.cpp.o -MF CMakeFiles/BaseFunctionz.dir/home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.cpp.o.d -o CMakeFiles/BaseFunctionz.dir/home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.cpp.o -c /home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.cpp

CMakeFiles/BaseFunctionz.dir/home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BaseFunctionz.dir/home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.cpp > CMakeFiles/BaseFunctionz.dir/home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.cpp.i

CMakeFiles/BaseFunctionz.dir/home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BaseFunctionz.dir/home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.cpp -o CMakeFiles/BaseFunctionz.dir/home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.cpp.s

# Object files for target BaseFunctionz
BaseFunctionz_OBJECTS = \
"CMakeFiles/BaseFunctionz.dir/home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.cpp.o"

# External object files for target BaseFunctionz
BaseFunctionz_EXTERNAL_OBJECTS =

libBaseFunctionz.so: CMakeFiles/BaseFunctionz.dir/home/jepetolee/GoCppLinkingLibrary/TechnicalIndicator/BaseFunctions.cpp.o
libBaseFunctionz.so: CMakeFiles/BaseFunctionz.dir/build.make
libBaseFunctionz.so: /home/jepetolee/libtorch/lib/libtorch.so
libBaseFunctionz.so: /home/jepetolee/libtorch/lib/libc10.so
libBaseFunctionz.so: /home/jepetolee/libtorch/lib/libkineto.a
libBaseFunctionz.so: /home/jepetolee/libtorch/lib/libc10.so
libBaseFunctionz.so: CMakeFiles/BaseFunctionz.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jepetolee/GoCppLinkingLibrary/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libBaseFunctionz.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BaseFunctionz.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BaseFunctionz.dir/build: libBaseFunctionz.so
.PHONY : CMakeFiles/BaseFunctionz.dir/build

CMakeFiles/BaseFunctionz.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BaseFunctionz.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BaseFunctionz.dir/clean

CMakeFiles/BaseFunctionz.dir/depend:
	cd /home/jepetolee/GoCppLinkingLibrary/test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jepetolee/GoCppLinkingLibrary/test /home/jepetolee/GoCppLinkingLibrary/test /home/jepetolee/GoCppLinkingLibrary/test /home/jepetolee/GoCppLinkingLibrary/test /home/jepetolee/GoCppLinkingLibrary/test/CMakeFiles/BaseFunctionz.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BaseFunctionz.dir/depend

