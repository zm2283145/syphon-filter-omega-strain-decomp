#include "types.h"
#pragma cplusplus on
#include "vslot_pad.h"
class T36F110 {
public:
    VPAD16(a) VPAD1(b)
    virtual void f4C(int);
    char pad[0x9C]; int aA0;
};
class A36F110 {
public:
    VPAD8(a) VPAD4(b) VPAD2(c) VPAD1(d)
    virtual T36F110* f44();
};
extern "C" void func_0036F110(int key, A36F110* a, int arg);
void func_0036F110(int key, A36F110* a, int arg)
{
    T36F110* t = a ? a->f44() : 0;
    if (t && t->aA0 == key) t->f4C(arg);
}