#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Tgt { char pad[0x10]; float f10; };
class Ch {
public:
    VPAD2(a)
    virtual void v2();
    virtual float Duration();
    float f4;
    float f8;
    float fC;
    float f10;
    float f14;
    char a18[8];
    float f20;
    float f24;
    float f28;
    char pad2C[4];
    Tgt* p30;
    float f34;
    unsigned char b38;
};
extern "C" {
extern float D_0048A188;
extern char D_0048A180;
extern float Math_FMod(float, float);
extern int AnimChannel_IsFreshSegment(Ch*);
extern int Curve_HasRemaining(Ch*);
extern void AnimChannel_RebuildSegment(void*, float*, float*, float*, float*);
extern void AnimChannel_UpdateEndpoint(void*, int, float*, float*);
extern void func_0017CA90(void*, int);
extern void* func_00139BC0(int, void*);
extern void func_0017CA00(void*, float*, float*, float*, void*, float);
}
static inline bool Eq(float a, float b) { return a == b; }
static inline void Set2(float* q, float a, float b) { q[0] = a; q[1] = b; }
static inline float Wrap(Ch* p, float d)
{
    float r;
    if (!p->b38) {
        return d;
    }
    r = Math_FMod(d, 1.0f);
    if (r < 0.5f) {
        r += 1.0f;
    } else if (r > 0.5f) {
        r -= 1.0f;
    }
    return r;
}

extern "C" void AnimChannel_PreUpdate(Ch* c)
{
    if (!c->b38) {
        if (AnimChannel_IsFreshSegment(c)) {
            float t = c->Duration();
            AnimChannel_RebuildSegment(c->a18, &c->f8, &c->fC, &c->f10, &t);
        } else if (Curve_HasRemaining(c)) {
            float t = c->Duration();
            AnimChannel_UpdateEndpoint(c->a18, 1, &c->f10, &t);
        }
    } else {
        bool go = 0;
        if (c->f34 == c->p30->f10 && c->f28 > 0.0f) go = 1;
        if (go) {
            void* v;
            c->f10 = c->f8 + Wrap(c, c->f10 - c->f8);
            func_0017CA90(c->a18, -1);
            v = func_00139BC0(0x18, c->a18);
            if (v) func_0017CA00(v, &c->f8, &c->fC, &c->f10, &D_0048A180, c->f28);
        } else {
            bool ne = !Eq(0.0f, c->f34);
            if (ne) {
                float* q = &c->f20;
                float base = c->f20;
                float d = Wrap(c, c->f10 - base);
                c->f10 = base + d;
                Set2(q, c->f10, D_0048A188 * c->f28);
            }
        }
    }
}
