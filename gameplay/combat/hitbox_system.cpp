#include "hitbox_system.h"

void HitboxSystem::check_collisions() {
    auto view = registry.view<TransformComponent, HitboxComponent>();
    
    for(auto entity1 : view) {
        for(auto entity2 : view) {
            if(entity1 == entity2) continue;
            
            auto& transform1 = view.get<TransformComponent>(entity1);
            auto& hitbox1 = view.get<HitboxComponent>(entity1);
            auto& transform2 = view.get<TransformComponent>(entity2);
            auto& hitbox2 = view.get<HitboxComponent>(entity2);
            
            if(check_collision(transform1, hitbox1, transform2, hitbox2)) {
                hitbox1.on_collision(registry, entity2);
                hitbox2.on_collision(registry, entity1);
            }
        }
    }
}