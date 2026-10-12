#include "types.h"
extern char D_004BAF80[];
extern void func_00354490();
static void* D_004DF000[] = { 0, 0, (void*)func_00354490 };
extern char D_00533548[];
extern char D_00533550[];
extern void FreeList_Push();
void func_004D4CB0(void)
{
    *(int*)D_00533550 = (int)D_004DF000;
    *(int*)D_00533548 = (int)D_004BAF80;
    FreeList_Push((int)D_00533548);
}
