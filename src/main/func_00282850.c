/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "loose01_types.h"

extern int D_00506228;
extern int GObj_IdentityA(void*);

int Script_cBeamMsg_Who(ScriptArg* args) {
    return GObj_IdentityA(((PtrMsg*)args[0].p)->who);
}

void func_00282860(void) {
}

int cBeamMsg_v03(void) {
    return D_00506228;
}
