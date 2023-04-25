#glad
add_subdirectory(glad)

# glm
add_subdirectory(glm)

#glfw
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_INSTALL OFF)
add_subdirectory(glfw)

# bgfx
#set(BGFX_OPENGL_VERSION ${OPENGL_VERSION})
#add_subdirectory(bgfx.cmake)
#add_library(bgfx_interface INTERFACE)
#target_link_libraries(bgfx_interface INTERFACE bgfx bx bimg)