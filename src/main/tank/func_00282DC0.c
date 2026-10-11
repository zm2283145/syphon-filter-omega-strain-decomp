#include "types.h"
typedef struct { char pad[0x68]; int weapon; int weaponId; } Ang2DC0;
typedef struct { char pad[0x6C]; Ang2DC0* angles; } Tank2DC0;
typedef union { int i; Tank2DC0* p; } Arg2DC0;
extern int D_004FFD30;
extern int WeaponDb_Get(int db, int id);
int Script_cTank_SetWeapon(Arg2DC0* args) {
    volatile int id = args[1].i;
    Ang2DC0* a = args[0].p->angles;
    int i = id;
    if (a) {
        int db = D_004FFD30;
        a->weaponId = i;
        a->weapon = WeaponDb_Get(db, i);
    }
    return 0;
}