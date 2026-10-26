#include "types.h"
extern char D_004FFB38[];
extern char g_Game[];
extern void __register_global_object();
extern void World_Destruct();
extern void World_Construct();
#pragma opt_common_subs off
void StaticInit_globals(void)
{
    World_Construct((int)g_Game);
    __register_global_object((int)g_Game, (int)World_Destruct, (int)D_004FFB38);
}
