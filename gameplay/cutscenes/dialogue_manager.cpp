#include "dialogue_manager.h"

void DialogueManager::start_dialogue(const std::string& id) {
    static std::unordered_map<std::string, std::vector<DialogueEntry>> dialogues = {
        {"greeting", {
            DIALOGUE_ENTRY("Guard", "Halt! Who goes there?"),
            DIALOGUE_ENTRY("Player", "", {
                DIALOGUE_CHOICE("I'm a friend", {
                    ctx.set_relation("guard", 10);
                    ctx.exit_dialogue();
                }),
                DIALOGUE_CHOICE("None of your business", {
                    ctx.set_relation("guard", -5);
                    ctx.start_combat("guard");
                })
            })
        }}
    };
    
    if(dialogues.count(id)) {
        current_dialogue = dialogues[id];
        current_index = 0;
        in_dialogue = true;
    }
}