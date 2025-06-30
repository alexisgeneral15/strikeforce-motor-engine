#include "comic_system.h"

void ComicSystem::play_cutscene(const std::string& id) {
    if(!cutscenes.count(id)) return;
    
    auto& frames = cutscenes[id];
    CutsceneContext context;
    
    for(auto& frame : frames) {
        float elapsed = 0.0f;
        while(elapsed < frame.duration) {
            frame.action(context);
            elapsed += GetFrameTime();
        }
    }
}

// Ejemplo de definición de cutscene
void ComicSystem::init_example_cutscene() {
    cutscenes["intro"] = {
        COMIC_FRAME(2.0f, {
            ctx.show_panel("Narrator", "In a world torn by war...");
        }),
        COMIC_FRAME(3.0f, {
            ctx.show_image("backgrounds/warzone.png");
            ctx.shake_camera(0.5f);
        })
    };
}