#pragma cplusplus on
#include "types.h"
/* sync the equipped weapon with the networked item entity */
struct WSlot_B2D20 { int id; int pad[3]; };
struct Inv_B2D20 {
    char pad0[8]; WSlot_B2D20 slots[6]; char pad68[0x84 - 0x68]; unsigned char cur;
    int CurId() { return cur != 6 ? slots[cur].id : -1; }
};
struct Base_B2D20 { char pad0[0x1C]; };
struct Item_B2D20 { char pad0[6]; short id; short GetId() { return id; } };
struct Ent_B2D20 : Base_B2D20, Item_B2D20 { };
struct NetRec_B2D20 { char pad0[0x10]; Ent_B2D20* ent; };
struct Obj_B2D20 {
    char pad0[0xC];
    int netId;
    char pad10[4];
    unsigned char remote;
    char pad15[0x3524 - 0x15];
    Inv_B2D20* inv;
    char pad3528[0x3584 - 0x3528];
    Ent_B2D20* ent;
};
extern "C" {
NetRec_B2D20* cNetObj_GetNetSystem(int id);
void cWeapon_Select(Inv_B2D20* inv, int id);
void cHuman_CheckForChangedWeapons(Obj_B2D20* o);
}
static inline Item_B2D20* AsItem(Ent_B2D20* e) { return e; }
void cHuman_CheckForChangedWeapons(Obj_B2D20* o)
{
    if (!o->remote) {
        if (!o->ent) {
            NetRec_B2D20* n = cNetObj_GetNetSystem(o->netId);
            if (n && n->ent) o->ent = n->ent;
        }
        if (AsItem(o->ent)) {
            if (o->inv->CurId() != AsItem(o->ent)->GetId())
                cWeapon_Select(o->inv, AsItem(o->ent)->id);
        }
    } else {
        if (AsItem(o->ent)) {
            if (o->inv->CurId() != AsItem(o->ent)->GetId())
                AsItem(o->ent)->id = o->inv->CurId();
        }
    }
}
