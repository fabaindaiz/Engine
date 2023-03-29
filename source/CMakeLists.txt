cmake_minimum_required(VERSION 3.16.0)
project(RPGEngine VERSION 0.1.0
                  LANGUAGES C CXX)

find_package(OpenGL REQUIRED)
set(OPENGL_VERSION "46")

find_package(Doxygen)

# external dependencies
add_subdirectory(ext)

# shaderc
include(shaderc.cmake)

# configure engine library
add_subdirectory(src)

# add game directory
add_subdirectory(rpg)

# documentation
if(DOXYGEN_FOUND)
    set(DOXYGEN_USE_MDFILE_AS_MAINPAGE README.md)
    set(DOXYGEN_OUTPUT_LANGUAGE SPANISH)

    doxygen_add_docs(rpg_docs src README.md)
endif()
