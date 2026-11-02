#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* 0020D680 CameraCol_Sweep (gameCameraCollision.cc): sweeps each collision sphere of the camera
   (a 1-entry fixed list) first along the collision routine's base path, then towards the requested
   position, and returns the furthest collision-free position. */
struct V;
static inline void CopyA(V* d, const V* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); }
static inline void CopyB(V* d, const V* s) { __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(t) : "r"(d), "r"(s) : "memory"); }
static inline V Sum(const V& a, const V& b);
static inline V Diff(const V& a, const V& b);
struct V {
    float x, y, z, w;
    V() {}
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
    V(const V& a, float s) { __int128 t = 0; V* q = this; const V* v = &a;
        __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory"); }
    V operator*(float s) const { V r(*this, s); return r; }
    V operator-() const;
} __attribute__((aligned(16)));
static inline void SumA(V* c, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(c), "r"(a), "r"(b) : "memory"); }
static inline V Sum(const V& a, const V& b) { V c; SumA(&c, &a, &b); return c; }
static inline V SumP(const V& a, const V& b) { const V* pa = &a; V c; SumA(&c, pa, &b); return c; }
static inline void DiffA(V* c, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(c), "r"(a), "r"(b) : "memory"); }
static inline V Diff(const V& a, const V& b) { V c; DiffA(&c, &a, &b); return c; }
static inline V DiffP(const V& a, const V& b) { const V* pa = &a; V c; DiffA(&c, pa, &b); return c; }
static inline V operator+(const V& a, const V& b) { return Sum(a, b); }
static inline V operator-(const V& a, const V& b) { return Diff(a, b); }
static inline V AddP(const V& a, const V& b) { return SumP(a, b); }
static inline V SubP(const V& a, const V& b) { return DiffP(a, b); }
static inline void NegA(V* t, const V* v) { __asm__ volatile("lqc2 $vf1, 0x0(%1); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%0)" : : "r"(t), "r"(v) : "memory"); }
static inline V Neg(const V& v) { V t; NegA(&t, &v); return t; }
inline V V::operator-() const { return Neg(*this); }
static inline V AddW(const V& x, const V& y) { return x + y; }
extern "C" signed char D_004E1D88;
static inline V Scale(const V& v, float s) { return v * s; } /* guard of cVector::Zero()'s static */
extern "C" V D_004E1D90;
static inline const V& ZeroR()
{
    if (!D_004E1D88) {
        ((int*)&D_004E1D90)[0] = 0;
        ((int*)&D_004E1D90)[1] = 0;
        ((int*)&D_004E1D90)[2] = 0;
        ((int*)&D_004E1D90)[3] = 0;
        D_004E1D88 = 1;
    }
    return D_004E1D90;
}
static inline V Zero() { return ZeroR(); }
static inline V ZeroW() { return Zero(); }
struct M {
    float m[4][4];
    M(const V& q) {
        M* mm = this; const V* qp = &q;
        __asm__ volatile(
            "lqc2 $vf1, 0x0(%1); vadd.xyzw $vf2, $vf1, $vf1; vaddw.xyz $vf3, $vf0, $vf0w; vmulx.w $vf8, $vf0, $vf0x; vmulx.w $vf9, $vf0, $vf0x;"
            "vmuly.xyzw $vf5, $vf1, $vf2y; vmulz.xyzw $vf6, $vf1, $vf2z; vmulx.xyzw $vf4, $vf1, $vf2x; vmulx.w $vf10, $vf0, $vf0x;"
            "vsubay.x $ACC, $vf3, $vf5y; vmsubz.x $vf8, $vf3, $vf6z; vsubw.x $vf9, $vf5, $vf6w; vaddw.x $vf10, $vf6, $vf5w;"
            "vaddw.y $vf8, $vf4, $vf6w; vsubax.y $ACC, $vf3, $vf4x; vmsubz.y $vf9, $vf3, $vf6z; vsubw.y $vf10, $vf6, $vf4w;"
            "vsubw.z $vf8, $vf4, $vf5w; vaddw.z $vf9, $vf5, $vf4w; vsubax.z $ACC, $vf3, $vf4x; vmsuby.z $vf10, $vf3, $vf5y;"
            "sqc2 $vf0, 0x30(%0); sqc2 $vf8, 0x0(%0); sqc2 $vf9, 0x10(%0); sqc2 $vf10, 0x20(%0)"
            : : "r"(mm), "r"(qp) : "memory");
    }
} __attribute__((aligned(16)));
struct Arr;
struct Probe {                      /* cCollisionProbe_SphereSweptRay, 0x1E0 */
    unsigned char hit;
    char pad1[0x7F];
    V spherePath;                   /* 0x80 */
    char pad90[0x60];
    V sphereStartPos;               /* 0xF0 */
    char pad100[0x10];
    unsigned char b110; char pad111[7];
    unsigned char b118; char pad119[0xC7];
};
struct Sphere {                     /* one swept sphere, 0x40 */
    float radius;
    V offset;
    bool useOffset;
    bool useTransform;
    V scale;
    Sphere(float r = 0.0f, V o = ZeroR()) : radius(r), offset(o), useOffset(false), useTransform(false), scale(1.0f, 1.0f, 1.0f, 0.0f) {}
    Sphere(float r, V o, bool uo, bool ut, V s) : radius(r), offset(o), useOffset(uo), useTransform(ut), scale(s) {}
};
struct SphereList {
    unsigned int count;
    Sphere items[1];
    SphereList() : count(0) {}
    void Add(Sphere s) { if (count < 1) { items[count] = s; count++; } }
};
struct CameraCol {
    char pad0[4];
    Arr* collection;    /* 0x04 */
    char pad8[8];
    V ext;              /* 0x10 */
    V rot;              /* 0x20 */
    char pad30[0x10];
    V v40;              /* 0x40 */
    V v50;              /* 0x50 */
    unsigned char hit;  /* 0x60 */
    char pad61[0xF];
    V result;           /* 0x70 */
    char pad80[0x30];
    V vB0;              /* 0xB0 */
};
extern "C" {
extern float D_004A3F60;
extern V D_004A3F70;
extern float D_004A3F88;
void cCollisionProbe_SphereSweptRay_ctor(Probe* p);
void ColQuery_InitTransformedThunk(Probe* self, Arr* faceList, const V& start, const V& path, unsigned char acc, float r, float c1, float c2, float d1, float d2, const M& rotation, const V& scale);
void cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc(Probe* self, Arr* faceList, float r, float c1, float c2,
    float d1, float d2, const V& start, const V& path, unsigned char acc);
int ColQuery_ExecuteThunk(Probe* p, int a, int b);
const V& CameraCol_Sweep(CameraCol* self, const V& target);
}
const V& CameraCol_Sweep(CameraCol* self, const V& target)
{
    self->hit = 0;
    self->result = target;
    SphereList list;
    list.Add(Sphere(D_004A3F60, Scale(self->ext, D_004A3F88), false, true, D_004A3F70));
    V a = self->ext * D_004A3F60;
    V b = self->vB0 * D_004A3F60;
    V c = self->v50 + b;
    Probe probe;
    cCollisionProbe_SphereSweptRay_ctor(&probe);
    for (unsigned int i = 0; i < list.count; i++) {
        Sphere& e = list.items[i];
        V off = e.useOffset ? AddP(-a, e.offset) : ZeroW();
        V start = AddP(-a, e.offset);
        V from = AddP(self->v40 + off, b);
        V to = c + start;
        V dir = to - from;
        if (e.useTransform)
            ColQuery_InitTransformedThunk(&probe, self->collection, from, dir, 0, e.radius, 0.05f, 0.05f, 0.0f, e.radius, M(self->rot), e.scale);
        else
            cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc(&probe, self->collection, e.radius, 0.05f, 0.05f, 0.0f, e.radius, from, dir, 0);
        probe.b110 = 0;
        probe.b118 = 0;
        ColQuery_ExecuteThunk(&probe, 0, 0);
        if (probe.hit) {
            self->hit = 1;
            c = SubP(probe.sphereStartPos + probe.spherePath, start);
        }
    }
    Probe probe2;
    cCollisionProbe_SphereSweptRay_ctor(&probe2);
    for (unsigned int j = 0; j < list.count; j++) {
        Sphere& e = list.items[j];
        V p = AddP(-a, e.offset);
        V from = c + p;
        V to = self->result + e.offset;
        V dir = to - from;
        if (e.useTransform)
            ColQuery_InitTransformedThunk(&probe2, self->collection, from, dir, 0, e.radius, 0.05f, 0.05f, 0.0f, e.radius, M(self->rot), e.scale);
        else
            cCollisionProbe_SphereSweptRay_Reset_cArrayR_float_float_float_etc(&probe2, self->collection, e.radius, 0.05f, 0.05f, 0.0f, e.radius, from, dir, 0);
        probe2.b110 = 0;
        probe2.b118 = 0;
        ColQuery_ExecuteThunk(&probe2, 0, 0);
        if (probe2.hit) {
            self->hit = 1;
            self->result = SubP(probe2.sphereStartPos + probe2.spherePath, e.offset);
        }
    }
    return self->result;
}
