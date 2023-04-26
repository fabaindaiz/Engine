#pragma once

#define MA_NO_DECODING
#define MA_NO_ENCODING

#include <iostream>
#include "miniaudio.h"

#define DEVICE_FORMAT       ma_format_f32
#define DEVICE_CHANNELS     2
#define DEVICE_SAMPLE_RATE  48000


namespace Engine
{

class SoundGenerator
{
private:
    ma_device mDevice;

    ma_waveform mSineWave;
    ma_device_config mDeviceConfig;

public:
    SoundGenerator() = default;

    ma_device& device()
    {
        return mDevice;
    }

    const ma_device& device() const
    {
        return mDevice;
    }

    ma_waveform& sineWave()
    {
        return mSineWave;
    }

    const ma_waveform& sineWave() const
    {
        return mSineWave;
    }


    int init_device();
    void uninit_device();

    int playNote(std::chrono::milliseconds duration, double amplitude, double frecuency);
    void stopSound();
};

std::ostream& operator<< (std::ostream& os, const SoundGenerator& sound);

} // namespace Engine