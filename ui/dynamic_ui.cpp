#include "ui/dynamic_ui.h"

UI_ELEMENT(Button) {
    UI_PROPERTY(text, "Button");
    UI_PROPERTY(on_click, nullptr);
    
    void update(float dt) override {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), bounds)) {
            if (on_click) on_click();
        }
    }
};

void UISystem::add_element(UIElement* element) {
    elements.push_back(element);
}

void UISystem::update_all(float dt) {
    for (auto& element : elements) {
        element->update(dt);
    }
}