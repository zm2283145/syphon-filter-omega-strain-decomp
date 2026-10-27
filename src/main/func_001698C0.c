#include "types.h"
extern signed char D_004EE1C0;
extern char D_004EE1C8[];
extern char D_004EE1E0[];
void cMachine_ctor(void* p);
void cMachine_dtor(void* p, int flags);
void __register_global_object(void* obj, void* dtor, void* link);
void* GetMachine(void)
{
    if (!D_004EE1C0) {
        cMachine_ctor(D_004EE1E0);
        __register_global_object(D_004EE1E0, cMachine_dtor, D_004EE1C8);
        D_004EE1C0 = 1;
    }
    return D_004EE1E0;
}