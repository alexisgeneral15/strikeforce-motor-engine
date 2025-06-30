#pragma once
#include "binary_writer.h"
#include <type_traits>

class Serializer {
public:
    template<typename T>
    static void serialize(OutputArchive& ar, const T& value) {
        if constexpr (std::is_arithmetic_v<T>) {
            ar.write(&value, sizeof(T));
        } else {
            static_assert(false, "Type not serializable");
        }
    }
};