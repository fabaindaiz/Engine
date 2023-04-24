#include <glad/gl.h>
#include "bgfx/bgfx.h"
#include "bgfx/platform.h"
#include "bx/math.h"
#include <glfw/glfw3.h>z


#define WNDW_WIDTH 960
#define WNDW_HEIGHT 540

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

void renderInit() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(WNDW_WIDTH, WNDW_HEIGHT, "LearnOpenGL", NULL, NULL);
	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, key_callback);

	bgfx::Init bgfxInit;
	bgfxInit.type = bgfx::RendererType::Count;
	//bgfxInit.type = bgfx::RendererType::Vulkan;
	//bgfxInit.type = bgfx::RendererType::OpenGL;

	bgfxInit.resolution.width = WNDW_WIDTH;
	bgfxInit.resolution.height = WNDW_HEIGHT;
	bgfxInit.resolution.reset = BGFX_RESET_VSYNC;

	bgfx::init(bgfxInit);
	bgfx::setViewClear(0, BGFX_CLEAR_COLOR | BGFX_CLEAR_DEPTH, 0x443355FF, 1.0f, 0);
	bgfx::setViewRect(0, 0, 0, WNDW_WIDTH, WNDW_HEIGHT);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		bgfx::frame();
	}

	bgfx::shutdown();

	glfwDestroyWindow(window);
	glfwTerminate();

}
