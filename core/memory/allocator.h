#pragma once
#include <cstddef>

class ArenaAllocator {
public:
    ArenaAllocator(size_t size);
    ~ArenaAllocator();
    
    void* allocate(size_t size);
    void reset();
    
private:
    char* arena;
    size_t arena_size;
    size_t current_offset = 0;
};