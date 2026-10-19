#pragma cplusplus on
#include "types.h"
typedef struct { unsigned char flag; char p[3]; int id; int c; int ammo; } E_INV;
typedef struct {
    int pad0; char pad4[0x14]; int x18; char pad1C[0x68];
    unsigned char cur; char pad85[0x1B]; unsigned char busy; char padA1[0x1B]; int xBC; int xC0;
} INV;
typedef struct { char pad[0x70]; int x70; char pad74[4]; unsigned char x78; char pad79[0x93]; int x10C; } WD;
extern "C" void* g_WeaponDatabase;
extern "C" WD* WeaponDb_Get(void* db, int id);
extern "C" int WeaponInv_GetClip(INV* s, int slot);
extern "C" int WeaponInv_HasSpareOfAmmoType(INV* s, int x);

extern "C" bool WeaponInv_AllowsAction(INV* s)
{
    bool ret = false;
    if (s->cur != 6 && !s->busy && !s->xBC && !s->xC0) {
        int id = *(int*)((char*)s + s->cur * 16 + 8);
        if (id != -1) {
            WD* wd = WeaponDb_Get(g_WeaponDatabase, id);
            int clip = WeaponInv_GetClip(s, 6);
            bool half = !(s->x18 == -1) && s->cur == 0;
            if (half) clip /= 2;
            ret = wd->x78 != 2 && clip < wd->x70 && WeaponInv_HasSpareOfAmmoType(s, wd->x10C);
        }
    }
    return ret;
}

