#include "types.h"
typedef union ScriptArg { int i; float f; void* p; unsigned char b; } ScriptArg;
typedef struct { int p0, p4; int stats[18]; int level[1]; } A2FCD0;
int Script_cAgentData_AddScore(ScriptArg* args)
{
    A2FCD0* self;
    int val;
    int idx;
    int v[1];
    v[0] = args[2].i;
    val = *(int*)v;
    idx = args[1].b;
    self = (A2FCD0*)args[0].p;
    if (idx < 31 && val > 0) {
        self->stats[idx] += val;
        if (idx < 13)
            self->level[idx] += val;
    }
    return 0;
}