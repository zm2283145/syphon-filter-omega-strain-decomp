#ifndef PLAYERCONTROLS_TYPES_H
#define PLAYERCONTROLS_TYPES_H

/*
 * Provisional types for src/main/playerControls (player input state and the
 * small helpers around the input helper func_0024B5D0). Field names are
 * placeholders (unkXX) unless the research notes justify them.
 */

#include "types.h"

/* Player input state (embedded in the player component at +0x50). */
typedef struct InputState {
    char pad00[0x24];
    unsigned char crouchZone;  /* 0x24: inside a code-9 (crouch) trigger zone */
    unsigned char unk25;       /* 0x25 */
    unsigned char unk26;       /* 0x26: set together with unk27/unk28 */
    signed char unk27;         /* 0x27 */
    int unk28;                 /* 0x28 */
} InputState;

/* Camera fields touched from the input code. */
typedef struct PlayerCamera {
    char pad000[0xC68];
    float fovTarget;           /* 0xC68: field-of-view angle +0xC64 approaches */
} PlayerCamera;

/* Object whose float at +0x934 is returned negated by func_00250380. */
typedef struct ControlsUnk934 {
    char pad000[0x934];
    float unk934;
} ControlsUnk934;

/* Object with a count-like int at +0x5C. */
typedef struct ControlsUnk5C {
    char pad00[0x5C];
    int unk5C;
} ControlsUnk5C;

/* Optional float: flag byte plus value. */
typedef struct OptFloat {
    unsigned char set;
    float value;
} OptFloat;

/* Vector of 8-byte elements (count at +4, data at +8). */
typedef struct Pair8 {
    int a, b;
} Pair8;

typedef struct Pair8Vec {
    int unk0;
    int count;
    Pair8* data;
} Pair8Vec;

typedef struct Vec3f {
    float x, y, z;
} Vec3f;

typedef struct Vec2f {
    float x, y;
} Vec2f;

#endif
