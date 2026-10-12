#include "types.h"
#pragma cplusplus on
typedef struct { char pad[0x10]; float f10; } DSeg;
class DCurve {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(float, float);
    float f4; float f8; float fC; float f10; float f14;
    float f18; float f1C; float f20; float f24; float f28; float f2C;
    DSeg* f30; float f34; float f38; float f3C;
};
static const float dat_0048A168[2] = { 0.0f, 0.0f };
extern "C" int Curve_CountDown(void*, float);
extern "C" int Curve_HasRemaining(void*);
extern "C" float Curve_Hermite(void*);
extern "C" void func_0017DEA0(DCurve* p, float dt, float b) {
    if (!(p->f38 <= 0.0f)) {
        p->f38 -= dt;
        if (p->f38 <= 0.0f) {
            float t;
            p->f38 = 0.0f;
            p->f10 = (*(float*)dat_0048A168);
            t = p->f3C;
            if (!(t < 0.0f)) {
                float r = t * p->f2C;
                p->f1C *= r;
                p->f24 *= r;
                p->f28 = t;
                {
                    p->f2C = (0.0f != t) ? 1.0f / t : 0.0f;
                }
                p->f34 = p->f30->f10;
            }
        }
    }
    p->f4 = p->f8;
    p->v4();
    Curve_CountDown(&p->f30, dt);
    if (Curve_HasRemaining(p)) {
        p->f8 = Curve_Hermite(&p->f30);
        p->v5();
    } else {
        p->f8 = p->f10;
    }
    p->v6(dt, b);
}


