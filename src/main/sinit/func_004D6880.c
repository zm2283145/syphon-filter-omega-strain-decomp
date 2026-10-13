#include "types.h"
extern char D_0055A2D0[];
extern char g_EventQueue[];
extern void ScalarCollection_Init();
extern void __register_global_object();
extern void func_003EA2E0();
#pragma opt_common_subs off
void func_004D6880(void)
{
    ScalarCollection_Init((int)g_EventQueue);
    __register_global_object((int)g_EventQueue, (int)func_003EA2E0, (int)D_0055A2D0);
}
