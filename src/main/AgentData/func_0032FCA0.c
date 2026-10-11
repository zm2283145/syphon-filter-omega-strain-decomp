#include "types.h"
typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;
typedef struct { int p0, p4; int stats[1]; } A2FCA0;
static inline void Set2FCA0(A2FCA0* s, int i, int v) { s->stats[i] = v; }
#pragma opt_propagation off
int Script_cAgentData_SetStat(ScriptArg* args)
{
    int v[1];
    v[0] = args[2].i;
    Set2FCA0((A2FCA0*)args[0].p, args[1].b, *(int*)v);
    return 0;
}
