#include "types.h"
extern char D_00543780[];
extern char D_00543790[];
extern void __register_global_object();
extern void func_003D5970();
extern void func_003D5B90();
#pragma opt_common_subs off
void func_004D5E00(void)
{
    func_003D5B90((int)D_00543790);
    __register_global_object((int)D_00543790, (int)func_003D5970, (int)D_00543780);
}
