#pragma once
#include "../math/vector2.h"
#include <string>
#include <unordered_map>

class Sound; // Forward declaration

class SpatialAudio {
public:
    void Init();
    void Update(const Vector2& listener_pos);
    
    void PlaySound(const std::string& name, const Vector2& position);
    
private:
    std::unordered_map<std::string, Sound*> sounds;
    Vector2 listener_position;
    
    float CalculateVolume(const Vector2& sound_pos);
    float CalculatePan(const Vector2& sound_pos);
};