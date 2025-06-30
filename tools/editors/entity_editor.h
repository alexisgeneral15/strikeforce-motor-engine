#pragma once
#include "../../ecs/ecs.h"
#include "imgui.h"

#define COMPONENT_EDITOR_INTERFACE(name) \
    void draw_##name##_editor(Entity* entity); \
    void draw_##name##_component_inspector(name##Component* component)

class EntityEditor {
public:
    void set_context(Entity* entity);
    void draw_editor();
    
    COMPONENT_EDITOR_INTERFACE(transform);
    COMPONENT_EDITOR_INTERFACE(render);
    COMPONENT_EDITOR_INTERFACE(physics);
    COMPONENT_EDITOR_INTERFACE(script);

private:
    Entity* current_entity = nullptr;
};