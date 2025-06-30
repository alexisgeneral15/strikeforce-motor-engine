#include "modular_weapons.h"

#define WEAPON_PART(slot) \
    void ModularWeapon::attach_##slot(const std::string& part_id) { \
        slots[WeaponSlot::slot] = weapon_parts.load(part_id); \
        recalculate_stats(); \
    }

WEAPON_PART(barrel);
WEAPON_PART(magazine);
WEAPON_PART(sight);
WEAPON_PART(stock);

void ModularWeapon::recalculate_stats() {
    base_damage = 0;
    fire_rate = 1.0f;
    accuracy = 1.0f;
    recoil = 1.0f;

    for (auto& [slot, part] : slots) {
        if (!part) continue;
        base_damage += part->damage_mod;
        fire_rate *= part->rate_mod;
        accuracy *= part->accuracy_mod;
        recoil *= part->recoil_mod;
    }
}