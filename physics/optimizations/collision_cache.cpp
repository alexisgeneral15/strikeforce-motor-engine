#include "collision_cache.h"

#define CACHE_KEY(body1, body2) \
    ((body1->id << 32) | body2->id)

CollisionData* CollisionCache::get(uint64_t body1, uint64_t body2) {
    auto key = CACHE_KEY(body1, body2);
    auto it = cache.find(key);
    return it != cache.end() ? &it->second : nullptr;
}

void CollisionCache::store(const CollisionData& data) {
    auto key = CACHE_KEY(data.body1, data.body2);
    cache[key] = data;
}