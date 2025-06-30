#pragma once
#include "../ecs/ecs.h"

#define DIALOGUE_ENTRY(speaker, text) \
    DialogueEntry { speaker, text, {} }

#define DIALOGUE_CHOICE(text, outcome) \
    { text, [](DialogueContext& ctx) { outcome } }

class DialogueManager {
public:
    struct DialogueEntry {
        std::string speaker;
        std::string text;
        std::vector<std::pair<std::string, std::function<void(DialogueContext&)>>> choices;
    };
    
    void start_dialogue(const std::string& id);
};