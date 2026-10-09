/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptManager_types.h"

extern void Script_Unschedule(int id);

/* Script native: Unschedule(args[0]). volatile mirrors the original stack temporary. */
int Script_UnscheduleThunk(ScriptArg* args) {
    volatile int id = args[0].i;
    Script_Unschedule(id);
    return 0;
}
