#include "types.h"
extern char D_0055A2D0[];
extern char g_EventQueue[];
extern void std_list_deleter_voidPtr_ctor_void();
extern void __register_global_object();
extern void cLList_cCBDataPtr_dtor();
#pragma opt_common_subs off
void StaticInit_callback(void)
{
    std_list_deleter_voidPtr_ctor_void((int)g_EventQueue);
    __register_global_object((int)g_EventQueue, (int)cLList_cCBDataPtr_dtor, (int)D_0055A2D0);
}
