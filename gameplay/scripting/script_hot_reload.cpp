#include "script_hot_reload.h"

SCRIPT_RELOAD_CALLBACK(player_ai);
SCRIPT_RELOAD_CALLBACK(enemy_ai);
SCRIPT_RELOAD_CALLBACK(ui_scripts);

void ScriptHotReload::on_file_modified(const std::filesystem::path& path) {
    std::string ext = path.extension().string();
    if(ext == ".lua") {
        std::string stem = path.stem().string();
        
        if(stem == "player_ai") player_ai_reload_callback(path);
        else if(stem == "enemy_ai") enemy_ai_reload_callback(path);
        else if(stem == "ui") ui_scripts_reload_callback(path);
    }
}