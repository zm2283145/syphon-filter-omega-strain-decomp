#include "types.h"
#pragma opt_common_subs off
#pragma opt_propagation off
extern float Math_FMod(float, float);
static inline float clamp_(float a, float lo, float hi) { asm { max.s lo, a, lo
 min.s lo, lo, hi } return lo; }
typedef struct {
    char pad0[4];
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    float f18;
    float f1C;
    float f20;
    char pad24[4];
    float f28;
    char pad2C[0x38 - 0x2C];
    unsigned char b38;
} Ch;
extern char D_0048A190;
extern void func_0017CA90(void*, int);
extern void* func_00139BC0(int, void*);
extern void func_0017CA00(void*, float*, float*, float*, void*, float);

static inline float Clamp(Ch* c, float x)
{
    float v;
    if (!c->b38) {
        v = clamp_(x, 0.0f, 1.0f);
    } else {
        v = Math_FMod(x, 1.0f);
        if (v < 0.0f) v += 1.0f;
    }
    return v;
}
static inline float Wrap(Ch* p, float d)
{
    float r;
    float h;
    if (!p->b38) {
        return d;
    }
    r = Math_FMod(d, 1.0f);
    h = 0.5f;
    if (r < h) {
        r += 1.0f;
    } else if (r > h) {
        r -= 1.0f;
    }
    return r;
}

void func_001B8E40(Ch* c, float* dt)
{
    void* v;
    c->f4 += *dt;
    c->f8 += *dt;
    c->f10 += *dt;
    c->f18 += *dt;
    c->f20 += *dt;
    c->f4 = Clamp(c, c->f4);
    c->f8 = Clamp(c, c->f8);
    c->f10 = c->f8 + Wrap(c, c->f10 - c->f8);
    func_0017CA90(&c->f18, -1);
    v = func_00139BC0(0x18, &c->f18);
    if (v) func_0017CA00(v, &c->f8, &c->fC, &c->f10, &D_0048A190, c->f28);
}





