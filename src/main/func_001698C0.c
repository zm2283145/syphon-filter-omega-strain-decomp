#include "types.h"
extern signed char D_004EE1C0;
extern char D_004EE1C8[];
extern char D_004EE1E0[];
void func_00169780(void* p);
void func_001696D0(void* p, int flags);
void __register_global_object(void* obj, void* dtor, void* link);
void* func_001698C0(void)
{
    if (!D_004EE1C0) {
        func_00169780(D_004EE1E0);
        __register_global_object(D_004EE1E0, func_001696D0, D_004EE1C8);
        D_004EE1C0 = 1;
    }
    return D_004EE1E0;
}