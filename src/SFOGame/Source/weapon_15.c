/*
 * SFOGame/Source/weapon: 2 files, 00143510-00143560
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00143510 */
#pragma push /* merge_units */
/*
 * Matched functions (byte-identical with the retail executable).
 * Actor inventory and weapon-definition helpers, cOutOfAmmoMsg.
 */

#include "types.h"
#include "weapon_types.h"

/* Equip mode of the selected weapon; 0 when holstered (slot 6). */
int cWeapon_GetPoseType(Inventory* inv) {
    int selected = inv->selected;
    int mode = 0;

    if (selected != 6) {
        InventorySlot* slot = &inv->slots[selected];

        mode = cWeaponDB_GetEntry(g_WeaponDatabase, slot->id)->equipMode;
    }
    return mode;
}
static inline void merge_flush_func_00143510(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00143510 */

/* merge_units: begin func_00143560 */
#pragma push /* merge_units */
#pragma cplusplus on
typedef struct { unsigned char flag; char p[3]; int id; int c; int ammo; } E_INV;
typedef struct {
    int pad0; char pad4[0x14]; int x18; char pad1C[0x68];
    unsigned char cur; char pad85[0x1B]; unsigned char busy; char padA1[0x1B]; int xBC; int xC0;
} INV;
typedef struct { char pad[0x70]; int x70; char pad74[4]; unsigned char x78; char pad79[0x93]; int x10C; } WD;
extern "C" void* g_WeaponDatabase;
#if 0 /* merge_units */
extern "C" WD* cWeaponDB_GetEntry(void* db, int id);
#endif /* merge_units */
#define cWeaponDB_GetEntry(a0, a1) ((WD *)cWeaponDB_GetEntry((a0), (a1))) /* merge_units */

extern "C" int cWeapon_GetClipAmmo(INV* s, int slot);
extern "C" int cWeapon_HasAmmoType(INV* s, int x);

extern "C" bool cWeapon_CanReload(INV* s)
{
    bool ret = false;
    if (s->cur != 6 && !s->busy && !s->xBC && !s->xC0) {
        int id = *(int*)((char*)s + s->cur * 16 + 8);
        if (id != -1) {
            WD* wd = cWeaponDB_GetEntry(g_WeaponDatabase, id);
            int clip = cWeapon_GetClipAmmo(s, 6);
            bool half = !(s->x18 == -1) && s->cur == 0;
            if (half) clip /= 2;
            ret = wd->x78 != 2 && clip < wd->x70 && cWeapon_HasAmmoType(s, wd->x10C);
        }
    }
    return ret;
}
#undef cWeaponDB_GetEntry /* merge_units */
static inline void merge_flush_func_00143560(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00143560 */
