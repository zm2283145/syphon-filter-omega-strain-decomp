#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
class R_1CD0 {
public:
    VPAD16(a) VPAD2(b) VPAD1(c)
    virtual int IsLocal();
};
struct Ev_1CD0 { void* vt; char pad[0x20]; int id; char pad28[8]; };
struct Slot_1CD0 { int pad0; int id; int pad8; int count; };
struct Own_1CD0 { char pad[0x58]; R_1CD0* recv; char pad5C[4]; char equip[4]; };
struct W_1CD0 { char pad[0x13C]; int slot; };
struct S_1CD0 { int pad0; Slot_1CD0 slots[8]; unsigned char cur; char pad85[3]; Own_1CD0* own; char pad8C[0x63]; unsigned char busy; };
extern "C" {
extern void* D_004FFD30;
extern unsigned char D_005721C8;
extern char D_004EA150[];
extern char D_004D91E0[];
W_1CD0* WeaponDb_Get(void* db, int id);
void Equip_SetSlot(void* eq, int a, int slot);
void Event_Construct(Ev_1CD0* e, void* type);
void Event_Send(Ev_1CD0* e, void* target, int a);
void cMessage_dtor(Ev_1CD0* e, int f);
void WeaponInv_Cycle(S_1CD0* self, int a);
}
extern "C" void Inventory_ReleaseItem(S_1CD0* self)
{
    self->busy = 0;
    if (self->cur == 4 || self->cur == 5) {
        Slot_1CD0* s = &self->slots[self->cur];
        unsigned char local;
        R_1CD0* r;
        if (s->count > 0) {
            Equip_SetSlot(self->own->equip, 0, WeaponDb_Get(D_004FFD30, s->id)->slot);
            return;
        }
        local = 0;
        r = self->own->recv;
        if (r && r->IsLocal())
            local = 1;
        if (local && !D_005721C8) {
            int id = s->id;
            Ev_1CD0 e;
            Event_Construct(&e, D_004EA150);
            e.id = id;
            e.vt = D_004D91E0;
            Event_Send(&e, self->own->recv, 0);
            e.vt = D_004D91E0;
            cMessage_dtor(&e, 0);
        }
        s->id = -1;
        WeaponInv_Cycle(self, 1);
    }
}