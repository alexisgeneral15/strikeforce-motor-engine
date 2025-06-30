#include "jiggle_physics.h"

void JigglePhysics::update(float dt) {
    for (auto& bone : bones) {
        Vector2 target = get_target_position(bone);
        Vector2 velocity = bone.position - bone.prev_position;
        
        // Aplicar fuerza de resorte con amortiguación
        Vector2 force = (target - bone.position) * stiffness - velocity * damping;
        
        // Integración Verlet
        Vector2 temp = bone.position;
        bone.position += velocity * (1.0f - damping) + force * dt * dt;
        bone.prev_position = temp;
    }
}