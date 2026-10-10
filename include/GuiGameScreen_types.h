#ifndef GUIGAMESCREEN_TYPES_H
#define GUIGAMESCREEN_TYPES_H

/*
 * Types used by GuiGameScreen.cc (in-game menu / interact prompt screen).
 * Offsets come from the matched code; unkXX fields are not understood yet.
 */

#include "types.h"

/* One script-native argument word (int, float bits or pointer). */
typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

/* Child widget whose flag word lives at +0x14. */
typedef struct GuiGameChild {
    char pad00[0x14];
    unsigned short flags;           /* 0x14 bit 1 = visible/active */
} GuiGameChild;

/* Text-array style choice list; entry count at +0x94. */
typedef struct GuiChoiceList {
    char pad00[0x94];
    int count;                      /* 0x94 */
} GuiChoiceList;

/* The game screen widget. */
typedef struct GuiGameScreen {
    char pad00[0xE0];
    GuiGameChild* menu;             /* 0xE0 */
    char padE4[0x4];
    GuiChoiceList* choices;         /* 0xE8 */
    int unkEC;                      /* 0xEC */
} GuiGameScreen;

typedef struct GameHudOwner {
    char pad0000[0x6A4];
    void* hud;
} GameHudOwner;

#define STACK_COPY(arr) (*(int*)(arr))

#endif
