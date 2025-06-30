#pragma once
#include "../../ecs.h"
#include <vector>
#include <memory>

class ScriptNode {
public:
    virtual void execute() = 0;
    virtual ~ScriptNode() = default;
};

class VisualScriptRuntime : public System {
public:
    void update(float dt) override;
    
private:
    std::vector<std::unique_ptr<ScriptNode>> execution_queue;
};