#include "types.h"
typedef struct { int a; int b; int c; int d; int e; int f; int g; int h; } P3A7190;
extern int snd_SendIOPCommandNoWait(int cmd, int size, void* data, int x, long long y);
int func_003A7190(int a, int b, unsigned short c, unsigned short d, int ch, int dh, int e, int f, int g, int h, int x, long long y)
{
    P3A7190 p;
    p.a = a;
    p.b = b;
    p.c = (ch << 16) | c;
    p.d = (dh << 16) | d;
    p.e = e;
    p.f = f;
    p.g = g;
    p.h = h;
    return snd_SendIOPCommandNoWait(0x2C, 0x20, &p, x, y);
}
