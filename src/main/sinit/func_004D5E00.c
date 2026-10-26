#include "types.h"
extern char D_00543780[];
extern char D_00543790[];
extern void __register_global_object();
extern void cShadowMan_dtor();
extern void cShadowMan_ctor();
#pragma opt_common_subs off
void StaticInit_shadows(void)
{
    cShadowMan_ctor((int)D_00543790);
    __register_global_object((int)D_00543790, (int)cShadowMan_dtor, (int)D_00543780);
}
