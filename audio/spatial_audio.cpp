#include "spatial_audio.h"

#define AUDIO_EVENT(name) \
    void SpatialAudio::play_##name(const Vector2& position) { \
        int channel = channel_pool.get_channel(); \
        if (channel != -1) { \
            float vol = calculate_volume(position); \
            float pan = calculate_pan(position); \
            FMOD_Channel_SetVolume(channel, vol); \
            FMOD_Channel_SetPan(channel, pan); \
            FMOD_Channel_Play(channel, sounds[#name]); \
        } \
    }

AUDIO_EVENT(explosion);
AUDIO_EVENT(gunshot);
AUDIO_EVENT(impact);

float SpatialAudio::calculate_volume(const Vector2& pos) {
    float dist = Vector2Distance(listener_pos, pos);
    return 1.0f - std::clamp(dist / max_distance, 0.0f, 1.0f);
}