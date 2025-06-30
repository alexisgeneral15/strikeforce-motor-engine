#pragma once
#include "../ecs/ecs.h"
#include "ai_component.h"

class AISystem : public System {
public:
    void Update(float dt) override;
    
private:
    void ProcessAI(Entity entity, AIComponent& ai);
};