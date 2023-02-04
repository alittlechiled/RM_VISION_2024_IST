get_filename_component(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR} NAME)

project(${PROJECT_DIR})
string(REGEX REPLACE "(.*)/(.*)" "\\1" PROJECT_INIT_PATH  ${PROJECT_SOURCE_DIR})
message("top filder is " ${PROJECT_INIT_PATH})

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        /usr/local/include/usr/local/include/fmt
        /usr/local/include/toml
        ${PROJECT_INIT_PATH}/conf_read/include
        ${PROJECT_INIT_PATH}/arm_light/include
        ${PROJECT_INIT_PATH}/arms_detector/include/arms_detector
        /opt/HuarayTech/MVviewer/include
        ${PROJECT_INIT_PATH}/original_images_get/include/original_images_get
        ${CMAKE_CURRENT_SOURCE_DIR}/include/thread
    	
        
) 

target_sources(${PROJECT_NAME}
    PRIVATE
    	src/detect_thread.cpp
        src/image_get_thread.cpp
)

