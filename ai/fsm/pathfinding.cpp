#include "pathfinding.h"

#define HEURISTIC(a, b) \
    std::abs(a.x - b.x) + std::abs(a.y - b.y)

std::vector<Vector2> AStar::find_path(Vector2 start, Vector2 goal) {
    open_set.push(start, HEURISTIC(start, goal));
    
    while (!open_set.empty()) {
        auto current = open_set.pop();
        
        if (current == goal) {
            return reconstruct_path(came_from, current);
        }
        
        for (auto& neighbor : get_neighbors(current)) {
            float tentative_g = g_score[current] + 1;
            if (tentative_g < g_score[neighbor]) {
                came_from[neighbor] = current;
                g_score[neighbor] = tentative_g;
                open_set.push(neighbor, tentative_g + HEURISTIC(neighbor, goal));
            }
        }
    }
    
    return {};
}