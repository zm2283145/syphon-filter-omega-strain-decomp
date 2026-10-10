#include "types.h"

typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern void func_00333860(void* agent, int a1, int requirement);

/* Script native: completes commendation requirement args[1] for agent data args[0]. */
int Scr_cAgentData_CompleteCommendationReq(ScriptArg* args)
{
    int part[1];
    part[0] = args[1].i;
    func_00333860(args[0].p, 1, *(int*)part);
    return 0;
}
