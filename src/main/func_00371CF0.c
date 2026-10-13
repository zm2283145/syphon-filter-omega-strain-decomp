#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { const V* s = &o; void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(s), "r"(this) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct M { float m[4][4]; } __attribute__((aligned(16)));
extern "C" {
M* Mtx_Copy(M* d, const M* s);
M* Mtx_InvertRigid(M* m);
}
static inline V MulV(const M& m, V v) {
    const M* pm = &m; V* pv = &v;
    __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(pv), "r"(pm) : "memory");
    return *pv;
}
static inline void Inverse(M* out, const M* m) { M a; Mtx_Copy(out, Mtx_InvertRigid(Mtx_Copy(&a, m))); }
struct Src {
    int f0;
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual float Radius();
    char pad8[8];
    float f10;
    char pad14[0xC];
    float f20, f24, f28;
    char pad2C[4];
    V v30;
};
struct Ent { V pos; float sx, sy, sz, r; };
struct Sys {
    char pad[0x2130];
    int count;
    Src* src[7];
    Ent ents[6];
    int f2210;
};
static inline void Inverse2(M* out, const M* m) { Inverse(out, m); }
static inline V XP2(const M* m, const V& p) { M inv; Inverse2(&inv, m); return MulV(inv, p); }
static inline void CopyTo(const V* s, V* d) { void* xx = d; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); }
extern "C" void func_00371CF0(Sys* s, const M* m)
{
    int i;
    for (i = 0; i < s->count; i++) {
        Src* o = s->src[i];
        s->ents[i].sx = 128.0f * o->f20;
        s->ents[i].sy = 128.0f * o->f24;
        s->ents[i].sz = 128.0f * o->f28;
        s->ents[i].r = o->f10;
        s->ents[i].pos = o->v30;
        if (m) {
            { V r = XP2(m, s->ents[i].pos); CopyTo(&r, &s->ents[i].pos); }
        }
        s->ents[i].pos.w = o->Radius();
    }
    s->f2210 = s->count;
}
