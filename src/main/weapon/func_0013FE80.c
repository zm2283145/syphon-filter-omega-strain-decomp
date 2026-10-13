#pragma cplusplus on
#pragma opt_common_subs off
#include "types.h"
#include "vslot_pad.h"
class R_FE80 {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsLocal();
};
struct Own_FE80 { char pad[0x14]; unsigned char f14; char pad15[0x43]; R_FE80* recv; };
struct S_FE80 { char pad[0x88]; Own_FE80* own; };
extern "C" {
extern char D_004FFB50[];
void* Agent_GetSelected(void* list, int idx);
void Stats_Add(void* agent, int stat, int n);
}
extern "C" void Weapon_RecordShotStats(S_FE80* self, int hit)
{
    Own_FE80* o = self->own;
    if (o->recv) {
        unsigned char local = 0;
        R_FE80* r = o->recv;
        if (r && r->IsLocal())
            local = 1;
        if (local && self->own->f14) {
            Stats_Add(Agent_GetSelected(D_004FFB50, -1), 9, 1);
            if (hit)
                Stats_Add(Agent_GetSelected(D_004FFB50, -1), 0xB, 1);
        }
    }
}




