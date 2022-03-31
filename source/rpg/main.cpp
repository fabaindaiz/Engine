#include <iostream>
#include "core2d/actor.h"
#include "core2d/bounding_box.h"
#include "core2d/render.h"
#include "core2d/vector2d_functions.h"
#include "core2d/vector2d.h"

int main()
{
    renderInit();

    Actor actor1{Vector2D{-20, 0}, Vector2D{0.5f, 0.5f}, Vector2D{ 1,  1}};
    Actor actor2{Vector2D{ 20, 0}, Vector2D{0.5f, 0.5f}, Vector2D{-1, 1}};

    //std::cout << "actor1 = " << actor1 << std::endl;
    //std::cout << "actor2 = " << actor2 << std::endl;

    const  float delta_time = 0.1f;

    int frames = 0;
    
    while (true)
    {
        std::cout << "Frame " << frames << std::endl;
        
        std::cout << "actor1 = " << actor1.getPosition() << std::endl;
        std::cout << "actor2 = " << actor2.getPosition() << std::endl;
        std::cout << std::endl;

        actor1.update(delta_time);
        actor2.update(delta_time);

        frames++;

        if (actor1.collide(actor2)) {
            break;
        }

    }

    std::cout << "Collide detected in frame " << frames << std::endl;
    std::cout << "actor1 = " << actor1.getPosition() << std::endl;
    std::cout << "actor2 = " << actor2.getPosition() << std::endl;
    std::cout << std::endl;

    std::cout << "Program ended with no errors" << std::endl;

    return 0;
}