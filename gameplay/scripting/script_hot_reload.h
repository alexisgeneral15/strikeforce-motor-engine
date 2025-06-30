#pragma once
#include <filesystem>
#include "../core/hot_reload.h"

#define SCRIPT_RELOAD_CALLBACK(name) \
    void name##_reload_callback(const std::filesystem::path& path) { \
        auto it = loaded_scripts.find(path.string()); \
        if(it != loaded_scripts.end()) { \
            lua.script_file(path.string()); \
        } \
    }

class ScriptHotReload : public FileWatcher::Listener {
public:
    void on_file_modified(const std::filesystem::path& path) override;
};