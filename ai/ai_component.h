#pragma once
#include "../ecs/ecs.h"

class AIComponent : public Component {
public:
    virtual void update(float dt) = 0;
};