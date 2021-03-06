cmake_minimum_required(VERSION 3.20)
set(CMAKE_LEGACY_CYGWIN_WIN32 OFF)
project(engine C CXX)

set(ENGINE_HEADERS
	core2d/actor.h
	core2d/bounding_box.h
	core2d/geometric_functions.h
	core2d/render.h
	core2d/vector2d_functions.h
	core2d/vector2d.h
 )
set(ENGINE_SOURCES
	core2d/actor.cpp
	core2d/bounding_box.cpp
	core2d/geometric_functions.cpp
	core2d/render.cpp
	core2d/vector2d_functions.cpp
	core2d/vector2d.cpp
 )

add_library(engine STATIC ${ENGINE_SOURCES} ${ENGINE_HEADERS})
if (MSVC)
    target_compile_options(engine PUBLIC /wd5033)
endif(MSVC)
target_include_directories(engine PRIVATE ${THIRD_PARTY_INCLUDE_DIRECTORIES} ENGINE_INCLUDE_DIRECTORY)
target_link_libraries(engine PRIVATE ${THIRD_PARTY_LIBRARIES})
set_property(TARGET engine PROPERTY CXX_STANDARD 20)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ENGINE_SOURCES} ${ENGINE_HEADERS})
