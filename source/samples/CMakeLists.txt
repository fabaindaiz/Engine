function(EngineSample TARGETNAME FILENAME)
    add_executable(${TARGETNAME} ${FILENAME})
    set_property(TARGET ${TARGETNAME} PROPERTY CXX_STANDARD 20)
    set_property(TARGET ${TARGETNAME} PROPERTY FOLDER samples)
    target_link_libraries(${TARGETNAME} PRIVATE rpg_engine)
endfunction(EngineSample)

EngineSample(test_cpp test_cpp.cpp)
EngineSample(test_core test_core.cpp)
EngineSample(test_audio test_audio.cpp)
EngineSample(test_opengl test_opengl.cpp)

EngineSample(test_render test_render.cpp)