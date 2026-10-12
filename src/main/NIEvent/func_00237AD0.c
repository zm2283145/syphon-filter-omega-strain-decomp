#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class Light00237AD0 {
public:
    int id;
    virtual void dtor(int flag);
    VPAD8(a) VPAD1(b)
    virtual void stop();
};
struct Ev00237AD0 { char pad[0x140]; Light00237AD0* light; };
extern "C" void Object_Deactivate(Ev00237AD0* self);
extern "C" void cNIEventLight_v16(Ev00237AD0* self)
{
    Object_Deactivate(self);
    if (self->light) {
        self->light->stop();
        if (self->light)
            self->light->dtor(1);
        self->light = 0;
    }
}