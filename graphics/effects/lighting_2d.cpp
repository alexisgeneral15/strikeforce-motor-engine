#include "lighting_2d.h"

#define LIGHT_TYPE(type) \
    void type##Light::calculate(const LightParams& params, LightBuffer& buffer) 

LIGHT_TYPE(Point) {
    float intensity = params.intensity / (1.0f + params.falloff * params.distance);
    buffer.color = params.color * intensity;
};

void Lighting2D::render_lightmap() {
    light_fbo.begin();
    {
        for (auto& light : lights) {
            light->render(light_shader);
        }
    }
    light_fbo.end();
}