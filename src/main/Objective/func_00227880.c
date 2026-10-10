#include "types.h"

typedef union ScriptArg {
    int i;
    float f;
    void* p;
} ScriptArg;

extern void Global_SetObjectiveFailColor(int, int, int, float);

/* Script: SetObjectiveFailColor(r, g, b, a); arguments are staged through the stack. */
int Script_SetObjectiveFailColor(ScriptArg* args) {
    int a[1];
    int b[1];
    int g[1];
    int r[1];
    a[0] = args[3].i;
    b[0] = args[2].i;
    g[0] = args[1].i;
    r[0] = args[0].i;
    Global_SetObjectiveFailColor(*(int*)r, *(int*)g, *(int*)b, *(float*)a);
    return 0;
}
