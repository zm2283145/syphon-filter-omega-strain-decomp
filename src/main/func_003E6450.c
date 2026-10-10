#include "types.h"

typedef union ScriptArg { int i; float f; void* p; signed char c; } ScriptArg;
extern void* func_003CB1C0(void* obj);
extern void* GObj_IdentityB(void* obj);
extern void Global_PerformAction_WithObject(void* actor, int action, void* target, int extra, float value, int flag);

/* Script native: makes args[0] perform action args[1] on object args[2] with args[3]/args[4]. */
int Script_PerformAction_WithObject_3(ScriptArg* args)
{
    int p4[1];
    int p3[1];
    void* actor;
    int action;
    float value;
    p4[0] = args[4].i;
    p3[0] = args[3].i;
    action = args[1].c;
    value = *(float*)p4;
    actor = func_003CB1C0(args[0].p);
    Global_PerformAction_WithObject(actor, action, GObj_IdentityB(args[2].p), *(int*)p3, value, 0);
    return 0;
}
