#include "types.h"
typedef struct { char pad[0x4C]; int kind; char pad2[0x33B4 - 0x50]; int bodies; } Plr_5400;
extern Plr_5400* PlayerSlots_Get(int i);
extern int D_0049D010;
int Script_SetPlayerBodies(int* args)
{
    unsigned char f = ((unsigned char)(args[0] != 0) != 0) ^ 1;
    int i;
    for (i = 0; i < 4; i++) {
        Plr_5400* p = PlayerSlots_Get(i);
        if (p && p->kind == D_0049D010)
            p->bodies = f;
    }
    return 0;
}