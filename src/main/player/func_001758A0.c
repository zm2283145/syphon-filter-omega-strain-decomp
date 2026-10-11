#include "types.h"
#pragma global_optimizer off
typedef struct { char pad[0x4C]; int kind; char pad2[0x3528 - 0x50]; void* inv; } Obj_P;
extern Obj_P* GObj_IdentityB(void* o);
extern int D_0049D010;
extern void Global_PlayerRemoveItem(void* inv, int a, int b);
static inline void Do_001758A0(int b, int a, void* o)
{
    Obj_P* p = GObj_IdentityB(o);
    if (p->kind == D_0049D010)
        Global_PlayerRemoveItem(p->inv, a, b);
}
int Script_PlayerRemoveItem(int* args)
{
    int b[1];
    int a[1];
    b[0] = args[2];
    a[0] = args[1];
    Do_001758A0(*(int*)b, *(int*)a, (void*)args[0]);
    return 0;
}
