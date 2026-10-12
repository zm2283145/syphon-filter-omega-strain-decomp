#include "types.h"
#pragma push
#pragma opt_propagation off
typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern void* GObj_IdentityB(void*);
extern void Blast_Prepare(void* obj, int kind, float x, float y, float z, int flag, int a, int b, int c);
/* Script native: creates a blast of kind args[1] at (args[2], args[3], args[4]) on object args[0], flag args[5]; returns 0. */
    int Script_CreateBlast_2(ScriptArg* args)
{
    int flag;
    volatile int kind;
    float fz, fy, fx;
    int x[1];
    int y[1];
    int z[1];
    flag = args[5].i != 0;
    z[0] = args[4].i;
    fz = *(float*)z;
    y[0] = args[3].i;
    fy = *(float*)y;
    x[0] = args[2].i;
    fx = *(float*)x;
    kind = args[1].i;
    Blast_Prepare(GObj_IdentityB(args[0].p), kind, fx, fy, fz, flag, 0, 0, 0);
    return 0;
}
#pragma pop
