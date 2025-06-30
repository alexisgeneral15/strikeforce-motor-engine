#include "metal_backend.h"

#define METAL_CHECK(call) \
    if (call != METAL_SUCCESS) { \
        throw MetalException(__FILE__, __LINE__); \
    }

void MetalBackend::setup_pipeline() {
    MTLRenderPipelineDescriptor* pipelineDesc = 
        [MTLRenderPipelineDescriptor new];
    pipelineDesc.vertexFunction = vertexShader;
    pipelineDesc.fragmentFunction = fragmentShader;
    
    METAL_CHECK([device newRenderPipelineStateWithDescriptor:pipelineDesc
        error:&pipelineError]);
}