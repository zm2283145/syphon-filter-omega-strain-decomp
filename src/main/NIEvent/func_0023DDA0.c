#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Info0023DDA0 { int w[16]; };
class Obj0023DDA0 {
public:
    VPAD32(a) VPAD2(b) VPAD1(c)
    virtual void onA(Info0023DDA0* info);
    VPAD4(d) VPAD1(e)
    virtual void onB(Info0023DDA0* info);
    char pad[0x12C];
    unsigned char flag;
};
extern "C" void cNIEventBase_ParentXform(Info0023DDA0* out, Obj0023DDA0* self);
extern "C" void cNIEventBase_ForceMatUpdate(Obj0023DDA0* self)
{
    if (self->flag) {
        Info0023DDA0 a;
        cNIEventBase_ParentXform(&a, self);
        self->onA(&a);
    } else {
        Info0023DDA0 b;
        cNIEventBase_ParentXform(&b, self);
        self->onB(&b);
    }
}