/*
 * Libs/SFOLib/Source/collision: 4 files, 003BF460-003BF750
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003BF460 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern int cCollisionProbe_SphereSweptRay_DetectForCollision_uchar_uchar(int);

int ColQuery_ExecuteThunk(int a0) {
    return cCollisionProbe_SphereSweptRay_DetectForCollision_uchar_uchar(a0);
}
static inline void merge_flush_func_003BF460(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BF460 */

/* merge_units: begin func_003BF470 */
#pragma push /* merge_units */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
static inline void QF470(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
typedef struct { signed char hit; char pad[0xF]; V4 a; V4 b; V4 c; V4 d; V4 e; V4 f; } LosResult;
typedef struct { signed char hit; char pad[0xF]; V4 p; V4 n; V4 t; V4 r; V4 q; } LosHit;
extern void cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc(LosResult* r, void* x, V4* a, V4* b, int k, float f0, float f1, float f2, float f3, float f4);
void Los_CombineResult(LosResult* r, LosHit* h, void* x)
{
    cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc(r, x, &h->q, &h->r, 0, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    r->hit = h->hit;
    QF470(&r->a, &h->p);
    { void* xx = &r->b; }
    QF470(&r->b, &h->p);
    { void* xx = &r->c; }
    QF470(&r->c, &h->p);
    { void* xx = &r->d; }
    QF470(&r->d, &h->n);
    { void* xx = &r->e; }
    QF470(&r->e, &h->n);
    QF470(&r->f, &h->t);
}
static inline void merge_flush_func_003BF470(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BF470 */

/* merge_units: begin func_003BF540 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq quad copies as GCC-style volatile asm; the unused xx keeps retail's dead addiu; local decl order picks the copy registers */
struct V {
    float x, y, z, w;
    V() {}
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct CQ {
    signed char b0; char pad1[0xF];
    V v10; char pad20[0x20];
    V v40; char pad50[0x20];
    V v70; char pad80[0x10];
    V v90;
    float fA0; char padA4[0xC];
    char boxB0[0x20];
    int xD0; float fD4; float fD8; char padDC[4];
    V vE0; char padF0[0x10];
    float f100, f104, f108, f10C;
    unsigned char b110; char pad111[3]; float f114; unsigned char b118; unsigned char b119;
};
extern "C" {
extern signed char D_004E1D88;
extern V D_004E1D90;
extern void* D_00542D00;
void cVector_opAssign(V* d, const V* s);
int cVector_IsZero(V* v);
void cVector_GetNormalized_void(V* out, V* v);
V* cVector_GetZero(void);
V* cVector_ctor_cVectorR(V* d, V* s);
float cVector_Dot(V* a, V* b);
void cBox_Empty(void* b);
void cBox_Include(void* b, V* v);
void cVector_opAdd(V* out, V* a, V* b);
void cBox_Grow(void* b, float r);
void std_vector_deleter_cVector_clear(void* l);
}
static inline const V& Zero()
{
    if (!D_004E1D88) {
        D_004E1D88 = 1;
        D_004E1D90.x = 0.0f;
        D_004E1D90.y = 0.0f;
        D_004E1D90.z = 0.0f;
        D_004E1D90.w = 0.0f;
    }
    return D_004E1D90;
}
extern "C" void cCollisionProbe_SphereSweptRay_Reset_CommonCode(CQ* q, int a1, V* org, V* dir, unsigned char k, float r, float f0, float f1, float f2, float f3)
{
    q->xD0 = a1;
    q->fD4 = r;
    q->fD8 = r * r;
    { void* d = &q->vE0; __int128 t; const void* s = org; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    cVector_opAssign(&q->v70, dir);
    {
        V a, b;
        cVector_opAssign(&q->v90, !(cVector_IsZero(&q->v70) != 0) ? (cVector_GetNormalized_void(&a, dir), &a) : cVector_ctor_cVectorR(&b, cVector_GetZero()));
    }
    q->fA0 = cVector_Dot(dir, dir);
    q->f100 = f0;
    q->f104 = f1;
    q->f108 = f2;
    q->f10C = f3;
    q->b0 = 0;
    q->v10 = Zero();
    q->v40 = Zero();
    q->b110 = 0;
    q->f114 = 1.0f;
    q->b118 = 1;
    q->b119 = k;
    cBox_Empty(q->boxB0);
    cBox_Include(q->boxB0, &q->vE0);
    {
        V t;
        cVector_opAdd(&t, &q->vE0, &q->v70);
        cBox_Include(q->boxB0, &t);
    }
    cBox_Grow(q->boxB0, q->fD4);
    std_vector_deleter_cVector_clear(D_00542D00);
}
static inline void merge_flush_func_003BF540(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BF540 */

/* merge_units: begin func_003BF750 */
#pragma push /* merge_units */
extern void cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc_2(void* q, float a, float b, float c, float d, float e, float f, float g);
/* Calls cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc_2 with the last two parameters zeroed. */
void ColQuery_InitTransformedThunk(void* q, float a, float b, float c, float d, float e)
{
    cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc_2(q, a, b, c, d, e, 0.0f, 0.0f);
}
static inline void merge_flush_func_003BF750(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_003BF750 */
