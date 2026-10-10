#include "types.h"
#include "scriptUtils_types.h"

extern void func_00333130(void* agent, int unlock, int req);

/* Script native: cAgentData.UnlockCommendationReq(agent, req). */
int Script_cAgentData_UnlockCommendationReq(ScriptArg* args) {
    int part[1]; /* staged through the stack */
    part[0] = args[1].i;
    func_00333130(args[0].p, 1, *(int*)part);
    return 0;
}
