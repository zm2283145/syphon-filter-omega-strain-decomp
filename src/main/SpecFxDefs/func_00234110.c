#pragma cplusplus on
#pragma inline_depth(10)

#include "types.h"

struct V4 {
    float x, y, z, w;
    V4() {}
    V4(float a, float b, float c, float d) { x = a; y = b; z = c; w = d; }
    V4(const V4& o) { V4* d = this; const V4* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); }
    V4& operator=(const V4& o) { V4* d = this; const V4* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=&r"(t) : "r"(s), "r"(d) : "memory"); return *this; }
} __attribute__((aligned(16)));

static inline void OpS(V4* pr, const V4* pa, const V4* pb)
{
    __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vsub.xyzw $vf1, $vf1, $vf2; sqc2 $vf1, 0x0(%0)" : : "r"(pr), "r"(pa), "r"(pb) : "memory");
}
static inline V4 operator-(const V4& a, const V4& b) { V4 r; OpS(&r, &a, &b); return r; }
static inline float Max(float a, float b) { float r = 0.0f; asm { max.s r, a, b } return r; }
static inline float Min(float a, float b) { float r = 0.0f; asm { min.s r, a, b } return r; }

struct Box0 { V4 lo, hi; };
struct Box : Box0 {
    Box() {
        lo.x = 3.4028235e38f; lo.y = 3.4028235e38f; lo.z = 3.4028235e38f; lo.w = 1.0f;
        hi.x = -3.4028235e38f; hi.y = -3.4028235e38f; hi.z = -3.4028235e38f; hi.w = 1.0f;
    }
    void Extend(V4* p) { V4* l = &lo; V4* h = &hi; __asm__ volatile("lqc2 $vf1, 0x0(%0); lqc2 $vf2, 0x0(%1); lqc2 $vf3, 0x0(%2); vmini.xyz $vf1, $vf1, $vf3; vmax.xyz $vf2, $vf2, $vf3; sqc2 $vf1, 0x0(%0); sqc2 $vf2, 0x0(%1)" : : "r"(l), "r"(h), "r"(p) : "memory"); }
    void Reset() {
        lo = V4(3.4028235e38f, 3.4028235e38f, 3.4028235e38f, 1.0f);
        hi = V4(-3.4028235e38f, -3.4028235e38f, -3.4028235e38f, 1.0f);
    }
    unsigned char Empty() const { return lo.x > hi.x; }
    V4 Size() const { return Empty() ? V4(0.0f, 0.0f, 0.0f, 0.0f) : hi - lo; }
};

/* Intersection of two boxes in x/y (z from b), widened in x and y to at least 16 units inside b. */
extern "C" Box func_00234110(Box0* a, Box0* b)
{
    V4 p;
    Box r;
    r.Reset();
    p.x = Max(a->lo.x, b->lo.x);
    p.y = Max(a->lo.y, b->lo.y);
    p.z = b->lo.z;
    r.Extend(&p);
    p.x = Min(a->hi.x, b->hi.x);
    p.y = Min(a->hi.y, b->hi.y);
    p.z = b->hi.z;
    r.Extend(&p);
    if (r.Size().x < 16.0f) {
        float d = 16.0f - r.Size().x;
        p.x = Max(a->lo.x - d, b->lo.x);
        r.Extend(&p);
        p.x = Min(a->hi.x + d, b->hi.x);
        r.Extend(&p);
    }
    if (r.Size().y < 16.0f) {
        float d = 16.0f - r.Size().y;
        p.y = Max(a->lo.y - d, b->lo.y);
        r.Extend(&p);
        p.y = Min(a->hi.y + d, b->hi.y);
        r.Extend(&p);
    }
    return r;
}
