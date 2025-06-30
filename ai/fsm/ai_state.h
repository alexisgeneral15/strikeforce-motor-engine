#pragma once
#include <functional>

#define AI_STATE(name) \
    class name##State : public AIState { \
    public: \
        name##State() : AIState(#name) {} \
        void enter(AIController* owner) override; \
        void update(float dt) override; \
        void exit(AIController* owner) override; \
    }

class AIState {
public:
    explicit AIState(const std::string& name) : name(name) {}
    virtual ~AIState() = default;
    
    virtual void enter(AIController* owner) = 0;
    virtual void update(float dt) = 0;
    virtual void exit(AIController* owner) = 0;
    
protected:
    std::string name;
};