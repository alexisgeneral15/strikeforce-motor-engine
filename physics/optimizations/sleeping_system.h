#pragma once
#include "../rigidbody.h"
#include <vector>

class SleepingSystem {
public:
    void add_body(RigidBody* body);
    void update(float dt);
    
private:
    std::vector<RigidBody*> bodies;
};