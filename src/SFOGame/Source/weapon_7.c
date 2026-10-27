/*
 * SFOGame/Source/weapon: 1 file, 00142450
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00142450 */
#pragma push /* merge_units */
#include "types.h"
typedef struct { void* vt; char pad[0x18]; int size; unsigned char kind; char pad21[0xB]; unsigned char b2C; char pad2D[7]; unsigned char slot; char pad35[3]; int drop; char pad3C[4]; } Ev_2450;
typedef struct { int pad0; int id; int x8; int count; } Slot_2450;
typedef struct { char pad[0x60]; char equip[4]; } Own_2450;
typedef struct { char pad[0x139]; unsigned char keep; } W_2450;
typedef struct { int pad0; Slot_2450 slots[8]; unsigned char cur; char pad85[3]; Own_2450* own; } S_2450;
extern void* g_WeaponDatabase;
extern unsigned char g_IsMultiplayer;
extern unsigned char WeaponHolsterAttachPoints[];
extern unsigned char WeaponHandAttachPoints[];
extern char D_0052ACC8[];
extern void cMessage_getSOBJClassId();
extern void cNetWeaponMsg_dtor();
extern void cNetWeaponMsg_Clone();
extern void cNetWeaponMsg_Pack();
void * const D_004DE610[8] = { (void*)0x0, (void*)0x0, (void*)cNetWeaponMsg_dtor, (void*)cNetWeaponMsg_Clone, (void*)cNetWeaponMsg_Pack, (void*)cMessage_getSOBJClassId, (void*)0x0, (void*)0x0 };
W_2450* cWeaponDB_GetEntry(void* db, int id);
void cMan_RemoveGun(void* eq, unsigned char kind, int slot);
void cWeaponDB_UnloadWeapon(void* db, int id, int a);
void cMessage_ctor_cMessageNameR(Ev_2450* e, void* type);
void QueueMessage_cMessageR_cSystemP_int(Ev_2450* e, void* target, int a);
void cMessage_dtor(Ev_2450* e, int f);
void cWeapon_RemoveWeapon(S_2450* self, int slot, int unused, int drop, int remote)
{
    int i = (unsigned char)slot;
    Slot_2450* s = &self->slots[i];
    unsigned char cur;
    unsigned char kind;
    s->count = 0;
    s->x8 = 0;
    cur = self->cur;
    if (i == cur || (i == 1 && cur == 0)) {
        kind = WeaponHandAttachPoints[i];
        if (i == cur)
            self->cur = 6;
    } else {
        kind = WeaponHolsterAttachPoints[i];
    }
    cMan_RemoveGun(self->own->equip, kind, i);
    if (drop && !cWeaponDB_GetEntry(g_WeaponDatabase, s->id)->keep)
        cWeaponDB_UnloadWeapon(g_WeaponDatabase, s->id, 0);
    s->id = -1;
    if (g_IsMultiplayer && !remote) {
        Ev_2450 e;
        cMessage_ctor_cMessageNameR(&e, D_0052ACC8);
        e.slot = slot;
        e.drop = (unsigned char)drop;
        e.b2C = 0;
        e.vt = ((char*)D_004DE610);
        e.size = 0x40;
        e.kind = 4;
        QueueMessage_cMessageR_cSystemP_int(&e, self->own, 0);
        e.vt = ((char*)D_004DE610);
        cMessage_dtor(&e, 0);
    }
}
static inline void merge_flush_func_00142450(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00142450 */
