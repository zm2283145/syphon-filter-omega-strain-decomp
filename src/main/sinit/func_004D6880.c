#include "types.h"
extern char D_0055A2D0[];
extern char g_EventQueue[];
extern void ScalarCollection_Init();
extern void __register_global_object();
extern void EventQueue_dtor();
#pragma opt_common_subs off
void StaticInit_callback(void)
{
    ScalarCollection_Init((int)g_EventQueue);
    __register_global_object((int)g_EventQueue, (int)EventQueue_dtor, (int)D_0055A2D0);
}
