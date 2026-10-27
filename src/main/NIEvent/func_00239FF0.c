#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
#pragma inline_depth(8)

struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); }
    V& operator=(const V& o) { V* d = this; const V* s = &o; __int128 t; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(t) : "r"(d), "r"(s) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct Mtx {
    V r0, r1, r2, t;
    Mtx() {}
    Mtx(const Mtx& o) { Mtx* d = this; const Mtx* s = &o; __int128 qa, qb; __asm__ volatile("lq %0, 0x0(%3); lq %1, 0x10(%3); sq %0, 0x0(%2); lq %0, 0x20(%3); sq %1, 0x10(%2); lq %1, 0x30(%3); sq %0, 0x20(%2); sq %1, 0x30(%2)" : "=&r"(qa), "=&r"(qb) : "r"(d), "r"(s) : "memory"); }
};
struct Sub {
    VPAD1(a)
    virtual void SetMtx(Mtx* m);
    VPAD16(b) VPAD2(c)
    virtual void Sync();
    char pad4[0xC];
    Mtx m;
    unsigned char f50;
};
struct Box { V mn, mx; };
struct Obj {
    VPAD32(a)
    virtual Box* GetBox();
    char pad4[0x4C];
    Sub* sub;
};
static inline const Mtx& SubMtx(Sub* o) { if (o->f50) o->Sync(); return o->m; }
// abs.s: no C equivalent
static inline float Fabs(float x) { float r = 0.0f; asm { abs.s r, x } return r; }
static inline void MulM(V* v, Mtx* m) { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }

extern "C" int cNIEventOBJ_GetBeamExtents(Obj* o, V* mn, V* mx)
{
    V c;
    V e;
    Box* b = o->GetBox();
    if (!b) return 0;
    *mn = b->mn;
    *mx = b->mx;
    Mtx m = SubMtx(o->sub);
    float ax = Fabs(mx->x - mn->x);
    float ay = Fabs(mx->y - mn->y);
    float az = Fabs(mx->z - mn->z);
    c.w = 1.0f;
    c.x = mn->x + (mx->x - mn->x) / 2.0f;
    c.y = mn->y + (mx->y - mn->y) / 2.0f;
    c.z = mn->z + (mx->z - mn->z) / 2.0f;
    e = c;
    if (!(ax < ay) && !(ax < az)) {
        c.x = mn->x;
        e.x = mx->x;
    } else if (!(ay < ax) && !(ay < az)) {
        c.y = mn->y;
        e.y = mx->y;
    } else {
        c.z = mn->z;
        e.z = mx->z;
    }
    *mn = c;
    *mx = e;
    MulM(mn, &m);
    MulM(mx, &m);
    return 1;
}



