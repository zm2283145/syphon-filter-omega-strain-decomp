#include "types.h"
typedef struct { char pad[0x4C]; int classKey; char pad50[0x3524 - 0x50]; void* weapons; } G_185550;
typedef union { int i; unsigned char b; } A_185550;
extern int D_0049D010;
extern G_185550* GObj_IdentityB(int handle);
extern void Global_SetHardpointVis(void* w, unsigned char hp, unsigned char vis);
int Script_SetHardpointVis(A_185550* args)
{
    unsigned char vis = args[2].i != 0;
    unsigned char hp = args[1].b;
    G_185550* g = GObj_IdentityB(args[0].i);
    if (g && g->classKey == D_0049D010) Global_SetHardpointVis(g->weapons, hp, vis);
    return 0;
}
