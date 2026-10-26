#include "types.h"
extern char D_0055C5C0[];
extern char D_0055C5D0[];
extern void __register_global_object();
extern void cHogFile_dtor();
extern void cHogFile_ctor();
#pragma opt_common_subs off
void StaticInit_MoviePlayer(void)
{
    cHogFile_ctor((int)D_0055C5D0);
    __register_global_object((int)D_0055C5D0, (int)cHogFile_dtor, (int)D_0055C5C0);
}
