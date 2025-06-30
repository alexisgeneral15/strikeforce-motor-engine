#include "damage_system.h"

DAMAGE_TYPE(Normal, {
    if(auto health = target->get_component<HealthComponent>()) {
        health->current -= amount;
    }
});

DAMAGE_TYPE(Poison, {
    if(auto health = target->get_component<HealthComponent>()) {
        health->current -= amount * 0.5f;
        if(auto status = target->get_component<StatusComponent>()) {
            status->apply_poison(5.0f);
        }
    }
});

void DamageSystem::apply_damage(Entity* target, float amount, const std::string& type) {
    static std::unordered_map<std::string, std::function<void(Entity*, float)>> damage_types = {
        {"normal", NormalDamage::apply},
        {"poison", PoisonDamage::apply}
    };
    
    if(damage_types.find(type) != damage_types.end()) {
        damage_types[type](target, amount);
    }
}