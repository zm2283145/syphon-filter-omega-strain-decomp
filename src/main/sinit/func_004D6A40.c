#include "types.h"
extern char D_0055C5C0[];
extern char D_0055C5D0[];
extern void __register_global_object();
extern void func_0036D5D0();
extern void func_0036D630();
#pragma opt_common_subs off
void func_004D6A40(void)
{
    func_0036D630((int)D_0055C5D0);
    __register_global_object((int)D_0055C5D0, (int)func_0036D5D0, (int)D_0055C5C0);
}
