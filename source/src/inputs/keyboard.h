#pragma once


namespace Engine
{

enum class Key : unsigned int
{
    W = 0, A, S, D, Q, E,
    _1, _2, _3, _4,
    LEFT, RIGHT, UP, DOWN,
    SPACE, ESCAPE, ENTER,
    SIZEOF
};

namespace KeyboardImplementation
{
    using GLFWKeyCode = int;

    GLFWKeyCode toGLFWKeyCode(Key aliceKey);

    Key toAliceKeyCode(GLFWKeyCode glfwKeyCode);
}

} // namespace Engine