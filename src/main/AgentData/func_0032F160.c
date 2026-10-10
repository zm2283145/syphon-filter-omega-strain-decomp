#include "types.h"

extern void func_00333860(void* agent, int kind, int value);

typedef union { int i; void* p; float f; } ScriptArg;

/* Script native: completes an Omega requirement (kind 4) on the agent data. */
int Script_cAgentData_CompleteOmegaReq(ScriptArg* args)
{
    int p1[1];
    p1[0] = args[1].i;
    func_00333860(args[0].p, 4, *(int*)p1);
    return 0;
}
