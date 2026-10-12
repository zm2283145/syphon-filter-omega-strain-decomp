#pragma cplusplus on
#include "types.h"
typedef struct { char pad[0x10]; float f10; } Tgt;
typedef struct {
    char pad0[8];
    float f8;
    float fC;
    float f10;
    char pad14[4];
    char a18[8];
    float f20;
    float f24;
    float f28;
    char pad2C[4];
    Tgt* p30;
    float f34;
} AC;
extern "C" {
extern float D_0048A1B0;
extern char D_0048A1A8;
extern void func_0017CA90(void*, int);
extern void* func_00139BC0(int, void*);
extern void func_0017CA00(void*, float*, float*, float*, void*, float);
}
static inline bool Gt(float a, float b) { return a > b; }
static inline bool Eq(float a, float b) { return a == b; }
static inline void Set2(float* q, float a, float b) { q[0] = a; q[1] = b; }
static inline float WrapPi(float a)
{
    for (;;) {
        if (Gt(a, 3.1415927f)) { a += -6.2831855f; continue; }
        if (a < -3.1415927f) { a += 6.2831855f; continue; }
        break;
    }
    return a;
}

extern "C" void AngleCurve_PreUpdate(AC* c)
{
    bool go = 0;
    if (c->f34 == c->p30->f10 && c->f28 > 0.0f) go = 1;
    if (go) {
        void* v;
        c->f10 = c->f8 + WrapPi(c->f10 - c->f8);
        func_0017CA90(c->a18, -1);
        v = func_00139BC0(0x18, c->a18);
        if (v) func_0017CA00(v, &c->f8, &c->fC, &c->f10, &D_0048A1A8, c->f28);
    } else {
        bool ne = !Eq(0.0f, c->f34);
        if (ne) {
            float* q = &c->f20;
            float base = c->f20;
            float d = WrapPi(c->f10 - base);
            c->f10 = base + d;
            Set2(q, c->f10, D_0048A1B0 * c->f28);
        }
    }
}








