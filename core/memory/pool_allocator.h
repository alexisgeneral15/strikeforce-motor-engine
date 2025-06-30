#pragma once
#include <vector>

template<typename T, size_t PoolSize>
class PoolAllocator {
public:
    T* allocate() {
        for (auto& block : pool) {
            if (!block.used) {
                block.used = true;
                return reinterpret_cast<T*>(&block.data);
            }
        }
        return nullptr;
    }
    
    void deallocate(T* ptr) {
        char* data_ptr = reinterpret_cast<char*>(ptr);
        for (auto& block : pool) {
            if (block.data == data_ptr) {
                block.used = false;
                break;
            }
        }
    }

private:
    MEMORY_BLOCK(sizeof(T));
    std::array<sizeof(T)Block, PoolSize> pool;
};