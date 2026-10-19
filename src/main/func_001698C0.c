#include "types.h"
extern signed char D_004EE1C0;
extern char D_004EE1C8[];
extern char D_004EE1E0[];
void App_Ctor(void* p);
void App_dtor(void* p, int flags);
void __register_global_object(void* obj, void* dtor, void* link);
void* App_GetInstance(void)
{
    if (!D_004EE1C0) {
        App_Ctor(D_004EE1E0);
        __register_global_object(D_004EE1E0, App_dtor, D_004EE1C8);
        D_004EE1C0 = 1;
    }
    return D_004EE1E0;
}