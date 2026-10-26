#pragma opt_propagation off
#pragma cplusplus on
#include "types.h"
#include "vslot_pad.h"
struct HuB { char pad[0x1C]; };
struct HuC { int a; short pad; short id; short Id() { return id; } };
struct HuItem : HuB, HuC {};
struct HuSlot { int a, b, id, c; };
struct HuInv {
    HuSlot slots[8];
    char pad80[4];
    unsigned char cur;
    int CurId() { return cur != 6 ? slots[cur].id : -1; }
};
struct HuOwner { char pad[0x3524]; HuInv* inv; char pad3528[0x3584 - 0x3528]; HuItem* item; };
struct HuTarget {
    VPAD32(a) VPAD32(b)
    virtual unsigned char State();
    char pad4[0x2C - 4];
    unsigned char b2C, b2D, b2E;
    bool IsActive() { return b2D && b2C && !b2E; }
};
struct HuRef { char pad[8]; int id; };
struct HuSelf {
    VPAD16(a) VPAD4(b) VPAD2(c)
    virtual void Select(HuTarget* t, int id, int n);
    char pad4[0x40];
    HuItem* ref;
    HuC* item;
    HuOwner* owner;
};
extern "C" {
HuTarget* Object_LookupById(int* id);
void WeaponInv_EquipItem(HuInv* inv, int id);
void cNetPlayer_AimWeapon(HuSelf* s, HuTarget* t);
}
extern "C" void cNetPlayer_NextFrame(HuSelf* s)
{
    HuTarget* t = 0;
    if (!s->ref) {
        HuItem* it = s->owner->item;
        if (it)
            s->ref = it;
    }
    if (!s->item) {
        HuItem* it = s->owner->item;
        if (it)
            s->item = it;
    }
    if (s->ref && s->item) {
        HuInv* inv = s->owner->inv;
        short id = s->item->Id();
        int cur = inv->CurId();
        if (cur != id)
            WeaponInv_EquipItem(inv, id);
    }
    if (s->ref) {
        int id = ((HuRef*)s->ref)->id;
        HuTarget* p;
        if ((p = Object_LookupById(&id)) != 0) {
            t = p;
            if (t->State() != 3 && t->IsActive())
                s->Select(t, s->owner->inv->CurId(), -1);
            else
                t = 0;
        }
    }
    cNetPlayer_AimWeapon(s, t);
}


