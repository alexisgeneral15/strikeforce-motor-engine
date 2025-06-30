// En gameplay_defines.h
#define WEAPON_TYPE(name, damage) \
    struct name##Weapon { \
        static constexpr float base_damage = damage; \
        void fire(Entity* owner); \
    };

WEAPON_TYPE(Pistol, 25.0f)
WEAPON_TYPE(Rifle, 40.0f)
WEAPON_TYPE(Shotgun, 60.0f)