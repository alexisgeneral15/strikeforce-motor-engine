#pragma once
#include "../../ecs.h"
#include "../../math/vector3.h"
#include <memory>

class ProjectileBehavior {
public:
    virtual void update(class Projectile& projectile, float dt) = 0;
    virtual ~ProjectileBehavior() = default;
};

class Projectile : public Component {
public:
    Vector3 position;
    Vector3 velocity;
    float speed;
    float lifetime;
    Entity* target = nullptr;
    std::unique_ptr<ProjectileBehavior> behavior;

    void mark_for_removal() { should_remove = true; }
    bool should_remove = false;
};

class ProjectileSystem : public System {
public:
    void update(float dt) override;

private:
    entt::view<Projectile> view;
};