/*
 * main/weapon: range (4 files, 00142140-001423E0)
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* headers shared by the blocks below */
#include "types.h"

/* merge_units: begin func_00142140 */
#pragma push /* merge_units */
extern void HeldItem_Reset(int);

void func_00142140(int a0) {
    int cond;

    a0 = *(int*)(char*)a0;
    cond = a0 == 0;
    if (cond) goto L00142160;
    HeldItem_Reset(a0);
L00142160:;
    goto ret;
ret:;
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00142140(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00142140 */

/* merge_units: begin func_00142170 */
#pragma push /* merge_units */
typedef struct {
    int a;
    int id;
    int ammo;
    int extra;
} Slot_142170;
typedef struct {
    int pad0;
    Slot_142170 slots[6];
    char pad64[0x24];
    int actor;
} Inv_142170;
typedef struct {
    char pad0[0x70];
    int clip;
    int f74;
    char pad78[0x78];
    unsigned char fF0;
} Wpn_142170;
extern int g_WeaponDatabase;
extern float MaxNpcAmmoPct;
extern float D_00489C20;
Wpn_142170* WeaponDb_Get(int, int);
int WeaponInv_ClipsForActor(int, int);
int Random_Next(void);
static inline float frand(void) { return Random_Next() / 2147483648.0f; }

void WeaponInv_RandomizeDroppedAmmo(Inv_142170* inv)
{
    int i;
    for (i = 0; i < 6; i++) {
        Slot_142170* s = &inv->slots[i];
        if (s->id != -1) {
            Wpn_142170* w = WeaponDb_Get(g_WeaponDatabase, s->id);
            int total = w->clip * WeaponInv_ClipsForActor(inv->actor, w->f74);
            float pct;
            int n;
            pct = frand();
            pct *= D_00489C20 - MaxNpcAmmoPct;
            pct += MaxNpcAmmoPct;
            if (total < 10) pct *= 2.0f;
            n = (int)(total * pct);
            if (w->fF0 == 1) {
                s->extra = n;
                s->ammo = 0;
            } else {
                if (w->clip < n) {
                    s->extra = n - w->clip;
                    n -= s->extra;
                } else {
                    s->extra = 0;
                }
                s->ammo = n;
                if (s->extra > 0) {
                    int r = (int)(w->clip * (frand()));
                    s->ammo -= r;
                    s->extra += r;
                }
            }
        }
    }
}
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00142170(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00142170 */

/* merge_units: begin func_00142320 */
#pragma push /* merge_units */
typedef struct { int a; int id; int c; int d; } E_INV;
typedef struct { int pad; E_INV e[7]; char pad2[0x84 - 0x74]; unsigned char cur; char pad3[3]; void* owner; char pad4[0xA8 - 0x8C]; unsigned char lock; } INV;
typedef struct { char pad[0xA8]; unsigned char xA8; } WDef_2320;
#if 0 /* merge_units */
extern void* g_WeaponDatabase;
#endif /* merge_units */
#define g_WeaponDatabase (*(void **)&g_WeaponDatabase) /* merge_units */

#if 0 /* merge_units */
extern WDef_2320* WeaponDb_Get(void* db, int id);
#endif /* merge_units */
#define WeaponDb_Get(a0, a1) ((WDef_2320 *)WeaponDb_Get((int)(a0), (a1))) /* merge_units */

extern void Backpack_AddWeapon(void* o, int id, int d, int c, int z);
extern void WeaponInv_RemoveSlot(INV* self, unsigned char slot, int a, int b, int c);
void WeaponInv_MoveItemsToBackpack(INV* self, void* o)
{
    int i;
    if (self->lock)
        return;
    for (i = 7; i >= 0; i--) {
        E_INV* e = (E_INV*)((char*)self + i * 16 + 4);
        if (e->id != -1 && WeaponDb_Get(g_WeaponDatabase, e->id)->xA8) {
            Backpack_AddWeapon(o, e->id, e->d, e->c, 0);
            WeaponInv_RemoveSlot(self, i, 0, 0, 0);
        }
    }
}
#undef g_WeaponDatabase /* merge_units */
#undef WeaponDb_Get /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_00142320(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_00142320 */

/* merge_units: begin func_001423E0 */
#pragma push /* merge_units */
typedef struct { int a0; int a4; int id; int ac; } S23E0;
#if 0 /* merge_units */
extern void WeaponInv_RemoveSlot(void* self, unsigned char slot, int a, int b, int c);
#endif /* merge_units */
#define WeaponInv_RemoveSlot(a0, a1, a2, a3, a4) (WeaponInv_RemoveSlot((void *)(a0), (a1), (a2), (a3), (a4))) /* merge_units */

void WeaponInv_ClearSlots(S23E0* self)
{
    int i;
    S23E0* p;
    i = 0;
    p = self;
    do {
        if (p->id != -1)
            WeaponInv_RemoveSlot(self, i, 0, 1, 0);
        i++;
        p++;
    } while (i < 6);
}
#undef WeaponInv_RemoveSlot /* merge_units */
/* merge_units: generate this block's code under its own pragmas */
static inline void merge_flush_func_001423E0(void) {}
#pragma pop /* merge_units */
/* merge_units: end func_001423E0 */
