#include "types.h"
extern char D_00542DA8[];
extern char D_00542DC0[];
extern void __register_global_object();
extern void cBBoxMan_dtor();
extern void memset();
#pragma opt_common_subs off
void StaticInit_bboxman(void)
{
    memset((int)D_00542DC0, 0, 2012);
    __register_global_object((int)D_00542DC0, (int)cBBoxMan_dtor, (int)D_00542DA8);
}
