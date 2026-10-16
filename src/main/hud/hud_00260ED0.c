#include "types.h"
#pragma global_optimizer off
typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
typedef struct { float v; float pad[3]; } E_0ED0;
extern E_0ED0 D_004F8190[], D_004F8194[], D_004F8198[], D_004F819C[];
extern unsigned char D_004F8230;
static inline void SetNVLockColor_0ED0(int idx, float f, int b, int g, int r)
{
    D_004F8230 = 1;
    if (idx < 10) {
        if (f > 0.0f) D_004F8190[idx].v = f;
        D_004F8194[idx].v = r;
        D_004F8198[idx].v = g;
        D_004F819C[idx].v = b;
    }
}
int Script_SetNVLockColor(ScriptArg* args)
{
    int b[1];
    int g[1];
    int r[1];
    int f[1];
    int i[1];
    b[0] = args[4].i;
    g[0] = args[3].i;
    r[0] = args[2].i;
    f[0] = args[1].i;
    i[0] = args[0].i;
    SetNVLockColor_0ED0(*(int*)i, *(float*)f, *(int*)b, *(int*)g, *(int*)r);
    return 0;
}