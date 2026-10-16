#include "types.h"
#pragma cplusplus on
#include "vslot_pad.h"
struct E356BE0 { unsigned short a0; unsigned short a2; short pad4; unsigned short a6; unsigned short a8; };
class S356BE0 {
public:
    VPAD16(a) VPAD8(b)
    virtual void f68();
};
extern "C" int func_00356BE0(S356BE0* self, E356BE0* e);
int func_00356BE0(S356BE0* self, E356BE0* e)
{
    bool b = e->a0 == 1 && e->a2 == 0 && e->a8 == 0x10 && e->a6 == 0;
    if (b) {
        self->f68();
        return 1;
    }
    return 0;
}

