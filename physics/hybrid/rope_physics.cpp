#include "rope_physics.h"

#define CONSTRAINT(node1, node2, length) \
    Vector2 delta = nodes[node2] - nodes[node1]; \
    float current_length = delta.length(); \
    if (current_length > 0) { \
        float diff = (current_length - length) / current_length; \
        nodes[node1] += delta * 0.5f * diff; \
        nodes[node2] -= delta * 0.5f * diff; \
    }

void RopePhysics::simulate(float dt) {
    // Aplicar gravedad
    for (auto& node : nodes) {
        node.velocity += gravity * dt;
        node.position += node.velocity * dt;
    }
    
    // Resolver restricciones
    for (int i = 0; i < constraint_iterations; ++i) {
        for (size_t j = 0; j < nodes.size() - 1; ++j) {
            CONSTRAINT(j, j+1, segment_length);
        }
    }
}