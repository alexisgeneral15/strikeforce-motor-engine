#pragma once
#include <fstream>

class BinaryWriter {
public:
    void Write(const void* data, size_t size);
};