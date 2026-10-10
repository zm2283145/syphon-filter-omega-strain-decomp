#include "types.h"

typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern void Global_SetInterfaceTextColor(int item, int r, int g, float alpha);

/* Script native: sets interface text color (item, r, g, alpha); returns 0. */
int Script_SetInterfaceTextColor(ScriptArg* args)
{
    int a3[1];
    int a2[1];
    int a1[1];
    int a0[1];
    a3[0] = args[3].i;
    a2[0] = args[2].i;
    a1[0] = args[1].i;
    a0[0] = args[0].i;
    Global_SetInterfaceTextColor(*(int*)a0, *(int*)a1, *(int*)a2, *(float*)a3);
    return 0;
}
