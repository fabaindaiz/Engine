add_executable(rpg_main main.cpp)
set_property(TARGET rpg_main PROPERTY CXX_STANDARD 20)
target_link_libraries(rpg_main PRIVATE rpg_engine)