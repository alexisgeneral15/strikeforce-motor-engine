#pragma once
#include "../../math/vector2.h"
#include <vector>

struct RopeNode {
    Vector2 position;
    Vector2 velocity;
};

class RopePhysics {
public:
    RopePhysics(size_t segment_count, float length);
    
    void simulate(float dt);
    void set_gravity(const Vector2& g) { gravity = g; }
    
private:
    std::vector<RopeNode> nodes;
    Vector2 gravity = {0, 9.8f};
    float segment_length;
    int constraint_iterations = 3;
};