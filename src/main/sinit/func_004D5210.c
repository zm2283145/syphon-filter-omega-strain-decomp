#include "types.h"
extern char D_00537F70[];
extern char D_00537F80[];
extern void __register_global_object();
extern void cDmaMan_dtor();
extern void memset();
#pragma opt_common_subs off
void StaticInit_dmaman(void)
{
    memset((int)D_00537F80, 0, 244);
    __register_global_object((int)D_00537F80, (int)cDmaMan_dtor, (int)D_00537F70);
}
