#include "types.h"
extern char D_00542998[];
extern char D_005429B0[];
extern void __register_global_object();
extern void cSkeletonData_dtor();
void StaticInit_skeleton(void)
{
    *(int*)D_005429B0 = 0;
    __register_global_object((int)D_005429B0, (int)cSkeletonData_dtor, (int)D_00542998);
}
