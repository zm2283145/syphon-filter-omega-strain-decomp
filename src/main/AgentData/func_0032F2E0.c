#include "types.h"
typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern void func_00333130(void* agentData, int kind, int medal);
/* Script native: unlocks medal requirement args[1] on agent data args[0]; returns 0. */
int Script_cAgentData_UnlockMedalRequirement(ScriptArg* args)
{
    int medal[1];
    medal[0] = args[1].i;
    func_00333130(args[0].p, 2, *(int*)medal);
    return 0;
}
