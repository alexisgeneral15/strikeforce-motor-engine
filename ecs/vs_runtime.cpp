#include "vs_runtime.h"

#define NODE_EXECUTE(name) \
    void name##Node::execute() override

NODE_EXECUTE(Print) {
    std::cout << message << std::endl;
    std::this_thread::sleep_for(std::chrono::duration<float>(delay));
};

NODE_EXECUTE(Condition) {
    bool result = false;
    switch (cond_type) {
        case 0: result = (input_a == input_b); break;
        case 1: result = (input_a != input_b); break;
        case 2: result = (input_a > input_b); break;
        case 3: result = (input_a < input_b); break;
    }
    output = result;
};

void VisualScriptRuntime::update(float dt) {
    for (auto& node : execution_queue) {
        node->execute();
    }
}