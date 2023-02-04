get_filename_component(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${PROJECT_DIR})

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC
    	${CMAKE_CURRENT_SOURCE_DIR}/include
) 

target_sources( ${PROJECT_NAME}
    PRIVATE
        src/arm_and_light.cpp
)

