/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"
#include "NIEvent_types.h"

extern void func_0023E3D0(void* obj, float speed);

/* SetSpeed(object, speed): float argument is passed through a stack slot. */
int Script_cNIEventOBJ_SetSpeed(NIEventScriptArg* args) {
    NIEventScriptArg speed[1];

    speed[0].i = args[1].i;
    func_0023E3D0(args[0].p, speed[0].f);
    return 0;
}
