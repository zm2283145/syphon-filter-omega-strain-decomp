#include "types.h"

typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern void Global_SetNVInterfaceTextColor(int a, int b, int c, float d);

/* Script native: sets the night-vision interface text colour. */
int Script_SetNVInterfaceTextColor(ScriptArg* args)
{
    int a3[1];
    int a2[1];
    int a1[1];
    int a0[1];
    a3[0] = args[3].i;
    a2[0] = args[2].i;
    a1[0] = args[1].i;
    a0[0] = args[0].i;
    Global_SetNVInterfaceTextColor(*(int*)a0, *(int*)a1, *(int*)a2, *(float*)a3);
    return 0;
}
