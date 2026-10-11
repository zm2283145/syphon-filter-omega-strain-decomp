#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class NPC_BEA0 {
public:
    VPAD32(a) VPAD32(b) VPAD32(c) VPAD16(d) VPAD8(e) VPAD4(f)
    virtual void OnClear();
    char pad[0xB8];
    int bits[9];
};
extern "C" void cNPC_v7B(NPC_BEA0* self, int notify)
{
    int i;
    for (i = 0; i < 9; i++)
        self->bits[i] = 0;
    if (notify)
        self->OnClear();
}