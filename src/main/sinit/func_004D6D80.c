#include "types.h"
extern char g_AgentPartCache[], D_0055DD90[], D_00571570[];
extern char Monster_dtor[], cVector_ctor_void[];
extern float D_005716C0[4];
extern float D_005716D0[4];
extern void Monster_ctor(void* p);
extern void __construct_array(void* arr, void* ctor, void* dtor, int size, int n);
extern void __register_global_object(void* obj, void* dtor, void* link);
void StaticInit_manUtils(void)
{
    Monster_ctor(g_AgentPartCache);
    __register_global_object(g_AgentPartCache, Monster_dtor, D_0055DD90);
    __construct_array(D_00571570, cVector_ctor_void, 0, 0x10, 0x15);
    D_005716C0[0] = 3.4028235e38f;
    D_005716C0[1] = 3.4028235e38f;
    D_005716C0[2] = 3.4028235e38f;
    D_005716C0[3] = 1.0f;
    D_005716D0[0] = -3.4028235e38f;
    D_005716D0[1] = -3.4028235e38f;
    D_005716D0[2] = -3.4028235e38f;
    D_005716D0[3] = 1.0f;
}

