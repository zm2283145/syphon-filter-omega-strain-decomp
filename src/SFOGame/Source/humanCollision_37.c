/*
 * SFOGame/Source/humanCollision: 3 files, 001EEBA0-001EECB0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001EEBA0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Original translation unit not identified yet; functions are named by address
 * until real names are known.
 */

#include "types.h"

extern char D_004F5000[];
extern void __destroy_array(int, int, int, int);
extern int cCollisionProbe_Ray_dtor(int, int);

void* std_vector_deleter_cCollisionFace_data_void(char* self) {
    return self + 8;
}

void func_001EEBB0(void) {
    __destroy_array((int)D_004F5000, (int)cCollisionProbe_Ray_dtor, 112, 7);
}
static inline void merge_flush_func_001EEBA0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EEBA0 */

/* merge_units: begin func_001EEBD0 */
#pragma push /* merge_units */
#pragma cplusplus on
struct V { float x, y, z, w; } __attribute__((aligned(16)));
typedef struct { int x, y, z, w; } __attribute__((aligned(16))) V4;
struct T {
    unsigned char b0;
    char pad1[0xF];
    V v10;
    V v20;
    V v30;
    V v40;
    V v50;
    unsigned char b60;
    unsigned char b61;
    unsigned char b62;
    char pad63;
    int i64;
};
extern "C" {
extern signed char D_004E1D88;
extern V4 D_004E1D90;
V* cVector_GetZero(void);
void cVector_ctor_cVectorR(V* d, const void* s);
void cVector_Get0001(V* v);
void cCollisionModel_FaceLocator_ctor(V* v);
T* cCollisionProbe_Ray_defctor(T* o);
}
static inline V4* Vec4_Zero(void) {
    if (!D_004E1D88) {
        D_004E1D90.x = 0;
        D_004E1D88 = 1;
        D_004E1D90.y = 0;
        D_004E1D90.z = 0;
        D_004E1D90.w = 0;
    }
    return &D_004E1D90;
}
static inline void VF0(void* d) { asm volatile { .set noreorder
 sqc2 vf0, 0x0(d)
 .set reorder } }
static inline void Cp1(void* d, const void* s) { __int128 t; __asm__ volatile("lq %0, 0(%1); sq %0, 0(%2)" : "=r"(t) : "r"(s), "r"(d) : "memory"); }
T* cCollisionProbe_Ray_defctor(T* o_)
{
    V4* z;
    T* o;
    const V* rr;
    V t;
    V a;
    V p;
    {
        void* s = &a;
        VF0(s);
        void* d = &t;
        Cp1(d, s);
    }
    rr = &t; /* dead: retail keeps this addiu (in the guard bnez delay slot) */
    z = Vec4_Zero();
    o_->b0 = 0;
    o = o_;
    cVector_ctor_cVectorR(&o->v10, cVector_GetZero());
    cVector_Get0001(&p);
    cVector_ctor_cVectorR(&o->v20, &p);
    cCollisionModel_FaceLocator_ctor(&o->v30);
    cVector_ctor_cVectorR(&o->v40, z);
    cVector_ctor_cVectorR(&o->v50, &t);
    o->b60 = 0;
    o->b61 = 0;
    o->b62 = 0;
    o->i64 = 0;
    return o;
}
static inline void merge_flush_func_001EEBD0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EEBD0 */

/* merge_units: begin func_001EECB0 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "alloc_guard.h"
typedef struct { void* vt; int f[7]; char b20; char pad21[3]; char b24; char pad25[3]; int w28; } CEv_f4;
extern "C" {
extern char D_004DFD80[];
extern char D_004DAD20[];
void* cMemMan_Allocate(int, int, char*, int);
}
static inline void* AllocL_f4(int size, char* file, int line)
{
    AllocGuard g;
    return cMemMan_Allocate(0, size, file, line);
}
extern "C" CEv_f4* cGameEventMsg_Clone(CEv_f4* src)
{
    CEv_f4* e = (CEv_f4*)AllocL_f4(sizeof(CEv_f4), "gameEventMsg.hh", 0x2C);
    if (e) {
        e->vt = D_004DFD80;
        e->f[0] = src->f[0];
        e->f[1] = src->f[1];
        e->f[2] = src->f[2];
        e->f[3] = src->f[3];
        e->f[4] = src->f[4];
        e->f[5] = src->f[5];
        e->f[6] = src->f[6];
        e->b20 = src->b20;
        e->vt = D_004DAD20;
        e->b24 = src->b24;
        e->w28 = src->w28;
    }
    return e;
}
static inline void merge_flush_func_001EECB0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_001EECB0 */
