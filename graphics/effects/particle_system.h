#pragma once
#include "../rendering/texture.h"
#include <vector>

struct Particle {
    Vector2 position;
    Vector2 velocity;
    Color color;
    float lifetime;
    bool active = false;
};

class ParticleBehavior {
public:
    virtual void update(Particle& p, float dt) = 0;
    virtual ~ParticleBehavior() = default;
};

class ParticleEmitter {
public:
    void init(size_t max_particles);
    void update(float dt);
    void set_behavior(std::unique_ptr<ParticleBehavior> new_behavior);
    
private:
    std::vector<Particle> particles;
    std::unique_ptr<ParticleBehavior> behavior;
    Texture particle_texture;
};