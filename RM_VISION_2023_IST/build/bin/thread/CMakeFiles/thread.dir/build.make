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
include bin/thread/CMakeFiles/thread.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include bin/thread/CMakeFiles/thread.dir/compiler_depend.make

# Include the progress variables for this target.
include bin/thread/CMakeFiles/thread.dir/progress.make

# Include the compile flags for this target's objects.
include bin/thread/CMakeFiles/thread.dir/flags.make

bin/thread/CMakeFiles/thread.dir/src/detect_thread.cpp.o: bin/thread/CMakeFiles/thread.dir/flags.make
bin/thread/CMakeFiles/thread.dir/src/detect_thread.cpp.o: ../src/thread/src/detect_thread.cpp
bin/thread/CMakeFiles/thread.dir/src/detect_thread.cpp.o: bin/thread/CMakeFiles/thread.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/thread/CMakeFiles/thread.dir/src/detect_thread.cpp.o"
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin/thread && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT bin/thread/CMakeFiles/thread.dir/src/detect_thread.cpp.o -MF CMakeFiles/thread.dir/src/detect_thread.cpp.o.d -o CMakeFiles/thread.dir/src/detect_thread.cpp.o -c /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/src/thread/src/detect_thread.cpp

bin/thread/CMakeFiles/thread.dir/src/detect_thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/thread.dir/src/detect_thread.cpp.i"
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin/thread && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/src/thread/src/detect_thread.cpp > CMakeFiles/thread.dir/src/detect_thread.cpp.i

bin/thread/CMakeFiles/thread.dir/src/detect_thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/thread.dir/src/detect_thread.cpp.s"
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin/thread && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/src/thread/src/detect_thread.cpp -o CMakeFiles/thread.dir/src/detect_thread.cpp.s

bin/thread/CMakeFiles/thread.dir/src/image_get_thread.cpp.o: bin/thread/CMakeFiles/thread.dir/flags.make
bin/thread/CMakeFiles/thread.dir/src/image_get_thread.cpp.o: ../src/thread/src/image_get_thread.cpp
bin/thread/CMakeFiles/thread.dir/src/image_get_thread.cpp.o: bin/thread/CMakeFiles/thread.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object bin/thread/CMakeFiles/thread.dir/src/image_get_thread.cpp.o"
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin/thread && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT bin/thread/CMakeFiles/thread.dir/src/image_get_thread.cpp.o -MF CMakeFiles/thread.dir/src/image_get_thread.cpp.o.d -o CMakeFiles/thread.dir/src/image_get_thread.cpp.o -c /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/src/thread/src/image_get_thread.cpp

bin/thread/CMakeFiles/thread.dir/src/image_get_thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/thread.dir/src/image_get_thread.cpp.i"
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin/thread && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/src/thread/src/image_get_thread.cpp > CMakeFiles/thread.dir/src/image_get_thread.cpp.i

bin/thread/CMakeFiles/thread.dir/src/image_get_thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/thread.dir/src/image_get_thread.cpp.s"
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin/thread && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/src/thread/src/image_get_thread.cpp -o CMakeFiles/thread.dir/src/image_get_thread.cpp.s

# Object files for target thread
thread_OBJECTS = \
"CMakeFiles/thread.dir/src/detect_thread.cpp.o" \
"CMakeFiles/thread.dir/src/image_get_thread.cpp.o"

# External object files for target thread
thread_EXTERNAL_OBJECTS =

bin/thread/libthread.a: bin/thread/CMakeFiles/thread.dir/src/detect_thread.cpp.o
bin/thread/libthread.a: bin/thread/CMakeFiles/thread.dir/src/image_get_thread.cpp.o
bin/thread/libthread.a: bin/thread/CMakeFiles/thread.dir/build.make
bin/thread/libthread.a: bin/thread/CMakeFiles/thread.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libthread.a"
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin/thread && $(CMAKE_COMMAND) -P CMakeFiles/thread.dir/cmake_clean_target.cmake
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin/thread && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/thread.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/thread/CMakeFiles/thread.dir/build: bin/thread/libthread.a
.PHONY : bin/thread/CMakeFiles/thread.dir/build

bin/thread/CMakeFiles/thread.dir/clean:
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin/thread && $(CMAKE_COMMAND) -P CMakeFiles/thread.dir/cmake_clean.cmake
.PHONY : bin/thread/CMakeFiles/thread.dir/clean

bin/thread/CMakeFiles/thread.dir/depend:
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/src/thread /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin/thread /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin/thread/CMakeFiles/thread.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/thread/CMakeFiles/thread.dir/depend

