#include "keyboard.h"
#include <GLFW/glfw3.h>


namespace Engine
{

    namespace KeyboardImplementation
    {

        GLFWKeyCode toGLFWKeyCode(Key aliceKey)
        {
            switch (aliceKey)
            {
            case Key::W: return GLFW_KEY_W;
            case Key::A: return GLFW_KEY_A;
            case Key::S: return GLFW_KEY_S;
            case Key::D: return GLFW_KEY_D;
            case Key::Q: return GLFW_KEY_Q;
            case Key::E: return GLFW_KEY_E;
            case Key::_1: return GLFW_KEY_1;
            case Key::_2: return GLFW_KEY_2;
            case Key::_3: return GLFW_KEY_3;
            case Key::_4: return GLFW_KEY_4;
            case Key::UP: return GLFW_KEY_UP;
            case Key::DOWN: return GLFW_KEY_DOWN;
            case Key::LEFT: return GLFW_KEY_LEFT;
            case Key::RIGHT: return GLFW_KEY_RIGHT;
            case Key::SPACE: return GLFW_KEY_SPACE;
            case Key::ESCAPE: return GLFW_KEY_ESCAPE;
            case Key::ENTER: return GLFW_KEY_ENTER;
            default: throw;
            };
        }

        Key toAliceKeyCode(GLFWKeyCode glfwKeyCode)
        {
            switch (glfwKeyCode)
            {
            case GLFW_KEY_W: return Key::W;
            case GLFW_KEY_A: return Key::A;
            case GLFW_KEY_S: return Key::S;
            case GLFW_KEY_D: return Key::D;
            case GLFW_KEY_Q: return Key::Q;
            case GLFW_KEY_E: return Key::E;
            case GLFW_KEY_1: return Key::_1;
            case GLFW_KEY_2: return Key::_2;
            case GLFW_KEY_3: return Key::_3;
            case GLFW_KEY_4: return Key::_4;
            case GLFW_KEY_UP: return Key::UP;
            case GLFW_KEY_DOWN: return Key::DOWN;
            case GLFW_KEY_LEFT: return Key::LEFT;
            case GLFW_KEY_RIGHT: return Key::RIGHT;
            case GLFW_KEY_SPACE: return Key::SPACE;
            case GLFW_KEY_ESCAPE: return Key::ESCAPE;
            case GLFW_KEY_ENTER: return Key::ENTER;
            default: throw;
            };
        }

    } // namespace KeyboardImplementation

} // namespace Engine