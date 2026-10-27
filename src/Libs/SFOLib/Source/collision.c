/*
 * Libs/SFOLib/Source/collision: 4 files, 003BCDD0-003BCF20
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BCDD0 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char pad[0x62]; unsigned char useLos; } Col_3BCDD0;
extern int cCollisionProbe_Ray_DetectForCollision_cArrayR_4(Col_3BCDD0* c, void* ray, int mode, void* out);
extern int cCollisionProbe_Ray_DetectForCollision_cArrayR_3(Col_3BCDD0* c, void* ray, int mode, void* out);
extern int cCollisionProbe_Ray_DetectForCollision_cArrayR_2(Col_3BCDD0* c, void* ray, int mode, void* out);
extern int cCollisionProbe_Ray_DetectForCollision_cArrayR(Col_3BCDD0* c, void* ray, int mode, void* out);
unsigned char cCollisionProbe_Ray_DetectForCollision_cArrayR_bool(Col_3BCDD0* c, void* ray, int mode, void* out) {
    unsigned char r;
    if (c->useLos) {
        if (mode) r = cCollisionProbe_Ray_DetectForCollision_cArrayR_4(c, ray, mode, out);
        else r = cCollisionProbe_Ray_DetectForCollision_cArrayR_3(c, ray, mode, out);
    } else if (mode) r = cCollisionProbe_Ray_DetectForCollision_cArrayR_2(c, ray, mode, out);
    else r = cCollisionProbe_Ray_DetectForCollision_cArrayR(c, ray, mode, out);
    return r;
}
static inline void merge_flush_func_003BCDD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BCDD0 */

/* merge_units: begin func_003BCE50 */
#pragma push /* merge_units */
typedef struct { char p00[0x62]; unsigned char mask; } ColA_3BCE50;
typedef struct { char p00[0x40]; unsigned char mask; } ColB_3BCE50;
extern int cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_4(ColA_3BCE50* a, ColB_3BCE50* b, int mode, void* d);
extern int cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_3(ColA_3BCE50* a, ColB_3BCE50* b, int mode, void* d);
extern int cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_2(ColA_3BCE50* a, ColB_3BCE50* b, int mode, void* d);
extern int cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR(ColA_3BCE50* a, ColB_3BCE50* b, int mode, void* d);
unsigned char cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_bool(ColA_3BCE50* a, ColB_3BCE50* b, int mode, void* d) {
    unsigned char r;
    int hit = (unsigned char)(b->mask & a->mask) != 0;
    if (mode) {
        if (hit)
            r = cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_4(a, b, mode, d);
        else
            r = cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_3(a, b, mode, d);
    } else {
        if (hit)
            r = cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_2(a, b, mode, d);
        else
            r = cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR(a, b, mode, d);
    }
    return r;
}
static inline void merge_flush_func_003BCE50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BCE50 */

/* merge_units: begin func_003BCED0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */


extern int ColQuery_ExecuteSweep(int);
extern int ColQuery_InitSweep(int, int, int, int, int, int, int, float, float, float, float, float, float, float);

int ColQuery_ExecuteSweepThunk(int a0) {
    return ColQuery_ExecuteSweep(a0);
}

int ColQuery_RequestSweep(int a0, int a1, int a2, int a3, int t0, int t1, int t2, float f12, float f13, float f14, float f15, float f16, float f17) {
    return ColQuery_InitSweep(a0, a1, a2, a3, t0, t1, t2, 1.0f, f12, f13, f14, f15, f16, f17);
}
static inline void merge_flush_func_003BCED0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BCED0 */

/* merge_units: begin func_003BCF20 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 a; V4 b; } Seg;
typedef struct { char pad[0x70]; V4 v70; char pad2[0x20]; float fA0; } CQ;
extern void* cVector_ctor_void(void* p);
extern V4* cCollisionFace_Vertex(V4* base, int i);
extern V4* cVector_opAssign(V4* d, V4* s);
extern int cCollisionProbe_SphereSweptRay_TestLineSegment_IgnoringEndPoints(CQ* q, Seg* s, void* r);
extern int cCollisionProbe_SphereSweptRay_TestPoint(CQ* q, V4* v, void* r);
int cCollisionProbe_SphereSweptRay_TestFaceEdgesAndVertices(CQ* q, V4* tri, void* r) {
    unsigned char hit;
    unsigned char hitv;
    unsigned int i;
    V4* p = &q->v70;
    int t;
    asm {
        lqc2 vf1, 0x0(p)
        lqc2 vf2, 0x0(p)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni t, vf4
        qfsrv t, t, t
    }
    *(int*)&q->fA0 = t;
    hit = 0;
    for (i = 0; i < 3; i++) {
        Seg s;
        cVector_ctor_void(&s.a);
        cVector_ctor_void(&s.b);
        cVector_opAssign(&s.a, cCollisionFace_Vertex(tri, i));
        cVector_opAssign(&s.b, cCollisionFace_Vertex(tri, i == 2 ? 0 : i + 1));
        hit = cCollisionProbe_SphereSweptRay_TestLineSegment_IgnoringEndPoints(q, &s, r) || hit;
    }
    if (hit) goto yes;
    hitv = 0;
    for (i = 0; i < 3; i++) {
        hitv = cCollisionProbe_SphereSweptRay_TestPoint(q, cCollisionFace_Vertex(tri, i), r) || hitv;
    }
    if (hitv) {
    yes:
        return 1;
    }
    return 0;
}
static inline void merge_flush_func_003BCF20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BCF20 */
