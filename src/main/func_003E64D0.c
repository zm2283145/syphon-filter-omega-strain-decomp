/*
 * Matched functions (byte-identical with the retail executable).
 * Script natives for the PerformAction family.
 */

#include "types.h"
#include "loose04_types.h"

extern int GObj_IdentityB(int handle);
extern int Global_PerformAction_WithObject(int obj, int action, int target, int arg, int flags, float time);
extern int func_003CB1C0(int handle);
extern int func_003E67C0(int obj, int action, int target, int arg, float time);

/* PerformAction_WithObject(obj, action, target, arg). */
int Script_PerformAction_WithObject_2(L4ScriptArg* args) {
    volatile int arg = args[3].i; /* reloaded from the stack in the original */
    int obj;
    int action;

    action = args[1].c;
    obj = func_003CB1C0(args[0].i);
    Global_PerformAction_WithObject(obj, action, GObj_IdentityB(args[2].i), arg, 0, -1.0f);
    return 0;
}

/* PerformAction_WithObject(obj, action, target). */
int Script_PerformAction_WithObject(L4ScriptArg* args) {
    int obj;
    int action;

    action = args[1].c;
    obj = func_003CB1C0(args[0].i);
    func_003E67C0(obj, action, GObj_IdentityB(args[2].i), 0, -1.0f);
    return 0;
}
