#include "types.h"
extern char D_0053BB60[];
extern char D_0053BB70[];
extern char D_0053BB80[];
extern char D_0053BB90[];
extern void ScalarCollection_Init();
extern void __register_global_object();
extern void func_003A6320();
extern void func_00409520();
extern void func_00409580();
#pragma opt_common_subs off
void func_004D55D0(void)
{
    ScalarCollection_Init((int)D_0053BB70);
    __register_global_object((int)D_0053BB70, (int)func_003A6320, (int)D_0053BB60);
    func_00409580((int)D_0053BB90);
    __register_global_object((int)D_0053BB90, (int)func_00409520, (int)D_0053BB80);
}
