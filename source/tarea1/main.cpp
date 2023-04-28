#include <iostream>
#include <chrono>
#include "audio/sound.h"
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

    int deltaTime = 10;
    float deltaTimeFloat = static_cast<float>(deltaTime);
    std::chrono::milliseconds duration{ deltaTime };

    Engine::SoundManager soundManager = Engine::SoundManager();

    Engine::Canvas canvas(SCR_WIDTH, SCR_HEIGHT, "Hello Box Renderer!");
    canvas.setBackgroundColor(Engine::Color::White());

    // Static
    Engine::Actor final{ { 0.0f, 1.0f}, { 2.0f, 0.1f} };
    Engine::Actor lose1{ { -1.1f, 0.0f}, { 0.1f, 2.0f} };
    Engine::Actor lose2{ { 1.1f, 0.0f}, { 0.1f, 2.0f} };

    // Frog
    Engine::Actor frog{ { 0.0f, -0.9f}, { 0.05f, 0.05f}};

    Engine::BoxId id_frog_body = canvas.addBox({ { 0.0f, 0.0f}, { 0.1f, 0.1f}, Engine::Color::Green() });
    Engine::BoxId id_frog_back = canvas.addBox({ { 0.0f, 0.0f}, { 0.06f, 0.06f}, Engine::Color::Lime() });
    Engine::BoxId id_frog_eye1 = canvas.addBox({ { 0.0f, 0.0f}, { 0.02f, 0.02f}, Engine::Color::Yellow() });
    Engine::BoxId id_frog_eye2 = canvas.addBox({ { 0.0f, 0.0f}, { 0.02f, 0.02f}, Engine::Color::Yellow() });

    // Truck1
    Engine::Actor truck1{ {0.0f, 0.0f}, { 0.15f, 0.06f} };
    float truck1_speed = 0.0004f;
    float truck1_offset = 0.2f;

    Engine::Path truck1_path = Engine::Path();
    truck1_path.addDestination({ -1.5f, -0.15f }).addDestination({ 1.5f, -0.15f });

    Engine::BoxId id_truck1_body = canvas.addBox({ { 0.0f, 0.0f}, { 0.3f, 0.12f}, Engine::Color::Gray() });
    Engine::BoxId id_truck1_back = canvas.addBox({ { 0.0f, 0.0f}, { 0.1f, 0.1f}, Engine::Color::Red() });

    // Truck2
    Engine::Actor truck2{ {0.0f, 0.0f}, { 0.15f, 0.06f} };
    float truck2_speed = 0.0004f;
    float truck2_offset = -0.2f;

    Engine::Path truck2_path = Engine::Path();
    truck2_path.addDestination({ -1.5f, -0.15f }).addDestination({ 1.5f, -0.15f });

    Engine::BoxId id_truck2_body = canvas.addBox({ { 0.0f, 0.0f}, { 0.3f, 0.12f}, Engine::Color::Gray() });
    Engine::BoxId id_truck2_back = canvas.addBox({ { 0.0f, 0.0f}, { 0.1f, 0.1f}, Engine::Color::Red() });

    // Truck3
    Engine::Actor truck3{ {0.0f, 0.0f}, { 0.15f, 0.06f} };
    float truck3_speed = 0.00035f;
    float truck3_offset = -0.5f;

    Engine::Path truck3_path = Engine::Path();
    truck3_path.addDestination({ 1.5f, 0.0f }).addDestination({ -1.5f, 0.0f });

    Engine::BoxId id_truck3_body = canvas.addBox({ { 0.0f, 0.0f}, { 0.3f, 0.12f}, Engine::Color::Gray() });
    Engine::BoxId id_truck3_back = canvas.addBox({ { 0.0f, 0.0f}, { 0.1f, 0.1f}, Engine::Color::Red() });

    // Truck4
    Engine::Actor truck4{ {0.0f, 0.0f}, { 0.15f, 0.06f} };
    float truck4_speed = 0.00035f;
    float truck4_offset = -0.5f;

    Engine::Path truck4_path = Engine::Path();
    truck4_path.addDestination({ 1.5f, 0.0f }).addDestination({ -1.5f, 0.0f });

    Engine::BoxId id_truck4_body = canvas.addBox({ { 0.0f, 0.0f}, { 0.3f, 0.12f}, Engine::Color::Gray() });
    Engine::BoxId id_truck4_back = canvas.addBox({ { 0.0f, 0.0f}, { 0.1f, 0.1f}, Engine::Color::Red() });

    // Truck5
    Engine::Actor truck5{ {0.0f, 0.0f}, { 0.15f, 0.06f} };
    float truck5_speed = 0.0003f;
    float truck5_offset = 0.0f;

    Engine::Path truck5_path = Engine::Path();
    truck5_path.addDestination({ 1.5f, -0.3f }).addDestination({ -1.5f, -0.3f });

    Engine::BoxId id_truck5_body = canvas.addBox({ { 0.0f, 0.0f}, { 0.3f, 0.12f}, Engine::Color::Gray() });
    Engine::BoxId id_truck5_back = canvas.addBox({ { 0.0f, 0.0f}, { 0.1f, 0.1f}, Engine::Color::Red() });

    // Car1
    Engine::Actor car1{ {0.0f, 0.0f}, { 0.05f, 0.04f} };
    float car1_speed = 0.0005f;
    float car1_offset = -0.5f;

    Engine::Path car1_path = Engine::Path();
    car1_path.addDestination({ 1.5f, 0.3f }).addDestination({ -1.5f, 0.3f });

    Engine::BoxId id_car1_body = canvas.addBox({ { 0.0f, 0.0f}, { 0.1f, 0.08f}, Engine::Color::Navy() });
    Engine::BoxId id_car1_back = canvas.addBox({ { 0.0f, 0.0f}, { 0.03f, 0.06f}, Engine::Color::Aqua() });

    // Car2
    Engine::Actor car2{ {0.0f, 0.0f}, { 0.05f, 0.04f} };
    float car2_speed = 0.0005f;
    float car2_offset = -0.15f;

    Engine::Path car2_path = Engine::Path();
    car2_path.addDestination({ 1.5f, 0.3f }).addDestination({ -1.5f, 0.3f });

    Engine::BoxId id_car2_body = canvas.addBox({ { 0.0f, 0.0f}, { 0.1f, 0.08f}, Engine::Color::Navy() });
    Engine::BoxId id_car2_back = canvas.addBox({ { 0.0f, 0.0f}, { 0.03f, 0.06f}, Engine::Color::Aqua() });

    // Car3
    Engine::Actor car3{ {0.0f, 0.0f}, { 0.05f, 0.04f} };
    float car3_speed = 0.00045f;
    float car3_offset = 0.16f;

    Engine::Path car3_path = Engine::Path();
    car3_path.addDestination({ -1.5f, 0.45f }).addDestination({ 1.5f, 0.45f });

    Engine::BoxId id_car3_body = canvas.addBox({ { 0.0f, 0.0f}, { 0.1f, 0.08f}, Engine::Color::Navy() });
    Engine::BoxId id_car3_back = canvas.addBox({ { 0.0f, 0.0f}, { 0.03f, 0.06f}, Engine::Color::Aqua() });

    // Car4
    Engine::Actor car4{ {0.0f, 0.0f}, { 0.05f, 0.04f} };
    float car4_speed = 0.00045f;
    float car4_offset = -0.45f;

    Engine::Path car4_path = Engine::Path();
    car4_path.addDestination({ -1.5f, 0.45f }).addDestination({ 1.5f, 0.45f });

    Engine::BoxId id_car4_body = canvas.addBox({ { 0.0f, 0.0f}, { 0.1f, 0.08f}, Engine::Color::Navy() });
    Engine::BoxId id_car4_back = canvas.addBox({ { 0.0f, 0.0f}, { 0.03f, 0.06f}, Engine::Color::Aqua() });

    // Car5
    Engine::Actor car5{ {0.0f, 0.0f}, { 0.05f, 0.04f} };
    float car5_speed = 0.0004f;
    float car5_offset = -0.45f;

    Engine::Path car5_path = Engine::Path();
    car5_path.addDestination({ -1.5f, 0.15f }).addDestination({ 1.5f, 0.15f });

    Engine::BoxId id_car5_body = canvas.addBox({ { 0.0f, 0.0f}, { 0.1f, 0.08f}, Engine::Color::Navy() });
    Engine::BoxId id_car5_back = canvas.addBox({ { 0.0f, 0.0f}, { 0.03f, 0.06f}, Engine::Color::Aqua() });

    // Tractor1
    Engine::Actor tractor1{ {0.0f, 0.0f}, { 0.1f, 0.05f} };
    float tractor1_speed = 0.00025f;
    float tractor1_offset = 0.2f;

    Engine::Path tractor1_path = Engine::Path();
    tractor1_path.addDestination({ -1.5f, -0.45f }).addDestination({ 1.5f, -0.45f });

    Engine::BoxId id_tractor1_body = canvas.addBox({ { 0.0f, 0.0f}, { 0.2f, 0.1f}, Engine::Color::Green() });
    Engine::BoxId id_tractor1_back = canvas.addBox({ { 0.0f, 0.0f}, { 0.06f, 0.08f}, Engine::Color::Yellow() });

    // Tractor2
    Engine::Actor tractor2{ {0.0f, 0.0f}, { 0.1f, 0.05f} };
    float tractor2_speed = 0.0002f;
    float tractor2_offset = 0.5f;

    Engine::Path tractor2_path = Engine::Path();
    tractor2_path.addDestination({ 1.5f, -0.6f }).addDestination({ -1.5f, -0.6f });

    Engine::BoxId id_tractor2_body = canvas.addBox({ { 0.0f, 0.0f}, { 0.2f, 0.1f}, Engine::Color::Green() });
    Engine::BoxId id_tractor2_back = canvas.addBox({ { 0.0f, 0.0f}, { 0.06f, 0.08f}, Engine::Color::Yellow() });

    // Tractor3
    Engine::Actor tractor3{ {0.0f, 0.0f}, { 0.1f, 0.05f} };
    float tractor3_speed = 0.0002f;
    float tractor3_offset = 0.2f;

    Engine::Path tractor3_path = Engine::Path();
    tractor3_path.addDestination({ 1.5f, -0.6f }).addDestination({ -1.5f, -0.6f });

    Engine::BoxId id_tractor3_body = canvas.addBox({ { 0.0f, 0.0f}, { 0.2f, 0.1f}, Engine::Color::Green() });
    Engine::BoxId id_tractor3_back = canvas.addBox({ { 0.0f, 0.0f}, { 0.06f, 0.08f}, Engine::Color::Yellow() });

    // Train1
    Engine::Actor train1{ {0.0f, 0.0f}, { 0.38f, 0.06f} };
    float train1_speed = 0.0003f;
    float train1_offset = 0.2f;

    Engine::Path train1_path = Engine::Path();
    train1_path.addDestination({ 3.0f, 0.6f }).addDestination({ -3.0f, 0.6f });

    Engine::BoxId id_train1_body = canvas.addBox({ { 0.0f, 0.0f}, { 0.25f, 0.12f}, Engine::Color::Gray() });
    Engine::BoxId id_train1_back = canvas.addBox({ { 0.0f, 0.0f}, { 0.25f, 0.12f}, Engine::Color::Gray() });
    Engine::BoxId id_train1_front = canvas.addBox({ { 0.0f, 0.0f}, { 0.25f, 0.12f}, Engine::Color::Gray() });

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

    Engine::Box& truck4_body = canvas.getBox(id_truck4_body);
    Engine::Box& truck4_back = canvas.getBox(id_truck4_back);

    Engine::Box& truck5_body = canvas.getBox(id_truck5_body);
    Engine::Box& truck5_back = canvas.getBox(id_truck5_back);

    Engine::Box& car1_body = canvas.getBox(id_car1_body);
    Engine::Box& car1_back = canvas.getBox(id_car1_back);

    Engine::Box& car2_body = canvas.getBox(id_car2_body);
    Engine::Box& car2_back = canvas.getBox(id_car2_back);

    Engine::Box& car3_body = canvas.getBox(id_car3_body);
    Engine::Box& car3_back = canvas.getBox(id_car3_back);

    Engine::Box& car4_body = canvas.getBox(id_car4_body);
    Engine::Box& car4_back = canvas.getBox(id_car4_back);

    Engine::Box& car5_body = canvas.getBox(id_car5_body);
    Engine::Box& car5_back = canvas.getBox(id_car5_back);

    Engine::Box& tractor1_body = canvas.getBox(id_tractor1_body);
    Engine::Box& tractor1_back = canvas.getBox(id_tractor1_back);

    Engine::Box& tractor2_body = canvas.getBox(id_tractor2_body);
    Engine::Box& tractor2_back = canvas.getBox(id_tractor2_back);

    Engine::Box& tractor3_body = canvas.getBox(id_tractor3_body);
    Engine::Box& tractor3_back = canvas.getBox(id_tractor3_back);

    Engine::Box& train1_body = canvas.getBox(id_train1_body);
    Engine::Box& train1_back = canvas.getBox(id_train1_back);
    Engine::Box& train1_front = canvas.getBox(id_train1_front);


    auto update = [&](float dt)
    {
        time += dt;
        frames += 1;

        //std::cout << frog.position() << std::endl;

        if (frog.collide(final)) {
            frog.setPosition({ 0.0f, -0.9f });
            soundManager.scheduleNote(Engine::Note{ 200, 1.0, 523.251 });

        }
        if (frog.collide(lose1)) {
            frog.setPosition({ 0.0f, -0.9f });
            soundManager.scheduleNote(Engine::Note{ 200, 1.0, 261.626 });
        }
        if (frog.collide(lose2)) {
            frog.setPosition({ 0.0f, -0.9f });
            soundManager.scheduleNote(Engine::Note{ 200, 1.0, 261.626 });
        }

        // Frog
        frog_body.setPosition(frog.position());
        frog_back.setPosition(frog.position());
        frog_eye1.setPosition(frog.position() + Engine::Vec2{ -0.03f, 0.05 });
        frog_eye2.setPosition(frog.position() + Engine::Vec2{ 0.03f, 0.05 });

        // Truck1
        if (frog.collide(truck1)) {
            frog.setPosition({ 0.0f, -0.9f });
            soundManager.scheduleNote(Engine::Note{ 200, 1.0, 261.626 });
        }
        truck1.setPosition(truck1_path.travel(truck1_speed * time + truck1_offset));
        truck1_body.setPosition(truck1.position());
        truck1_back.setPosition(truck1.position() + Engine::Vec2{ 0.15f, 0.0f });

        // Truck2
        if (frog.collide(truck2)) {
            frog.setPosition({ 0.0f, -0.9f });
            soundManager.scheduleNote(Engine::Note{ 200, 1.0, 261.626 });
        }
        truck2.setPosition(truck2_path.travel(truck2_speed * time + truck2_offset));
        truck2_body.setPosition(truck2.position());
        truck2_back.setPosition(truck2.position() + Engine::Vec2{ 0.15f, 0.0f });

        // Truck3
        if (frog.collide(truck3)) {
            frog.setPosition({ 0.0f, -0.9f });
            soundManager.scheduleNote(Engine::Note{ 200, 1.0, 261.626 });
        }
        truck3.setPosition(truck3_path.travel(truck3_speed * time + truck3_offset));
        truck3_body.setPosition(truck3.position());
        truck3_back.setPosition(truck3.position() + Engine::Vec2{ -0.15f, 0.0f });

        // Truck4
        if (frog.collide(truck4)) {
            frog.setPosition({ 0.0f, -0.9f });
            soundManager.scheduleNote(Engine::Note{ 200, 1.0, 261.626 });
        }
        truck4.setPosition(truck4_path.travel(truck4_speed * time + truck4_offset));
        truck4_body.setPosition(truck4.position());
        truck4_back.setPosition(truck4.position() + Engine::Vec2{ -0.15f, 0.0f });

        // Truck5
        if (frog.collide(truck5)) {
            frog.setPosition({ 0.0f, -0.9f });
            soundManager.scheduleNote(Engine::Note{ 200, 1.0, 261.626 });
        }
        truck5.setPosition(truck5_path.travel(truck5_speed * time + truck5_offset));
        truck5_body.setPosition(truck5.position());
        truck5_back.setPosition(truck5.position() + Engine::Vec2{ -0.15f, 0.0f });

        // Car1
        if (frog.collide(car1)) {
            frog.setPosition({ 0.0f, -0.9f });
            soundManager.scheduleNote(Engine::Note{ 200, 1.0, 261.626 });
        }
        car1.setPosition(car1_path.travel(car1_speed * time + car1_offset));
        car1_body.setPosition(car1.position());
        car1_back.setPosition(car1.position() + Engine::Vec2{ -0.025f, 0.0f });

        // Car2
        if (frog.collide(car2)) {
            frog.setPosition({ 0.0f, -0.9f });
            soundManager.scheduleNote(Engine::Note{ 200, 1.0, 261.626 });
        }
        car2.setPosition(car2_path.travel(car2_speed * time + car2_offset));
        car2_body.setPosition(car2.position());
        car2_back.setPosition(car2.position() + Engine::Vec2{ -0.025f, 0.0f });

        // Car3
        if (frog.collide(car3)) {
            frog.setPosition({ 0.0f, -0.9f });
            soundManager.scheduleNote(Engine::Note{ 200, 1.0, 261.626 });
        }
        car3.setPosition(car3_path.travel(car3_speed * time + car3_offset));
        car3_body.setPosition(car3.position());
        car3_back.setPosition(car3.position() + Engine::Vec2{ 0.025f, 0.0f });

        // Car4
        if (frog.collide(car4)) {
            frog.setPosition({ 0.0f, -0.9f });
            soundManager.scheduleNote(Engine::Note{ 200, 1.0, 261.626 });
        }
        car4.setPosition(car4_path.travel(car4_speed * time + car4_offset));
        car4_body.setPosition(car4.position());
        car4_back.setPosition(car4.position() + Engine::Vec2{ 0.025f, 0.0f });

        // Car5
        if (frog.collide(car5)) {
            frog.setPosition({ 0.0f, -0.9f });
            soundManager.scheduleNote(Engine::Note{ 200, 1.0, 261.626 });
        }
        car5.setPosition(car5_path.travel(car5_speed * time + car5_offset));
        car5_body.setPosition(car5.position());
        car5_back.setPosition(car5.position() + Engine::Vec2{ 0.025f, 0.0f });

        soundManager.tick(deltaTimeFloat);
        std::this_thread::sleep_for(duration);

        // Tractor1
        if (frog.collide(tractor1)) {
            frog.setPosition({ 0.0f, -0.9f });
            soundManager.scheduleNote(Engine::Note{ 200, 1.0, 261.626 });
        }
        tractor1.setPosition(tractor1_path.travel(tractor1_speed * time + tractor1_offset));
        tractor1_body.setPosition(tractor1.position());
        tractor1_back.setPosition(tractor1.position() + Engine::Vec2{ -0.05f, 0.0f });

        // Tractor2
        if (frog.collide(tractor2)) {
            frog.setPosition({ 0.0f, -0.9f });
            soundManager.scheduleNote(Engine::Note{ 200, 1.0, 261.626 });
        }
        tractor2.setPosition(tractor2_path.travel(tractor2_speed * time + tractor2_offset));
        tractor2_body.setPosition(tractor2.position());
        tractor2_back.setPosition(tractor2.position() + Engine::Vec2{ 0.05f, 0.0f });

        // Tractor3
        if (frog.collide(tractor3)) {
            frog.setPosition({ 0.0f, -0.9f });
            soundManager.scheduleNote(Engine::Note{ 200, 1.0, 261.626 });
        }
        tractor3.setPosition(tractor3_path.travel(tractor3_speed * time + tractor3_offset));
        tractor3_body.setPosition(tractor3.position());
        tractor3_back.setPosition(tractor3.position() + Engine::Vec2{ 0.05f, 0.0f });

        // Truck1
        if (frog.collide(train1)) {
            frog.setPosition({ 0.0f, -0.9f });
            soundManager.scheduleNote(Engine::Note{ 200, 1.0, 261.626 });
        }
        train1.setPosition(train1_path.travel(train1_speed * time + train1_offset));
        train1_body.setPosition(train1.position());
        train1_back.setPosition(train1.position() + Engine::Vec2{ 0.26f, 0.0f });
        train1_front.setPosition(train1.position() + Engine::Vec2{ -0.26f, 0.0f });

    };


    Engine::Controller controller;
    controller.onKeyPress(Engine::Key::W, [&]() { 
        frog.setPosition(frog.position() + Engine::Vec2{ 0.0f, 0.15f});
        soundManager.scheduleNote(Engine::Note{ 30, 1.0, 349.228 });
        });

    controller.onKeyPress(Engine::Key::A, [&]() { 
        frog.setPosition(frog.position() + Engine::Vec2{ -0.15f, 0.0f});
        soundManager.scheduleNote(Engine::Note{ 30, 1.0, 349.228 });
        });

    controller.onKeyPress(Engine::Key::D, [&]() { 
        frog.setPosition(frog.position() + Engine::Vec2{ 0.15f, 0.0f });
        soundManager.scheduleNote(Engine::Note{ 30, 1.0, 349.228 });
        });

    controller.onKeyPress(Engine::Key::ESCAPE, [&]() { canvas.close(); });

    //runScene
    canvas.drawScene(controller, update);

    return 0;
}