/*
 * SFOGame/Source/scriptUtils: 1 file, 002693F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002693F0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptUtils_types.h"

extern void* cNodeList_ctor(void* obj);
extern int cNodeList_SOBJ_toInt(void* obj);
extern void* cGroup_SOBJ_convert(void* obj);

void Debug_PrintStub(void) {
}

/* Script native: CreateNodeList(args[0]). */
int Script_CreateNodeList(ScriptArg* args) {
    return cNodeList_SOBJ_toInt(cNodeList_ctor(cGroup_SOBJ_convert(args[0].p)));
}
static inline void merge_flush_func_002693F0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_002693F0 */
