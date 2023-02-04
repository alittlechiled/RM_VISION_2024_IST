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
include bin/CMakeFiles/rm_vision.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include bin/CMakeFiles/rm_vision.dir/compiler_depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/rm_vision.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/rm_vision.dir/flags.make

bin/CMakeFiles/rm_vision.dir/main.cpp.o: bin/CMakeFiles/rm_vision.dir/flags.make
bin/CMakeFiles/rm_vision.dir/main.cpp.o: ../src/main.cpp
bin/CMakeFiles/rm_vision.dir/main.cpp.o: bin/CMakeFiles/rm_vision.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object bin/CMakeFiles/rm_vision.dir/main.cpp.o"
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT bin/CMakeFiles/rm_vision.dir/main.cpp.o -MF CMakeFiles/rm_vision.dir/main.cpp.o.d -o CMakeFiles/rm_vision.dir/main.cpp.o -c /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/src/main.cpp

bin/CMakeFiles/rm_vision.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rm_vision.dir/main.cpp.i"
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/src/main.cpp > CMakeFiles/rm_vision.dir/main.cpp.i

bin/CMakeFiles/rm_vision.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rm_vision.dir/main.cpp.s"
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/src/main.cpp -o CMakeFiles/rm_vision.dir/main.cpp.s

# Object files for target rm_vision
rm_vision_OBJECTS = \
"CMakeFiles/rm_vision.dir/main.cpp.o"

# External object files for target rm_vision
rm_vision_EXTERNAL_OBJECTS =

bin/rm_vision: bin/CMakeFiles/rm_vision.dir/main.cpp.o
bin/rm_vision: bin/CMakeFiles/rm_vision.dir/build.make
bin/rm_vision: bin/thread/libthread.a
bin/rm_vision: bin/arms_detector/libarms_detector.a
bin/rm_vision: bin/original_images_get/liboriginal_images_get.a
bin/rm_vision: bin/arm_light/libarm_light.a
bin/rm_vision: bin/conf_read/libconf_read.a
bin/rm_vision: /usr/lib/libgxiapi.so
bin/rm_vision: /opt/HuarayTech/MVviewer/lib/libMVSDK.so
bin/rm_vision: /usr/local/lib/libopencv_gapi.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_stitching.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_alphamat.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_aruco.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_barcode.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_bgsegm.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_bioinspired.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_ccalib.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_dnn_objdetect.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_dnn_superres.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_dpm.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_face.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_freetype.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_fuzzy.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_hfs.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_img_hash.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_intensity_transform.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_line_descriptor.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_mcc.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_quality.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_rapid.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_reg.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_rgbd.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_saliency.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_stereo.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_structured_light.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_phase_unwrapping.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_superres.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_optflow.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_surface_matching.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_tracking.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_highgui.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_datasets.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_plot.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_text.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_videostab.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_videoio.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_wechat_qrcode.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_xfeatures2d.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_ml.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_shape.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_ximgproc.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_video.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_dnn.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_xobjdetect.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_imgcodecs.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_objdetect.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_calib3d.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_features2d.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_flann.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_xphoto.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_photo.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_imgproc.so.4.5.3
bin/rm_vision: /usr/local/lib/libopencv_core.so.4.5.3
bin/rm_vision: bin/CMakeFiles/rm_vision.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rm_vision"
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rm_vision.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/rm_vision.dir/build: bin/rm_vision
.PHONY : bin/CMakeFiles/rm_vision.dir/build

bin/CMakeFiles/rm_vision.dir/clean:
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin && $(CMAKE_COMMAND) -P CMakeFiles/rm_vision.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/rm_vision.dir/clean

bin/CMakeFiles/rm_vision.dir/depend:
	cd /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/src /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin /home/shunxiaochuan/RM_VISION_2023_IST/RM_VISION_2023_IST/build/bin/CMakeFiles/rm_vision.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/rm_vision.dir/depend

