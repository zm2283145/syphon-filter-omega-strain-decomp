/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptUtils_types.h"

extern ScriptArray* func_002690C0(void* obj);

/* Script native: Array.Count(). volatile mirrors the original stack temporary. */
int Script_Array_Count(ScriptArg* args) {
    volatile int count = func_002690C0(args[0].p)->count;
    return count;
}
