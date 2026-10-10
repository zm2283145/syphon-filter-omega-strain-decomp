#include "types.h"

typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern char D_0053B5C0[];
extern void Global_Wind(void* wind, float a, float b, float c, float d, float e);

/* Script native: sets the global wind parameters from five float args; returns 0. */
int Script_Wind(ScriptArg* args)
{
    int a[1];
    int b[1];
    int c[1];
    int d[1];
    int e[1];
    e[0] = args[4].i;
    d[0] = args[3].i;
    c[0] = args[2].i;
    b[0] = args[1].i;
    a[0] = args[0].i;
    Global_Wind(D_0053B5C0, *(float*)a, *(float*)b, *(float*)c, *(float*)d, *(float*)e);
    return 0;
}
