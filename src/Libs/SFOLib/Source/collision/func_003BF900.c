#include "types.h"
#include "vc_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
extern void cVector_opSub(V4* out, V4* a, V4* b);
extern void cVector_Cross(V4* out, V4* a, V4* b);
extern float func_003BF9E0(V4* p);
extern void cVector_opMul(V4* out, V4* v, float s);
extern V4* cVector_Normalize_void(V4* v);
extern V4* cVector_ctor_cVectorR(V4* d, V4* s);
extern void cCollisionFace_SetUnitNormal(V4* p, V4* v);
#pragma push
#pragma opt_unroll_loops off
#pragma opt_rotateloops off
#pragma opt_strength_reduction off
void func_003BF900(V4* dst, V4* src) {
    V4 a;
    V4 b;
    V4 e;
    V4 d;
    V4 c;
    int i;
    for (i = 0; i < 3; i++) {
        float inv = 1.0f / src[i].y;
        src[i].x = src[i].x * inv;
        src[i].z = src[i].z * inv;
        /* asm quad copy: keeps the i++ scheduled between lq and sq */
        VCopyF(&dst[i], &src[i]);
    }
    cVector_opSub(&a, &dst[1], &dst[0]);
    cVector_opSub(&b, &dst[2], &dst[0]);
    cVector_Cross(&c, &a, &b);
    cVector_opMul(&d, &c, func_003BF9E0(dst));
    cVector_ctor_cVectorR(&e, cVector_Normalize_void(&d));
    cCollisionFace_SetUnitNormal(dst, &e);
}
#pragma pop
