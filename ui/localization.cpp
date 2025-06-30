#include "ui/localization.h"

Localization& Localization::get() {
    static Localization instance;
    return instance;
}

void Localization::load_language(const std::string& language) {
    current_language = language;
    // Cargar archivos JSON con las traducciones
}

const std::string& Localization::get_string(const std::string& category, const std::string& key) {
    static std::string empty;
    auto& cat = strings[current_language];
    auto it = cat.find(category);
    if (it != cat.end()) {
        auto& str_map = it->second;
        auto str_it = str_map.find(key);
        if (str_it != str_map.end()) {
            return str_it->second;
        }
    }
    return empty;
}