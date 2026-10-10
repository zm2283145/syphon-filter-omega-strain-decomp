#include "types.h"
typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern void* func_0014A690(void*);
extern void* GObj_IdentityB(void*);
extern float Global_Distance_4(void*, void*);
/* Script native: distance between two script objects. */
int Script_Distance_4(ScriptArg* args)
{
    volatile float result;
    void* a = func_0014A690(args[0].p);
    result = Global_Distance_4(a, GObj_IdentityB(args[1].p));
    return *(int*)&result;
}
