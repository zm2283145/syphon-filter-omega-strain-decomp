#include "types.h"
#pragma opt_propagation off
typedef union ScriptArg { int i; float f; void* p; } ScriptArg;
extern void* GObj_IdentityB(void*);
extern void func_0021A200(void* obj, int kind, float x, float y, float z, int a, int b, int c, int d);
/* Script native: creates a blast of kind args[1] at (args[2], args[3], args[4]) on object args[0]; returns 0. */
int Script_CreateBlast(ScriptArg* args)
{
    int z[1];
    int y[1];
    int x[1];
    volatile int kind;
    float fx, fy, fz;
    z[0] = args[4].i;
    fz = *(float*)z;
    y[0] = args[3].i;
    fy = *(float*)y;
    x[0] = args[2].i;
    fx = *(float*)x;
    kind = args[1].i;
    func_0021A200(GObj_IdentityB(args[0].p), kind, fx, fy, fz, 1, 0, 0, 0);
    return 0;
}
#pragma opt_propagation reset
