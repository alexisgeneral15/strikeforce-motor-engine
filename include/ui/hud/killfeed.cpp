#include "ui/hud/killfeed.h"

void Killfeed::add_kill(const std::string& killer, const std::string& victim, const std::string& weapon) {
    entries.emplace_front(KillEntry{killer, victim, weapon}, KILLFEED_ENTRY_DURATION);
    if (entries.size() > KILLFEED_ENTRY_MAX) {
        entries.pop_back();
    }
}

void Killfeed::draw() override {
    float y_offset = 0;
    for (auto& [entry, time] : entries) {
        DrawText(TextFormat("%s killed %s with %s", 
            entry.killer.c_str(), 
            entry.victim.c_str(), 
            entry.weapon.c_str()),
            bounds.x, bounds.y + y_offset, 20, WHITE);
        y_offset += 25;
    }
}