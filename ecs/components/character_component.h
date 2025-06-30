#pragma once
#include "../ecs.h"

LUA_BIND(CharacterComponent) {
    .property("health", &CharacterComponent::health),
    .property("speed", &CharacterComponent::speed),
    .function("takeDamage", &CharacterComponent::take_damage)
});

COMPONENT(CharacterComponent) {
    float health = 100.0f;
    float speed = 5.0f;
    
    void take_damage(float amount) {
        health -= amount;
    }
};