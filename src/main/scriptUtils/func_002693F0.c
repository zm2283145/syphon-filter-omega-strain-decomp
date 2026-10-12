/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptUtils_types.h"

extern void* cNodeList_ctor(void* obj);
extern int func_002697E0(void* obj);
extern void* Group_FromHandle(void* obj);

void func_002693F0(void) {
}

/* Script native: CreateNodeList(args[0]). */
int Script_CreateNodeList(ScriptArg* args) {
    return func_002697E0(cNodeList_ctor(Group_FromHandle(args[0].p)));
}
