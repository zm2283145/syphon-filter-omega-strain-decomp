#include "types.h"
#pragma cplusplus on
typedef struct { char pad[0x10]; float f10; } B4CurveTgt;
class B4Curve {
public:
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual float GetSpeed();
    float f4; float f8; float fC; float f10; float f14;
    char f18[8];
    float f20; float f24; float f28; float f2C;
    B4CurveTgt* tgt;
    float f34;
};
extern "C" void func_0017CA90(void*, int);
extern "C" void* func_00139BC0(int, void*);
extern "C" void func_0017CA00(float, void*, float*, float*, float*, float*);
static inline bool b4NonZero(float x) { return !(0.0f == x); }
extern "C" void Curve_Retarget(B4Curve* p) {
    unsigned char go = 0;
    if (p->f34 == p->tgt->f10 && !(p->f28 <= 0.0f)) go = 1;
    if (go) {
        float s[1];
        void* n;
        s[0] = p->GetSpeed();
        func_0017CA90(p->f18, -1);
        n = func_00139BC0(0x18, p->f18);
        if (n) func_0017CA00(p->f28, n, &p->f8, &p->fC, &p->f10, s);
    } else if (b4NonZero(p->f34)) {
        float s = p->GetSpeed();
        float v = s * p->f28;
        p->f20 = p->f10;
        p->f24 = v;
    }
}