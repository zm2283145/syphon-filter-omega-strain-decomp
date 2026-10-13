#include "types.h"

typedef union { int i; float f; void* p; } ScriptArg;

extern void* NpcScript_GetReceiver(void* p);
extern float Global_Distance_5(void* a, void* b);

/* Script native: returns the distance between two resolved objects, as raw float bits. */
int Script_Distance_5(ScriptArg* args)
{
    ScriptArg result[1];
    void* a = NpcScript_GetReceiver(args[0].p);
    void* b = NpcScript_GetReceiver(args[1].p);
    result[0].f = Global_Distance_5(a, b);
    return result[0].i;
}
