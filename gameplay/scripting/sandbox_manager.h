#pragma once
#include "lua_engine.h"

#define SANDBOX_FUNCTION(name) \
    int name##_wrapper(lua_State* L) { \
        SandboxContext ctx(L); \
        return name(ctx); \
    } \
    lua_register(L, #name, name##_wrapper)

class SandboxManager {
public:
    void register_api();
    void set_restrictions(const std::string& profile);
};