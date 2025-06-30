#include "lua_engine.h"

LUA_COMPONENT(Transform,
    "x", &TransformComponent::x,
    "y", &TransformComponent::y
);

LUA_COMPONENT(Health,
    "current", &HealthComponent::current,
    "max", &HealthComponent::max
);

void LuaEngine::bind_component(const std::string& name) {
    if(name == "Transform") LuaBinder<TransformComponent>::bind(lua);
    if(name == "Health") LuaBinder<HealthComponent>::bind(lua);
}

void LuaEngine::load_script(Entity* entity, const std::string& path) {
    auto result = lua.script_file(path);
    if(result.valid()) {
        sol::function init = lua["init"];
        if(init) init(entity);
    }
}