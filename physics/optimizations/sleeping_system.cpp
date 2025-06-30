#include "sleeping_system.h"

#define SLEEP_THRESHOLD 0.1f
#define INACTIVITY_TIME 2.0f

void SleepingSystem::update(float dt) {
    for (auto& body : bodies) {
        if (body->velocity.length_squared() < SLEEP_THRESHOLD * SLEEP_THRESHOLD) {
            body->inactive_time += dt;
            if (body->inactive_time >= INACTIVITY_TIME) {
                body->set_active(false);
            }
        } else {
            body->inactive_time = 0.0f;
            body->set_active(true);
        }
    }
}