#include "post_processing.h"

#define POST_EFFECT(name) \
    void name##Effect::apply(Framebuffer& src, Framebuffer& dst) 

POST_EFFECT(Bloom) {
    bloom_shader.set_texture("u_scene", src.get_color_texture());
    dst.begin();
    bloom_shader.draw_fullscreen_quad();
    dst.end();
};

void PostProcessor::apply_effects() {
    Framebuffer* current = &main_fbo;
    Framebuffer* next = &pingpong_fbo[0];
    
    for (auto& effect : effects) {
        effect->apply(*current, *next);
        std::swap(current, next);
    }
    
    final_result = current->get_color_texture();
}