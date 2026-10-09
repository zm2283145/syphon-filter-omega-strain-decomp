/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptUtils_types.h"

extern void* GObj_IdentityB(void* obj);
extern int Global_SetPersonalTimer(void* obj, int a1, float time);

/* Script native: SetPersonalTimer(obj = args[0], time = args[1]).
 * volatile mirrors the original stack temporary. */
int Script_SetPersonalTimer_2(ScriptArg* args) {
    volatile int bits = args[1].i;
    Global_SetPersonalTimer(GObj_IdentityB(args[0].p), 0, *(float*)&bits);
    return 0;
}
