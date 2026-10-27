#include "types.h"
typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;
extern void cAgentData_CompleteRequirement(void* self, int kind, int v);
int Script_cAgentData_CompleteMedalReq(ScriptArg* args)
{
    int p1[1];
    p1[0] = args[1].i;
    cAgentData_CompleteRequirement(args[0].p, 2, *(int*)p1);
    return 0;
}