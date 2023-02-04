cmake_minimum_required(VERSION 3.16)
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "FATAL: 禁止在源文件目录 build")
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} cmake)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV 4 REQUIRED)
include_directories(SYSTEM ${OpenCV_INCLUDE_DIRS})
message(${OpenCV_INCLUDE_DIRS})
link_libraries(${OpenCV_LIBS})

add_executable(rm_vision main.cpp)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thread)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/arms_detector)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/original_images_get)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/arm_light)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/conf_read)

target_link_libraries(rm_vision thread)
target_link_libraries(rm_vision arms_detector)
target_link_libraries(rm_vision original_images_get)
target_link_libraries(rm_vision arm_light)
target_link_libraries(rm_vision conf_read)


