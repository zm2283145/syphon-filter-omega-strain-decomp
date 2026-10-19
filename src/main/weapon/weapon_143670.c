/*
 * main/weapon: range (10 files, 00143670-001439B0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00143670 */
#pragma push /* merge_units */
typedef struct { unsigned char flag; char p[3]; int id; int c; int ammo; } E_INV;
typedef struct { int pad; E_INV e[7]; char pad2[0x84 - 0x74]; unsigned char cur; } INV;
typedef struct { char pad[0x200]; int x[64]; } WDef;
extern void* g_WeaponDatabase;
typedef struct { char pad[0x10C]; int x10C; } WD_3670;
extern WD_3670* WeaponDb_Get(void* db, int id);
int WeaponInv_HasSpareOfAmmoType(INV* self, int kind)
{
    int i;
    for (i = 0; i < 6; i++) {
        E_INV* e = &self->e[0];
        if (e->id != -1) {
            WD_3670* w = WeaponDb_Get(g_WeaponDatabase, e->id);
            if (w->x10C == kind && e->ammo > 0)
                return 1;
        }
        self = (INV*)((char*)self + 16);
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00143670(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00143670 */

/* merge_units: begin func_00143710 */
#pragma push /* merge_units */
typedef struct { int a; int id; int c; int d; } E_INV_00143710;
typedef struct { int pad; E_INV_00143710 e[7]; char pad2[0x84 - 0x74]; unsigned char cur; char pad3[3]; void* owner; char pad4[0xA8 - 0x8C]; unsigned char lock; } INV_00143710;
typedef struct { int a; int b; int id; int d; } Slot_3710;
typedef struct { char pad[0x70]; int x70; } WDef_3710;
#if 0 /* merge_units */
extern WDef_3710* WeaponDb_Get(void* db, int id);
#endif /* merge_units */
#define WeaponDb_Get(a0, a1) ((WDef_3710 *)WeaponDb_Get((a0), (a1))) /* merge_units */

int WeaponInv_HasAmmoText(INV_00143710* self, int id)
{
    if (id == -1 && self->cur != 6) id = self->e[self->cur].id;
    return id != -1 ? WeaponDb_Get(g_WeaponDatabase, id)->x70 != 0 : 0;
}
#undef WeaponDb_Get /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00143710(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00143710 */

/* merge_units: begin func_00143770 */
#pragma push /* merge_units */
extern int HeldItem_Release(int);

void WeaponInv_ReleaseHeldObject(int a0) {
    int v0;
    int cond;

    a0 = *(int*)(char*)a0;
    cond = a0 == 0;
    if (cond) goto L00143790;
    v0 = HeldItem_Release(a0);
L00143790:;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00143770(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00143770 */

/* merge_units: begin func_001437A0 */
#pragma push /* merge_units */
typedef struct E3Slot437 { int unk0; int id; int unk8; int unkC; } E3Slot437;
typedef struct E3Inv437 { int unk00; E3Slot437 slots[8]; unsigned char selected; } E3Inv437;
typedef struct E3Def437 { char pad[0xF0]; signed char unkF0; } E3Def437;
#if 0 /* merge_units */
extern E3Def437* WeaponDb_Get(void* table, int id);
#endif /* merge_units */
#define WeaponDb_Get(a0, a1) ((E3Def437 *)WeaponDb_Get((a0), (a1))) /* merge_units */

static inline E3Slot437* GetSel(E3Inv437* inv) { return &inv->slots[inv->selected]; }
int WeaponInv_GetHeldClass(E3Inv437* inv) {
    if (inv->selected != 6) {
        return WeaponDb_Get(g_WeaponDatabase, GetSel(inv)->id)->unkF0;
    }
    return 11;
}
#undef WeaponDb_Get /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001437A0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001437A0 */

/* merge_units: begin func_001437E0 */
#pragma push /* merge_units */
typedef struct { int a; int id; int c; int d; } E_INV_001437E0;
typedef struct { int pad; E_INV_001437E0 e[7]; char pad2[0x84 - 0x74]; unsigned char cur; char pad3[3]; void* owner; char pad4[0xA8 - 0x8C]; unsigned char lock; } INV_001437E0;
#if 0 /* merge_units */
extern void* WeaponDb_Get(void* db, int id);
#endif /* merge_units */
#define WeaponDb_Get(a0, a1) ((void *)WeaponDb_Get((a0), (a1))) /* merge_units */

void* WeaponInv_GetHeldItem(INV_001437E0* self)
{
    return self->cur != 6 ? WeaponDb_Get(g_WeaponDatabase, *(int*)((char*)self + self->cur * 16 + 8)) : 0;
}
#undef WeaponDb_Get /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001437E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001437E0 */

/* merge_units: begin func_00143820 */
#pragma push /* merge_units */
typedef struct { char pad[0x78]; unsigned char x78; } WD_3820;
#if 0 /* merge_units */
extern WD_3820* WeaponDb_Get(void* db, int id);
#endif /* merge_units */
#define WeaponDb_Get(a0, a1) ((WD_3820 *)WeaponDb_Get((a0), (a1))) /* merge_units */

int WeaponInv_IsFullAuto(INV* self)
{
    return self->cur != 6 ? WeaponDb_Get(g_WeaponDatabase, *(int*)((char*)self + self->cur * 16 + 8))->x78 == 1 : 0;
}
#undef WeaponDb_Get /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00143820(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00143820 */

/* merge_units: begin func_00143870 */
#pragma push /* merge_units */
typedef struct { int a; int b; int c; int d; } E3870;
typedef struct { char pad[0x10]; int base; int pad14; int id; int pad1c; int extra; char pad2[0x84-0x24]; char cur; } S3870;
int WeaponInv_GetSpare(S3870* self, char slot)
{
    int r;
    if ((unsigned char)slot == 6)
        slot = self->cur;
    if ((unsigned char)slot != 6) {
        r = *(int*)((char*)self + (unsigned char)slot * 16 + 0x10);
        if ((unsigned char)slot == 0 && self->id != -1)
            r += self->extra;
        return r;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00143870(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00143870 */

/* merge_units: begin func_001438E0 */
#pragma push /* merge_units */
typedef struct { char pad[0x70]; int x70; } WD_38E0;
#if 0 /* merge_units */
extern WD_38E0* WeaponDb_Get(void* db, int id);
#endif /* merge_units */
#define WeaponDb_Get(a0, a1) ((WD_38E0 *)WeaponDb_Get((a0), (a1))) /* merge_units */

int WeaponInv_GetClipSize(INV* self, char slot)
{
    if ((unsigned char)slot == 6)
        slot = self->cur;
    if ((unsigned char)slot != 6)
        return WeaponDb_Get(g_WeaponDatabase, *(int*)((char*)self + (unsigned char)slot * 16 + 8))->x70;
    return 0;
}
#undef WeaponDb_Get /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001438E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001438E0 */

/* merge_units: begin func_00143940 */
#pragma push /* merge_units */
typedef struct { char pad[0x10]; int base; int pad14; int id; int extra; int pad20; char pad2[0x84-0x24]; char cur; } S3870_00143940;
int WeaponInv_GetClip(S3870_00143940* self, char slot)
{
    int r;
    if ((unsigned char)slot == 6)
        slot = self->cur;
    if ((unsigned char)slot != 6) {
        r = *(int*)((char*)self + (unsigned char)slot * 16 + 0xC);
        if ((unsigned char)slot == 0 && self->id != -1)
            r += self->extra;
        return r;
    }
    return 0;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00143940(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00143940 */

/* merge_units: begin func_001439B0 */
#pragma push /* merge_units */
typedef struct { int pad0; int pad4; int id; int padC; } Slot_39B0;
typedef struct { Slot_39B0 slots[6]; } S_39B0;
int WeaponInv_CanChangeMode(S_39B0* self);
void WeaponInv_HolsterCurrent(S_39B0* self);
int WeaponInv_SlotOfItem(int id);
void WeaponInv_Equip(S_39B0* self, int slot);
unsigned char WeaponInv_EquipItem(S_39B0* self, int id)
{
    unsigned char r = 0;
    if (WeaponInv_CanChangeMode(self)) {
        if (id == -1) {
            WeaponInv_HolsterCurrent(self);
            r = 1;
        } else {
            int slot = WeaponInv_SlotOfItem(id);
            int* p = (int*)((char*)&self->slots[0].id + ((unsigned char)slot << 4));
            if (id == *p) {
                WeaponInv_Equip(self, slot);
                r = (id == *p);
            }
        }
    }
    return r;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001439B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001439B0 */
