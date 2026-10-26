#include "types.h"
typedef struct { char pad[0xC]; unsigned char ready; } Obj_4D0190;
extern char D_004F8000[], D_004F7FF0[], D_004F8040[], D_004F8030[];
extern char D_00493890[];
extern char BlindDuration, BlindNVFactor;
extern char cArray_cVector_dtor[], cLList_cAreaEffectPtr_dtor[];
extern int D_004F8020, D_004F8028;
extern signed char D_004EA0C8;
extern char* g_LosCheckService;
extern void std_vector_cVector_ctor(void* p);
extern void Vector_Reserve_25DBD0_Thunk(void* p, int n);
extern void func_0025DBA0(void* p);
extern void PtrVec_Reserve_Thunk_25DB90(void* p, int n);
extern int cArrayCapacity_Int(int* n);
extern int Script_RegisterVariable();
extern void __register_global_object(void* obj, void* dtor, void* link);
void StaticInit_grenade(void)
{
    {
        int n[1];
        Obj_4D0190* o = (Obj_4D0190*)D_004F8000;
        n[0] = 0x40;
        std_vector_cVector_ctor(o);
        Vector_Reserve_25DBD0_Thunk(o, cArrayCapacity_Int(n));
        o->ready = 0;
        __register_global_object(o, cArray_cVector_dtor, D_004F7FF0);
    }
    D_004F8020 = Script_RegisterVariable("BlindDuration", (int)&BlindDuration, D_00493890);
    D_004F8028 = Script_RegisterVariable("BlindNVFactor", (int)&BlindNVFactor, D_00493890);
    {
        int n[1];
        Obj_4D0190* o = (Obj_4D0190*)D_004F8040;
        n[0] = 0x80;
        func_0025DBA0(o);
        PtrVec_Reserve_Thunk_25DB90(o, cArrayCapacity_Int(n));
        o->ready = 0;
        __register_global_object(o, cLList_cAreaEffectPtr_dtor, D_004F8030);
    }
    if (!D_004EA0C8) {
        g_LosCheckService = "LOS Manager";
        D_004EA0C8 = 1;
    }
}
