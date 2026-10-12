#include "types.h"
typedef struct { int a; int c; long long b; __int128 d; int e; char pad[0xC]; } P3A8000;
extern int snd_SendIOPCommandNoWait(int cmd, int size, void* data, int x, int y);
int func_003A8000(int a, long long b, int c, __int128 d, int e, int x, int y)
{
    P3A8000 p;
    p.a = a;
    p.b = b;
    p.c = c;
    p.d = d;
    p.e = e;
    return snd_SendIOPCommandNoWait(0x56, 0x30, &p, x, y);
}
