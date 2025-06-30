#include "ui/animation_ui.h"

UI_ANIMATION(Fade) {
    ANIMATION_PROPERTY(duration);
    ANIMATION_PROPERTY(target_alpha);
    
    void update(float dt) override {
        float delta = target_alpha - element->get_alpha();
        element->set_alpha(element->get_alpha() + delta * (dt/duration));
    }
};

void UIAnimationSystem::add_animation(UIAnimation* anim) {
    active_animations.push_back(anim);
}

void UIAnimationSystem::update(float dt) {
    for (auto it = active_animations.begin(); it != active_animations.end(); ) {
        (*it)->update(dt);
        if ((*it)->is_complete()) {
            it = active_animations.erase(it);
        } else {
            ++it;
        }
    }
}