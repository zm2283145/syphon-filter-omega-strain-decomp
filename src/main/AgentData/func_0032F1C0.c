#include "types.h"

typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern void func_00333860(void* agent, int a1, int requirement);

/* Script native: completes special rating requirement args[1] for agent data args[0]. */
int Scr_cAgentData_CompleteSpecialRatingReq(ScriptArg* args)
{
    int part[1];
    part[0] = args[1].i;
    func_00333860(args[0].p, 0, *(int*)part);
    return 0;
}
