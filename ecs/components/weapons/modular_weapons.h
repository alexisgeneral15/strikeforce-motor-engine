#pragma once
#include "../../ecs.h"
#include <unordered_map>
#include <memory>

enum class WeaponSlot { barrel, magazine, sight, stock };

struct WeaponPart {
    std::string id;
    float damage_mod;
    float rate_mod;
    float accuracy_mod;
    float recoil_mod;
    Mesh mesh;
};

class ModularWeapon : public Component {
public:
    void attach_barrel(const std::string& part_id);
    void attach_magazine(const std::string& part_id);
    void attach_sight(const std::string& part_id);
    void attach_stock(const std::string& part_id);

    float get_damage() const { return base_damage; }
    float get_fire_rate() const { return fire_rate; }

private:
    std::unordered_map<WeaponSlot, std::shared_ptr<WeaponPart>> slots;
    float base_damage;
    float fire_rate;
    float accuracy;
    float recoil;

    void recalculate_stats();
};