#pragma once
#include "../input_system.h"
#include <vector>

struct TouchPoint {
    float x;
    float y;
    int id;
};

class TouchInput : public InputSystem {
public:
    void process_events(const std::vector<TouchEvent>& events) override;
    
private:
    static constexpr int swipe_required_fingers = 1;
    static constexpr int pinch_required_fingers = 2;
    static constexpr int tap_required_fingers = 1;
};