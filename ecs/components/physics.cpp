#include "physics.h"

#define PHYSICS_INTEGRATOR(type) \
    void type##Physics::integrate(float dt) override

PHYSICS_INTEGRATOR(RigidBody) {
    velocity += acceleration * dt;
    position += velocity * dt;
    acceleration = {0, 0, 0};
};

PHYSICS_INTEGRATOR(SoftBody) {
    for (auto& node : nodes) {
        node.velocity += node.acceleration * dt;
        node.position += node.velocity * dt;
        node.acceleration = {0, 0, 0};
    }
};

void PhysicsSystem::update(float dt) {
    auto rigid_view = registry.view<RigidBody>();
    for (auto entity : rigid_view) {
        rigid_view.get<RigidBody>(entity).integrate(dt);
    }
}