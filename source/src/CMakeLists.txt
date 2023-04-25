add_library(rpg_engine STATIC)
set_property(TARGET rpg_engine PROPERTY FOLDER lib)
target_compile_features(rpg_engine PUBLIC cxx_std_20)

target_include_directories(rpg_engine PUBLIC ./)

#target_link_libraries(rpg_engine PUBLIC bgfx_interface)
target_link_libraries(rpg_engine PUBLIC glad
                                        glfw
                                        glm)

function(add_engine_subdir FOLDER)
    set(SOURCES "")
    include(${FOLDER}/sources.cmake)
    list(TRANSFORM SOURCES PREPEND "${FOLDER}/")
    target_sources(rpg_engine PRIVATE ${SOURCES})
endfunction(add_engine_subdir)

add_engine_subdir(core)
add_engine_subdir(inputs)
add_engine_subdir(render)
