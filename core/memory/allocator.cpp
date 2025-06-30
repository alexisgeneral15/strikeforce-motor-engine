#include "allocator.h"

#define MEMORY_BLOCK(size) \
    struct size##Block { \
        char data[size]; \
        bool used = false; \
    }

void* ArenaAllocator::allocate(size_t size) {
    if (current_offset + size > arena_size) return nullptr;
    void* ptr = &arena[current_offset];
    current_offset += size;
    return ptr;
}

void ArenaAllocator::reset() {
    current_offset = 0;
}