#pragma once
#include "../collider.h"
#include <vector>

class BroadphaseGrid {
public:
    void initialize(float world_size, int subdivisions);
    void update();
    
    std::vector<Collider*> query(const Bounds& area);
    
private:
    std::vector<std::vector<Collider*>> grid;
    float cell_size;
    int grid_width;
    
    GridPos calculate_cell(const Bounds& bounds);
};