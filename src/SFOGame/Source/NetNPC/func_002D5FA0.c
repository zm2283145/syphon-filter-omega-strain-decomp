#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct Npc2D5FA0 { VPAD16(a) VPAD1(b) virtual void Release(); char pad[0x14C]; int f150; char p154[5]; unsigned char b159; };
extern "C" {
extern char D_004DE2A0[];
void cNPC_dtor(Npc2D5FA0* p, int f);
void operator_delete(void* p);
}
extern "C" Npc2D5FA0* cNetNPC_dtor(Npc2D5FA0* self, short del)
{
    if (self) {
        *(void**)self = D_004DE2A0;
        if (!self->b159) {
            self->f150 = -1;
            self->Release();
        }
        cNPC_dtor(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}
