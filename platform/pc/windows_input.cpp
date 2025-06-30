#include "windows_input.h"

#define INPUT_ACTION(name, vk_code) \
    void WindowsInput::update_##name() { \
        state.name = (GetAsyncKeyState(vk_code) & 0x8000) != 0; \
    }

INPUT_ACTION(move_left, VK_LEFT);
INPUT_ACTION(move_right, VK_RIGHT);
INPUT_ACTION(jump, VK_SPACE);

void WindowsInput::update() {
    update_move_left();
    update_move_right();
    update_jump();
}