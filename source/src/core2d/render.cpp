#include <glad/glad.h>
#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include "bx/math.h"
#include <glfw/glfw3.h>


#define WNDW_WIDTH 960
#define WNDW_HEIGHT 540

void renderInit() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(WNDW_WIDTH, WNDW_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		glfwTerminate();
	}

	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window))
	{
		bgfx::Init bgfxInit;
		bgfxInit.resolution.width = WNDW_WIDTH;
		bgfxInit.resolution.height = WNDW_HEIGHT;
		bgfxInit.resolution.reset = BGFX_RESET_VSYNC;
		glfwTerminate();
	}

	bgfx::shutdown();

	glfwDestroyWindow(window);
	glfwTerminate();

}
