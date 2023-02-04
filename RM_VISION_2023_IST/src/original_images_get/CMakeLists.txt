get_filename_component(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${PROJECT_DIR})
if (TARGET ${PROJECT_NAME})
    return()
endif()

add_library(${PROJECT_NAME})

target_include_directories( ${PROJECT_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/original_images_get
    PRIVATE
        /opt/HuarayTech/MVviewer/include
)

target_sources( ${PROJECT_NAME}
    PRIVATE
        src/camera_deal.cpp
        src/daheng_camera.cpp
        src/dahua.cpp
        src/img_get.cpp
)

target_link_libraries( ${PROJECT_NAME}
    PRIVATE
        /usr/lib/libgxiapi.so
        /opt/HuarayTech/MVviewer/lib/libMVSDK.so
)
