#include "types.h"
typedef struct { char pad[0x6A4]; void* player; } Game_P;
extern Game_P* D_004FFC2C;
extern void cPlayer_SetMenuTitle(void* p, int v);
void func_00176220(int unused, int v)
{
    void* p = D_004FFC2C->player;
    if (p)
        cPlayer_SetMenuTitle(p, v);
}
