#include "types.h"
typedef struct { char p[0x20]; int f20; } H272200;
typedef struct { char p[0x19]; unsigned char b19; char p1A[0x5A]; H272200* h; } O272200;
typedef struct { char p[0x280]; int f280; } G272200;
extern O272200* func_00260D50(int a, int b);
extern void func_003E7EC0(O272200* o, void* x);
extern void func_003D0810(H272200* h, void* c);
extern G272200* func_001698C0(void);
extern char D_004A8DA0[];
O272200* func_00272200(int a, int b, void* x)
{
    O272200* o = func_00260D50(a, b);
    if (o && x && o->h) {
        func_003E7EC0(o, x);
        o->b19 = 0;
        func_003D0810(o->h, D_004A8DA0);
        o->h->f20 = func_001698C0()->f280;
    }
    return o;
}
