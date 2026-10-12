#include "types.h"
typedef struct { char pad[0x4C]; int team; } C3Ent175480;
extern C3Ent175480* PlayerSlots_Get(int i);
extern void Actor_SetInvulnerable(C3Ent175480* e, int on);
extern int D_0049D010;
int Script_SetPlayerInvulnerability(int* args)
{
    int on = args[0] != 0;
    int i;
    C3Ent175480* e;
    for (i = 0; i < 4; i++) {
        e = PlayerSlots_Get(i);
        if (e != 0 && e->team == D_0049D010) {
            Actor_SetInvulnerable(e, on);
        }
    }
    return 0;
}