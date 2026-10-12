#include "types.h"
extern char D_00537F70[];
extern char D_00537F80[];
extern void __register_global_object();
extern void func_00376200();
extern void memset();
#pragma opt_common_subs off
void func_004D5210(void)
{
    memset((int)D_00537F80, 0, 244);
    __register_global_object((int)D_00537F80, (int)func_00376200, (int)D_00537F70);
}
