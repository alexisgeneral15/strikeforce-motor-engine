#pragma once
#include "../rendering/texture.h"
#include "../rendering/shader.h"
#include <vector>
#include <memory>

class DistortionEffect {
public:
    virtual void apply(Texture& src, Texture& distortion_map) = 0;
    virtual ~DistortionEffect() = default;
};

class DistortionManager {
public:
    void init();
    void add_effect(std::unique_ptr<DistortionEffect> effect);
    void render_effects();
    
private:
    std::vector<std::unique_ptr<DistortionEffect>> effects;
    Framebuffer distortion_fbo;
    Texture main_texture;
    Texture distortion_map;
};