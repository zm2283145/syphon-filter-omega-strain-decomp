/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptManager_types.h"

extern ScriptManager D_00555070;
extern ScriptEnumEntry* func_003DCF70(ScriptManager* manager, int a1, int a3, int t0);

/* Resolves an enum through the script manager and stores its global id in script->enumMap[slot]. */
ScriptEnumEntry* func_003DC540(Script* script, int a1, int slot, int a3, int t0) {
    ScriptEnumEntry* entry = func_003DCF70(&D_00555070, a1, a3, t0);
    script->enumMap[slot] = entry->id;
    return entry;
}
