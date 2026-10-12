#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class NPC_77B0 {
public:
    VPAD32(a) VPAD8(b) VPAD4(c) VPAD2(d)
    virtual void Reset();
};
extern "C" void NpcAi_GetPlayerRecord(NPC_77B0* self, int a, int b);
extern "C" int func_0015B060(NPC_77B0* self, int a);
extern "C" void func_001577B0(NPC_77B0* self, int a)
{
    NpcAi_GetPlayerRecord(self, a, 0);
    if (!func_0015B060(self, -1))
        self->Reset();
}