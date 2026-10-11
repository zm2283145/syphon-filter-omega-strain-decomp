#pragma cplusplus on
#include "vslot_pad.h"
class C3D310 {
public:
    VPAD16(p) VPAD4(q) VPAD2(r)
    virtual void Slot22();
};
extern "C" unsigned char D_00532FE8;
extern "C" void func_0041E3B0(C3D310* self);
extern "C" void func_0033D0C0(C3D310* self);
extern "C" void func_0033D310(C3D310* self)
{
    func_0041E3B0(self);
    self->Slot22();
    if (D_00532FE8)
        func_0033D0C0(self);
}