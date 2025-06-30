#pragma once
#include "../ecs/ecs.h"
#include <functional>
#include <vector>

#define UI_ELEMENT(type) \
    class type : public UIElement { \
    public: \
        static constexpr const char* type_name = #type; \
        void update(float dt) override; \
        void draw() override;

#define UI_PROPERTY(name, default_value) \
    private: \
        decltype(default_value) name = default_value; \
    public: \
        auto& get_##name() const { return name; } \
        void set_##name(auto&& value) { name = std::forward<decltype(value)>(value); }

class UISystem {
public:
    void add_element(UIElement* element);
    void update_all(float dt);
    void draw_all();
    
private:
    std::vector<UIElement*> elements;
};