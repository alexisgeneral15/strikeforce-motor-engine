#pragma once
#include "../ecs/ecs.h"
#include <FMOD/fmod.hpp>

#define AUDIO_EVENT(name) \
    void play_##name(const Vector2& position, float volume = 1.0f); \
    void stop_##name()

class SpatialAudioSystem {
public:
    void init();
    void update(const Vector2& listener_pos);
    
    AUDIO_EVENT(explosion);
    AUDIO_EVENT(gunshot);
    AUDIO_EVENT(impact);
    
private:
    FMOD::System* fmod_system;
    std::unordered_map<std::string, FMOD::Sound*> sounds;
    FMOD::ChannelGroup* channel_group;
    
    float calculate_pan(const Vector2& sound_pos);
    float calculate_volume(const Vector2& sound_pos, float base_volume);
};