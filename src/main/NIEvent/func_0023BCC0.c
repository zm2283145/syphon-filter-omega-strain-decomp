#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class Item0023BCC0 {
public:
    VPAD8(a) VPAD1(b)
    virtual void reset(int how);
};
struct Ev0023BCC0 {
    char pad00[0x2C];
    char b2C;
    char pad2D[0xA0 - 0x2D];
    int count;
    Item0023BCC0** items;
};
#pragma opt_strength_reduction off
extern "C" void cNIEventOBJ_v09(Ev0023BCC0* self)
{
    int i;
    self->b2C = 0;
    for (i = 0; i < self->count; i++)
        self->items[i]->reset(-1);
}
#pragma opt_strength_reduction reset
