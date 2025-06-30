#include "skeletal_animation.h"
#include <cmath>

void SkeletalAnimation::update(float dt) {
    if (keyframes.empty()) return;
    
    current_time += dt * speed;
    if (current_time > duration) {
        if (looping) current_time = 0;
        else current_time = duration;
    }
    
    float frame_ratio = current_time / (duration / keyframes.size());
    int current_frame = static_cast<int>(frame_ratio) % keyframes.size();
    int next_frame = (current_frame + 1) % keyframes.size();
    float blend_factor = frame_ratio - current_frame;
    
    for (size_t i = 0; i < bones.size(); ++i) {
        bones[i].current_transform = interpolate(
            keyframes[current_frame].transforms[i],
            keyframes[next_frame].transforms[i],
            blend_factor
        );
    }
}