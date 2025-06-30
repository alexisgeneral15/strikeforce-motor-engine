#pragma once
#include "../ecs/ecs.h"

#define HITBOX(type, callback) \
    COMPONENT(type##Hitbox) { \
        void on_collision(Entity* other) override { \
            callback(other); \
        } \
    }

class HitboxSystem : public System {
public:
    void check_collisions();
};