#include "types.h"
#pragma cplusplus on
#pragma bool off
struct Seg364D20 { char pad[0x10]; float end; };
struct Pair364D20 { float a; float b; };
class Ch364D20 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetRate();
    int a;
    float b8;
    float bc;
    float b10;
    int b14;
    int b18;
    int b1C;
    Pair364D20 out;
    float scale;
    char pad2[0x30 - 0x2C];
    Seg364D20* ref;
    float cur;
    unsigned char wrap;
};
extern "C" float Math_FMod(float, float);
extern "C" int AnimChannel_IsFreshSegment(Ch364D20*);
extern "C" int Curve_HasRemaining(Ch364D20*);
extern "C" void AnimChannel_RebuildSegment(void*, float*, float*, float*, float*);
extern "C" void AnimChannel_UpdateEndpoint(void*, int, float*, float*);
extern "C" void func_0017CA90(void* p, float d, int n);
extern "C" void* func_00139BC0(int kind, void* p);
extern "C" void func_0017CA00(void* p, float s, void* a, void* b, void* c, float* r);
extern float D_00492ED0;
extern float D_00492ED8;
static inline int IsZero_364D20(float f) { return 0.0f == f; }
static inline float Wrap_364D20(Ch364D20* p, float d)
{
    float r;
    if (!p->wrap) {
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
static inline void Set_364D20(Pair364D20* q, float a, float b) { q->a = a; q->b = b; }
extern "C" void func_00364D20(Ch364D20* o)
{
    if (!o->wrap) {
        if (AnimChannel_IsFreshSegment(o)) {
            float r = o->GetRate();
            AnimChannel_RebuildSegment(&o->b18, &o->b8, &o->bc, &o->b10, &r);
        } else if (Curve_HasRemaining(o)) {
            float r = o->GetRate();
            AnimChannel_UpdateEndpoint(&o->b18, 1, &o->b10, &r);
        }
    } else {
        unsigned char flag = 0;
        if (o->cur == o->ref->end && !(o->scale <= 0.0f)) {
            flag = 1;
        }
        if (flag) {
            void* p;
            float d = Wrap_364D20(o, o->b10 - o->b8);
            o->b10 = o->b8 + d;
            func_0017CA90(&o->b18, d, -1);
            p = func_00139BC0(0x18, &o->b18);
            if (p) {
                func_0017CA00(p, o->scale, &o->b8, &o->bc, &o->b10, &D_00492ED0);
            }
        } else if ((IsZero_364D20(o->cur) ^ 1)) {
            Pair364D20* q = &o->out;
            float base = q->a;
            float d = Wrap_364D20(o, o->b10 - base);
            o->b10 = base + d;
            Set_364D20(q, o->b10, D_00492ED8 * o->scale);
        }
    }
}
