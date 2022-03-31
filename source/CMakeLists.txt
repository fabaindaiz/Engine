cmake_minimum_required(VERSION 3.20)
set(CMAKE_LEGACY_CYGWIN_WIN32 OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(OpenGL REQUIRED)

project(rpg C CXX)

set(THIRD_PARTY_INCLUDE_DIRECTORIES 
	"${CMAKE_CURRENT_SOURCE_DIR}/third-party/glad/include"
	"${CMAKE_CURRENT_SOURCE_DIR}/third-party/glfw-3.3.6/include")
set(ENGINE_INCLUDE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/source")

set(THIRD_PARTY_LIBRARIES glad glfw)

add_subdirectory(third-party)
add_subdirectory(source)
add_subdirectory(rpg)
