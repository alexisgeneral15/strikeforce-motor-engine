#pragma once
#include <unordered_map>
#include <vector>

#define LOCALIZED_STRING(category, key) \
    Localization::get().get_string(category, key)

class Localization {
public:
    static Localization& get();
    
    void load_language(const std::string& language);
    const std::string& get_string(const std::string& category, const std::string& key);
    
private:
    std::unordered_map<std::string, 
        std::unordered_map<std::string, std::string>> strings;
    std::string current_language;
};