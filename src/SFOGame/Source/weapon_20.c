/*
 * SFOGame/Source/weapon: 7 files, 00143BC0-00143DE0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00143BC0 */
#pragma push /* merge_units */
#include "types.h"

typedef struct { char pad[8]; unsigned char b8; } Sub_143BC0;
typedef struct { Sub_143BC0* sub; char p4[0x9C]; unsigned char a0; char pa1[0x1B]; int bc; int c0; char pc4[0x2B]; unsigned char ef; } S_143BC0;
#pragma cplusplus on
static inline int Busy_143(S_143BC0* s) { int b = (s->ef != 0); if (!b) b = (s->a0 != 0); if (!b) b = (s->bc != 0); if (!b) b = (s->c0 != 0); return b; }
extern "C" bool cWeapon_CanChangeWeapon(S_143BC0* s) {
    bool r = false;
    if (Busy_143(s) ^ 1) {
        bool idle = !(s->sub != 0) || !(s->sub->b8 != 0);
        if (idle) r = true;
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00143BC0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00143BC0 */

/* merge_units: begin func_00143C50 */
#pragma push /* merge_units */
typedef struct { int x0; int x4; int x8; int xC; } Slot143C50;
typedef struct { Slot143C50 s[6]; } Inv143C50;
extern void cWeapon_DrawWeapon_eWpnSlot(Inv143C50*, int);
void cWeapon_DrawWeapon_void(Inv143C50* inv) {
    int slot = 6;
    int i;
    for (i = 0; i < 6; i++) {
        if (inv->s[i].x8 != -1) { slot = (unsigned char)i; break; }
    }
    if ((unsigned char)slot != 6) cWeapon_DrawWeapon_eWpnSlot(inv, slot);
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00143C50(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00143C50 */

/* merge_units: begin func_00143CC0 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */

#include "weapon_types.h"

extern void cWeapon_StoreWeapon_void(Inventory* inv);

void cWeapon_ForceHolster(Inventory* inv) {
    if (inv->selected != 6) {
        cWeapon_StoreWeapon_void(inv);
    }
}
static inline void merge_flush_func_00143CC0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00143CC0 */

/* merge_units: begin func_00143CF0 */
#pragma push /* merge_units */
typedef struct { char pad[0x85]; unsigned char item; } Inv3CF0;
#if 0 /* merge_units */
extern void cWeapon_DrawWeapon_eWpnSlot(Inv3CF0* p, int item);
#endif /* merge_units */
#define cWeapon_DrawWeapon_eWpnSlot(a0, a1) (cWeapon_DrawWeapon_eWpnSlot((Inv143C50 *)(a0), (a1))) /* merge_units */

void cWeapon_DrawLastWeaponUsed(Inv3CF0* p) {
    if (p->item != 6) {
        cWeapon_DrawWeapon_eWpnSlot(p, ((signed char*)p)[0x85]);
    }
}
#undef cWeapon_DrawWeapon_eWpnSlot /* merge_units */
static inline void merge_flush_func_00143CF0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00143CF0 */

/* merge_units: begin func_00143D20 */
#pragma push /* merge_units */
extern signed char WeaponClassToSlot[];

/* Maps a weapon id through definition byte +0x30 and the WeaponClassToSlot table. */
int cWeapon_GetWeaponSlot(int id) {
    WeaponDef* def = cWeaponDB_GetEntry(g_WeaponDatabase, id);

    return WeaponClassToSlot[def->unk30];
}
static inline void merge_flush_func_00143D20(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00143D20 */

/* merge_units: begin func_00143D60 */
#pragma push /* merge_units */
#pragma peephole off
typedef struct { int a0; int id; int x; int y; } E3D60;
typedef struct { int pad; E3D60 e[2]; } S3D60;
void cWeapon_EqualizeDualWieldAmmo(char* self)
{
    E3D60* b = (E3D60*)(self + 0x14);
    E3D60* a = (E3D60*)(self + 0x4);
    if (*(int*)(self + 0x18) != -1 && a->id != -1) {
        int y = (b->y + a->y + 1) / 2;
        int x = (b->x + a->x + 1) / 2;
        a->x = x;
        b->x = x;
        a->y = y;
        b->y = y;
    }
}
static inline void merge_flush_func_00143D60(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00143D60 */

/* merge_units: begin func_00143DE0 */
#pragma push /* merge_units */
extern int cHuman_AdjustMaxClips(void* a0, int key);

int cWeapon_AdjustMaxClips(Inventory* inv, int key) {
    return cHuman_AdjustMaxClips(inv->unk88, key);
}
static inline void merge_flush_func_00143DE0(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00143DE0 */
