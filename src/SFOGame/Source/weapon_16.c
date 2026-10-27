/*
 * SFOGame/Source/weapon: 1 file, 00143560
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00143560 */
#pragma push /* merge_units */
#pragma cplusplus on
#include "types.h"
typedef struct { unsigned char flag; char p[3]; int id; int c; int ammo; } E_INV;
typedef struct {
    int pad0; char pad4[0x14]; int x18; char pad1C[0x68];
    unsigned char cur; char pad85[0x1B]; unsigned char busy; char padA1[0x1B]; int xBC; int xC0;
} INV;
typedef struct { char pad[0x70]; int x70; char pad74[4]; unsigned char x78; char pad79[0x93]; int x10C; } WD;
extern "C" void* g_WeaponDatabase;
extern "C" WD* cWeaponDB_GetEntry(void* db, int id);
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
static inline void merge_flush_func_00143560(void) {} /* merge_units */
#pragma pop /* merge_units */
/* merge_units: end func_00143560 */
