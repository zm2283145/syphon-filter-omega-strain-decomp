#include "types.h"
#include "v4_asm_copy.h"
typedef struct { __int128 q; } Q231F00;
typedef struct { char p[0x30]; Q231F00 pos; } O231F00;
typedef struct { float sx, sy, sz, pad; Q231F00 pos; int f20; float a; float b; int pad2; } L231F00;
extern void* func_003EBFB0(int size);
extern void func_00231F60(void* p, L231F00* l);
void func_00231F00(O231F00* o, float a, float b)
{
    L231F00 l;
    void* p;
    l.f20 = 0;
l.sx = 1.0f;
l.a = a;
l.sy = 1.0f;
l.sz = 1.0f;
{ Q231F00* s = &o->pos; Q231F00* d = &l.pos; V4Copy(d, s); }
l.b = b;
    p = func_003EBFB0(0x18);
    if (p) func_00231F60(p, &l);
}
