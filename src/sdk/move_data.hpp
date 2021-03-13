#pragma once

#include "vector.hpp"
#include "qangle.hpp"
#include "base_handle.hpp"

struct MoveData {
    bool first_run_of_functions : 1;
    bool game_code_moved_player : 1;
    BaseHandle player_handle;
    int impulse_command;
    QAngle view_angles;
    QAngle abs_view_angles;
    int buttons;
    int old_buttons;
    float forward_move;
    float old_forward_move;
    float side_move;
    float up_move;
    float max_speed;
    float client_max_speed;
    Vector velocity;
    QAngle angles;
    QAngle old_angles;
    float out_step_height;
    Vector out_wish_vel;
    Vector out_jump_vel;
    Vector constraint_center;
    float constraint_radius;
    float constraint_width;
    float constraint_speed_factor;
    Vector abs_origin;
};
