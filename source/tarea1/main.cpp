#include <iostream>
#include "core/actor.h"
#include "core/bounding_box.h"
#include "core/vec2.h"
#include "core/vec2_functions.h"
#include "core/path.h"
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

    float time = 0.0f;
    int frames = 0;

    Engine::Canvas canvas(SCR_WIDTH, SCR_HEIGHT, "Hello Box Renderer!");
    canvas.setBackgroundColor(Engine::Color::White());

    // Static
    Engine::Actor final{ { 0.0f, 1.0f}, { 2.0f, 0.1f} };
    Engine::Actor lose1{ { -1.1f, 0.0f}, { 0.1f, 2.0f} };
    Engine::Actor lose2{ { 1.1f, 0.0f}, { 0.1f, 2.0f} };

    // Frog
    Engine::Actor frog{ { 0.0f, -0.9f}, { 0.06f, 0.06f}};

    Engine::BoxId id_frog_body = canvas.addBox({ { 0.0f, 0.0f}, { 0.12f, 0.12f}, Engine::Color::Green() });
    Engine::BoxId id_frog_back = canvas.addBox({ { 0.0f, 0.0f}, { 0.08f, 0.08f}, Engine::Color::Lime() });
    Engine::BoxId id_frog_eye1 = canvas.addBox({ { 0.0f, 0.0f}, { 0.02f, 0.02f}, Engine::Color::Yellow() });
    Engine::BoxId id_frog_eye2 = canvas.addBox({ { 0.0f, 0.0f}, { 0.02f, 0.02f}, Engine::Color::Yellow() });

    // Truck1
    Engine::Actor truck1{ {0.0f, 0.0f}, { 0.1f, 0.06f} };
    float truck1_speed = 0.0004f;
    float truck1_offset = 0.2f;

    Engine::Path truck1_path = Engine::Path();
    truck1_path.addDestination({ -1.5f, 0.0f }).addDestination({ 1.5f, 0.0f });

    Engine::BoxId id_truck1_body = canvas.addBox({ { 0.0f, 0.0f}, { 0.2f, 0.12f}, Engine::Color::Gray() });
    Engine::BoxId id_truck1_back = canvas.addBox({ { 0.0f, 0.0f}, { 0.1f, 0.1f}, Engine::Color::Red() });

    // Truck2
    Engine::Actor truck2{ {0.0f, 0.0f}, { 0.1f, 0.06f} };
    float truck2_speed = 0.0004f;
    float truck2_offset = -0.2f;

    Engine::Path truck2_path = Engine::Path();
    truck2_path.addDestination({ -1.5f, 0.0f }).addDestination({ 1.5f, 0.0f });

    Engine::BoxId id_truck2_body = canvas.addBox({ { 0.0f, 0.0f}, { 0.2f, 0.12f}, Engine::Color::Gray() });
    Engine::BoxId id_truck2_back = canvas.addBox({ { 0.0f, 0.0f}, { 0.1f, 0.1f}, Engine::Color::Red() });

    // Truck2
    Engine::Actor truck3{ {0.0f, 0.0f}, { 0.1f, 0.06f} };
    float truck3_speed = 0.0003f;
    float truck3_offset = -0.5f;

    Engine::Path truck3_path = Engine::Path();
    truck3_path.addDestination({ 1.5f, 0.15f }).addDestination({ -1.5f, 0.15f });

    Engine::BoxId id_truck3_body = canvas.addBox({ { 0.0f, 0.0f}, { 0.2f, 0.12f}, Engine::Color::Gray() });
    Engine::BoxId id_truck3_back = canvas.addBox({ { 0.0f, 0.0f}, { 0.1f, 0.1f}, Engine::Color::Red() });


    // Updated boxes
    Engine::Box& frog_body = canvas.getBox(id_frog_body);
    Engine::Box& frog_back = canvas.getBox(id_frog_back);
    Engine::Box& frog_eye1 = canvas.getBox(id_frog_eye1);
    Engine::Box& frog_eye2 = canvas.getBox(id_frog_eye2);

    Engine::Box& truck1_body = canvas.getBox(id_truck1_body);
    Engine::Box& truck1_back = canvas.getBox(id_truck1_back);

    Engine::Box& truck2_body = canvas.getBox(id_truck2_body);
    Engine::Box& truck2_back = canvas.getBox(id_truck2_back);
    
    Engine::Box& truck3_body = canvas.getBox(id_truck3_body);
    Engine::Box& truck3_back = canvas.getBox(id_truck3_back);


    auto update = [&](float dt)
    {
        time += dt;
        frames += 1;
        
        //std::cout << frog.position() << std::endl;

        if (frog.collide(final)) {
            canvas.addBox({ { 0.0f, 0.0f}, { 2.0f, 2.0f}, Engine::Color::Red() });
        }
        if (frog.collide(lose1)) frog.setPosition({ 0.0f, -0.9f});
        if (frog.collide(lose2)) frog.setPosition({ 0.0f, -0.9f});

        // Frog
        frog_body.setPosition(frog.position());
        frog_back.setPosition(frog.position());
        frog_eye1.setPosition(frog.position() + Engine::Vec2{-0.04f, 0.05});
        frog_eye2.setPosition(frog.position() + Engine::Vec2{ 0.04f, 0.05});

        // Truck1
        if (frog.collide(truck1)) frog.setPosition({ 0.0f, -0.9f });
        truck1.setPosition(truck1_path.travel(truck1_speed * time + truck1_offset));
        truck1_body.setPosition(truck1.position());
        truck1_back.setPosition(truck1.position() + Engine::Vec2{ 0.08f, 0.0f});

        // Truck2
        if (frog.collide(truck2)) frog.setPosition({ 0.0f, -0.9f });
        truck2.setPosition(truck2_path.travel(truck2_speed * time + truck2_offset));
        truck2_body.setPosition(truck2.position());
        truck2_back.setPosition(truck2.position() + Engine::Vec2{ 0.08f, 0.0f });

        // Truck3
        if (frog.collide(truck3)) frog.setPosition({ 0.0f, -0.9f });
        truck3.setPosition(truck3_path.travel(truck3_speed * time + truck3_offset));
        truck3_body.setPosition(truck3.position());
        truck3_back.setPosition(truck3.position() + Engine::Vec2{ -0.08f, 0.0f });

    };


    Engine::Controller controller;
    controller.onKeyPress(Engine::Key::W, [&]() { frog.setPosition(frog.position() + Engine::Vec2{ 0.0f, 0.15f}); });
    controller.onKeyPress(Engine::Key::A, [&]() { frog.setPosition(frog.position() + Engine::Vec2{ -0.15f, 0.0f}); });
    controller.onKeyPress(Engine::Key::D, [&]() { frog.setPosition(frog.position() + Engine::Vec2{ 0.15f, 0.0f }); });
    controller.onKeyPress(Engine::Key::ESCAPE, [&]() { canvas.close(); });

    //runScene
    canvas.drawScene(controller, update);

    return 0;
}