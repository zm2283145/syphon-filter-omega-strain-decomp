#include "types.h"
typedef struct { int v[6]; } S3A8120;
typedef struct { int a; S3A8120 s; } P3A8120;
extern int snd_SendIOPCommandNoWait(int cmd, int size, void* data, int x, int y);
int func_003A8120(int a, S3A8120* s)
{
    P3A8120 p;
    S3A8120* d = &p.s;
    p.a = a;
    if (s) { d->v[0] = s->v[0]; d->v[1] = s->v[1]; d->v[2] = s->v[2]; d->v[3] = s->v[3]; d->v[4] = s->v[4]; d->v[5] = s->v[5]; } else d->v[0] = -1;
    return snd_SendIOPCommandNoWait(0x60, 0x1C, &p, 0, 0);
}
