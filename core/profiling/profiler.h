#pragma once
#include <vector>
#include <string>

struct ProfileData {
    std::string name;
    float duration_ms;
};

class Profiler {
public:
    static Profiler& Get();
    
    void BeginFrame();
    void EndFrame();
    void RecordSample(const std::string& name, float duration);
    
private:
    std::vector<ProfileData> frame_data;
    std::vector<std::vector<ProfileData>> frame_history;
};