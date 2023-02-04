get_filename_component(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${PROJECT_DIR})

add_library(${PROJECT_NAME})

string(REGEX REPLACE "(.*)/(.*)" "\\1" PROJECT_INIT_PATH  ${PROJECT_SOURCE_DIR})
message("building the arm_detect")

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/arms_detector
        ${PROJECT_INIT_PATH}/arm_light/include
) 

target_sources(${PROJECT_NAME}
    PRIVATE
    	src/img_deal.cpp
        src/arms_detect.cpp
        src/classifier_shape_of_armor.cpp
)