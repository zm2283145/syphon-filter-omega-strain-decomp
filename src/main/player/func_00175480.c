#include "types.h"
typedef struct { char pad[0x4C]; int team; } C3Ent175480;
extern C3Ent175480* func_003FB8D0(int i);
extern void func_001B8750(C3Ent175480* e, int on);
extern int D_0049D010;
int Script_SetPlayerInvulnerability(int* args)
{
    int on = args[0] != 0;
    int i;
    C3Ent175480* e;
    for (i = 0; i < 4; i++) {
        e = func_003FB8D0(i);
        if (e != 0 && e->team == D_0049D010) {
            func_001B8750(e, on);
        }
    }
    return 0;
}