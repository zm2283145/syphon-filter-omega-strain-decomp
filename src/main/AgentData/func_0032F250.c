#include "types.h"
extern void func_00333130(int agent, int kind, int value);
/* Script: cAgentData.UnlockOmegaRequirement(agent, value). */
int Script_cAgentData_UnlockOmegaRequirement(int* args)
{
    int part[1]; /* staged through the stack */
    part[0] = args[1];
    func_00333130(args[0], 4, *(int*)part);
    return 0;
}
