#pragma once
#include "../math/vector2.h"
#include <vector>

class AStar {
public:
    std::vector<Vector2> find_path(Vector2 start, Vector2 goal);
};