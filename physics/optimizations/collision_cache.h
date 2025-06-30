#pragma once
#include "../collision_data.h"
#include <unordered_map>

class CollisionCache {
public:
    CollisionData* get(uint64_t body1, uint64_t body2);
    void store(const CollisionData& data);
    void clear();
    
private:
    std::unordered_map<uint64_t, CollisionData> cache;
};