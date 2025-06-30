#include "batch_renderer.h"

void BatchRenderer::submit(const DrawCommand& cmd) {
    if (current_batch_size >= max_batch_size || 
       (current_batch_size > 0 && cmd.texture != current_texture)) {
        flush();
    }
    
    batch_buffer[current_batch_size++] = cmd;
}