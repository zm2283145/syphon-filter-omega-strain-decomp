#include "types.h"
typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern void* NpcScript_GetReceiver(void*);
extern void* GObj_IdentityB(void*);
extern float Global_Distance_4(void*, void*);
/* Script native: distance between two script objects. */
int Script_Distance_4(ScriptArg* args)
{
    volatile float result;
    void* a = NpcScript_GetReceiver(args[0].p);
    result = Global_Distance_4(a, GObj_IdentityB(args[1].p));
    return *(int*)&result;
}
