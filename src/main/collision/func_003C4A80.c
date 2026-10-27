#pragma cplusplus on
#pragma always_inline on
#pragma inline_depth(8)
#include "types.h"
/* cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_4: intersects the trace segment (origin q->org, direction q->dir) with
 * water candidate triangle c: back faces are flipped (in place for double-sided candidates),
 * the plane hit point must lie inside the segment, and the barycentric test is done in the
 * plane of the two smallest normal components; hits are reported to q->sink. */
/* VU0 vector helpers: the lq/sq copies and VU0 macro ops have no C equivalent; the dead xx
 * reproduces retail's duplicated destination addiu. */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
static inline void SubV(V* r, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline void AddV(V* r, const V* a, const V* b) { __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vadd.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline void NegV(V* r, const V* a) { __asm__ volatile("lqc2 $vf1, 0x0(%0); vmulax.xyzw $ACC, $vf0, $vf0x; vmsubw.xyzw $vf1, $vf1, $vf0w; sqc2 $vf1, 0x0(%1)" : : "r"(a), "r"(r) : "memory"); }
static inline void ScaleV(V* r, const V* a, float k) { int t; __asm__ volatile(".set noreorder; lqc2 $vf1, 0x0(%2); mfc1 %0, %3; qmtc2.ni %0, $vf2; vmulx.xyzw $vf1, $vf1, $vf2x; sqc2 $vf1, 0x0(%1); .set reorder" : "=&r"(t) : "r"(r), "r"(a), "f"(k) : "memory"); }
/* the copied normal is negated through a Metrowerks asm block (retail's trailing nop) */
static inline void NegM(V* r, const V* a) { asm {
        lqc2 vf1, 0x0(a)
        vmulax.xyzw ACC, vf0, vf0x
        vmsubw.xyzw vf1, vf1, vf0w
        sqc2 vf1, 0x0(r)
    } }
static inline V operator-(const V& a, const V& b) { V r; SubV(&r, &a, &b); return r; }
static inline V operator+(const V& a, const V& b) { V r; AddV(&r, &a, &b); return r; }
static inline V operator*(const V& a, float k) { V r; ScaleV(&r, &a, k); return r; }
/* 3-component dot product through VU0 (mtsah/qfsrv lane shift) */
static inline float Dot3(const V* a, const V* b)
{
    int t;
    float r = 0.0f;
    asm {
        lqc2 vf1, 0(a)
        lqc2 vf2, 0(b)
        vmul.xyzw vf3, vf1, vf2
        mtsah zero, 6
        vmulax.w ACC, vf0, vf3x
        vmadday.w ACC, vf0, vf3y
        vmaddz.w vf4, vf0, vf3z
        qmfc2.ni t, vf4
        qfsrv t, t, t
        mtc1 t, r
    }
    return r;
}
struct Cand { V p[3]; V n; unsigned char flags; };
class Sink {
public:
    virtual void Hit(V* p, Cand* c);
};
struct LosQ { char pad0[0x40]; V dir; V org; char pad60[4]; Sink* sink; };
extern "C" {
V* cCollisionFace_UnitNormal(Cand* c);
float cVector_X_void(V* v);
float cVector_Y_void(V* v);
float cVector_Z_void(V* v);
float Math_Fabs(float f);
V* cCollisionFace_Vertex(Cand* c, int i);
V cVector_opSub(const V* a, const V* b);
int cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_4(LosQ* q, Cand* c);
}

/* the barycentric test is returned as a materialised bool */
static inline bool InTri(float u, float v) { return (u >= 0.0f && v >= 0.0f) && u + v <= 1.0f; }
static inline void Inside(LosQ* q, Cand* c, const V& hit)
{
    int axis;
    float ax = Math_Fabs(cVector_X_void(cCollisionFace_UnitNormal(c)));
    float ay = Math_Fabs(cVector_Y_void(cCollisionFace_UnitNormal(c)));
    float az = Math_Fabs(cVector_Z_void(cCollisionFace_UnitNormal(c)));
    if (ax > ay) {
        if (az > ax)
            axis = 2;
        else
            axis = 0;
    } else {
        if (ay > az)
            axis = 1;
        else
            axis = 2;
    }
    float u, v;
    V e1 = cVector_opSub(cCollisionFace_Vertex(c, 1), cCollisionFace_Vertex(c, 0));
    V e2 = cVector_opSub(cCollisionFace_Vertex(c, 2), cCollisionFace_Vertex(c, 0));
    V e3 = cVector_opSub(&hit, cCollisionFace_Vertex(c, 0));
    switch ((unsigned char)axis) {
    case 0: {
        float det = e1.y * e2.z - e1.z * e2.y;
        float inv = 1.0f / det;
        u = inv * (e2.z * e3.y - e2.y * e3.z);
        v = inv * (e3.z * e1.y - e3.y * e1.z);
        break;
    }
    case 1: {
        float det = e1.z * e2.x - e1.x * e2.z;
        float inv = 1.0f / det;
        u = inv * (e2.x * e3.z - e2.z * e3.x);
        v = inv * (e3.x * e1.z - e3.z * e1.x);
        break;
    }
    case 2: {
        float det = e1.x * e2.y - e1.y * e2.x;
        float inv = 1.0f / det;
        u = inv * (e2.y * e3.x - e2.x * e3.y);
        v = inv * (e3.y * e1.x - e3.x * e1.y);
        break;
    }
    }
    if (InTri(u, v))
        q->sink->Hit((V*)&hit, c);
}

extern "C" int cCollisionProbe_Ray_DetectForCollision_cCollisionFaceR_4(LosQ* q, Cand* c)
{
    V t;
    const V* n = &c->n;
    float d = Dot3(&q->dir, n);
    bool ok = d < 0.0f;
    bool two = (c->flags & 2) != 0;
    if (!ok) {
        if (two) {
            NegV(&c->n, &c->n);
        } else {
            t = c->n;
            NegM(&t, &t);
            n = &t;
        }
        ok = true;
        d = -d;
    }
    if (ok) {
        V r = c->p[0] - q->org;
        float e = Dot3(&r, n);
        if (e < 0.0f && !(e <= d)) {
            float k = e / d;
            V s = q->dir * k;
            V hit = q->org + s; /* named s/hit give retail's slot order */
            Inside(q, c, hit);
        }
    }
    return 0;
}
