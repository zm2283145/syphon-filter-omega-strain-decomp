#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class Tgt00239FA0 {
public:
    VPAD16(a) VPAD4(b)
    virtual void apply();
    char pad[0x34];
    int value;
};
struct Ev00239FA0 {
    char pad00[0x38];
    int value;
    char pad3C[0xDC - 0x3C];
    unsigned char enabled;
    char padDD[0x140 - 0xDD];
    Tgt00239FA0* target;
};
extern "C" void cNIEventOBJ_v14(Ev00239FA0* self)
{
    if (self->enabled) {
        self->target->value = self->value;
        self->target->apply();
    }
}