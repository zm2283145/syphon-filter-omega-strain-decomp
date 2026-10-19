#include "types.h"
typedef struct { char pad[0x2F0]; unsigned char b2f0; } P255;
extern int g_WeaponDatabase;
extern int g_Hud;
extern char D_004A7B18[];
extern int Backpack_ListItems(P255*, int*, int, int);
extern void Backpack_QueryAmmo(P255*, int, int*, int*, int*);
extern char* WeaponDb_Get(int, int);
extern int WeaponInv_AddAmmo(int, char*, int);
extern char* Loc_LookupText(char*);
extern void Backpack_RemoveAmmo(P255*, int, int);
extern int sprintf(char*, const char*, ...);
extern void Hud_PostNotification(int, char*);
unsigned char Backpack_PickupAmmo(P255* p, int arg) {
    int x[1];
    int y[1];
    int z[1];
    int ids[10];
    char buf[0x80];
    unsigned char any = 0;
    if (p->b2f0) {
        int db = g_WeaponDatabase;
        int n = Backpack_ListItems(p, ids, arg, 10);
        int i;
        for (i = 0; i < n; i++) {
            char* w;
            int amt;
            Backpack_QueryAmmo(p, ids[i], x, y, z);
            w = WeaponDb_Get(db, ids[i]);
            amt = WeaponInv_AddAmmo(arg, w, z[0]);
            if (amt) {
                char* nm = Loc_LookupText(w + 0x80);
                Backpack_RemoveAmmo(p, ids[i], amt);
                sprintf(buf, D_004A7B18, nm, Loc_LookupText("PickupAmmo"));
                Hud_PostNotification(g_Hud, buf);
                any = 1;
            }
        }
    }
    return any;
}
