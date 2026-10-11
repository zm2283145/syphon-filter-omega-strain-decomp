#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class NPC_AEC0 {
public:
    VPAD32(a) VPAD16(b) VPAD4(c) VPAD2(d) VPAD1(e)
    virtual void AddItem(int w);
};
extern "C" int func_003FB8D0(int i);
extern "C" void cNPC_v39(NPC_AEC0* self)
{
    int i = 0;
    do {
        int w = func_003FB8D0(i);
        if (w)
            self->AddItem(w);
        i++;
    } while (i < 4);
}