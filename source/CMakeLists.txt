cmake_minimum_required(VERSION 3.20)
set(CMAKE_LEGACY_CYGWIN_WIN32 OFF)

project(code_as_static_library C CXX)

add_library(arrow_lib STATIC
    "actor.h"
    "actor.cpp"
    "bounding_box.h"
    "bounding_box.cpp"
    "geometric_functions.h"
    "geometric_functions.cpp"
    "vector2d_functions.h"
    "vector2d_functions.cpp"
    "vector2d.h"
    "vector2d.cpp"
)

add_executable(main "main.cpp")
set_property(TARGET main PROPERTY CXX_STANDARD 20)

# Here we bind the library

## Headers are in this directory
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

## We need the path to the librady binary
target_link_libraries(main PRIVATE arrow_lib)
