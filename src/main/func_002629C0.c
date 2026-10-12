#include "types.h"
extern int D_004F8354;
extern void** D_004F8358;
extern void func_00262A20(void* p);
#pragma push
#pragma opt_strength_reduction off
void func_002629C0(void)
{
    int i;
    for (i = 0; i < D_004F8354; i++) func_00262A20(D_004F8358[i]);
}
#pragma pop
