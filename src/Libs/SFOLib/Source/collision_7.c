/*
 * Libs/SFOLib/Source/collision: 3 files, 003BF760-003BF9E0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BF760 */
#pragma push /* merge_units */
#include "types.h"
#include "vc_copy.h"
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 r[4]; } Mtx;
typedef struct { int cap; int n; } VecE;
extern void* func_003C0200(VecE* v, int index);
extern void* cVector_ctor_void(void* p);
extern V4* cCollisionFace_Vertex(void* base, int i);
extern V4* cVector_opAssign(V4* d, V4* s);
extern V4 cVector_GetTransformed(V4* vp, Mtx* m);
extern int func_003C01E0(V4* p, float x);
extern void func_003BFAB0(void* e, VecE* v, int i, float f, V4* t);
#if 0 /* merge_units */
extern void func_003BF900(void* e, V4* t);
#endif /* merge_units */
void func_003BF900(); /* merge_units */

#pragma opt_rotateloops off
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma opt_propagation off
void func_003BF760(VecE* v, Mtx* mtx, float f) {
    int i;
    for (i = v->n - 1; i >= 0; i--) {
        Mtx m;
        void* e;
        V4 t[3];
        V4 r0;
        V4 r1;
        V4 r2;
        Mtx* pm;
        Mtx* d;
        __int128 qa;
        __int128 qb;
        d = &m;
        asm { .set reorder; lq qa, 0x0(mtx); lq qb, 0x10(mtx); sq qa, 0x0(d); lq qa, 0x20(mtx); sq qb, 0x10(d); lq qb, 0x30(mtx); sq qa, 0x20(d); sq qb, 0x30(d) }
        pm = &m;
        e = func_003C0200(v, i);
        cVector_ctor_void(&t[0]);
        cVector_ctor_void(&t[1]);
        cVector_ctor_void(&t[2]);
        r0 = cVector_GetTransformed(cCollisionFace_Vertex(e, 0), pm);
        cVector_opAssign(&t[0], &r0);
        r1 = cVector_GetTransformed(cCollisionFace_Vertex(e, 1), pm);
        cVector_opAssign(&t[1], &r1);
        r2 = cVector_GetTransformed(cCollisionFace_Vertex(e, 2), pm);
        cVector_opAssign(&t[2], &r2);
        if (func_003C01E0(&t[0], f) || func_003C01E0(&t[1], f) || func_003C01E0(&t[2], f)) {
            func_003BFAB0(e, v, i, f, t);
        } else {
            func_003BF900(e, t);
        }
    }
}
static inline void merge_flush_func_003BF760(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BF760 */

/* merge_units: begin func_003BF900 */
#pragma push /* merge_units */
extern void cVector_opSub(V4* out, V4* a, V4* b);
extern void cVector_Cross(V4* out, V4* a, V4* b);
#if 0 /* merge_units */
extern float func_003BF9E0(V4* p);
#endif /* merge_units */
float func_003BF9E0(); /* merge_units */

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
static inline void merge_flush_func_003BF900(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BF900 */

/* merge_units: begin func_003BF9E0 */
#pragma push /* merge_units */
typedef struct { char pad[3]; unsigned char type; char pad2[0x14]; int f18; } B4Track;
typedef struct { int f0; B4Track** tracks; } B4Anim;
typedef struct { char pad[0x60]; int idx; B4Anim* anim; } B4Obj5;
extern char* cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(B4Track*, int*);
float func_003BF9E0(B4Obj5* p) {
    int idx = p->idx;
    B4Track* t = p->anim->tracks[0];
    float* v;
    if (t->type < 4) {
        int k[1];
        k[0] = t->f18;
        v = (float*)(cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(t, k) + idx * 64);
    } else if (t->type < 5) {
        int k[1];
        k[0] = t->f18;
        v = (float*)(cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(t, k) + idx * 32);
    } else {
        int k[1];
        k[0] = t->f18;
        v = (float*)(cCollisionModel_Data_GetAbsoluteAddress_cCollisionModelAddress_5(t, k) + idx * 16);
    }
    if (*v > 0.0f) return 1.0f;
    return -1.0f;
}
static inline void merge_flush_func_003BF9E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BF9E0 */
