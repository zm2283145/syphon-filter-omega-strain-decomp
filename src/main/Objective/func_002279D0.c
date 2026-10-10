#include "types.h"

typedef union { int i; float f; } ScriptArg;

extern void Global_SetObjectiveColor(int objective, int a, int b, float c);

/* Script native: sets an objective's color. */
int Script_SetObjectiveColor(ScriptArg* args)
{
    ScriptArg c[1];
    int b[1];
    int a[1];
    int objective[1];
    c[0].i = args[3].i;
    b[0] = args[2].i;
    a[0] = args[1].i;
    objective[0] = args[0].i;
    Global_SetObjectiveColor(*(int*)objective, *(int*)a, *(int*)b, c[0].f);
    return 0;
}
