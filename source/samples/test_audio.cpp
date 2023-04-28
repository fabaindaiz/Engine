#include <chrono>
#include "audio/sound.h"


int main()
{
    Engine::SoundManager soundManager = Engine::SoundManager();

    int deltaTime = 33;
    float deltaTimeFloat = static_cast<float>(deltaTime);
    std::chrono::milliseconds duration{ deltaTime };

    soundManager.scheduleNote(Engine::Note{ 200, 1.0, 261.626 }); // Do
    soundManager.scheduleNote(Engine::Note{ 200, 1.0, 293.665 }); // Re
    soundManager.scheduleNote(Engine::Note{ 200, 1.0, 329.628 }); // Mi
    soundManager.scheduleNote(Engine::Note{ 200, 1.0, 349.228 }); // Fa
    soundManager.scheduleNote(Engine::Note{ 200, 1.0, 391.995 }); // Sol
    soundManager.scheduleNote(Engine::Note{ 200, 1.0, 440.000 }); // La
    soundManager.scheduleNote(Engine::Note{ 200, 1.0, 493.883 }); // Si
    soundManager.scheduleNote(Engine::Note{ 200, 1.0, 523.251 }); // Do

    std::cout << soundManager << std::endl;

    while (true)
    {
        soundManager.tick(deltaTimeFloat);
        std::this_thread::sleep_for(duration);

        if (!soundManager.hasSound())
        {
            break;
        }
    }
    
    return 0;
}