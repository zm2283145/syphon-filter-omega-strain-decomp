#include "types.h"
#pragma global_optimizer off
typedef struct { int a0; int a4; int id; int ac; } Slot_P;
typedef struct { Slot_P s[8]; char pad[4]; unsigned char cur; } Inv_P;
typedef struct { char pad[0x4C]; int kind; char pad2[0x3524 - 0x50]; Inv_P* inv; } Plr_P;
typedef struct { char pad[0x30]; Plr_P* ctl; } GObj_P;
typedef struct { char pad[0x6A4]; Plr_P* player; } Game_P;
extern Game_P* D_004FFC2C;
extern int D_0049D010;
static inline Plr_P* AsPlayer(GObj_P* o) { Plr_P* p = o->ctl; if (p && p->kind == D_0049D010) return p; return 0; }
static inline int ActiveId(Inv_P* inv) { unsigned char c = inv->cur; if (c != 6) return inv->s[c].id; return -1; }
static inline int GetW(GObj_P* o)
{
    int r = -1;
    Plr_P* p = o->ctl;
    if (p && p->kind == D_0049D010)
        r = ActiveId(p->inv);
    return r;
}
int Script_cPlayer_GetActiveWeapon(GObj_P** args)
{
    int r[1];
    r[0] = GetW(args[0]);
    return *(int*)r;
}
