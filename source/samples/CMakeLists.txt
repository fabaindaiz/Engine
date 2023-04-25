add_executable(test_opengl test_opengl.cpp)
set_property(TARGET test_opengl PROPERTY CXX_STANDARD 20)
set_property(TARGET rpg_main PROPERTY FOLDER samples)
target_link_libraries(test_opengl PRIVATE rpg_engine)

add_executable(test_cpp test_cpp.cpp)
set_property(TARGET test_cpp PROPERTY CXX_STANDARD 20)
set_property(TARGET rpg_main PROPERTY FOLDER samples)
target_link_libraries(test_cpp PRIVATE rpg_engine)

add_executable(hello_box_renderer hello_box_renderer.cpp)
set_property(TARGET hello_box_renderer PROPERTY CXX_STANDARD 20)
set_property(TARGET rpg_main PROPERTY FOLDER samples)
target_link_libraries(hello_box_renderer PRIVATE rpg_engine)