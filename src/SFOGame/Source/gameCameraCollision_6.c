/*
 * SFOGame/Source/gameCameraCollision: 2 files, 0020DEE0-0020DF80
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_0020DEE0 */
#pragma push /* merge_units */
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
static inline void merge_flush_func_0020DEE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020DEE0 */

/* merge_units: begin func_0020DF80 */
#pragma push /* merge_units */
#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
struct V;
static inline V Sum(const V& a, const V& b);
struct V {
    float x, y, z, w;
    V() {}
    V(const float& r, float m) { float mm = m; x = r + mm; y = r + mm; z = r + mm; w = 0.0f; }
    V(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }

    V(const V& a, float s) { __int128 t = 0; V* q = this; const V* v = &a;
        __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "+r"(t) : "r"(q), "r"(v), "f"(s) : "memory"); }
    V operator*(float s) const { return V(*this, s); }
    V operator+(const V& b) const { return Sum(*this, b); }
    V operator-() const { V t; __asm__ volatile("lqc2 $vf1, 0x0(%1); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%0)" : : "r"(&t), "r"(this) : "memory"); return t; }
    void operator+=(const V& b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%0); vadd.xyz $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%1)" : : "r"(&b), "r"(this) : "memory"); }
} __attribute__((aligned(16)));
static inline V Sum(const V& a, const V& b) { V c; __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(&c), "r"(&a), "r"(&b) : "memory"); return c; }
struct Box { V lo, hi;
    void Extend(const V& p) { V* l = &lo; V* h = &hi; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); lqc2 $vf3, 0x0(%2); vmini.xyz $vf1, $vf1, $vf3; vmax.xyz $vf2, $vf2, $vf3; sqc2 $vf1, 0x0(%0); sqc2 $vf2, 0x0(%1)" : : "r"(l), "r"(h), "r"(&p) : "memory"); }
};
extern "C" void* std_vector_deleter_cVector_data(void* self);
struct It { V* p; It() {} It(const It& o) { p = o.p; } };
static inline bool operator==(const It& a, const It& b) { V* y = b.p; V* x = a.p; return x == y; }
static inline bool operator!=(const It& a, const It& b) { return !(a == b); }
struct VecList {
    int f0; int n; V* data;
    It begin() { It t; t.p = *(V**)std_vector_deleter_cVector_data(this); return t; }
    It end() { It t; t.p = *(V**)std_vector_deleter_cVector_data(this) + n; return t; }
};
struct CameraCol_0020DF80 {
    char pad0[0x10];
    V ext;
    char pad20[0x10];
    VecList pts;
    char pad3C[4];
    V a;
    V b;
};
static inline void Grow(Box* out, const V& pad) { out->lo += -pad; out->hi += pad; }
extern "C" {
extern float D_004A3F60;
void cGameCameraCollisionRoutine_ConstructTestObjectForFirstPassCull(CameraCol_0020DF80* c, Box* out);
}
void cGameCameraCollisionRoutine_ConstructTestObjectForFirstPassCull(CameraCol_0020DF80* c, Box* out)
{
    V off; off = V(c->ext, D_004A3F60);
    out->lo = V(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f);
    out->hi = V(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f);
    for (It it = c->pts.begin(), e = c->pts.end(); it != e; it.p++) {
        V p = *it.p + off;
        out->Extend(p);
    }
    out->Extend(c->a);
    out->Extend(c->b);
    Grow(out, V(D_004A3F60, 0.25f));
}
static inline void merge_flush_func_0020DF80(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_0020DF80 */
