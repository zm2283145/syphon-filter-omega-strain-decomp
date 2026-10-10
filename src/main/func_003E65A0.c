#include "types.h"
#pragma opt_propagation off

typedef union ScriptArg { int i; float f; void* p; signed char c; } ScriptArg;
extern void* func_003CB1C0(void* object);
extern void Global_PerformAction_2(void* actor, signed char action, int target, int zero, float value);

/* Script native: makes the actor of args[0] perform action args[1] on args[2] with value args[3]; returns 0. */
int Script_PerformAction_3(ScriptArg* args)
{
    int value[1];
    int target[1];
    float v;
    value[0] = args[3].i;
    target[0] = args[2].i;
    v = *(float*)value;
    Global_PerformAction_2(func_003CB1C0(args[0].p), args[1].c, *(int*)target, 0, v);
    return 0;
}
