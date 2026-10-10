#include "types.h"

typedef union { int i; void* p; } ScriptArg;

extern void func_00333860(void* agent, int kind, int index);

/* Script native: completes a bonus-level requirement (kind 3) of the agent data. */
int Script_cAgentData_CompleteBonusLevelReq(ScriptArg* args)
{
    int index[1];
    index[0] = args[1].i;
    func_00333860(args[0].p, 3, *(int*)index);
    return 0;
}
