#pragma once
#include "../ecs/ecs.h"

#define DAMAGE_TYPE(name, effect) \
    struct name##Damage { \
        static void apply(Entity* target, float amount) { \
            effect \
        } \
    }

class DamageSystem {
public:
    static void apply_damage(Entity* target, float amount, const std::string& type);
};