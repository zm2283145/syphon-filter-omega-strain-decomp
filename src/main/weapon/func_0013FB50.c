#include "types.h"
extern int WeaponDb_Get(int db, int id);
extern int D_004FFD30;
typedef struct { char pad[0x68]; int weapon; } S_FB50;
int WeaponInv_GetSlot6Record(S_FB50* p)
{
    int r;
    int id = p->weapon;
    if (id != -1) { r = WeaponDb_Get(D_004FFD30, id); asm { .set reorder } /* empty-asm barrier: keeps the call arm's b; nop */ } else r = 0;
    return r;
}
