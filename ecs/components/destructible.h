#pragma once
#include "../../ecs.h"
#include <unordered_map>
#include <memory>

class DestructionEffect {
public:
    virtual void apply(class Destructible& obj) = 0;
    virtual ~DestructionEffect() = default;
};

class Destructible : public Component {
public:
    float health = 100.0f;
    std::string material_type = "wood";
    float resistance = 1.0f;
};

class DestructibleSystem : public System {
public:
    void init();
    void update(float dt) override;

private:
    std::unordered_map<std::string, std::unique_ptr<DestructionEffect>> destruction_effects;
};