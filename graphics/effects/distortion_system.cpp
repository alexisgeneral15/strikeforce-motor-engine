#include "distortion_system.h"

#define DISTORTION_EFFECT(name) \
    void name##Distortion::apply(Texture& src, Texture& distortion_map) 

DISTORTION_EFFECT(Wave) {
    wave_shader.set_texture("u_scene", src);
    wave_shader.set_texture("u_distortion", distortion_map);
    wave_shader.set_float("u_time", GetTime());
    wave_shader.draw_fullscreen_quad();
};

void DistortionManager::render_effects() {
    distortion_fbo.begin();
    {
        for (auto& effect : effects) {
            effect->apply(main_texture, distortion_map);
        }
    }
    distortion_fbo.end();
}