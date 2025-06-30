#pragma once
#include "../input_system.h"
#include <windows.h>

class WindowsInput : public InputSystem {
public:
    void update() override;
    
private:
    struct {
        bool move_left;
        bool move_right;
        bool jump;
    } state;
};