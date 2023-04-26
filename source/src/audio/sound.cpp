#define MA_NO_DECODING
#define MA_NO_ENCODING
#define MINIAUDIO_IMPLEMENTATION

#include <stdio.h>
#include <thread>
#include <iostream>
#include "sound.h"
#include "miniaudio.h"


namespace Engine
{

void data_callback(ma_device* pDevice, void* pOutput, const void* pInput, ma_uint32 frameCount)
{
    ma_waveform* pSineWave;
    MA_ASSERT(pDevice -> playback.channels == DEVICE_CHANNELS);

    pSineWave = (ma_waveform*) pDevice -> pUserData;
    MA_ASSERT(pSineWave != NULL);

    ma_waveform_read_pcm_frames(pSineWave, pOutput, frameCount, NULL);
}

SoundManager::SoundManager()
{
    ma_device_config deviceConfig = ma_device_config_init(ma_device_type_playback);
    deviceConfig.playback.format = DEVICE_FORMAT;
    deviceConfig.playback.channels = DEVICE_CHANNELS;
    deviceConfig.sampleRate = DEVICE_SAMPLE_RATE;
    deviceConfig.dataCallback = Engine::data_callback;
    deviceConfig.pUserData = &mSineWave;

    if (ma_device_init(NULL, &deviceConfig, &mDevice) != MA_SUCCESS) {
        printf("Failed to open playback device.\n");
        throw;
    }
    mTimer = 0.0f;
}

void SoundManager::tick(float milliseconds)
{
    mTimer -= milliseconds;
    if (mTimer < 0.0) playNext();
}

void SoundManager::scheduleNote(const Note& note)
{
    mSchedule.push_back(note);
}

void SoundManager::playNote(const Note& note)
{
    /* Other wave types:
        ma_waveform_type_sine,
        ma_waveform_type_square,
        ma_waveform_type_triangle,
        ma_waveform_type_sawtooth
    */
     ma_waveform_config sineWaveConfig = ma_waveform_config_init(
         mDevice.playback.format,
         mDevice.playback.channels,
         mDevice.sampleRate,
         ma_waveform_type_sine,
         note.amplitude,
         note.frecuency);
    ma_waveform_init(&sineWaveConfig, &mSineWave);

    if (ma_device_start(&mDevice) != MA_SUCCESS) {
        printf("Failed to start playback device.\n");
        ma_device_uninit(&mDevice);
        throw;
    }
    mTimer = note.milliseconds;
}

void SoundManager::playNext()
{
    if (mSchedule.empty())
    {
        ma_device_stop(&mDevice);
        mTimer = 0.0f;
        return;
    }

    Note note = mSchedule.front();
    mSchedule.pop_front();

    playNote(note);
}

bool SoundManager::hasSound()
{
    return !(mSchedule.empty() && mTimer == 0.f);
}

void SoundManager::stopSound()
{
    ma_device_stop(&mDevice);
}

void SoundManager::clearSound()
{
    mSchedule.clear();
    ma_device_stop(&mDevice);
    mTimer = 0.0f;
}

std::ostream& operator<< (std::ostream& os, const SoundManager& sound)
{
    return os << "SoundGenerator " << "( " << sound.device().playback.name << ", " << sound.schedule().size() << " )";
}

} // namespace Engine