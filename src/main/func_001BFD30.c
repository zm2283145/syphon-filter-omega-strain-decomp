/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose00_types.h"

extern int Global_LoadAnimation(int anim);

/* Script native: LoadAnimation(id). */
int Script_LoadAnimation(ScriptArg* args) {
    volatile int anim = args[0].i; /* stored to the stack and reloaded */

    Global_LoadAnimation(anim);
    return 0;
}
