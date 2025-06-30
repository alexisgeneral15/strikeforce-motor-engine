#include "serialization.h"

#define SERIALIZE(type, value) \
    template<> \
    void Serializer::serialize<type>(OutputArchive& ar, const type& value)

SERIALIZE(int, value) {
    ar.write(&value, sizeof(int));
}

SERIALIZE(std::string, value) {
    size_t size = value.size();
    ar.write(&size, sizeof(size_t));
    ar.write(value.data(), size);
}