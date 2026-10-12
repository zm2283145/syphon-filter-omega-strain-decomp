#include "types.h"
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
int Hud_PostNotification(int, char *);
int Loc_LookupText(char *);
char *WeaponDb_Get(int, int);
int sprintf(char *, char *, int, int);
extern char D_0049B1B8;
extern char D_0049B1C0;
extern int D_004FFC2C;
extern int D_004FFD30;
typedef struct { int f0; int id; int f8; int ammo; } Slot13F;
typedef struct { int f0; Slot13F s[6]; char p64[0x20]; unsigned char f84; char p85[3]; char *f88; } PS0_0013FD20;
int Weapon_TransferSpareRounds(PS0_0013FD20 *arg0, int arg1, int arg2) {
int total;
int i;
Slot13F *s;
char *w;
char buf[128];

    total = 0;
    for (i = 0; i < 6; i++) {
        if (i == arg0->f84) continue;
        s = &arg0->s[i];
        if (s->id == -1) continue;
        w = WeaponDb_Get(D_004FFD30, s->id);
        if (F_(w, 0x10C, int) != arg2) continue;
        if (F_(w, 0xF0, unsigned char) != 0) continue;
        if (s->ammo <= 0) continue;
        if (arg0->f88 != NULL && F_(arg0->f88, 0x14, unsigned char) != 0) {
            int t = Loc_LookupText(w + 0x80);
            sprintf(buf, &D_0049B1B8, t, Loc_LookupText(&D_0049B1C0));
            Hud_PostNotification(D_004FFC2C, buf);
        }
        { int a = s->ammo; if (arg1 < a) { total += arg1; s->ammo = a - arg1; break; } s->ammo = 0; arg1 -= a; total += a; }
    }
    return total;
}