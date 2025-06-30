#include "particle_system.h"

#define PARTICLE_BEHAVIOR(name) \
    void name##Behavior::update(Particle& p, float dt) 

PARTICLE_BEHAVIOR(Fire) {
    p.velocity.y -= gravity * dt;
    p.color.a = static_cast<unsigned char>(p.lifetime * 255.0f);
};

void ParticleEmitter::update(float dt) {
    for (auto& p : particles) {
        if (p.active) {
            behavior->update(p, dt);
            p.lifetime -= dt;
            if (p.lifetime <= 0.0f) {
                p.active = false;
            }
        }
    }
}