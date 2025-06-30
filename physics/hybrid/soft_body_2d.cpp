#include "soft_body_2d.h"

#define SPRING_FORCE(node1, node2, stiffness) \
    Vector2 delta = nodes[node2] - nodes[node1]; \
    float length = delta.length(); \
    Vector2 force = delta.normalized() * (length - rest_length) * stiffness; \
    apply_force(node1, force); \
    apply_force(node2, -force)

void SoftBody2D::update(float dt) {
    for (size_t i = 0; i < nodes.size(); ++i) {
        // Aplicar fuerzas de resorte
        for (auto& connection : connections[i]) {
            SPRING_FORCE(i, connection.node, connection.stiffness);
        }
        
        // Integración Verlet
        Vector2 temp = nodes[i];
        nodes[i] += (nodes[i] - prev_positions[i]) * (1.0f - damping) + accelerations[i] * dt * dt;
        prev_positions[i] = temp;
        accelerations[i] = Vector2::zero();
    }
}