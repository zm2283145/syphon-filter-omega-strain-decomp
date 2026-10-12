#include "types.h"
typedef struct { char pad[0x2F0]; unsigned char b2f0; } P255;
extern int D_004FFD30;
extern int D_004FFC2C;
extern char D_004A7B18[];
extern int func_002553E0(P255*, int*, int, int);
extern void func_00255500(P255*, int, int*, int*, int*);
extern char* WeaponDb_Get(int, int);
extern int func_00142830(int, char*, int);
extern char* Loc_LookupText(char*);
extern void func_00255650(P255*, int, int);
extern int sprintf(char*, const char*, ...);
extern void Hud_PostNotification(int, char*);
unsigned char func_00255290(P255* p, int arg) {
    int x[1];
    int y[1];
    int z[1];
    int ids[10];
    char buf[0x80];
    unsigned char any = 0;
    if (p->b2f0) {
        int db = D_004FFD30;
        int n = func_002553E0(p, ids, arg, 10);
        int i;
        for (i = 0; i < n; i++) {
            char* w;
            int amt;
            func_00255500(p, ids[i], x, y, z);
            w = WeaponDb_Get(db, ids[i]);
            amt = func_00142830(arg, w, z[0]);
            if (amt) {
                char* nm = Loc_LookupText(w + 0x80);
                func_00255650(p, ids[i], amt);
                sprintf(buf, D_004A7B18, nm, Loc_LookupText("PickupAmmo"));
                Hud_PostNotification(D_004FFC2C, buf);
                any = 1;
            }
        }
    }
    return any;
}
