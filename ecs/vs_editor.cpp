#include "vs_editor.h"

#define NODE_TYPE(name) \
    void name##Node::draw_editor() override

NODE_TYPE(Print) {
    ImGui::InputText("Message", &message);
    ImGui::DragFloat("Delay", &delay);
};

NODE_TYPE(Condition) {
    ImGui::Combo("Condition Type", &cond_type, "Equals\0NotEquals\0Greater\0Less\0");
};

void VisualScriptEditor::update() {
    for (auto& node : nodes) {
        node->draw_editor();
    }
}