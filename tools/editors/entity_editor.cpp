#include "entity_editor.h"

#define COMPONENT_EDITOR(name) \
    void EntityEditor::draw_##name##_editor(Entity* entity) { \
        auto component = entity->get_component<name##Component>(); \
        if(component) { \
            ImGui::Text(#name " Component"); \
            component->inspect(); \
        } \
    }

COMPONENT_EDITOR(Transform)
COMPONENT_EDITOR(Render)
COMPONENT_EDITOR(Physics)
COMPONENT_EDITOR(AI)