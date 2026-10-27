#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"

class Tgt0023A250 {
public:
    VPAD32(a)
    virtual int run();
};
struct Ev0023A250 {
    char pad00[0x2C];
    unsigned char b2C;
    unsigned char b2D;
    unsigned char b2E;
    char pad2F[0xDC - 0x2F];
    unsigned char enabled;
    char padDD[0x140 - 0xDD];
    Tgt0023A250* target;
};
extern "C" int cNIEventOBJ_GetBBox(Ev0023A250* self)
{
    Tgt0023A250* t;
    return (self->enabled && (t = self->target) != 0 && !(self->b2D == 0) && self->b2C && !self->b2E)
        ? t->run() : 0;
}
