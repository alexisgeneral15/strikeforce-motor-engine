#include "broadphase.h"

#define BROADPHASE_GRID_CELL(size) \
    struct GridCell_##size { \
        std::vector<Collider*> colliders; \
        void add(Collider* col) { colliders.push_back(col); } \
    }

void BroadphaseGrid::update() {
    for (auto& cell : grid) {
        cell.colliders.clear();
    }
    
    for (auto collider : world_colliders) {
        auto cell = calculate_cell(collider->bounds);
        grid[cell.x + cell.y * grid_width].add(collider);
    }
}