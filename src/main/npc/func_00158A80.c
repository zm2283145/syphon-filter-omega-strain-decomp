#include "types.h"
typedef struct { char pad[0x14]; unsigned char used; char pad15[3]; } E_8A80;
extern E_8A80 D_004EA1D0[16];
extern int D_004EA350;
extern int D_004EA358;
extern int D_004EA380;
extern float WorthShootingThreshold;
int func_0042B1A0(int a);
void NpcAi_ResetFireProgress(void)
{
    int i;
    D_004EA358 = 0;
    D_004EA350 = 4;
    WorthShootingThreshold = 0.5f;
    for (i = 0; i < 16; i++)
        D_004EA1D0[i].used = 0;
    D_004EA380 = func_0042B1A0(1);
}