#include "destructible.h"

#define DESTRUCTION_EFFECT(type) \
    void type##Destruction::apply(Destructible& obj) override

DESTRUCTION_EFFECT(Wood) {
    spawn_particles("wood_splinters", obj.position);
    play_sound("wood_break");
};

DESTRUCTION_EFFECT(Metal) {
    spawn_particles("metal_sparks", obj.position);
    play_sound("metal_crash");
    spawn_debris(obj.position);
};

void DestructibleSystem::update(float dt) {
    auto view = registry.view<Destructible>();
    for (auto entity : view) {
        auto& destructible = view.get<Destructible>(entity);
        if (destructible.health <= 0) {
            if (destruction_effects.count(destructible.material_type)) {
                destruction_effects[destructible.material_type]->apply(destructible);
            }
            registry.destroy(entity);
        }
    }
}