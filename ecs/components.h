#pragma once

#include "ecs.h"

struct TransformComponent : public Component {
    float x, y;
    float rotation;
    float scale;
};

struct SpriteComponent : public Component {
    std::string texturePath;
    float width, height;
    // Otros parámetros de sprite
};

struct RigidbodyComponent : public Component {
    float velocityX, velocityY;
    float mass;
    bool isStatic;
};