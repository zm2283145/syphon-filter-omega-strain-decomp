#include "types.h"
#include "v4_asm_copy.h"
#include "vc_copy.h"
typedef struct { float x, y, z; } V3_2C5D90;
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4_2C5D90;
typedef struct {
    V3_2C5D90 a; char pC[4];
    V4_2C5D90 q;
    signed char c20; char p21[3];
    float f24, f28, f2C, f30, f34;
    unsigned char b38, b39, b3A, b3B, b3C;
} S2C5D90;
/* Member-wise copy (assignment operator). */
S2C5D90* func_002C5D90(S2C5D90* d, S2C5D90* s)
{
    { float x = s->a.x; float y = s->a.y; d->a.x = x; d->a.y = y; d->a.z = s->a.z; }
    VCopyF(&d->q, &s->q);
    d->c20 = s->c20;
    d->f24 = s->f24; d->f28 = s->f28; d->f2C = s->f2C; d->f30 = s->f30; d->f34 = s->f34;
    d->b38 = s->b38; d->b39 = s->b39; d->b3A = s->b3A; d->b3B = s->b3B; d->b3C = s->b3C;
    return d;
}
