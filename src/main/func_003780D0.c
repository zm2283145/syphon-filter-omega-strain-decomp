#include "types.h"

typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern void* D_0053924C;
extern void Global_SetTexture(void* manager, int object, int texture);

/* Script native: sets texture args[1] on object args[0]; returns 0. */
int Script_SetTexture(ScriptArg* args)
{
    int object[1];
    int texture[1];
    texture[0] = args[1].i;
    object[0] = args[0].i;
    Global_SetTexture(D_0053924C, *(int*)object, *(int*)texture);
    return 0;
}
