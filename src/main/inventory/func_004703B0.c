#include "types.h"
typedef struct { char p[8]; char m8[0x20]; char m28[4]; } E4703B0;
extern void* D_004FFD30;
extern int D_00587FF4;
extern E4703B0* D_00587FF8;
extern void WeaponDb_LoadModel(void* m, void* a, void* b, int c, int d, int e, int f);
#pragma push
#pragma opt_strength_reduction off
void func_004703B0(void)
{
    void* m = D_004FFD30;
    int i;
    for (i = 0; i < D_00587FF4; i++) WeaponDb_LoadModel(m, D_00587FF8[i].m8, D_00587FF8[i].m28, -1, 0, 0, 0);
}
#pragma pop
