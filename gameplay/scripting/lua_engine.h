#pragma once
#include <sol/sol.hpp>
#include "../ecs/ecs.h"

#define LUA_COMPONENT(name) \
    template<> \
    struct LuaBinder<name##Component> { \
        static void bind(sol::state& lua) { \
            lua.new_usertype<name##Component>(#name "Component", \
                sol::constructors<name##Component()>()

class LuaEngine {
public:
    void bind_component(const std::string& name);
    void load_script(Entity* entity, const std::string& path);
    
private:
    sol::state lua;
};