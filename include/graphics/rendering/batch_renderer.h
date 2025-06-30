#pragma once

#include <GL/glew.h>
#include "../ecs/components.h"

struct SpriteInstance {
    // Datos de instancia para renderizado
};

class BatchRenderer {
public:
    BatchRenderer();
    ~BatchRenderer();
    
    void Submit(const SpriteComponent& sprite, const TransformComponent& transform);
    void Flush();

private:
    GLuint instanceVBO;
    GLuint VAO;
    std::vector<SpriteInstance> batches;
    size_t currentBatch = 0;
    size_t maxBatches = 1000;
    GLuint currentTexture = 0;
};