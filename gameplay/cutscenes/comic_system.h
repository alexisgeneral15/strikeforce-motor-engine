#pragma once
#include <vector>
#include "../ecs/ecs.h"

#define COMIC_FRAME(duration, action) \
    { duration, [](CutsceneContext& ctx) { action } }

class ComicSystem {
public:
    struct Frame {
        float duration;
        std::function<void(CutsceneContext&)> action;
    };
    
    void play_cutscene(const std::string& id);
    
private:
    std::unordered_map<std::string, std::vector<Frame>> cutscenes;
};