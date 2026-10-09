#ifndef HUD_TYPES_H
#define HUD_TYPES_H

/*
 * Types used by hud.cc. Offsets come from the matched code; unkXX fields are
 * not understood yet.
 */

#include "types.h"

/* One script-native argument word (int, float bits or pointer). */
typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

/* List iterator (one node pointer). */
typedef struct ListPos {
    void* node;
} ListPos;

/* Hud element whose byte fields are set by func_00243480/func_00243490. */
typedef struct HudElement {
    char pad00[0x10];
    unsigned char unk10;            /* 0x10 */
    char pad11[0x4A];
    unsigned char unk5B;            /* 0x5B */
    char pad5C[0x18];
    int unk74;                      /* 0x74 */
} HudElement;

#endif
