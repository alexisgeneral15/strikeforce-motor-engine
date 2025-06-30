#pragma once
#include "../../ecs.h"
#include <vector>
#include <memory>

class VisualScriptNode {
public:
    virtual void draw_editor() = 0;
    virtual ~VisualScriptNode() = default;
};

class VisualScriptEditor : public System {
public:
    void update() override;
    
private:
    std::vector<std::unique_ptr<VisualScriptNode>> nodes;
};