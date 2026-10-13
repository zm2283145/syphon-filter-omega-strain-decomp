#include "types.h"
#include "vc_copy.h"
#pragma opt_propagation off
#pragma opt_common_subs off
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct CameraCol {
    char pad00[0x4];
    int collection;          /* +0x04 */
    char pad08[0x88];
    unsigned char flag90;    /* +0x90 */
    char pad91[0xF];
    V4 targetA0;             /* +0xA0 */
    V4 curB0;                /* +0xB0 */
} CameraCol;

static inline V4 CameraCol_Lerp(V4* b, V4* c, float s)
{
    V4 l0;
    V4* q1 = &l0; V4* bb = b; V4* cc = c;
    int rv1;
    asm {
        lqc2 vf1, 0x0(bb)
        lqc2 vf2, 0x0(cc)
        mfc1 rv1, s
        qmtc2.ni rv1, vf3
        vaddax.xyzw ACC, vf1, vf0x
        vmaddax.xyzw ACC, vf2, vf3x
        vmsubx.xyzw vf4, vf1, vf3x
        sqc2 vf4, 0x0(q1)
    }
    return l0;
}

void CameraCol_SetCollection(CameraCol* c, int unused, int collection, float t)
{
    float a = 1.5001501f;
    float b = 0.30003002f;
    float k;
    V4 tmp;
    c->collection = collection;
    if (c->flag90)
        k = a;
    else
    {
        k = b;
        asm { .set reorder } /* empty scheduling barrier: keeps retail's unfilled branch nops */
    }
    tmp = CameraCol_Lerp(&c->curB0, &c->targetA0, t * k);
    VCopyFF(&c->curB0, &tmp);
}



