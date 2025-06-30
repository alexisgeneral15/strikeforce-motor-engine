#include "ui/hud/dynamic_hud.h"

HUD_ELEMENT(HealthBar) {
    UI_PROPERTY(max_health, 100.0f);
    UI_PROPERTY(current_health, 100.0f);
    
    void draw() override {
        float ratio = current_health / max_health;
        DrawRectangleRec(bounds, RED);
        DrawRectangleRec({bounds.x, bounds.y, bounds.width * ratio, bounds.height}, GREEN);
    }
};

void DynamicHUD::update_player_data(const PlayerStats& stats) {
    if (auto health = dynamic_cast<HealthBarHUD*>(elements["health"])) {
        health->set_current_health(stats.health);
    }
}