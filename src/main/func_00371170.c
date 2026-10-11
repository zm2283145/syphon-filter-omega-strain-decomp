#include "types.h"
typedef struct { int pad[0x3F6]; int aFD8; int padFDC; int aFE0; int aFE4; char padFE8[0x10]; } E371170;
typedef struct { char pad[0x1020]; int cur; char pad1024[0xBC]; unsigned int a10E0; } S371170;
extern int func_00371110(S371170* o);
extern void func_0037C870(S371170* o, unsigned int flags);
extern void func_00370CC0(S371170* o, int a, int b, int c, int d, int e, int f, int g, int h, int i);
void func_00371170(S371170* o)
{
    if (func_00371110(o)) {
        E371170* e;
        func_0037C870(o, o->a10E0 | 0x40000);
        e = (E371170*)((char*)o + o->cur * 56);
        func_00370CC0(o, e->aFD8, e->aFE0, e->aFE4, 0, 2, 6, 0x412412, 6, 0x14);
    }
}