function(run_main TARGETNAME FILENAME)
	add_executable(${TARGETNAME} ${FILENAME})
	set_property(TARGET ${TARGETNAME} PROPERTY CXX_STANDARD 20)
	set_property(TARGET ${TARGETNAME} PROPERTY FOLDER rpg)
	target_link_libraries(${TARGETNAME} PRIVATE engine ${EXT_LIBRARIES})
	add_dependencies(rpg ${SHADERS})
endfunction(run_main)

run_main(rpg main.cpp)