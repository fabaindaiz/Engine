#include <iostream>
#include "core2d/actor.h"
#include "core2d/bounding_box.h"
#include "core2d/vec2.h"
#include "core2d/vec2_functions.h"
#include "render/render.h"


int main()
{
    Engine::Actor actor1{ Engine::Vec2{-20, 0}, Engine::Vec2{0.5f, 0.5f}};
    Engine::Actor actor2{ Engine::Vec2{ 20, 0}, Engine::Vec2{0.5f, 0.5f}};

    actor1.setVelocity(Engine::Vec2{1, 0});
    actor2.setAcceleration(Engine::Vec2{-0.1f, 0});

    //std::cout << "actor1 = " << actor1 << std::endl;
    //std::cout << "actor2 = " << actor2 << std::endl;

    const  float delta_time = 0.1f;

    int frames = 0;
    
    while (true)
    {
        std::cout << "Frame " << frames << std::endl;
        
        std::cout << "actor1 = " << actor1.position() << std::endl;
        std::cout << "actor2 = " << actor2.position() << std::endl;
        std::cout << std::endl;

        actor1.update(delta_time);
        actor2.update(delta_time);

        frames++;

        if (actor1.collide(actor2)) {
            break;
        }

    }

    std::cout << "Collide detected in frame " << frames << std::endl;
    std::cout << "actor1 = " << actor1.position() << std::endl;
    std::cout << "actor2 = " << actor2.position() << std::endl;
    std::cout << std::endl;

    std::cout << "Program ended with no errors" << std::endl;

    renderInit();

    return 0;
}