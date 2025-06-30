#pragma once
#include <memory>

#define ENGINE_ALLOC(type, ...) \
    Memory::allocate<type>(sizeof(type), ##__VA_ARGS__)

#define ENGINE_FREE(ptr) \
    Memory::deallocate(ptr)

namespace Memory {
    template<typename T, typename... Args>
    T* allocate(size_t size, Args&&... args) {
        void* mem = pool_alloc(size);
        return new (mem) T(std::forward<Args>(args)...);
    }

    template<typename T>
    void deallocate(T* ptr) {
        if (ptr) {
            ptr->~T();
            pool_free(ptr);
        }
    }
}