#pragma cplusplus on
#include "vslot_pad.h"
struct Sub3D3A0 { char pad[0x10]; int state; };
class C3D3A0 {
public:
    VPAD16(p) VPAD4(q) VPAD2(r) VPAD1(s)
    virtual void Slot23();
    char pad[0x78];
    Sub3D3A0* sub;
};
extern "C" void func_0041EFA0(C3D3A0* self);
extern "C" void GuiScreen_Wake(C3D3A0* self)
{
    func_0041EFA0(self);
    self->Slot23();
    if (self->sub)
        self->sub->state = -1;
}