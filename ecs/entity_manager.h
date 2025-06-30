#pragma once
#include <cstdint>

using EntityID = uint32_t;

class EntityManager {
public:
    static EntityManager& Get();
    Entity CreateEntity();
};