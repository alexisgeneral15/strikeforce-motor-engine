#pragma once
#include <sol/sol.hpp>

#define LUA_BIND(type) \
    template<> \
    struct LuaBinding<type> { \
        static void bind(sol::state& lua) { \
            lua.new_usertype<type>(#type

class LuaEngine {
    sol::state lua;
    
public:
    template<typename T>
    void register_type() {
        LuaBinding<T>::bind(lua);
    }

    void load_script(const std::string& path) {
        lua.script_file(path);
    }
};

template<typename T>
struct LuaBinding {
    static void bind(sol::state& lua);
};