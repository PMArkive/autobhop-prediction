#pragma once

namespace PlayerButtons {
    enum {
        ATTACK = 1 << 0,
        JUMP = 1 << 1,
        DUCK = 1 << 2,
        FORWARD = 1 << 3,
        BACK = 1 << 4,
        USE = 1 << 5,
        CANCEL = 1 << 6,
        LEFT = 1 << 7,
        RIGHT = 1 << 8,
        MOVE_LEFT = 1 << 9,
        MOVE_RIGHT = 1 << 10,
        ATTACK2 = 1 << 11,
        RUN = 1 << 12,
        RELOAD = 1 << 13,
        ALT1 = 1 << 14,
        ALT2 = 1 << 15,
        SCORE = 1 << 16,
        SPEED = 1 << 17,
        WALK = 1 << 18,
        ZOOM = 1 << 19,
        WEAPON1 = 1 << 20,
        WEAPON2 = 1 << 21,
        BULL_RUSH = 1 << 22,
        GRENADE1 = 1 << 23,
        GRENADE2 = 1 << 24,
        ATTACK3 = 1 << 25,
    };
}
