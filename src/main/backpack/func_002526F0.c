#pragma cplusplus on
#include "types.h"

typedef struct Icon_2526F0 {
    char pad0[0x60];
    int image;
    unsigned char mode;
} Icon_2526F0;

typedef struct Item_2526F0 {
    unsigned char kind;
    char pad1[3];
    int id;
    int unk8;
    Icon_2526F0* icon;
    Icon_2526F0* icon2;
    void* label;
    void* label2;
} Item_2526F0;

typedef struct Target_2526F0 {
    char pad0[0xC];
    int serial;
    char pad10[0x3528 - 0x10];
    void* items;
} Target_2526F0;

typedef struct Handle_2526F0 {
    Target_2526F0* p;
    int serial;
} Handle_2526F0;

typedef struct Owner_2526F0 {
    char pad0[0x2E4];
    int has2E8;
    int unk2E8;
    char pad2EC[0x300 - 0x2EC];
    Handle_2526F0 hTarget;
} Owner_2526F0;

typedef struct Slot_2526F0 {
    int unk0;
    int unk4;
    int weapon;
    int unkC;
} Slot_2526F0;

typedef struct Inv_2526F0 {
    Slot_2526F0 slots[8];
    char pad80[4];
    unsigned char cur;
} Inv_2526F0;

typedef struct Ctx_2526F0 {
    char pad0[0x33A0];
    int unk33A0;
    char pad33A4[0x3524 - 0x33A4];
    Inv_2526F0* inv;
    void* items;
} Ctx_2526F0;

typedef struct WeaponDef_2526F0 {
    char pad0[0x70];
    int unk70;
    int unk74;
    char pad78[0xF0 - 0x78];
    unsigned char type;
    char padF1[0x11C - 0xF1];
    int image11C;
    char pad120[0x13C - 0x120];
    int image13C;
} WeaponDef_2526F0;

typedef struct ItemDef_2526F0 {
    char pad0[0x28];
    int image;
} ItemDef_2526F0;

typedef struct Self_2526F0 {
    Owner_2526F0* owner;
    Item_2526F0 items[5];
    int count;
    int sel;
    int x;
} Self_2526F0;

extern "C" {
extern char* Loc_LookupText(char* key);
extern int Agent_GetSelected(void* list, int idx);
extern int AgentData_HasUnlock(int agent, int what);
extern int WeaponInv_SlotOfItem(int id);
extern void Backpack_CycleItem(Owner_2526F0* o, int id, int which);
extern bool Backpack_TakeItem(Owner_2526F0* o, int id, int which);
extern int WeaponInv_HasAmmoText(Inv_2526F0* inv, int id);
extern bool Backpack_GetItemSlotFlag(Owner_2526F0* o, int id);
extern void Backpack_QueryAmmo(Owner_2526F0* o, int id, int* a, int* b, int* c);
extern WeaponDef_2526F0* WeaponDb_Get(int db, int id);
extern int WeaponInv_GetSpare(Inv_2526F0* inv, int slot);
extern int WeaponInv_GetClip(Inv_2526F0* inv, int slot);
extern int func_00143DE0(Inv_2526F0* inv, int ammo);
extern int sprintf(char* buf, const char* fmt, ...);
extern int ItemInv_Count(void* items, int id);
extern void IeElement_SetData(void* label, Icon_2526F0* icon);
extern void IeElement_SetText(void* label, char* text);
extern void IeElement_PlayRange(void* label, float lo, float hi, unsigned char fl);
extern void IeElement_Fade(void* label, float v);

extern int D_0048AF08;
extern char D_004A79E0[];
extern char D_004A79E8[];
extern char D_004A79F0[];
extern char D_004A79F8[];
extern char D_004A7A08[];
extern char D_004A7A18[];
extern char D_004A7A28[];
extern char D_004A7A30[];
extern char D_004A7A38[];
extern char g_Game[];
extern int g_WeaponDatabase;
extern ItemDef_2526F0* D_00587FF8;
}

static inline void Icon_SetIM(Icon_2526F0* ic, int image, unsigned char mode) {
    ic->image = image;
    ic->mode = mode;
}

static inline void Icon_SetMI(Icon_2526F0* ic, unsigned char mode, int image) {
    ic->mode = mode;
    ic->image = image;
}

static inline int Owner_Get2E8(Owner_2526F0* o) {
    if (o->has2E8)
        return o->unk2E8;
    return 0;
}

static inline int Inv_CurWeapon(Inv_2526F0* inv) {
    if (inv->cur != 6)
        return inv->slots[inv->cur].weapon;
    return -1;
}

static inline bool Handle_Valid(Owner_2526F0* h) {
    Target_2526F0* t = h->hTarget.p;
    return !t || t->serial == h->hTarget.serial;
}
static inline Target_2526F0* Handle_Get2(Owner_2526F0* h) {
    return Handle_Valid(h) ? h->hTarget.p : 0;
}

static inline Target_2526F0* Handle_Get(Owner_2526F0* h) {
    bool isNull;
    bool ok;
    Target_2526F0* t;
    t = h->hTarget.p;
    isNull = !t;
    ok = true;
    if (!isNull) if (t->serial != h->hTarget.serial) ok = false;
    return ok ? t : 0;
}

extern "C" int Pickup_BuildPromptText(Self_2526F0* self, Ctx_2526F0* ctx) {
    int ammo;
    int clips;
    int reserve;
    char buf1[0x40];
    char buf2[0x40];
    int db;
    int extra;
    char* prefix;
    Inv_2526F0* inv;
    bool useCur;
    int i;
    int maxSpare;
    bool same;
    bool noAmmo;
    bool cur;
    char* full;
    bool dual;
    bool unlocked;
    bool show;
    Item_2526F0* it;
    char* line1;
    char* line2;

    db = g_WeaponDatabase;
    extra = Owner_Get2E8(self->owner);
    prefix = Loc_LookupText(D_004A79E0);
    inv = ctx->inv;
    useCur = self->x != 0;
    { char* e = D_004A79E8; if (D_0048AF08 == 0) prefix = e; }
    if (useCur)
        self->items[0].id = Inv_CurWeapon(inv);
    for (i = 0; i < self->count; i++) {
        it = &self->items[i];
        line1 = buf1;
        line2 = buf2;
        if (it->kind == 0) {
            int slot;
            unsigned char uslot;
            int wid;
            bool cond;
            bool isSlot4;
            bool isSlot0;
            int noSecond;
            WeaponDef_2526F0* wd2;

            slot = WeaponInv_SlotOfItem(it->id);
            if (useCur)
                slot = (signed char)inv->cur;
            uslot = slot;
            wid = inv->slots[uslot].weapon;
            noSecond = inv->slots[1].weapon >= 0;
            isSlot0 = uslot == 0;
            dual = false;
            if (isSlot0 && noSecond) dual = true;
            same = wid == it->id;
            unlocked = false;
            cond = isSlot0 && !dual && same;
            if (cond && AgentData_HasUnlock(Agent_GetSelected(g_Game, -1), 1))
                unlocked = true;
            Backpack_CycleItem(self->owner, it->id, 0);
            Backpack_CycleItem(self->owner, it->id, 1);
            show = Backpack_TakeItem(self->owner, it->id, 1);
            isSlot4 = uslot == 4;
            noAmmo = !WeaponInv_HasAmmoText(inv, it->id);
            cur = Backpack_GetItemSlotFlag(self->owner, it->id);
            Backpack_QueryAmmo(self->owner, it->id, &ammo, &clips, &reserve);
            if (wid > -1) {
                int spare;
                WeaponDef_2526F0* wd;
                int clip;
                wd = WeaponDb_Get(db, wid);
                spare = WeaponInv_GetSpare(inv, slot);
                maxSpare = wd->unk70 * func_00143DE0(inv, wd->unk74);
                clip = WeaponInv_GetClip(inv, slot);
                if (isSlot4) {
                    sprintf(line1, D_004A79F0, spare);
                } else if (!noAmmo) {

                    char* dualText;
                    if (dual) {
                        clip /= 2;
                        spare /= 2;
                    }
                    full = D_004A79E8;
                    if (spare == maxSpare)
                        full = Loc_LookupText(D_004A79F8);
                    dualText = D_004A79E8;
                    if (dual)
                        dualText = Loc_LookupText(D_004A7A08);
                    sprintf(line1, D_004A7A18, dualText, clip, spare, full);
                } else {
                    line1[0] = 0;
                }
                if (wd->type == 7) {
                    Icon_SetIM(it->icon, wd->image11C, 7);
                } else {
                    Icon_SetIM(it->icon, wd->image13C, 7);
                }
            } else {
                Icon_SetIM(it->icon, 0, 7);
                line1[0] = 0;
            }
            wd2 = WeaponDb_Get(db, it->id);
            if (!show || (same && cur)) {
                if (it->icon2) {
                    Icon_SetIM(it->icon2, 0, 7);
                }
                line2[0] = 0;
            } else if (same && !unlocked && !isSlot4 && reserve) {
                if (it->icon2) {
                    Icon_SetMI(it->icon2, 1, 0);
                }
                sprintf(line2, D_004A7A28, prefix, reserve);
            } else {
                if (it->icon2) {
                    if (wd2->type == 7) {
                        Icon_SetIM(it->icon2, wd2->image11C, 7);
                    } else {
                        Icon_SetIM(it->icon2, wd2->image13C, 7);
                    }
                }
                if (isSlot4)
                    sprintf(line2, D_004A79F0, ammo);
                else if (!noAmmo)
                    sprintf(line2, D_004A7A30, clips, ammo);
                else
                    line2[0] = 0;
            }
        } else if (it->kind == 2) {
            Icon_SetMI(it->icon, 2, 0);
            sprintf(line1, D_004A7A38, ctx->unk33A0);
            if (it->icon2) {
                Icon_SetMI(it->icon2, 2, 0);
            }
            sprintf(line2, D_004A7A38, extra);
        } else if (it->kind == 3) {
            if (it->icon2) {
                Icon_SetMI(it->icon2, 4, 0);
            }
            Icon_SetMI(it->icon, 7, 0);
            line1[0] = 0;
            line2[0] = 0;
        } else if (it->kind == 4) {
            if (it->icon2) {
                Icon_SetMI(it->icon2, 6, 0);
            }
            Icon_SetMI(it->icon, 7, 0);
            line1[0] = 0;
            line2[0] = 0;
        } else if (it->kind == 5) {
            int image;
            int n;
            void* items = Handle_Get(self->owner) ? Handle_Get2(self->owner)->items : 0;
            image = D_00587FF8[it->id].image;
            n = ItemInv_Count(items, it->id);
            line1[0] = 0;
            line2[0] = 0;
            if (n) {
                if (it->icon2) {
                    Icon_SetIM(it->icon2, image, 7);
                }
                if (n > 1)
                    sprintf(line2, D_004A7A38, n);
            } else {
                if (it->icon2) {
                    Icon_SetIM(it->icon2, 0, 7);
                }
            }
            n = ItemInv_Count(ctx->items, it->id);
            if (n) {
                Icon_SetIM(it->icon, image, 7);
                if (n > 1)
                    sprintf(line1, D_004A7A38, n);
            } else {
                Icon_SetIM(it->icon, 0, 7);
            }
        }
        IeElement_SetData(it->label, it->icon);
        if (it->label2)
            IeElement_SetData(it->label2, it->icon2);
        IeElement_SetText(it->label, line1);
        if (it->label2)
            IeElement_SetText(it->label2, line2);
        if (i == self->sel)
            IeElement_PlayRange(it->label, 20.0f + self->x, 35.0f + self->x, 1);
        else
            IeElement_Fade(it->label, 10.0f + self->x);
        if (it->label2)
            IeElement_Fade(it->label2, 10.0f + self->x);
    }
    return self->count > 0;
}









