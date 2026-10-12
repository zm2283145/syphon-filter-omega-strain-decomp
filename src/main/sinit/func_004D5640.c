#include "types.h"
extern char D_00542998[];
extern char D_005429B0[];
extern void __register_global_object();
extern void func_003AB3E0();
void func_004D5640(void)
{
    *(int*)D_005429B0 = 0;
    __register_global_object((int)D_005429B0, (int)func_003AB3E0, (int)D_00542998);
}
