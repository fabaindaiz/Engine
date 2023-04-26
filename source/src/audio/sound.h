#pragma once

#define MA_NO_DECODING
#define MA_NO_ENCODING

#include <iostream>
#include <deque>
#include "miniaudio.h"

#define DEVICE_FORMAT       ma_format_f32
#define DEVICE_CHANNELS     2
#define DEVICE_SAMPLE_RATE  48000


namespace Engine
{

struct Note
{
    int milliseconds;
    double amplitude, frecuency;
};

class SoundManager
{
private:
    ma_device mDevice;
    ma_waveform mSineWave;
    float mTimer;

    std::deque<Note> mSchedule;

public:
    SoundManager();

    ~SoundManager()
    {
        ma_device_uninit(&mDevice);
    }

    const ma_device device() const
    {
        return mDevice;
    }

    const std::deque<Note> schedule() const
    {
        return mSchedule;
    }

    void tick(float milliseconds);
    void scheduleNote(const Note& note);

    void playNote(const Note& note);
    void playNext();

    bool hasSound();

    void stopSound();
    void clearSound();
};

std::ostream& operator<< (std::ostream& os, const SoundManager& sound);

} // namespace Engine