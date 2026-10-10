#include "types.h"
#pragma cplusplus on
#pragma bool off
struct B5kRef { char pad[0x10]; float end; };
class B5kObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual float GetRate();
    int a;
    int b8;
    int bc;
    float b10;
    int b14;
    int b18;
    char pad[0x20 - 0x1C];
    float out0;
    float out1;
    float scale;
    char pad2[0x30 - 0x2C];
    B5kRef* ref;
    float cur;
};
extern "C" void func_0017CA90(void* p, int n);
extern "C" void* func_00139BC0(int kind, void* p);
extern "C" void func_0017CA00(void* p, float s, void* a, void* b, void* c, float* r);
static inline int B5kIsZero(float f) { return 0.0f == f; }
extern "C" void func_00364920(B5kObj* o) {
    unsigned char flag = 0;
    if (o->cur == o->ref->end && !(o->scale <= 0.0f)) {
        flag = 1;
    }
    if (flag) {
        float r = o->GetRate();
        void* p;
        func_0017CA90(&o->b18, -1);
        p = func_00139BC0(0x18, &o->b18);
        if (p) {
            func_0017CA00(p, o->scale, &o->b8, &o->bc, &o->b10, &r);
        }
    } else if ((B5kIsZero(o->cur) ^ 1)) {
        float r = o->GetRate();
        float s = o->scale;
        o->out0 = o->b10;
        o->out1 = r * s;
    }
}