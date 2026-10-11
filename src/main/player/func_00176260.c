#include "types.h"
#pragma global_optimizer off
typedef struct { int a0; int a4; int id; int ac; } Slot_P;
typedef struct { Slot_P s[8]; char pad[4]; unsigned char cur; } Inv_P;
typedef struct { char pad[0x4C]; int kind; char pad2[0x3524 - 0x50]; Inv_P* inv; } Plr_P;
typedef struct { char pad[0x30]; Plr_P* ctl; } GObj_P;
typedef struct { char pad[0x6A4]; Plr_P* player; } Game_P;
extern Game_P* D_004FFC2C;
extern int D_0049D010;
static inline Plr_P* AsPlayer(GObj_P* o) { Plr_P* p = o->ctl; return (p && p->kind == D_0049D010) ? p : 0; }
extern void cPlayer_LaunchChooseMenu(Plr_P* pl, Plr_P* who);
void func_00176260(GObj_P* o)
{
    Plr_P* pl = D_004FFC2C->player;
    if (pl)
        cPlayer_LaunchChooseMenu(pl, AsPlayer(o));
}