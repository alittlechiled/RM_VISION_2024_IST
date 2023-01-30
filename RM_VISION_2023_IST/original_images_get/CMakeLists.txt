cmake_minimum_required(VERSION 3.8)
project(original_images_get)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake_auto REQUIRED)

ament_auto_find_build_dependencies()
include_directories(SYSTEM /usr/local/include/opencv4)

include_directories(SYSTEM /opt/HuarayTech/MVviewer/include)

include_directories(SYSTEM /home/shunxiaochuan/all_folders/vinland-robomaster-2022-REDO-src/rm_capture-src-rm_capture/src/rm_capture/3rdparty/daheng)

include_directories(include/original_images_get/)

ament_auto_add_library (camera_deal_lib SHARED 
  DIRECTORY    
    src 
)
    
ament_auto_package()
