#pragma once
#include "ui_element.h"
#include <functional>

#define UI_ANIMATION(type) \
    class type##Animation : public UIAnimation { \
    public: \
        void update(float dt) override;

#define ANIMATION_PROPERTY(name) \
    private: \
        float name; \
    public: \
        auto& with_##name(float value) { name = value; return *this; }

class UIAnimationSystem {
public:
    void add_animation(UIAnimation* anim);
    void update(float dt);
    
private:
    std::vector<UIAnimation*> active_animations;
};