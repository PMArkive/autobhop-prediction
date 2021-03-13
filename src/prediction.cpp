#include "game_movement.hpp"

void enable_prediction() {
    void* vtable = *reinterpret_cast<void**>(game_movement);
    auto p = &reinterpret_cast<CheckJumpButton::T**>(vtable)[CheckJumpButton::index];

    *p = CheckJumpButton::fn;
}

void disable_prediction() {
    void* vtable = *reinterpret_cast<void**>(game_movement);
    auto p = &reinterpret_cast<CheckJumpButton::T**>(vtable)[CheckJumpButton::index];

    *p = CheckJumpButton::original;
}
