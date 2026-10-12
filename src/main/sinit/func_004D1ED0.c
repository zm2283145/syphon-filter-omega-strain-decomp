#include "types.h"
extern char D_004FFB38[];
extern char D_004FFB50[];
extern void __register_global_object();
extern void func_00136DF0();
extern void func_00137AB0();
#pragma opt_common_subs off
void func_004D1ED0(void)
{
    func_00137AB0((int)D_004FFB50);
    __register_global_object((int)D_004FFB50, (int)func_00136DF0, (int)D_004FFB38);
}
