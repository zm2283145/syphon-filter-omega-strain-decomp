#include "types.h"

typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

extern void func_00333130(void*, int, int);

/* Script: cAgentData.UnlockBonusLevelReq(value). */
int Script_cAgentData_UnlockBonusLevelReq(ScriptArg* args) {
    int value[1]; /* staged through the stack */
    value[0] = args[1].i;
    func_00333130(args[0].p, 3, *(int*)value);
    return 0;
}
