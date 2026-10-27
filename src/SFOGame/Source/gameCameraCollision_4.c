/*
 * SFOGame/Source/gameCameraCollision: 3 files, 0020CC50-0020CF90
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0020CC50 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { char d[36]; } E;
#pragma optimization_level 1
/* Returns the number of 36-byte elements between a and b. */
int std_distance_cSkaTransBLENDP_cSkaTransBLENDP_randomaccessiteratortag(E* a, E* b) { return b - a; }
#pragma optimization_level reset
static inline void merge_flush_func_0020CC50(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020CC50 */

/* merge_units: begin func_0020CC80 */
#pragma push /* merge_units */
typedef struct E_0020CC80 { int w[9]; } E_0020CC80;
typedef struct V { E_0020CC80* data; unsigned int count; unsigned int cap; } V;
extern char D_004A3E90[];
extern unsigned int std_distance_cSkaTransBLENDP_cSkaTransBLENDP(E_0020CC80* first, E_0020CC80* last);
extern unsigned int std_vector_imp_cSkaTransBLEND_capacity(V* v);
extern unsigned int* std_min(unsigned int* a, unsigned int* b);
extern E_0020CC80* std_vector_imp_cSkaTransBLEND_begin_void(V* v);
extern void cSkaTransBLEND_opAssign(E_0020CC80* d, E_0020CC80* s);
extern E_0020CC80* std_vector_imp_cSkaTransBLEND_end_void(V* v);
extern void* std_vector_deleter_cSkaTransBLEND_alloc_void(V* v);
extern void cAllocator_cSkaTransBLEND_destroy(void* alloc, E_0020CC80* p);
extern void cAllocator_cSkaTransBLEND_construct(void* alloc, E_0020CC80* p, E_0020CC80* s);
extern unsigned int std_vector_imp_cSkaTransBLEND_max_size(V* v);
extern void std_msl_error(const char* msg);
extern void std_vector_imp_cSkaTransBLEND_clear(V* v);
extern E_0020CC80** std_vector_deleter_cSkaTransBLEND_data_void(V* v);
extern unsigned int* std_vector_deleter_cSkaTransBLEND_cap_void(V* v);
extern void cAllocator_cSkaTransBLEND_deallocate(void* alloc, E_0020CC80* p, unsigned int n);
extern E_0020CC80* cAllocator_cSkaTransBLEND_allocate(void* alloc, unsigned int n, int hint);

#pragma push
#pragma optimization_level 1
void std_vector_imp_cSkaTransBLEND_do_assign(V* v, E_0020CC80* first, E_0020CC80* last)
{
    unsigned int n;
    E_0020CC80* p;
    E_0020CC80* end;
    n = std_distance_cSkaTransBLENDP_cSkaTransBLENDP(first, last);
    if (n <= std_vector_imp_cSkaTransBLEND_capacity(v)) {
        unsigned int k = *std_min(&n, &v->count);
        p = std_vector_imp_cSkaTransBLEND_begin_void(v);
        end = p + k;
        while (p < end) {
            cSkaTransBLEND_opAssign(p, first);
            p++;
            first++;
        }
        if (n < v->count) {
            end = std_vector_imp_cSkaTransBLEND_end_void(v);
            while (p < end) {
                cAllocator_cSkaTransBLEND_destroy(std_vector_deleter_cSkaTransBLEND_alloc_void(v), p);
                p++;
            }
            v->count = n;
        } else if (v->count < n) {
            while (first != last) {
                cAllocator_cSkaTransBLEND_construct(std_vector_deleter_cSkaTransBLEND_alloc_void(v), p, first);
                first++;
                p++;
                v->count++;
            }
        }
    } else {
        if (n > std_vector_imp_cSkaTransBLEND_max_size(v))
            std_msl_error(D_004A3E90);
        std_vector_imp_cSkaTransBLEND_clear(v);
        if (*std_vector_deleter_cSkaTransBLEND_data_void(v) != 0) {
            cAllocator_cSkaTransBLEND_deallocate(std_vector_deleter_cSkaTransBLEND_alloc_void(v), *std_vector_deleter_cSkaTransBLEND_data_void(v), *std_vector_deleter_cSkaTransBLEND_cap_void(v));
            *std_vector_deleter_cSkaTransBLEND_data_void(v) = 0;
            *std_vector_deleter_cSkaTransBLEND_cap_void(v) = 0;
        }
        *std_vector_deleter_cSkaTransBLEND_data_void(v) = cAllocator_cSkaTransBLEND_allocate(std_vector_deleter_cSkaTransBLEND_alloc_void(v), n, 0);
        *std_vector_deleter_cSkaTransBLEND_cap_void(v) = n;
        p = std_vector_imp_cSkaTransBLEND_begin_void(v);
        while (first != last) {
            cAllocator_cSkaTransBLEND_construct(std_vector_deleter_cSkaTransBLEND_alloc_void(v), p, first);
            first++;
            p++;
            v->count++;
        }
    }
}
#pragma pop
static inline void merge_flush_func_0020CC80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020CC80 */

/* merge_units: begin func_0020CF90 */
#pragma push /* merge_units */
#pragma cplusplus on
/* Camera_ZoomSweep: sweeps the camera's view volume from its position to its
 * target; on a hit narrows the zoom angle so the hit point stays in view. */
typedef struct { float x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 r[4]; } Mtx;
typedef struct { unsigned char hit; char p1[0x7F]; V4 v80; char p90[0x80]; unsigned char b110; char p111[7]; unsigned char b118; char p119[0xC7]; } Res;
typedef struct { char p0[4]; unsigned char b4; char p5[3]; float zoom; char pC[4]; V4 q; float f20; float f24; char p28[8]; V4 from; V4 to; } Cam;
extern "C" {
extern V4 D_004A3FB0;
extern float D_004A3FC0;
extern float D_004A3FD8;
void cCollisionProbe_SphereSweptRay_ctor(Res*);
int ColQuery_RequestSweep(Res* r, void* a1, V4* from, V4* to, int t0, Mtx* m, V4* ext, float f12, float f13, float f14, float f15, float f16, float f17);
int ColQuery_ExecuteSweepThunk(Res* r, int a, int b);
float Libc_Atanf(float);
void Camera_ZoomSweep(Cam* self, int unused, void* filter);
}
static inline void QToM(Mtx* m, V4* q) {
    Mtx* mm = m; V4* qp = q;
    __asm__ volatile(
        "lqc2 $vf1, 0x0(%1); vadd.xyzw $vf2, $vf1, $vf1; vaddw.xyz $vf3, $vf0, $vf0w; vmulx.w $vf8, $vf0, $vf0x; vmulx.w $vf9, $vf0, $vf0x;"
        "vmuly.xyzw $vf5, $vf1, $vf2y; vmulz.xyzw $vf6, $vf1, $vf2z; vmulx.xyzw $vf4, $vf1, $vf2x; vmulx.w $vf10, $vf0, $vf0x;"
        "vsubay.x $ACC, $vf3, $vf5y; vmsubz.x $vf8, $vf3, $vf6z; vsubw.x $vf9, $vf5, $vf6w; vaddw.x $vf10, $vf6, $vf5w;"
        "vaddw.y $vf8, $vf4, $vf6w; vsubax.y $ACC, $vf3, $vf4x; vmsubz.y $vf9, $vf3, $vf6z; vsubw.y $vf10, $vf6, $vf4w;"
        "vsubw.z $vf8, $vf4, $vf5w; vaddw.z $vf9, $vf5, $vf4w; vsubax.z $ACC, $vf3, $vf4x; vmsuby.z $vf10, $vf3, $vf5y;"
        "sqc2 $vf0, 0x30(%0); sqc2 $vf8, 0x0(%0); sqc2 $vf9, 0x10(%0); sqc2 $vf10, 0x20(%0)"
        : : "r"(mm), "r"(qp) : "memory");
}
static inline float Length(const V4& v)
{
    float r = 0.0f;
    int t;
    const V4* p = &v;
    asm {
        lqc2 vf1, 0x0(p)
        vmul.xyz vf2, vf1, vf1
        vmulax.w ACC, vf0, vf2x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf3, vf0, vf2z
        vsqrt Q, vf3w
        vwaitq
        vaddq.x vf4, vf0, Q
        qmfc2.ni t, vf4
        mtc1 t, r
    }
    return r;
}
static inline float FovFor(float x) { return 2.0f * Libc_Atanf(1.0f / (x * D_004A3FD8)); }

#pragma opt_common_subs off
void Camera_ZoomSweep(Cam* self, int unused, void* filter)
{
    Res res;
    Mtx m;
    cCollisionProbe_SphereSweptRay_ctor(&res);
    QToM(&m, &self->q);
    { Mtx* pm = &m; ColQuery_RequestSweep(&res, filter, &self->from, &self->to, 0, pm, &D_004A3FB0, 0.05f, 0.05f, 0.0f, 1.0f, self->zoom, D_004A3FC0); }
    res.b110 = 0;
    res.b118 = 0;
    ColQuery_ExecuteSweepThunk(&res, 0, 0);
    self->b4 = res.hit != 0;
    if (res.hit)
        self->zoom = FovFor(self->f24 + Length(res.v80));
}
static inline void merge_flush_func_0020CF90(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020CF90 */
