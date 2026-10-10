#include "types.h"

typedef union ScriptArg {
    int i;
    float f;
    void* p;
    signed char c;
} ScriptArg;

extern void func_00232BF0(signed char, int, float, float, float, float);

/* Script: AtmosphericEffect(type, a, b, c, d, e); arguments are staged through the stack. */
int Script_AtmosphericEffect_2(ScriptArg* args) {
    int e[1];
    int d[1];
    int c[1];
    int b[1];
    int a[1];
    e[0] = args[5].i;
    d[0] = args[4].i;
    c[0] = args[3].i;
    b[0] = args[2].i;
    a[0] = args[1].i;
    func_00232BF0(args[0].c, *(int*)e, *(float*)a, *(float*)b, *(float*)c, *(float*)d);
    return 0;
}
