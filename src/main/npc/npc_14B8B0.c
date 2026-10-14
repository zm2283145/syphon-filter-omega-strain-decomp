/*
 * main/npc: range (5 files, 0014B8B0-0014BCB0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_0014B8B0 */
#pragma push /* merge_units */
#pragma cplusplus on
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
static inline void UM(void* m) { void* p = m; int t; asm { sqc2 vf0, 0x30(p); qmfc2.ni t, vf0; pcpyud t, t, zero; sq t, 0x10(p); pexcw t, t; sq t, 0x20(p); pcpyud t, t, zero; sq t, 0(p) } }
typedef struct { float m[4][4]; } __attribute__((aligned(16))) Mtx;
#pragma opt_common_subs off
#pragma opt_rebuildconditionals off
extern "C" {
int Actor_IsArmed(void*);
int Backpack_Construct(void*, int, int);
int Inventory_HasAnyItem(int);
int Random_Next(void);
int WeaponInv_GetClipSize(int, int);
void WeaponInv_MoveItemsToBackpack(int, int);

void cNPC_v6B(char* self) {
    char* a = F_(self, 0x30, char*);
    int inv = F_(a, 0x3524, int);
    if (Inventory_HasAnyItem(inv)) {
        Mtx m;
        UM(&m);
        WeaponInv_MoveItemsToBackpack(inv, Backpack_Construct(a, 0, 0));
    }
    a = F_(self, 0x30, char*);
    if (Actor_IsArmed(a)) {
        int w = F_(a, 0x3524, int);
        F_(self, 0xA4, int) = (F_(F_(self, 0x30, char*), 0xC, unsigned short) & 7) + 3;
        if (Random_Next() & 1) {
            F_(self, 0xA4, int)++;
        }
        int c = F_(self, 0xA4, int);
        if (WeaponInv_GetClipSize(w, 6) < c) {
            int n = WeaponInv_GetClipSize(w, 6) / 2;
            F_(self, 0xA4, int) = (n <= 0) ? 1 : n;
        }
    } else {
        F_(self, 0xA4, int) = 0;
    }
    F_(self, 0xA8, int) = 0;
}
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B8B0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B8B0 */

/* merge_units: begin func_0014B9E0 */
#pragma push /* merge_units */
typedef struct { char pad[0xC]; int seed; char pad2[0x3524 - 0x10]; void* inv; } Ctl_NPCW;
typedef struct { char pad[0x30]; Ctl_NPCW* ctl; char pad2[0xA4 - 0x34]; int burst; int burstCount; } NPC_W;
#if 0 /* merge_units */
extern int Actor_IsArmed(Ctl_NPCW* c);
#endif /* merge_units */
#define Actor_IsArmed(a0) (Actor_IsArmed((void *)(a0))) /* merge_units */

extern int Random_Next(void);
#if 0 /* merge_units */
extern int WeaponInv_GetClipSize(void* inv, int slot);
#endif /* merge_units */
#define WeaponInv_GetClipSize(a0, a1) (WeaponInv_GetClipSize((int)(a0), (a1))) /* merge_units */

static inline void ResetBurst(NPC_W* self)
{
    Ctl_NPCW* c = self->ctl;
    if (Actor_IsArmed(c)) {
        void* inv = c->inv;
        self->burst = (self->ctl->seed & 7) + 3;
        if (Random_Next() & 1)
            self->burst++;
        if (self->burst > WeaponInv_GetClipSize(inv, 6)) {
            int h = WeaponInv_GetClipSize(inv, 6) / 2;
            if (h <= 0)
                h = 1;
            self->burst = h;
        }
    } else {
        self->burst = 0;
    }
    self->burstCount = 0;
}typedef struct { char pad[0x84]; unsigned char cur; } Inv_B9E0;
extern void WeaponInv_Cycle(Inv_B9E0* inv, int wrap);
void cNPC_v6A(NPC_W* self)
{
    Inv_B9E0* inv = (Inv_B9E0*)self->ctl->inv;
    WeaponInv_Cycle(inv, 1);
    if (inv->cur == 6)
        WeaponInv_Cycle(inv, 1);
    ResetBurst(self);
}
#undef Actor_IsArmed /* merge_units */
#undef WeaponInv_GetClipSize /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014B9E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014B9E0 */

/* merge_units: begin func_0014BAE0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int Actor_IsArmed(Ctl_NPCW* c);
#endif /* merge_units */
#define Actor_IsArmed(a0) (Actor_IsArmed((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int WeaponInv_GetClipSize(void* inv, int slot);
#endif /* merge_units */
#define WeaponInv_GetClipSize(a0, a1) (WeaponInv_GetClipSize((int)(a0), (a1))) /* merge_units */
extern void WeaponInv_EquipItem(void* inv, int w);
extern void WeaponInv_EquipFirst(void* inv);
void cNPC_v69(NPC_W* self, int w)
{
    Ctl_NPCW* c = self->ctl;
    if (w >= 0)
        WeaponInv_EquipItem(c->inv, w);
    else
        WeaponInv_EquipFirst(c->inv);
    ResetBurst(self);
}
#undef Actor_IsArmed /* merge_units */
#undef WeaponInv_GetClipSize /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014BAE0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014BAE0 */

/* merge_units: begin func_0014BBD0 */
#pragma push /* merge_units */
#if 0 /* merge_units */
extern int Actor_IsArmed(Ctl_NPCW* c);
#endif /* merge_units */
#define Actor_IsArmed(a0) (Actor_IsArmed((void *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern int WeaponInv_GetClipSize(void* inv, int slot);
#endif /* merge_units */
#define WeaponInv_GetClipSize(a0, a1) (WeaponInv_GetClipSize((int)(a0), (a1))) /* merge_units */
extern void WeaponInv_HolsterCurrent(void* inv);
void cNPC_v68(NPC_W* self)
{
    WeaponInv_HolsterCurrent(self->ctl->inv);
    ResetBurst(self);
}
#undef Actor_IsArmed /* merge_units */
#undef WeaponInv_GetClipSize /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014BBD0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014BBD0 */

/* merge_units: begin func_0014BCB0 */
#pragma push /* merge_units */
typedef struct { int a0; int a4; int id; int ac; } Slot_BCB0;
typedef struct { Slot_BCB0 s[8]; char pad[4]; unsigned char cur; } Inv_BCB0;
typedef struct { char pad[0x3524]; Inv_BCB0* inv; } Ctl_BCB0;
typedef struct { char pad[0x30]; Ctl_BCB0* ctl; } NPC_BCB0;
int cNPC_GetActiveWeapon(NPC_BCB0* self) { Inv_BCB0* inv = self->ctl->inv; if (inv->cur != 6) return inv->s[inv->cur].id; return -1; }
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_0014BCB0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_0014BCB0 */
