/*
 * SFOGame/Source/gameCameraCollision: 5 files, 0020CC50-0020D3E0
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

/* merge_units: begin func_0020D130 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V_0020D130;
static inline V_0020D130 Sum(const V_0020D130& a, const V_0020D130& b);
struct V_0020D130 {
    float x, y, z, w;
    V_0020D130() {}
    V_0020D130(float r) { float rr = r; x = rr; y = rr; z = rr; w = 0.0f; }
    V_0020D130(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V_0020D130(const V_0020D130& o) { V_0020D130* d = this; const V_0020D130* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); }
    V_0020D130& operator=(const V_0020D130& o) { V_0020D130* d = this; const V_0020D130* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }

    V_0020D130(const V_0020D130& a, float s) { __int128 t = 0; V_0020D130* q = this; const V_0020D130* v = &a;
        __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory"); }
    V_0020D130 operator*(float s) const { return V_0020D130(*this, s); }
    V_0020D130 operator+(const V_0020D130& b) const { return Sum(*this, b); }
    V_0020D130 operator-() const { V_0020D130 t; __asm__ volatile("lqc2 $vf1, 0x0(%1); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%0)" : : "r"(&t), "r"(this) : "memory"); return t; }
    void Add(const V_0020D130& b) { V_0020D130* d = this; const V_0020D130* s = &b; asm volatile {
 lqc2 vf1, 0x0(d)
 lqc2 vf2, 0x0(s)
 vadd.xyz vf1, vf1, vf2
 sqc2 vf1, 0x0(d)
 } }
    void operator+=(const V_0020D130& b) { const V_0020D130* s = &b; V_0020D130* d = this; asm volatile {
 lqc2 vf1, 0x0(d)
 lqc2 vf2, 0x0(s)
 vadd.xyz vf1, vf1, vf2
 sqc2 vf1, 0x0(d)
 } }
} __attribute__((aligned(16)));
static inline V_0020D130 Sum(const V_0020D130& a, const V_0020D130& b) { V_0020D130 c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(&a), "r"(&b) : "memory"); return c; }
struct Box { V_0020D130 lo, hi;
    Box() {}
    void Reset() { lo = V_0020D130(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f); hi = V_0020D130(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f); }
    Box(int) { lo.x = 3.4028235e38f; lo.y = 3.4028235e38f; lo.z = 3.4028235e38f; lo.w = 1.0f; hi.x = -3.4028235e38f; hi.y = -3.4028235e38f; hi.z = -3.4028235e38f; hi.w = 1.0f; }
    void Grow(float r) { V_0020D130 pad(r); lo += -pad; hi += pad; }
    void GrowB(float r) { V_0020D130 pad(r); lo.Add(-pad); hi += pad; }
    void Merge(const Box& b) { if (b.lo.x <= b.hi.x) { Extend(b.lo); Extend(b.hi); } }
    void Extend(const V_0020D130& p) { V_0020D130* l = &lo; V_0020D130* h = &hi; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); lqc2 $vf3, 0x0(%2); vmini.xyz $vf1, $vf1, $vf3; vmax.xyz $vf2, $vf2, $vf3; sqc2 $vf1, 0x0(%0); sqc2 $vf2, 0x0(%1)" : : "r"(l), "r"(h), "r"(&p) : "memory"); }
};

struct Sph {
    char pad0[0x20];
    float r;
    char pad24[0xC];
    V_0020D130 c;
    V_0020D130 off;
};
extern "C" {
void Camera_ZoomBounds(Sph* s, Box* out);
}
void Camera_ZoomBounds(Sph* s, Box* out)
{
    out->Reset();
    out->Extend(s->c);
    Box b(0);
    V_0020D130 p = s->c + s->off;
    b.Extend(p);
    b.GrowB(s->r);
    out->Merge(b);
    out->Grow(0.25f);
}
static inline void merge_flush_func_0020D130(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020D130 */

/* merge_units: begin func_0020D3E0 */
#pragma push /* merge_units */
/* 0020D3E0 Camera_UpdateZoom (lane r01, from c195nm's draft). The FPU register coloring was fixed by reading D_004A3FB4 through an inline getter. */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V_0020D3E0;
struct Mtx_0020D3E0;
struct V_0020D3E0 {
    float x, y, z, w;
    V_0020D3E0() {}
    V_0020D3E0(const V_0020D3E0& o) { V_0020D3E0* d = this; const V_0020D3E0* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); }
    V_0020D3E0& operator=(const V_0020D3E0& o) { V_0020D3E0* d = this; const V_0020D3E0* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    V_0020D3E0(const V_0020D3E0& a, float s) { __int128 t = 0; V_0020D3E0* q = this; const V_0020D3E0* v = &a;
        __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory"); }
    V_0020D3E0 operator*(float s) const { V_0020D3E0 r(*this, s); return r; }
    V_0020D3E0(const Mtx_0020D3E0* m);
} __attribute__((aligned(16)));
struct Mtx_0020D3E0 { V_0020D3E0 r0, r1, r2, r3; };
inline V_0020D3E0::V_0020D3E0(const Mtx_0020D3E0* m) {
    V_0020D3E0* o = this; const Mtx_0020D3E0* mm = m;
    int f;
    int t;
    asm {
        .set noreorder
        lqc2 vf1, 0x0(mm)
        lqc2 vf2, 0x10(mm)
        lqc2 vf3, 0x20(mm)
        vmulax.w ACC, vf0, vf1x
        vmadday.w ACC, vf0, vf2y
        vmaddz.w vf4, vf0, vf3z
        lui f, 0x3F00
        qmtc2.ni f, vf5
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi f, f, 0x11
        bnel f, zero, L1
        nop
        vaddw.w vf4, vf4, vf0w
        vsuby.z vf6, vf2, vf3y
        vsubz.x vf7, vf3, vf1z
        vsubx.y vf8, vf1, vf2x
        vsqrt Q, vf4w
        vaddz.x vf9, vf0, vf6z
        vaddx.y vf9, vf0, vf7x
        vaddy.z vf9, vf0, vf8y
        vwaitq
        vmulq.w vf9, vf0, Q
        vdiv Q, vf0w, vf9w
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyz vf9, vf9, Q
        j done
        nop
    L1:
        vsubay.x ACC, vf1, vf2y
        vsubaz.y ACC, vf2, vf3z
        vsubax.z ACC, vf3, vf1x
        vmadd.xyz vf10, vf0, vf0
        vnop
        vnop
        vnop
        vnop
        vnop
        cfc2.ni f, vi17
        andi t, f, 0x80
        bnel t, zero, L3
        nop
        andi t, f, 0x20
        bnel t, zero, L4
        nop
    L2:
        vmulaz.w ACC, vf0, vf10z
        vmsubay.w ACC, vf0, vf2y
        vmaddw.w vf4, vf0, vf0w
        vsubx.y vf6, vf1, vf2x
        vaddx.z vf7, vf1, vf3x
        vaddz.y vf8, vf3, vf2z
        vsqrt Q, vf4w
        vmuly.w vf9, vf0, vf6y
        vaddz.x vf9, vf0, vf7z
        vaddy.y vf9, vf0, vf8y
        vwaitq
        vaddq.z vf9, vf0, Q
        vdiv Q, vf0w, vf9z
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xyw vf9, vf9, Q
        j done
        nop
    L3:
        andi t, f, 0x40
        bnel t, zero, L2
        nop
        vmulay.w ACC, vf0, vf10y
        vmsubax.w ACC, vf0, vf1x
        vmaddw.w vf4, vf0, vf0w
        vaddz.y vf6, vf3, vf2z
        vsubz.x vf7, vf3, vf1z
        vaddy.x vf8, vf2, vf1y
        vsqrt Q, vf4w
        vaddy.z vf9, vf0, vf6y
        vmulx.w vf9, vf0, vf7x
        vaddx.x vf9, vf0, vf8x
        vwaitq
        vaddq.y vf9, vf0, Q
        vdiv Q, vf0w, vf9y
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.xzw vf9, vf9, Q
        j done
        nop
        nop
    L4:
        vmulax.w ACC, vf0, vf10x
        vmsubaz.w ACC, vf0, vf3z
        vmaddw.w vf4, vf0, vf0w
        vaddy.x vf6, vf2, vf1y
        vaddx.z vf7, vf1, vf3x
        vsuby.z vf8, vf2, vf3y
        vsqrt Q, vf4w
        vaddx.y vf9, vf0, vf6x
        vaddz.z vf9, vf0, vf7z
        vmulz.w vf9, vf0, vf8z
        vwaitq
        vaddq.x vf9, vf0, Q
        vdiv Q, vf0w, vf9x
        vmulx.xyzw vf9, vf9, vf5x
        vwaitq
        vmulq.yzw vf9, vf9, Q
    done:
        sqc2 vf9, 0x0(o)
        .set reorder
    }
}
struct Cam_0020D3E0 {
    int f0;
    unsigned char b4; char p5[3];
    float fov;
    char pC[4];
    V_0020D3E0 rot;
    float a, b;
    char p28[8];
    V_0020D3E0 pos;
    V_0020D3E0 up;
};
extern "C" {
float Libc_Tanf(float);
extern float D_004A3FD0;
extern float D_004A3FB4;
inline float GetFB4() { return D_004A3FB4; }

void Camera_UpdateZoom(Cam_0020D3E0* c, Mtx_0020D3E0* m, float fov);
}
void Camera_UpdateZoom(Cam_0020D3E0* c, Mtx_0020D3E0* m, float fov)
{
    c->b4 = 0;
    c->fov = fov;
    c->rot = V_0020D3E0(m);
    float inv = 1.0f / Libc_Tanf(0.5f * fov);
    float k = inv * D_004A3FD0;
    float a = k / (inv + GetFB4());
    float b = a * GetFB4();
    c->a = a;
    c->b = b;
    float s = k - b;
    V_0020D3E0 up = m->r1;
    c->pos = m->r3;
    c->up = up * s;

}
static inline void merge_flush_func_0020D3E0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020D3E0 */
