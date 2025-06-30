#pragma once
#include "../rendering/framebuffer.h"
#include <vector>
#include <memory>

struct LightParams {
    Vector3 color;
    float intensity;
    float falloff;
    float distance;
};

class Light {
public:
    virtual void calculate(const LightParams& params, LightBuffer& buffer) = 0;
    virtual ~Light() = default;
};

class Lighting2D {
public:
    void init();
    void add_light(std::unique_ptr<Light> light);
    void render_lightmap();
    
private:
    std::vector<std::unique_ptr<Light>> lights;
    Framebuffer light_fbo;
    Shader light_shader;
};