#include "projectile.h"

#define PROJECTILE_BEHAVIOR(name) \
    void name##Behavior::update(Projectile& projectile, float dt) override

PROJECTILE_BEHAVIOR(Bullet) {
    projectile.position += projectile.velocity * dt;
    projectile.lifetime -= dt;
    if (projectile.lifetime <= 0) {
        projectile.mark_for_removal();
    }
};

PROJECTILE_BEHAVIOR(Homing) {
    if (projectile.target) {
        Vector3 direction = normalize(projectile.target->position - projectile.position);
        projectile.velocity = direction * projectile.speed;
    }
    projectile.position += projectile.velocity * dt;
};

void ProjectileSystem::update(float dt) {
    for (auto& entity : view) {
        auto& projectile = view.get<Projectile>(entity);
        if (projectile.behavior) {
            projectile.behavior->update(projectile, dt);
        }
    }
}