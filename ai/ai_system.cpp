#include "ai_system.h"
#include "../ecs/entity_manager.h"

void AISystem::Update(float dt) {
    auto view = EntityManager::Get().View<AIComponent>();
    for (auto [entity, ai] : view.each()) {
        ProcessAI(entity, ai);
    }
}

void AISystem::ProcessAI(Entity entity, AIComponent& ai) {
    // Lógica de IA aquí
}