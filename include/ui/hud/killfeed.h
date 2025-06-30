#pragma once
#include "../ui_element.h"
#include <deque>

#define KILLFEED_ENTRY_MAX 5
#define KILLFEED_ENTRY_DURATION 3.0f

struct KillEntry {
    std::string killer;
    std::string victim;
    std::string weapon;
};

class Killfeed : public UIElement {
public:
    void add_kill(const std::string& killer, const std::string& victim, const std::string& weapon);
    void update(float dt) override;
    void draw() override;
    
private:
    std::deque<std::pair<KillEntry, float>> entries;
};