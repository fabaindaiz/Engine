cmake_minimum_required(VERSION 3.16.0)
project(RPGEngine VERSION 0.1.0
                  LANGUAGES C CXX)

find_package(OpenGL REQUIRED)
set(OPENGL_VERSION "44")

# external dependencies
add_subdirectory(ext)

# shaderc
#include(shaderc.cmake)

# configure engine library
add_subdirectory(src)

# add game directory
add_subdirectory(rpg)
add_subdirectory(samples)