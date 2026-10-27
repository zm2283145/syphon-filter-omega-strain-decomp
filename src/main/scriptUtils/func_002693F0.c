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
