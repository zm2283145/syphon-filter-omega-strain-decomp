#include "types.h"
extern char D_00542DA8[];
extern char D_00542DC0[];
extern void __register_global_object();
extern void func_003C8BF0();
extern void memset();
#pragma opt_common_subs off
void func_004D5810(void)
{
    memset((int)D_00542DC0, 0, 2012);
    __register_global_object((int)D_00542DC0, (int)func_003C8BF0, (int)D_00542DA8);
}
