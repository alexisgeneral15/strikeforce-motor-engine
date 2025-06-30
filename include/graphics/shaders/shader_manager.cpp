#include "graphics/shaders/shader_manager.h"

ShaderManager& ShaderManager::get() {
    static ShaderManager instance;
    return instance;
}

ShaderProgram* ShaderManager::get_program(const std::string& name) {
    auto it = programs.find(name);
    if (it == programs.end()) {
        // Carga bajo demanda
        if (name == "particle") programs[name] = std::make_unique<ParticleShader>();
        else if (name == "postfx") programs[name] = std::make_unique<PostFXShader>();
    }
    return programs[name].get();
}