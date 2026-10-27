#include "types.h"
typedef struct { char pad[0x2F0]; unsigned char b2f0; } P255;
extern int g_WeaponDatabase;
extern int g_Hud;
extern char D_004A7B18[];
extern int cBackpack_GetWeaponDbs(P255*, int*, int, int);
extern void cBackpack_GetAmmoCounts(P255*, int, int*, int*, int*);
extern char* cWeaponDB_GetEntry(int, int);
extern int cWeapon_PickupAmmo_tWDBDataP_int(int, char*, int);
extern char* nGlobalization_GetString_charP(char*);
extern void cBackpack_TakeAmmo(P255*, int, int);
extern int sprintf(char*, const char*, ...);
extern void cHud_Message(int, char*);
unsigned char cBackpack_AutoTakeAmmo(P255* p, int arg) {
    int x[1];
    int y[1];
    int z[1];
    int ids[10];
    char buf[0x80];
    unsigned char any = 0;
    if (p->b2f0) {
        int db = g_WeaponDatabase;
        int n = cBackpack_GetWeaponDbs(p, ids, arg, 10);
        int i;
        for (i = 0; i < n; i++) {
            char* w;
            int amt;
            cBackpack_GetAmmoCounts(p, ids[i], x, y, z);
            w = cWeaponDB_GetEntry(db, ids[i]);
            amt = cWeapon_PickupAmmo_tWDBDataP_int(arg, w, z[0]);
            if (amt) {
                char* nm = nGlobalization_GetString_charP(w + 0x80);
                cBackpack_TakeAmmo(p, ids[i], amt);
                sprintf(buf, D_004A7B18, nm, nGlobalization_GetString_charP("PickupAmmo"));
                cHud_Message(g_Hud, buf);
                any = 1;
            }
        }
    }
    return any;
}
