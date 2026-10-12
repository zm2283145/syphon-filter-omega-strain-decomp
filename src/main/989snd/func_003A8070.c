#include "types.h"
typedef struct { union { int i; long long l; } u; int d; int e; __int128 c; short f1; short f2; char p24[4]; int flags; char p2C[4]; } P3A8070;
extern int snd_SendIOPCommandNoWait(int cmd, int size, void* data, int x, long long y);
int func_003A8070(int a, long long b, __int128 c, int d, int e, short f1, short f2, int x, long long y)
{
    P3A8070 p;
    int* fl = &p.flags;
    *fl = 0;
    if (!a) p.u.l = b; else { p.u.i = a; *fl |= 1; }
    p.c = c;
p.d = d;
p.f1 = f1;
p.f2 = f2;
p.e = e;
    *fl |= 0x3C;
    return snd_SendIOPCommandNoWait(0x5C, 0x30, &p, x, y);
}
