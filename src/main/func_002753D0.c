#include "types.h"
#pragma global_optimizer off

typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern float D_004FFDB0, D_004FFDB4, D_004FFDB8, D_004FFDBC;

static inline void Global_SetRadarFriendCol(int r, int g, int b, float a)
{
    D_004FFDB0 = r / 255.0f;
    D_004FFDB4 = g / 255.0f;
    D_004FFDB8 = b / 255.0f;
    D_004FFDBC = a;
}

/* Script native: sets the radar object colour from 0-255 RGB args and a float alpha; returns 0. */
int Script_SetRadarFriendCol(ScriptArg* args)
{
    int a[1];
    int b[1];
    int g[1];
    int r[1];
    a[0] = args[3].i;
    b[0] = args[2].i;
    g[0] = args[1].i;
    r[0] = args[0].i;
    Global_SetRadarFriendCol(*(int*)r, *(int*)g, *(int*)b, *(float*)a);
    return 0;
}

