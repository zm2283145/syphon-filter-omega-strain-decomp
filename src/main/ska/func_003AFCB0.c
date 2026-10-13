#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq copies and VU0 ops as GCC-style volatile asm; unused xx locals reproduce retail's dead addius */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; }
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; }
    bool IsIdent() const { bool b = w == 1.0f; return b; }
    bool NotIdentR() const { return !IsIdent(); }
    bool NotIdent() const { bool b = !IsIdent(); return b; }
    V operator*(const V& b) const {
        V c; const V* r = &b; const V* l = this; V* d = &c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory");
        return c;
    }
} __attribute__((aligned(16)));

struct Ctx;
struct EvNode {
    virtual void v0();
    virtual void Eval(float t, const V* q, Ctx* c);
};
struct Child { char pad0[0x1C]; float k; EvNode* a; EvNode* b; };
struct Sel { char pad0[0x10]; V rot; int idx; char vec[4]; };

static inline float MaxF(float a, float b) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

/* Combined rotation (q * self->rot); retail keeps the product in the caller's frame after the inline returns. */
static inline const V* Pick(Sel* self, const V* q) {
    const V* r;
    if (self->rot.NotIdent()) {
        if (q->NotIdentR()) {
            V a = *q * self->rot;
            V b = a;
            r = &b;
        } else {
            r = &self->rot;
        }
        return r;
    }
    return q;
}
extern "C" {
extern float D_004BCD68;
Child* func_003B01C0(Ctx* c, Sel* s);
int func_003B01A0(Ctx* c, int i);
void* func_003B0180(void* v, int i);
EvNode* func_003B0170(void* e);
void* func_003B0150(Sel* s, Ctx* c);
int func_003B0140(void* p);
int func_003B0130(void* p);
int func_003B0050(Sel* s, Ctx* c);
void* AnimSelector_BeginTransition(Ctx* c, int a, int b, Sel* s);
void AnimSelector_Evaluate(Sel* self, float t, const V* q, Ctx* ctx);
}

void AnimSelector_Evaluate(Sel* self, float t, const V* q, Ctx* ctx)
{
    if (t < D_004BCD68) return;
    const V* r = Pick(self, q);
    Child* ch = func_003B01C0(ctx, self);
    if (ch) {
        float u = t * ch->k;
        ch->a->Eval(MaxF(0.0f, t - u), r, ctx);
        ch->b->Eval(u, r, ctx);
    } else {
        func_003B0170(func_003B0180(&self->vec, func_003B01A0(ctx, self->idx)))->Eval(t, r, ctx);
    }
    void* p = func_003B0150(self, ctx);
    int from = func_003B0140(p);
    int to = func_003B0130(p);
    if (from != to && !func_003B0050(self, ctx))
        AnimSelector_BeginTransition(ctx, from, to, self);
}

