#include "types.h"
typedef struct { char pad[0xC]; unsigned char ready; } Obj_4D0910;
extern char D_004F8350[], D_004F8338[];
extern char func_00267360[];
extern signed char D_004EA0C8;
extern char* g_LosCheckService;
extern void func_002674C0(void* p);
extern void PtrVec_Reserve_Thunk_2674B0(void* p, int n);
extern int func_001361D0(int* n);
extern void __register_global_object(void* obj, void* dtor, void* link);
void func_004D0910(void)
{
    {
        int n[1];
        Obj_4D0910* o = (Obj_4D0910*)D_004F8350;
        n[0] = 4;
        func_002674C0(o);
        PtrVec_Reserve_Thunk_2674B0(o, func_001361D0(n));
        o->ready = 1;
        __register_global_object(o, func_00267360, D_004F8338);
    }
    if (!D_004EA0C8) {
        g_LosCheckService = "LOS Manager";
        D_004EA0C8 = 1;
    }
}