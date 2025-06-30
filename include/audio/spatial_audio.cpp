#include "audio/spatial_audio.h"

void SpatialAudioSystem::init() {
    FMOD::System_Create(&fmod_system);
    fmod_system->init(32, FMOD_INIT_NORMAL, nullptr);
    
    // Precargar sonidos
    load_sound("explosion", "assets/audio/explosion.wav");
    load_sound("gunshot", "assets/audio/gunshot.wav");
}

void SpatialAudioSystem::play_gunshot(const Vector2& position, float volume) {
    FMOD::Channel* channel;
    fmod_system->playSound(sounds["gunshot"], channel_group, false, &channel);
    channel->setPan(calculate_pan(position));
    channel->setVolume(calculate_volume(position, volume));
}