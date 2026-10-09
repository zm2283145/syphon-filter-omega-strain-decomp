/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "scriptUtils_types.h"

extern char* D_004FFC2C;
extern void* GObj_IdentityB(void* obj);
extern int Global_ClearCallout(char* obj);
extern int Global_ClearCallout_2(CalloutOwner* obj);
extern CalloutOwner* func_0014A690(void* obj);
extern int func_00242B40(char* a0, char* key, int a2, int a3, int a4);

int Script_ClearCallout_2(ScriptArg* args) {
    Global_ClearCallout_2(func_0014A690(args[0].p));
    return 0;
}

int Global_ClearCallout_2(CalloutOwner* obj) {
    return func_00242B40(D_004FFC2C, obj->callout + 12, 0, 0, 1);
}

int Script_ClearCallout(ScriptArg* args) {
    Global_ClearCallout(GObj_IdentityB(args[0].p));
    return 0;
}

int Global_ClearCallout(char* obj) {
    return func_00242B40(D_004FFC2C, obj + 12, 0, 0, 1);
}
