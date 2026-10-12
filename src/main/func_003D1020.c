#include "types.h"
typedef struct { int f0; char f4[0xC]; char f10[0xC]; unsigned char b1C; } M3D1020;
extern signed char D_00543740;
extern M3D1020 D_00543760;
extern char D_00543764[];
extern char D_00543770[];
extern char D_00543748[];
extern char func_003D0B90[];
extern void func_003D1560(void* p);
extern void ScalarCollection_Init(void* p);
extern void __register_global_object(void* o, void* d, void* l);
#pragma push
#pragma opt_propagation off
M3D1020* func_003D1020(void)
{
    if (!D_00543740) {
        M3D1020* m = &D_00543760;
        D_00543760.f0 = 0;
        func_003D1560(D_00543764);
        ScalarCollection_Init(D_00543770);
        m->b1C = 1;
        __register_global_object(m, func_003D0B90, D_00543748);
        D_00543740 = 1;
    }
    return &D_00543760;
}
#pragma pop
