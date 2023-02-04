get_filename_component(PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${PROJECT_DIR})

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        /usr/local/include/usr/local/include/fmt
        /usr/local/include/toml
    	${CMAKE_CURRENT_SOURCE_DIR}/include
        
) 

target_sources(${PROJECT_NAME}
    PRIVATE
    	src/conf_read.cpp
)

