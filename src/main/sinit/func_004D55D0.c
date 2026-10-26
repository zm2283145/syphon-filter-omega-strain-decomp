#include "types.h"
extern char D_0053BB60[];
extern char D_0053BB70[];
extern char D_0053BB80[];
extern char D_0053BB90[];
extern void ScalarCollection_Init();
extern void __register_global_object();
extern void cSkeletonDataBank_dtor();
extern void cMaterialPropertiesTable_dtor();
extern void cMaterialPropertiesTable_ctor();
#pragma opt_common_subs off
void StaticInit_sfoglobals(void)
{
    ScalarCollection_Init((int)D_0053BB70);
    __register_global_object((int)D_0053BB70, (int)cSkeletonDataBank_dtor, (int)D_0053BB60);
    cMaterialPropertiesTable_ctor((int)D_0053BB90);
    __register_global_object((int)D_0053BB90, (int)cMaterialPropertiesTable_dtor, (int)D_0053BB80);
}
