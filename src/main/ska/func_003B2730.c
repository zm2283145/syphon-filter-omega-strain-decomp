#pragma cplusplus on
#pragma inline_depth(8)
#include "types.h"
#include "alloc_guard.h"
extern "C" char D_004DFC50[];
extern void * const D_004DFC30[];
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
static inline V Unit() { V l0; __asm__ volatile("sqc2 vf0, 0x0(%0)" : : "r"(&l0) : "memory"); return l0; }
struct F2 { float a, b; F2() {} };
struct ClipBase {
    void* vt;
    signed char b4;
    V v10;
    ClipBase() {}
    ~ClipBase() { vt = D_004DFC50; }
    ClipBase& operator=(const ClipBase& o) { b4 = o.b4; v10 = o.v10; return *this; }
};
struct SkaClip : ClipBase {
    int f20;
    void* clip;
    unsigned char b28, b29;
    F2 r2c;
    float f34, f38, f3c;
    int f40;
    signed char b44;
    unsigned char b45, b46;
    SkaClip() {}
    ~SkaClip() { vt = (void*)D_004DFC30; }
};
static inline V QMulR(const V* a, const V* b) {
    V r;
    __asm__ volatile("lqc2 vf1, 0x0(%0)\nlqc2 vf2, 0x0(%1)\nvmul.xyzw vf3, vf1, vf2\nvopmula.xyz ACC, vf1, vf2\nvmaddaw.xyz ACC, vf1, vf2w\nvmaddaw.xyz ACC, vf2, vf1w\nvopmsub.xyz vf4, vf2, vf1\nvsubaz.w ACC, vf3, vf3z\nvmsubay.w ACC, vf0, vf3y\nvmsubx.w vf4, vf0, vf3x\nsqc2 vf4, 0x0(%2)" : : "r"(a), "r"(b), "r"(&r) : "memory");
    return r;
}

static inline bool IsUnit(const V& v) { return 1.0f == v.w; }
static inline bool NotUnit(const V& v) { return !IsUnit(v); }
struct AnimContribution { char pad[0x20]; };
struct Ctx { char pad[0x14]; char stack[4]; };
extern "C" float D_004BCD68;
extern "C" void AnimContribution_Init(AnimContribution* c, SkaClip* clip, const V* q, float w);
extern "C" int AnimContext_GetCount(void* s);
extern "C" void** PtrStack_Top(void* s);
extern "C" void* AnimBlend_GetGroupCollection(void* b);
extern "C" void AnimGroup_AddContribution(void* g, AnimContribution* c, int id, float w);
extern "C" void func_003B0CB0(AnimContribution* c, int f);
static inline void Submit(SkaClip* self, const V* r, Ctx* ctx, float w)
{
    int id = self->f40;
    float wt = self->f3c;
    if (AnimContext_GetCount(ctx->stack)) {
        void* blend = *PtrStack_Top(ctx->stack);
        if (blend) {
            AnimContribution c;
            AnimContribution_Init(&c, self, r, w);
            AnimGroup_AddContribution(AnimBlend_GetGroupCollection(blend), &c, id, wt);
            func_003B0CB0(&c, -1);
        }
    }
}
static inline void Submit2(SkaClip* self, const V* r, Ctx* ctx, float w) { Submit(self, r, ctx, w); }
static inline const V* In1(const V* a, const V* b) { if (NotUnit(*a)) { V x(QMulR(a, b)); V t(x); return &t; } return b; }
extern "C" void SkaClip_Submit(SkaClip* self, const V* q, Ctx* ctx, float w)
{
    if (w < D_004BCD68)
        return;
    bool b = !IsUnit(self->v10);
    q = b ? In1(q, &self->v10) : q;
    { const V* r = q; Submit2(self, r, ctx, w); }
}
