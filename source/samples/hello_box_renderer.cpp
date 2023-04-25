
#include <iostream>
#include <string>
#include <vector>
#include <ciso646>
#include "render/canvas.h"
#include "render/color.h"
#include "render/box.h"
#include "inputs/controller.h"
#include "inputs/keyboard.h"


int main()
{
    // settings
    constexpr unsigned int SCR_WIDTH = 600;
    constexpr unsigned int SCR_HEIGHT = 600;

    Engine::Canvas canvas(SCR_WIDTH, SCR_HEIGHT, "Hello Box Renderer!");

    canvas.setBackgroundColor(Engine::Color::White());
    
    Engine::BoxId boxId1 = canvas.addBox({ {0.0f, 0.0f}, { 2.0f, 1.5f }, Engine::Color::Gray() });
    Engine::BoxId boxId2 = canvas.addBox({ {0.0f, 0.75f}, { 0.5f, 0.5f }, Engine::Color::Blue() });
    Engine::BoxId boxId3 = canvas.addBox({ {-0.5f, -0.5f}, { 0.75f, 0.75f }, Engine::Color::Red() });
    Engine::BoxId boxId4 = canvas.addBox({ {0.0f, 0.0f}, { 1.0f, 1.0f }, Engine::Color::Yellow() });

    bool movingRight = true;
    float speed = 0.0001;

    auto update = [&](float dt)
    {
        Engine::Box& box = canvas.getBox(boxId2);

        if (movingRight)
            box.position().x() += speed * dt;
        else
            box.position().x() -= speed * dt;

        if (box.position().x() > 0.5)
            movingRight = false;
        else if (box.position().x() < -0.5)
            movingRight = true;
    };

    Engine::Controller controller;
    controller.onKeyPress(Engine::Key::W, [&]() { speed *= 2.0f; });
    controller.onKeyPress(Engine::Key::S, [&]() { speed /= 2.0f; });
    controller.onKeyPress(Engine::Key::ESCAPE, [&]() { canvas.close(); });

    canvas.drawScene(controller, update); //runScene
    
    return 0;
}