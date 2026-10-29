#pragma cplusplus on
#include "types.h"
#pragma always_inline on
#pragma inline_depth(8)
/* lq/sq copies and VU0 ops as GCC-style volatile asm; unused xx locals reproduce retail's dead addius */
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%1); sq %0, 0x0(%2)" : "=r"(q) : "r"(&o), "r"(this) : "memory"); void* xx = this; }
    V& operator=(const V& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=&r"(q) : "r"(this), "r"(&o) : "memory"); void* xx = this; return *this; }
    static V Unit() { V r; V* d = &r; __asm__ volatile("sqc2 $vf0, 0x0(%0)" : : "r"(d) : "memory"); return r; }
    bool IsIdent() const { bool b = w == 1.0f; return b; }
    bool NotIdentR() const { return !IsIdent(); }
    bool NotIdent() const { bool b = !IsIdent(); return b; }
    V operator*(const V& b) const {
        V c; const V* r = &b; const V* l = this; V* d = &c;
        __asm__ volatile("lqc2 $vf1, 0x0(%1); lqc2 $vf2, 0x0(%2); vmul.xyzw $vf3, $vf1, $vf2; vopmula.xyz $ACC, $vf1, $vf2; vmaddaw.xyz $ACC, $vf1, $vf2w; vmaddaw.xyz $ACC, $vf2, $vf1w; vopmsub.xyz $vf4, $vf2, $vf1; vsubaz.w $ACC, $vf3, $vf3z; vmsubay.w $ACC, $vf0, $vf3y; vmsubx.w $vf4, $vf0, $vf3x; sqc2 $vf4, 0x0(%0)" : : "r"(d), "r"(l), "r"(r) : "memory");
        return c;
    }
} __attribute__((aligned(16)));

struct Ctx { char pad0[0x14]; int n; void* items[1]; };
struct EvNode {
    virtual void v0();
    virtual void Eval(float t, const V& q, Ctx* c);
    void Run(float t, const V& q, Ctx* c) { const void* xx = &q; Eval(t, q, c); }
};
static inline float MinA(float a, float b) { asm { min.s b, a, b } return b; }
static inline float MinT(const float& a, const float& b) { float r = 0.0f; __asm__ volatile("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float MinF(float a, float b) { float r = 0.0f; __asm__ volatile("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float MaxF(float a, float b) { float r = 0.0f; __asm__ volatile("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float ClampR(float x, float& lo, float hi) { __asm__ volatile("max.s %0, %1, %0; min.s %0, %0, %2" : "+f"(lo) : "f"(x), "f"(hi)); return lo; }
static inline float Clamp(float x, float lo, float hi) { __asm__ volatile("max.s %0, %1, %0; min.s %0, %0, %2" : "+f"(lo) : "f"(x), "f"(hi)); return lo; }

struct Phase {
    float dur, fade, rate, padC, cur;
    float Left() const { return MaxF(0.0f, 1.0f - cur); }
};
struct Blend { int pad0; EvNode* node; Phase ph; char pad1C[0xC4]; float limit; float time; };

extern "C" void cSkaSystem_Request_Process(Blend* self, bool* outA, float* outRem, bool* done, Ctx* ctx, bool* hold, float t, float dt);

void cSkaSystem_Request_Process(Blend* self, bool* outA, float* outRem, bool* done, Ctx* ctx, bool* hold, float t, float dt)
{
    *done = false;
    if (!*hold) {
        float one = 1.0f; float old = self->ph.cur;
        float v = MinA(one, old + dt * self->ph.rate);
        *done = old < 1.0f && v >= 1.0f;
        self->ph.cur = v;
    }
    float p = self->ph.cur;
    float z; float p2 = p * p;
    float x = 3.0f * p2 - 2.0f * (p * p2); z = 0.0f; float zc = z; float w = t * ClampR(x, z, 1.0f);
    if (zc != w) {
        if (ctx->n == 0) { ctx->items[ctx->n] = self; ctx->n++; }
        self->node->Run(w, V::Unit(), ctx);
        if (ctx->n) ctx->n--;
    }
    *outRem = MaxF(0.0f, t - w);
    *outA = false;
    if (!*hold) {
        Phase* ph = &self->ph;
        float a; float l = ph->Left(); a = l * ph->dur; if (a < 0.5f * (ph->dur - ph->fade)) *outA = true;
        ph = &self->ph;
        float b; float l2 = ph->Left(); b = l2 * ph->dur; if (!(b <= 0.5f * (ph->dur + ph->fade))) *hold = true;
    }
    self->time += dt;
    if (self->limit != -1.0f) self->time = MinT(self->limit, self->time);
}





