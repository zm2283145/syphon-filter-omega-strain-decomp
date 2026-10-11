#include "types.h"
#pragma global_optimizer off
typedef struct { char pad[0x6A4]; void* player; } Game_P;
extern Game_P* D_004FFC2C;
extern void cPlayer_SetMenuTitle(void* p, int v);
static inline void Call_00175DA0(int v)
{
    void* p = D_004FFC2C->player;
    if (p)
        cPlayer_SetMenuTitle(p, v);
}
int Script_cPlayer_SetMenuTitle(int* args)
{
    int v[1];
    v[0] = args[1];
    Call_00175DA0(*(int*)v);
    return 0;
}
