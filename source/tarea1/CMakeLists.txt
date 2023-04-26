function(EngineMain TARGETNAME FILENAME)
    add_executable(${TARGETNAME} ${FILENAME})
    set_property(TARGET ${TARGETNAME} PROPERTY CXX_STANDARD 20)
    set_property(TARGET ${TARGETNAME} PROPERTY FOLDER samples)
    target_link_libraries(${TARGETNAME} PRIVATE rpg_engine)
endfunction(EngineMain)

EngineMain(tarea1 main.cpp)