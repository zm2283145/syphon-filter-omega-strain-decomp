#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class Obj_7060 {
public:
    VPAD16(a) VPAD4(b) VPAD1(c)
    virtual void Attach(int on);
    virtual void Detach(int on);
};
struct S_7060 { char pad[0x1A4]; Obj_7060* obj; };
extern "C" {
void func_0040C9A0(Obj_7060* o);
void func_003CB230(float t, Obj_7060* o);
void Object_Register(Obj_7060* o);
}
extern "C" void func_00177060(S_7060* self, Obj_7060* o)
{
    if (self->obj) {
        self->obj->Detach(1);
        func_0040C9A0(self->obj);
        func_003CB230(0.1f, self->obj);
        self->obj = 0;
    }
    if (o) {
        self->obj = o;
        Object_Register(o);
        o->Attach(1);
    }
}