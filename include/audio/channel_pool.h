#pragma once
#include <vector>
#include <FMOD/fmod.hpp>

class AudioChannelPool {
public:
    explicit AudioChannelPool(size_t size);
    FMOD::Channel* get_channel();
    void release_channel(FMOD::Channel* channel);
    
private:
    std::vector<FMOD::Channel*> pool;
    std::vector<bool> in_use;
};