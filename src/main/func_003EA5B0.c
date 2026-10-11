#pragma cplusplus on
#include "types.h"
extern "C" { extern char D_004E06C0[]; void Receiver_Destruct(void* p, short f); void operator_delete(void* p); }
struct L3EA5B0 { char pad[0x58]; int x58; };
struct O3EA5B0 { void* vt; char pad[0x2C]; L3EA5B0* link; };
extern "C" O3EA5B0* func_003EA5B0(O3EA5B0* self, short del)
{
    if (self) {
        self->vt = D_004E06C0;
        {
            L3EA5B0* l = self->link;
            if (l) {
                l->x58 = 0;
                self->link = 0;
            }
        }
        Receiver_Destruct(self, 0);
        if (del > 0) operator_delete(self);
    }
    return self;
}