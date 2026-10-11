#include "types.h"
typedef struct { int pad[3]; int aC; int pad10; } E3536A0;
typedef struct { char pad[0x48]; int a48; char pad4C[0x28]; E3536A0* a74; } S3536A0;
extern int func_00421480(int list);
extern void func_00356850(S3536A0* o, int i, int v);
void func_003536A0(S3536A0* o)
{
    int i = func_00421480(o->a48);
    if (i != -1) func_00356850(o, i, ((E3536A0*)((char*)o->a74 + i * 20))->aC);
}
