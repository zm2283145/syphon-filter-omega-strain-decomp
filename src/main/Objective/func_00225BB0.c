#include "types.h"

typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern void* ObjMan_ResolveReceiver(void* manager);
extern int ObjMan_AddObjective(void* objectives, int objective);

/* Script native: adds objective args[1] to the objective list of manager args[0]; returns the result. */
int ObjMan_ScriptAddObjective(ScriptArg* args)
{
    volatile int result;
    int part[1];
    part[0] = args[1].i;
    result = ObjMan_AddObjective(ObjMan_ResolveReceiver(args[0].p), *(int*)part);
    return result;
}
