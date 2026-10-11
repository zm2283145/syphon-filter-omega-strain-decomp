#include "types.h"
typedef struct { int a; int b; int c; signed char d; } Desc_2107F0;
extern int func_002E9B60(void);
extern int func_002E9BE8(void* out, int a, int b, int c, int d, Desc_2107F0* desc);
extern int func_002E9CD0(int* h, void* name, int n);
extern void func_002E9D88(int h, void* a, void* b, void* c);
extern int D_0048AAE8;
extern char D_004A44D0[];
extern void func_002106F0();
extern void func_00210620();
extern void func_00210780();
void func_002107F0(void)
{
    int out[1];
    Desc_2107F0 desc;
    desc.a = 1000;
    desc.b = 1;
    desc.d = 0x40;
    desc.c = 0;
    if (func_002E9B60() == 0 && func_002E9BE8(out, 0, 4, 5, 1, &desc) == 0 &&
        func_002E9CD0(&D_0048AAE8, D_004A44D0, 8) == 0)
        func_002E9D88(D_0048AAE8, func_002106F0, func_00210620, func_00210780);
}