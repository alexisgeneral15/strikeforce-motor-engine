#pragma once
#include "../rendering/framebuffer.h"
#include <vector>
#include <memory>

class PostEffect {
public:
    virtual void apply(Framebuffer& src, Framebuffer& dst) = 0;
    virtual ~PostEffect() = default;
};

class PostProcessor {
public:
    void init();
    void add_effect(std::unique_ptr<PostEffect> effect);
    void apply_effects();
    
private:
    std::vector<std::unique_ptr<PostEffect>> effects;
    Framebuffer main_fbo;
    Framebuffer pingpong_fbo[2];
    Texture final_result;
};