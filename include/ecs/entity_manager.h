// engine/src/ecs/entity_manager.h
#pragma once
#include "core/memory/pool_allocator.h"

class EntityManager {
public:
    Entity CreateEntity() {
        EntityID id = entityPool.create();
        generation[id.index]++;
        return Entity{id.index, generation[id.index]};
    }

    void DestroyEntity(Entity entity) {
        if (generation[entity.index] == entity.generation) {
            entityPool.destroy(EntityID{entity.index});
            generation[entity.index]++;
        }
    }

private:
    struct EntityID { uint32_t index; };
    PoolAllocator<EntityID> entityPool;
    std::vector<uint8_t> generation;
};