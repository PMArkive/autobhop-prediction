#pragma once

class GameMovement;

inline GameMovement* game_movement;

namespace CheckJumpButton {
    bool __fastcall fn(GameMovement*);
    using T = decltype(fn);
    inline T* original;
    static const int index = 29;
}
