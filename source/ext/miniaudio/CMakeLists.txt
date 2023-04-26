add_library(miniaudio STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/miniaudio.cpp)
target_include_directories(miniaudio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)