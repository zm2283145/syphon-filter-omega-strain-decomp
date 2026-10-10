#include "types.h"

typedef union { int i; void* p; } ScriptArg;

extern void func_00333130(void* agent, int kind, int index);

/* Script native: unlocks a special-rating requirement (kind 0) of the agent data. */
int Script_cAgentData_UnlockSpecialRatingReq(ScriptArg* args)
{
    int index[1];
    index[0] = args[1].i;
    func_00333130(args[0].p, 0, *(int*)index);
    return 0;
}
