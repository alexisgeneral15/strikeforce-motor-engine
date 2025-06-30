#include "ecs.h"

#define COMPONENT_POOL(type) \
    template<> \
    ComponentPool<type>& EntityManager::get_pool<type>() { \
        static ComponentPool<type> pool; \
        return pool; \
    }

COMPONENT_POOL(Transform);
COMPONENT_POOL(Renderable);
COMPONENT_POOL(PhysicsBody);

Entity EntityManager::create() {
    EntityID id = next_id++;
    entities.insert(id);
    return Entity(id, this);
}

void SystemManager::update_all(float dt) {
    for (auto& system : systems) {
        system->update(dt);
    }
}