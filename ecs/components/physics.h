#pragma once
#include "../../ecs.h"
#include "../../math/vector3.h"
#include <vector>

class PhysicsBody : public Component {
public:
    virtual void integrate(float dt) = 0;
};

class RigidBody : public PhysicsBody {
public:
    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;
    float mass = 1.0f;
    void integrate(float dt) override;
};

class PhysicsSystem : public System {
public:
    void update(float dt) override;
};