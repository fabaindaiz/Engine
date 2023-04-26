#include <chrono>
#include "audio/sound.h"


int main()
{
    Engine::SoundGenerator generator = Engine::SoundGenerator();
    generator.init_device();
    std::chrono::milliseconds duration{ 200 };

    while (true)
    {
        generator.playNote(duration, 1.0, 261.626); // Do
        generator.playNote(duration, 1.0, 293.665); // Re
        generator.playNote(duration, 1.0, 329.628); // Mi
        generator.playNote(duration, 1.0, 349.228); // Fa
        generator.playNote(duration, 1.0, 391.995); // Sol
        generator.playNote(duration, 1.0, 440.000); // La
        generator.playNote(duration, 1.0, 493.883); // Si
        generator.playNote(duration, 1.0, 523.251); // Do
        generator.stopSound();

        std::cout << "Press 'Enter' to play again or 'q+Enter' to close..." << std::endl;
        char c = getchar();
        if (c == 'q')
            break;
    }
    
    generator.uninit_device();
    return 0;
}