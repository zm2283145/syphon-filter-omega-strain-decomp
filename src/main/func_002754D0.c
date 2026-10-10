#include "types.h"
#pragma global_optimizer off

typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern float D_004FFDA0, D_004FFDA4, D_004FFDA8, D_004FFDAC;

static inline void Global_SetRadarObjCol(int r, int g, int b, float a)
{
    D_004FFDA0 = r / 255.0f;
    D_004FFDA4 = g / 255.0f;
    D_004FFDA8 = b / 255.0f;
    D_004FFDAC = a;
}

/* Script native: sets the radar object colour from 0-255 RGB args and a float alpha; returns 0. */
int Script_SetRadarObjCol(ScriptArg* args)
{
    int r[1];
    int g[1];
    int b[1];
    int a[1];
    a[0] = args[3].i;
    b[0] = args[2].i;
    g[0] = args[1].i;
    r[0] = args[0].i;
    Global_SetRadarObjCol(*(int*)r, *(int*)g, *(int*)b, *(float*)a);
    return 0;
}

