#include "types.h"

typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern void* func_00175FA0(void* object);
extern void* GObj_IdentityB(void* object);
extern float Global_Distance_2(void* a, void* b);

/* Script native: distance between the two objects, returned as float bits. */
int Script_Distance_2(ScriptArg* args)
{
    void* a = func_00175FA0(args[0].p);
    float d[1];
    d[0] = Global_Distance_2(a, GObj_IdentityB(args[1].p));
    return *(int*)d;
}
