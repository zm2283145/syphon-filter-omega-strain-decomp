/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose02_types.h"

extern void* GObj_IdentityB(void* obj);
extern int Global_SetLocation(void* obj, int location);

/* Script native: SetLocation(object, location). */
int Script_SetLocation(ScriptArg* args) {
    int loc[1];

    loc[0] = args[1].i;
    Global_SetLocation(GObj_IdentityB(args[0].p), STACK_COPY(loc));
    return 0;
}
