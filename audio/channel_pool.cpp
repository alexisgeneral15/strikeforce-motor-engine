#pragma once
#include <vector>

namespace FMOD {
    class Channel;
}

class ChannelPool {
public:
    ChannelPool(int size);
    FMOD::Channel* GetChannel();
    
private:
    std::vector<FMOD::Channel*> channels;
};