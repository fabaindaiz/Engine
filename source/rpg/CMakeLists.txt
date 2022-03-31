function(run_main TARGETNAME FILENAME)
	add_executable(${TARGETNAME} ${FILENAME})
	set_property(TARGET ${TARGETNAME} PROPERTY CXX_STANDARD 20)
	set_property(TARGET ${TARGETNAME} PROPERTY FOLDER rpg)
	target_link_libraries(${TARGETNAME} PRIVATE engine)
	target_include_directories(${TARGETNAME} PRIVATE ${ENGINE_INCLUDE_DIRECTORY} ${THIRD_PARTY_INCLUDE_DIRECTORIES})
endfunction(run_main)

run_main(rpg main.cpp)