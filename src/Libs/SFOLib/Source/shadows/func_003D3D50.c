#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* cShadowMan_AssignShadow: adds projector idx to every receiver whose model takes this projector type,
 * lies within the shadow range of c and whose (world) bounds intersect the projector frustum.
 * VU0 math and quad copies are inline asm (as in cShadowMan_AddReceiver / cShadowMan_ProcessCaster). */
struct V {
    float x, y, z, w;
    V() {}
    /* quad copy as lq/sq (C struct copies go through FPRs); the unused xx keeps retail's dead address set-up */
    V(const V& o) { __int128 q; V* d = this; void* xx = this; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(&o), "r"(d) : "memory"); }
    V& operator=(const V& o) { void* xx = this; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
    float Length() const {
        int t; float r = 0.0f;
        __asm__ volatile("lqc2 $vf1, 0x0(%2); vmul.xyz $vf2, $vf1, $vf1; vmulax.w $ACC, $vf0, $vf2x; vmadday.w $ACC, $vf0, $vf2y; vmaddz.w $vf3, $vf0, $vf2z; vsqrt $Q, $vf3w; vwaitq; vaddq.x $vf4, $vf0, $Q; qmfc2.ni %1, $vf4; mtc1 %1, %0" : "+f"(r), "=&r"(t) : "r"(this) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct M { V r[4]; };
struct Box { V mn; V mx; };
struct Mdl { int x0; char* x4; char pad8[0x1C]; unsigned int flags; };
class XV {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void Refresh();
};
struct Xf { void* vt; char pad4[0xC]; M world; unsigned char dirty; };
struct Obj { char pad0[0x50]; Xf* x50; char pad54[0x14]; Mdl* x68; };
struct Recv { Obj* obj; int proj[24]; int nProj; char pad68[8]; V c; };
struct Proj { Obj* actor; float x4; float fov; short x0C; unsigned char type; char padF; M view; M x50; char pad90[0x20]; V dir; };
struct Shadow {
    char pad0[0xC];
    int range;              /* 0xC */
    char pad10[0x4D0 - 0x10];
    Recv recv[0x200];       /* 0x4D0 */
    char pad104D0[8];
    int count;              /* 0x104D8 */
    char pad104DC[0x10540 - 0x104DC];
    Proj proj[24];          /* 0x10540 */
};
extern "C" {
extern char g_Video[];
int XLib_TestBBox_cMatrixR_cVectorR_cVectorR(Obj* o, M* m, const V* mn, const V* mx);
void cShadowMan_AssignShadow(Shadow* sh, int idx, V* c);
}
static inline void Sub(V* r, const V* a, const V* b) { __asm__ volatile("lqc2 vf1, 0x0(%1); lqc2 vf2, 0x0(%2); vsub.xyzw vf1, vf1, vf2; sqc2 vf1, 0x0(%0)" : : "r"(r), "r"(a), "r"(b) : "memory"); }
static inline V operator-(const V& a, const V& b) { V r; Sub(&r, &a, &b); return r; }
static inline void MulM(V* v, M* m) { __asm__ volatile("lqc2 vf8, 0x0(%0); lqc2 vf4, 0x0(%1); lqc2 vf5, 0x10(%1); lqc2 vf6, 0x20(%1); lqc2 vf7, 0x30(%1); vmulax.xyzw ACC, vf4, vf8x; vmadday.xyzw ACC, vf5, vf8y; vmaddaz.xyzw ACC, vf6, vf8z; vmaddw.xyzw vf12, vf7, vf8w; sqc2 vf12, 0x0(%0)" : : "r"(v), "r"(m) : "memory"); }
struct V2 : V { V2(const V& o) { void* xx = this; V* d = this; const V* s = &o; __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(d), "r"(s) : "memory"); } } __attribute__((aligned(16)));
static inline V XformPt2(const V& v, M* mm) { const V* sv = &v; V2 p(*sv); V* pp = &p; MulM(pp, mm); return *pp; }
static inline V XformPt(const V& v, M* m) { M* mm = m; return XformPt2(v, mm); }
static inline int HasModel(Obj* o) { return o->x68->x0 ? 1 : 0; }
static inline Box* BoxOf(Obj* o) { return (Box*)(o->x68->x4 + 0x30); }

static inline bool HasFlag(Obj* o, unsigned int m) { return (o->x68->flags & m) != 0; }
static inline int TakesA(Proj* p, Recv* rc) { unsigned char r = 0; int one = 1; if (p->type == one) { bool f = HasFlag(rc->obj, 0x20); if (f) r = one; } return r; }
static inline bool TakesB(Proj* p, Recv* rc) { bool r = false; if (p->type == 2) { bool f = HasFlag(rc->obj, 0x40); if (f) r = true; } return r; }
/* World matrix of a transform, refreshed first when dirty (virtual slot 22). */
static inline M* WorldX(Xf* x) { if (x->dirty) ((XV*)x)->Refresh(); return &x->world; }
static inline M* World(Obj* o) { Xf* x = o->x50; if (x->dirty) ((XV*)x)->Refresh(); return &x->world; }
static inline float LenR(const V& v) { return v.Length(); }
#pragma opt_common_subs off
extern "C" void cShadowMan_AssignShadow(Shadow* sh, int idx, V* c)
{
    V mn; Proj* p; int i; V mx; Recv* rc;
    p = &sh->proj[idx];
    for (i = 0; i < sh->count; i++) {
        rc = &sh->recv[i];
        if (HasModel(rc->obj)) {
            unsigned char a = TakesA(p, rc);
            unsigned char b = TakesB(p, rc);
            if (a || b) {
                V d = *c - rc->c;
                if (LenR(d) < (float)sh->range) {
                    mn = BoxOf(rc->obj)->mn;
                    mx = BoxOf(rc->obj)->mx;
                    /* bring the model-space bounds into world space; the second matrix fetch re-reads the transform */
                    Xf* x = rc->obj->x50;
                    if (x) {
                        mn = XformPt(mn, WorldX(x));
                        mx = XformPt(mx, World(rc->obj));
                    }
                    bool hit = XLib_TestBBox_cMatrixR_cVectorR_cVectorR((Obj*)g_Video, &p->x50, &mn, &mx) != 0x80;
                    if (hit) {
                        int n = rc->nProj;
                        if (n < 24) {
                            rc->proj[n] = idx;
                            rc->nProj++;
                        }
                    }
                }
            }
        }
    }
}
