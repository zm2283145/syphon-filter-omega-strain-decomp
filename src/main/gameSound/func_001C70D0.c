/*
 * Matched functions (byte-identical with the retail executable).
 * SetReverb script native.
 */

#include "types.h"
#include "gameSound_types.h"

extern void Global_SetReverb(int unk0, int level1, int level2);

/* SetReverb(level): passes the level in both value slots. */
int Script_SetReverb(SoundScriptArg* args) {
    volatile int arg = args[0].i; /* original stack temporary */
    int level = arg;
    Global_SetReverb(1, level, level);
    return 0;
}
