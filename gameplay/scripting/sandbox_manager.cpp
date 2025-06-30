#include "sandbox_manager.h"

void SandboxManager::register_api() {
    static const luaL_Reg api[] = {
        {"log", [](lua_State* L) { 
            std::cout << lua_tostring(L, 1) << std::endl;
            return 0;
        }},
        {"get_time", [](lua_State* L) {
            lua_pushnumber(L, GetTime());
            return 1;
        }},
        {nullptr, nullptr}
    };
    
    luaL_newlib(lua, api);
    lua_setglobal(lua, "engine");
}

void SandboxManager::set_restrictions(const std::string& profile) {
    static std::unordered_map<std::string, std::vector<std::string>> profiles = {
        {"safe", {"os", "io", "debug"}},
        {"unsafe", {}}
    };
    
    if(profiles.count(profile)) {
        for(auto& module : profiles[profile]) {
            lua_pushnil(lua);
            lua_setglobal(lua, module.c_str());
        }
    }
}