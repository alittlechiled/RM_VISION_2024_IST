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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build

# Include any dependencies generated for this target.
include bin/conf_read/CMakeFiles/conf_read.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include bin/conf_read/CMakeFiles/conf_read.dir/compiler_depend.make

# Include the progress variables for this target.
include bin/conf_read/CMakeFiles/conf_read.dir/progress.make

# Include the compile flags for this target's objects.
include bin/conf_read/CMakeFiles/conf_read.dir/flags.make

bin/conf_read/CMakeFiles/conf_read.dir/src/conf_read.cpp.o: bin/conf_read/CMakeFiles/conf_read.dir/flags.make
bin/conf_read/CMakeFiles/conf_read.dir/src/conf_read.cpp.o: ../src/conf_read/src/conf_read.cpp
bin/conf_read/CMakeFiles/conf_read.dir/src/conf_read.cpp.o: bin/conf_read/CMakeFiles/conf_read.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/conf_read/CMakeFiles/conf_read.dir/src/conf_read.cpp.o"
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin/conf_read && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT bin/conf_read/CMakeFiles/conf_read.dir/src/conf_read.cpp.o -MF CMakeFiles/conf_read.dir/src/conf_read.cpp.o.d -o CMakeFiles/conf_read.dir/src/conf_read.cpp.o -c /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/src/conf_read/src/conf_read.cpp

bin/conf_read/CMakeFiles/conf_read.dir/src/conf_read.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/conf_read.dir/src/conf_read.cpp.i"
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin/conf_read && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/src/conf_read/src/conf_read.cpp > CMakeFiles/conf_read.dir/src/conf_read.cpp.i

bin/conf_read/CMakeFiles/conf_read.dir/src/conf_read.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/conf_read.dir/src/conf_read.cpp.s"
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin/conf_read && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/src/conf_read/src/conf_read.cpp -o CMakeFiles/conf_read.dir/src/conf_read.cpp.s

# Object files for target conf_read
conf_read_OBJECTS = \
"CMakeFiles/conf_read.dir/src/conf_read.cpp.o"

# External object files for target conf_read
conf_read_EXTERNAL_OBJECTS =

bin/conf_read/libconf_read.a: bin/conf_read/CMakeFiles/conf_read.dir/src/conf_read.cpp.o
bin/conf_read/libconf_read.a: bin/conf_read/CMakeFiles/conf_read.dir/build.make
bin/conf_read/libconf_read.a: bin/conf_read/CMakeFiles/conf_read.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libconf_read.a"
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin/conf_read && $(CMAKE_COMMAND) -P CMakeFiles/conf_read.dir/cmake_clean_target.cmake
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin/conf_read && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/conf_read.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/conf_read/CMakeFiles/conf_read.dir/build: bin/conf_read/libconf_read.a
.PHONY : bin/conf_read/CMakeFiles/conf_read.dir/build

bin/conf_read/CMakeFiles/conf_read.dir/clean:
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin/conf_read && $(CMAKE_COMMAND) -P CMakeFiles/conf_read.dir/cmake_clean.cmake
.PHONY : bin/conf_read/CMakeFiles/conf_read.dir/clean

bin/conf_read/CMakeFiles/conf_read.dir/depend:
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/src/conf_read /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin/conf_read /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin/conf_read/CMakeFiles/conf_read.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/conf_read/CMakeFiles/conf_read.dir/depend

