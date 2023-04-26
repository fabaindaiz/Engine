#ifndef MINIAUDIO_IMPLEMENTATION
#define MINIAUDIO_IMPLEMENTATION
#endif

#include <stdio.h>
#include <thread>
#include <chrono>
#include <iostream>
#include "sound.h"


namespace Engine
{

void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
{
    ma_waveform* pSineWave;

    MA_ASSERT(pDevice -> playback.channels == DEVICE_CHANNELS);

    pSineWave = (ma_waveform*) pDevice -> pUserData;
    //MA_ASSERT(pSineWave != NULL);

    ma_waveform_read_pcm_frames(pSineWave, pOutput, frameCount, NULL);
}

int SoundGenerator::init_device()
{
    mDeviceConfig = ma_device_config_init(ma_device_type_playback);
    mDeviceConfig.playback.format = DEVICE_FORMAT;
    mDeviceConfig.playback.channels = DEVICE_CHANNELS;
    mDeviceConfig.sampleRate = DEVICE_SAMPLE_RATE;
    mDeviceConfig.dataCallback = Engine::data_callback;
    mDeviceConfig.pUserData = &(this -> sineWave());

    if (ma_device_init(NULL, &mDeviceConfig, &mDevice) != MA_SUCCESS) {
        printf("Failed to open playback device.\n");
        return -4;
    }

    return 0;
}

void SoundGenerator::uninit_device()
{
    ma_device_uninit(&mDevice);
}

int SoundGenerator::playNote(std::chrono::milliseconds duration, double amplitude, double frecuency)
{
    ma_waveform_config sineWaveConfig;

    sineWaveConfig = ma_waveform_config_init(mDevice.playback.format, mDevice.playback.channels, mDevice.sampleRate, ma_waveform_type_sine, amplitude, frecuency);
    ma_waveform_init(&sineWaveConfig, &(this -> sineWave()));

    if (ma_device_start(&mDevice) != MA_SUCCESS) {
        printf("Failed to start playback device.\n");
        ma_device_uninit(&mDevice);
        return -5;
    }

    std::this_thread::sleep_for(duration);
    //ma_device_stop(&mDevice);
    return 0;
}

void SoundGenerator::stopSound()
{
    ma_device_stop(&mDevice);
}

std::ostream& operator<< (std::ostream& os, const SoundGenerator& sound)
{
    return os << "SoundGenerator " << "( " << sound.device().playback.name << ")";
}

} // namespace Engine