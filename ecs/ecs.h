#pragma once
#include <cstdint>
#include <memory>
#include <set>

using EntityID = uint32_t;

class EntityManager;

class Entity {
public:
    Entity(EntityID id, EntityManager* manager);
    EntityID GetID() const { return id; }
    
private:
    EntityID id;
    EntityManager* manager;
};

class System {
public:
    virtual void Update(float dt) = 0;
    virtual ~System() = default;
};