#include "profiler.h"

std::vector<FrameData> Profiler::frame_history;

void Profiler::end_frame() {
    frame_history.push_back(current_frame);
    if (frame_history.size() > max_frames) {
        frame_history.erase(frame_history.begin());
    }
}