#pragma once

#include <memory>
#include <unordered_map>
#include <vector>
#include <cstdint>

using Entity = uint32_t;

class Component {
public:
    virtual ~Component() = default;
};

class System {
public:
    virtual void Update(float deltaTime) = 0;
};

class ECS {
public:
    Entity CreateEntity();
    void DestroyEntity(Entity entity);
    
    template<typename T>
    void AddComponent(Entity entity, std::shared_ptr<T> component);
    
    template<typename T>
    std::shared_ptr<T> GetComponent(Entity entity);
    
    void AddSystem(std::shared_ptr<System> system);
    void UpdateSystems(float deltaTime);

private:
    std::vector<std::shared_ptr<System>> systems;
    std::unordered_map<Entity, std::unordered_map<size_t, std::shared_ptr<Component>>> entities;
    Entity nextEntityId = 0;
};