#include "types.h"
typedef struct { int pad0; int pad4; int id; int padC; } Slot_1855C0;
typedef struct { Slot_1855C0 s[8]; char pad80[4]; unsigned char cur; } W_1855C0;
typedef struct { char pad[0x4C]; int classKey; char pad50[0x3524 - 0x50]; W_1855C0* weapons; } G_1855C0;
extern int D_0049D010;
extern G_1855C0* GObj_IdentityB(int handle);
int Script_GetActiveWeapon(int* args)
{
    volatile int r;
    G_1855C0* g = GObj_IdentityB(args[0]);
    int v = -1;
    if (g && g->classKey == D_0049D010) {
        W_1855C0* w = g->weapons;
        v = (w->cur != 6) ? w->s[w->cur].id : -1;
    }
    r = v;
    return r;
}

