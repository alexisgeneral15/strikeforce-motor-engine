#include "modular_parts.h"

#define BODY_PART_SLOT(slot) \
    void ModularCharacter::set_##slot(const std::string& part_id) { \
        parts[BodyPart::slot] = part_manager.load(part_id); \
    }

BODY_PART_SLOT(head);
BODY_PART_SLOT(torso);
BODY_PART_SLOT(arms);
BODY_PART_SLOT(legs);

void ModularCharacter::update_mesh() {
    combined_mesh.clear();
    for (auto& [part_type, part] : parts) {
        combined_mesh.merge(part->mesh);
    }
}