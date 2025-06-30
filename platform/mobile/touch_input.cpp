#include "touch_input.h"

#define TOUCH_GESTURE(name) \
    void TouchInput::handle_##name(const TouchEvent& event) { \
        if (event.pointers.size() == name##_required_fingers) { \
            for (const auto& p : event.pointers) { \
                process_##name##_gesture(p); \
            } \
        } \
    }

TOUCH_GESTURE(swipe);
TOUCH_GESTURE(pinch);
TOUCH_GESTURE(tap);

void TouchInput::process_events(const std::vector<TouchEvent>& events) {
    for (const auto& event : events) {
        handle_swipe(event);
        handle_pinch(event);
        handle_tap(event);
    }
}