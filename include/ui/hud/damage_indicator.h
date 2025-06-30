#pragma once
#include "../ui_element.h"
#include <vector>

#define DAMAGE_INDICATOR_MAX 10
#define DAMAGE_FADE_TIME 1.0f

struct DamageIndicator {
    Vector2 position;
    float amount;
    float timer;
    Color color;
};

class DamageIndicatorSystem : public UIElement {
public:
    void add_damage(Vector2 world_pos, float amount, bool is_critical);
    void update(float dt) override;
    void draw() override;
    
private:
    std::vector<DamageIndicator> indicators;
    Camera2D* game_camera = nullptr;
};