#pragma once
#include "../graphics_backend.h"
#import <Metal/Metal.h>

class MetalBackend : public GraphicsBackend {
public:
    void initialize() override;
    void render_frame() override;
    
private:
    id<MTLDevice> device;
    id<MTLRenderPipelineState> pipeline;
    
    void setup_pipeline();
    void create_buffers();
};