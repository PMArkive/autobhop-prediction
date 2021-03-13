#include <sdk/game_movement.hpp>
#include <sdk/move_data.hpp>
#include <sdk/player_buttons.hpp>

#include "game_movement.hpp"

bool __fastcall CheckJumpButton::fn(GameMovement* gm) {
    gm->move_data->old_buttons &= ~PlayerButtons::JUMP;
    return original(gm);
}
