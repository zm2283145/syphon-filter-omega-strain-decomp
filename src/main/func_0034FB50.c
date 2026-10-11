#include "types.h"
typedef struct { char pad[0x6C]; void* a6C; char pad70[0x10]; int a80; } S34FB50;
extern void func_0034F3B0(S34FB50* o);
extern void func_00356C70(S34FB50* o);
extern void func_00424430(void* p, int a, int b);
void func_0034FB50(S34FB50* o)
{
    func_0034F3B0(o);
    func_00356C70(o);
    if (o->a6C) func_00424430(o->a6C, 0, o->a80);
}