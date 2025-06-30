#pragma once
#include <unordered_map>
#include <string>

#define SHADER_PROGRAM(name) \
    class name##Shader : public ShaderProgram { \
    public: \
        name##Shader() { \
            load("shaders/" #name ".vert", "shaders/" #name ".frag"); \
        } \
        void set_custom_uniforms() override; \
    }

class ShaderManager {
public:
    static ShaderManager& get();
    
    ShaderProgram* get_program(const std::string& name);
    void reload_all();
    
private:
    std::unordered_map<std::string, std::unique_ptr<ShaderProgram>> programs;
};