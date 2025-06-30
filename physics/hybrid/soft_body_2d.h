#pragma once
#include "../../math/vector2.h"
#include <vector>

struct SpringConnection {
    size_t node;
    float stiffness;
    float rest_length;
};

class SoftBody2D {
public:
    SoftBody2D(size_t node_count);
    
    void update(float dt);
    void apply_force(size_t node_index, const Vector2& force);
    
    void set_damping(float value) { damping = value; }
    
private:
    std::vector<Vector2> nodes;
    std::vector<Vector2> prev_positions;
    std::vector<Vector2> accelerations;
    std::vector<std::vector<SpringConnection>> connections;
    float damping = 0.05f;
};