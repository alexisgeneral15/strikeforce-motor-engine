#include "ui/hud/damage_indicator.h"

void DamageIndicatorSystem::add_damage(Vector2 world_pos, float amount, bool is_critical) {
    if (indicators.size() >= DAMAGE_INDICATOR_MAX) {
        indicators.erase(indicators.begin());
    }
    
    indicators.push_back({
        world_pos,
        amount,
        DAMAGE_FADE_TIME,
        is_critical ? RED : YELLOW
    });
}

void DamageIndicatorSystem::draw() override {
    for (auto& indicator : indicators) {
        Vector2 screen_pos = GetWorldToScreen2D(indicator.position, *game_camera);
        float alpha = (indicator.timer / DAMAGE_FADE_TIME) * 255;
        Color color = { indicator.color.r, indicator.color.g, indicator.color.b, (unsigned char)alpha };
        
        DrawText(TextFormat("%.0f", indicator.amount), 
            screen_pos.x, screen_pos.y, 
            is_critical ? 24 : 18, 
            color);
    }
}