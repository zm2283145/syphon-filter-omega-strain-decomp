#include "types.h"
typedef struct { char pad[0x4C]; int classKey; char pad50[0x3524 - 0x50]; void* inv; } Hum_5BF0;
typedef struct { char pad[0x30]; Hum_5BF0* hum; } Obj_5BF0;
typedef struct { Obj_5BF0* obj; int id; } Arg_5BF0;
typedef struct { char pad[0x13C]; int ok; } Wdb_5BF0;
Wdb_5BF0* WeaponDb_Get(int, int);
int WeaponInv_Add(void*, int, int, int, int, int);
extern int D_0049D010;
extern int D_004FFD30;
/* script: give the player a weapon when the weapon database entry is valid;
 * the id is staged through a stack slot (volatile) */
#pragma push
int Script_cPlayer_AddWeapon(Arg_5BF0* args)
{
    volatile int w[1];
    Hum_5BF0* h;
    int id;
    w[0] = args->id;
    h = args->obj->hum;
    id = w[0];
    if (h && h->classKey == D_0049D010 && WeaponDb_Get(D_004FFD30, id)->ok)
        WeaponInv_Add(h->inv, id, 1, 1, 0, 0);
    return 0;
}
#pragma pop
