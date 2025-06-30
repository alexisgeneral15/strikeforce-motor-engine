#pragma once
#include "../ui_system.h"

#define HUD_ELEMENT(name) \
    class name##HUD : public HUDElement { \
    public: \
        void update(float dt) override; \
        void draw() override;

class DynamicHUD : public UISystem {
public:
    void update_player_data(const PlayerStats& stats);
    void show_notification(const std::string& message);
    
private:
    std::unordered_map<std::string, HUDElement*> elements;
};