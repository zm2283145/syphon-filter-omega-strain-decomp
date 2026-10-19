#include "types.h"
typedef struct { int a0; int a4; int id; int ac; } Slot_P;
typedef struct { Slot_P s[8]; } Inv_P;
typedef struct { char pad[0x4C]; int kind; char pad2[0x3524 - 0x50]; Inv_P* inv; } Plr_P;
typedef struct { char pad[0x30]; Plr_P* ctl; } GObj_P;
typedef struct { GObj_P* o; unsigned char slot; } Args_5B60;
extern int g_HumanActorClassKey;
extern void Player_RemoveWeapon(GObj_P* o, int id, Plr_P* p);
int Script_cPlayer_RemoveWeaponFromSlot(Args_5B60* args)
{
    unsigned char slot = args->slot;
    GObj_P* o = args->o;
    Plr_P* p = o->ctl;
    if (p && p->kind == g_HumanActorClassKey)
        Player_RemoveWeapon(o, p->inv->s[slot].id, p);
    return 0;
}