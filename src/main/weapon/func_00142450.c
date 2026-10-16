#include "types.h"
typedef struct { void* vt; char pad[0x18]; int size; unsigned char kind; char pad21[0xB]; unsigned char b2C; char pad2D[7]; unsigned char slot; char pad35[3]; int drop; char pad3C[4]; } Ev_2450;
typedef struct { int pad0; int id; int x8; int count; } Slot_2450;
typedef struct { char pad[0x60]; char equip[4]; } Own_2450;
typedef struct { char pad[0x139]; unsigned char keep; } W_2450;
typedef struct { int pad0; Slot_2450 slots[8]; unsigned char cur; char pad85[3]; Own_2450* own; } S_2450;
extern void* D_004FFD30;
extern unsigned char D_005721C8;
extern unsigned char D_00489D70[];
extern unsigned char D_00489D78[];
extern char D_0052ACC8[];
extern void Message_GetScriptTypeKey();
extern void func_001425C0();
extern void func_00316A80();
extern void func_00316C80();
void * const D_004DE610[8] = { (void*)0x0, (void*)0x0, (void*)func_001425C0, (void*)func_00316A80, (void*)func_00316C80, (void*)Message_GetScriptTypeKey, (void*)0x0, (void*)0x0 };
W_2450* WeaponDb_Get(void* db, int id);
void Equip_ClearSlot(void* eq, unsigned char kind, int slot);
void WeaponDb_Unload(void* db, int id, int a);
void Event_Construct(Ev_2450* e, void* type);
void Event_Send(Ev_2450* e, void* target, int a);
void cMessage_dtor(Ev_2450* e, int f);
void WeaponInv_RemoveSlot(S_2450* self, int slot, int unused, int drop, int remote)
{
    int i = (unsigned char)slot;
    Slot_2450* s = &self->slots[i];
    unsigned char cur;
    unsigned char kind;
    s->count = 0;
    s->x8 = 0;
    cur = self->cur;
    if (i == cur || (i == 1 && cur == 0)) {
        kind = D_00489D78[i];
        if (i == cur)
            self->cur = 6;
    } else {
        kind = D_00489D70[i];
    }
    Equip_ClearSlot(self->own->equip, kind, i);
    if (drop && !WeaponDb_Get(D_004FFD30, s->id)->keep)
        WeaponDb_Unload(D_004FFD30, s->id, 0);
    s->id = -1;
    if (D_005721C8 && !remote) {
        Ev_2450 e;
        Event_Construct(&e, D_0052ACC8);
        e.slot = slot;
        e.drop = (unsigned char)drop;
        e.b2C = 0;
        e.vt = ((char*)D_004DE610);
        e.size = 0x40;
        e.kind = 4;
        Event_Send(&e, self->own, 0);
        e.vt = ((char*)D_004DE610);
        cMessage_dtor(&e, 0);
    }
}