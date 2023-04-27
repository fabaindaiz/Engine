
#include <iostream>
#include <string>
#include <vector>
#include "core/actor.h"
#include "core/path.h"
#include "core/vec2.h"
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
    
    Engine::Box box1{ {0.0f, 0.0f}, { 2.0f, 1.5f }, Engine::Color::Gray() };
    Engine::Box box2{ {0.0f, 0.75f}, { 0.5f, 0.5f }, Engine::Color::Blue() };
    Engine::Box box3{ {-0.5f, -0.5f}, { 0.75f, 0.75f }, Engine::Color::Red() };
    Engine::Box box4{ {0.0f, 0.0f}, { 1.0f, 1.0f }, Engine::Color::Yellow() };

    Engine::BoxId boxId1 = canvas.addBox(box1);
    Engine::BoxId boxId2 = canvas.addBox(box2);
    Engine::BoxId boxId3 = canvas.addBox(box3);
    Engine::BoxId boxId4 = canvas.addBox(box4);

    Engine::Actor actor1{ Engine::Vec2{0, 0}, Engine::Vec2{0.5f, 0.5f} };
    actor1.addChild({ Engine::Vec2{0, 0}, box1 });

    float speed = 0.0001;
    float d = 0.f;

    Engine::Path path = Engine::Path();
    path.addDestination(Engine::Vec2{ -1, -1 })
        .addDestination(Engine::Vec2{  1,  1 })
        .addDestination(Engine::Vec2{ -1,  1 })
        .addDestination(Engine::Vec2{  1, -1 })
        .addDestination(Engine::Vec2{ -1, -1 });

    auto update = [&](float dt)
    {
        Engine::Box& box = canvas.getBox(boxId2);

        d += speed * dt;
        box.setPosition(path.travel(d));
    };

    Engine::Controller controller;
    controller.onKeyPress(Engine::Key::W, [&]() { speed *= 2.0f; });
    controller.onKeyPress(Engine::Key::S, [&]() { speed /= 2.0f; });
    controller.onKeyPress(Engine::Key::ESCAPE, [&]() { canvas.close(); });

    canvas.drawScene(controller, update); //runScene
    
    return 0;
}