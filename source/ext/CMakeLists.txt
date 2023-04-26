# glad
add_subdirectory(glad)

# glfw
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_INSTALL OFF)
add_subdirectory(glfw)

# glm
add_subdirectory(glm)

# miniaudio
add_subdirectory(miniaudio)