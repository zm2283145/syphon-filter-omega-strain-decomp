/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptUtils_types.h"

extern ScriptArray* ScriptArray_Cast(void* obj);

/* Script native: Array.Print(); the cast result is unused in this build. */
int Script_Array_Print(ScriptArg* args) {
    ScriptArray_Cast(args[0].p);
    return 0;
}
