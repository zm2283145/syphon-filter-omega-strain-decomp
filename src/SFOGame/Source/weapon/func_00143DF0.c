#pragma opt_propagation off
#include "types.h"
typedef struct {
    void* vtable;
    char base[0x18];
    int x1C;
    unsigned char kind;
    char pad21[0xB];
    unsigned char op;
    char pad2D[7];
    char slot;
    char pad35[3];
    int value;
} Msg_INV;
typedef struct { int a; int b; int c; int d; } E_INV;
typedef struct { char pad[0x60]; char equip[0x24A2 - 0x60]; char flags[1]; } Actor_INV;
typedef struct { void** held; E_INV e[7]; char pad2[0x84 - 0x74]; unsigned char cur; char pad85[3]; Actor_INV* owner; } INV;
typedef struct { char pad[0x30]; unsigned char type; char pad31[0x70 - 0x31]; int clip; int ammoType; char pad78[0xF0 - 0x78]; unsigned char kind; char padF1[0x13C - 0xF1]; int equip; } WDB;
extern char D_0052ACC8[];
extern char D_004DE610[];
extern unsigned char g_IsMultiplayer;
extern int g_WeaponDatabase;
extern signed char WeaponClassToSlot[];
extern signed char WeaponHolsterAttachPoints[];
extern signed char WeaponHandAttachPoints[];
extern void cMessage_ctor_cMessageNameR(Msg_INV* msg, void* name);
extern void QueueMessage_cMessageR_cSystemP_int(Msg_INV* msg, void* target, int flags);
extern void cMessage_dtor(Msg_INV* msg, int flags);
extern WDB* cWeaponDB_GetEntry(int db, int id);
extern void cWeaponDB_LoadWeapon(int db, int id, int f);
extern int cHuman_AdjustMaxClips(Actor_INV* a, int type);
extern void cMan_AddGun(void* eq, unsigned char slot, int v);
void cWeapon_Add(INV* self, int id, unsigned char ammo, int unused, unsigned char preload, unsigned char quiet)
{
    signed char slot;
    E_INV* e;
    int db;
    int idx;
    WDB* w;
    unsigned char s;
    int v;
    db = g_WeaponDatabase;
    w = cWeaponDB_GetEntry(db, id);
    slot = WeaponClassToSlot[w->type];
    idx = slot & 0xFF;
    e = &self->e[idx];
    if (preload)
        cWeaponDB_LoadWeapon(g_WeaponDatabase, id, 0);
    if (e->b != -1 && (unsigned char)slot == 0 && id == e->b && self->e[1].b == -1) {
        slot = 1;
        idx = slot & 0xFF;
        e = &self->e[idx];
    }
    e->b = id;
    if (ammo) {
        WDB* w2 = cWeaponDB_GetEntry(db, id);
        e->c = w2->clip;
        e->d = w2->clip * cHuman_AdjustMaxClips(self->owner, w2->ammoType);
    } else {
        e->c = 0;
        e->d = 0;
    }
    s = slot;
    if (s == self->cur) {
        idx = WeaponHandAttachPoints[idx];
    } else {
        asm { .set reorder } /* barrier: retail fills the bne delay slot from the fall-through lui */
        idx = WeaponHolsterAttachPoints[idx];
    }
    if (s == 1 && self->cur == 0)
        idx = 1;
    v = cWeaponDB_GetEntry(db, id)->equip;
    if (v)
        cMan_AddGun(self->owner->pad + 0x60, idx, v);
    if (s == 6 || s == 7)
        self->owner->pad[(unsigned char)idx + 0x24A2] = 0;
    if (w->kind == 5 && self->held)
        *self->held = w;
    if (g_IsMultiplayer && !quiet) {
        Msg_INV msg;
        cMessage_ctor_cMessageNameR(&msg, D_0052ACC8);
        msg.vtable = D_004DE610;
        msg.op = 5;
        msg.value = ammo | (preload << 1);
        msg.slot = id;
        msg.x1C = 0x40;
        msg.kind = 4;
        QueueMessage_cMessageR_cSystemP_int(&msg, self->owner, 0);
        msg.vtable = D_004DE610;
        cMessage_dtor(&msg, 0);
    }
}








