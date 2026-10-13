#pragma cplusplus on
#include "types.h"
struct V {
    float x, y, z, w;
    V() {}
    V(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); }
    V& operator=(const V& o) { void* xx = this; /* dead on purpose: retail keeps this addiu */ __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
struct W {
    float x, y, z, w;
    W() {}
    W& operator=(const W& o) { __int128 q; __asm__ volatile("lq %0, 0x0(%2); sq %0, 0x0(%1)" : "=r"(q) : "r"(this), "r"(&o) : "memory"); return *this; }
} __attribute__((aligned(16)));
extern "C" float func_0017DC50(void* c);
extern "C" void Curve_Sample(V* out, void* c, float t);
static inline float CR_Max(float a, float b) { float r; asm { max.s r, a, b } return r; }
static inline bool Pos(float f) { return f > 0.0f; }
struct VC {
    /* vptr at 0; slots 0x18/0x1C/0x20 */
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void Begin();
    virtual void Changed();
    virtual void Update(float dt, float x);
    char pad4[0xC];
    W v10;
    W v20;
    char pad30[0x10];
    W v40;
    char pad50[0x60];
    void* curve;
    float t;
    bool Zero() const { return t == 0.0f; }
    bool NotZero() const { return !Zero(); }
};
extern "C" bool VectorCurve_Advance(VC* self, float dt, float x)
{
    bool done;
    self->v10 = self->v20;
    self->Begin();
    float z = 0.0f; /* dead on purpose: retail keeps this mtc1 */
    float old = self->t;
    self->t -= dt;
    self->t = CR_Max(0.0f, self->t);
    {
        bool r = Pos(old);
        if (r) r = self->Zero();
        done = r;
    }
    if (self->NotZero()) {
        V tmp;
        Curve_Sample(&tmp, self->curve, func_0017DC50(self->curve) - self->t);
        { void* xx = &tmp; /* dead on purpose: retail keeps this addiu */ }
        self->v20 = (W&)tmp;
        self->Changed();
    } else {
        self->v20 = self->v40;
    }
    self->Update(dt, x);
    return done;
}
