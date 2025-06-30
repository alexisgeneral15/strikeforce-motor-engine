#pragma once
#include "../../math/vector2.h"
#include <vector>

struct JiggleBone {
    Vector2 position;
    Vector2 prev_position;
    float stiffness;
    float damping;
};

class JigglePhysics {
public:
    void add_bone(const Vector2& position, float stiffness, float damping);
    void update(float dt);
    
private:
    std::vector<JiggleBone> bones;
    
    Vector2 get_target_position(const JiggleBone& bone);
};