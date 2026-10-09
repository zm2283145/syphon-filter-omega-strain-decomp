#ifndef PLAYER_TYPES_H
#define PLAYER_TYPES_H

/*
 * Provisional types for src/main/player (the player component, also the cPlayer
 * script object). Field names are placeholders (unkXX) unless the research
 * notes or function names justify them.
 */

#include "types.h"

/* One script-native argument slot; args[0] is the receiver object. */
typedef union PlayerScriptArg {
    int i;
    float f;
    void* p;
} PlayerScriptArg;

/* Actor fields used by the player component. */
typedef struct PlayerActor {
    char pad0000[0x4C];
    int classToken;          /* 0x4C: compared with the NPC class token */
    char pad0050[0x3524 - 0x50];
    void* inventory;         /* 0x3524 */
} PlayerActor;

/* Player input state embedded in the component at +0x50 (layout in playerControls). */
typedef struct PlayerInputState {
    char data[0x1A0 - 0x50];
} PlayerInputState;

/* Player component (class table D_004D9CF0); attached to the actor at actor +0x58. */
typedef struct PlayerComponent {
    void* vtable;            /* 0x000 */
    char pad004[0x30 - 0x04];
    PlayerActor* actor;      /* 0x030: owning actor, saved on attachment */
    char pad034[0x50 - 0x34];
    PlayerInputState input;  /* 0x050 */
    int unk1A0;              /* 0x1A0: passed to the input helper */
    int unk1A4;              /* 0x1A4 */
    float unk1A8;            /* 0x1A8: cleared after each update */
    float unk1AC;            /* 0x1AC: cleared after each update */
    int unk1B0;              /* 0x1B0 */
    int unk1B4;              /* 0x1B4 */
    int unk1B8;              /* 0x1B8: -1 when unset */
    unsigned char unk1BC;    /* 0x1BC */
    char pad1BD[0x1C0 - 0x1BD];
    int unk1C0;              /* 0x1C0 */
} PlayerComponent;

#endif
