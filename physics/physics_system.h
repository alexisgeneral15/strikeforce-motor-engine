#pragma once
#include "ecs/ecs.h"

#define PHYSICS_COMPONENT(type) \
    COMPONENT(type); \
    virtual void update(float dt) override

COMPONENT(PhysicsBody) {
    virtual void update(float dt) = 0;
};

class PhysicsSystem {
    std::vector<PhysicsBody*> bodies;
    
public:
    void add_body(PhysicsBody* body) {
        bodies.push_back(body);
    }

    void update(float dt) {
        for (auto& b : bodies) {
            b->update(dt);
        }
    }
};