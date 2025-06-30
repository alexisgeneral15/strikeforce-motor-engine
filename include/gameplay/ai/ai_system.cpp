// engine/src/gameplay/ai/ai_system.cpp
void AISystem::Update() {
    for (auto& entity : entities) {
        auto& ai = GetComponent<AIComponent>(entity);
        
        // Actualización del estado actual
        if (ai.currentState) {
            ai.currentState->Execute(entity);
        }
        
        // Evaluación de transiciones
        for (auto& transition : ai.currentState->transitions) {
            if (transition->ShouldTransition(entity)) {
                ai.currentState->Exit(entity);
                ai.currentState = transition->targetState;
                ai.currentState->Enter(entity);
                break;
            }
        }
    }
}