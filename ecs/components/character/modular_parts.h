#pragma once
#include "../../ecs.h"
#include <map>

enum class BodyPart { head, torso, arms, legs };

class ModularCharacter : public Component {
public:
    void set_head(const std::string& part_id);
    void set_torso(const std::string& part_id);
    void set_arms(const std::string& part_id);
    void set_legs(const std::string& part_id);
    
    void update_mesh();
    
private:
    std::map<BodyPart, std::shared_ptr<CharacterPart>> parts;
    Mesh combined_mesh;
};