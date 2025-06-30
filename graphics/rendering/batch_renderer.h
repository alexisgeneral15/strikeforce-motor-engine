#pragma once
#include <array>
#include "texture.h"

class BatchRenderer {
public:
    static constexpr size_t max_batch_size = 1024;
    
    void init();
    void submit(const DrawCommand& cmd);
    void flush();
    
private:
    std::array<DrawCommand, max_batch_size> batch_buffer;
    size_t current_batch_size = 0;
    Texture* current_texture = nullptr;
};