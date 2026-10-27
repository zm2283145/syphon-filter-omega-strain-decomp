#include "types.h"
typedef struct { char pad[0xC]; unsigned char ready; } Obj_4D6B50;
extern char D_0055CA40[], D_0055CA30[], D_0055CA70[], D_0055CA58[], D_0055CA90[];
extern char D_00493898[], D_004938A0[];
extern char cArray_1_dtor[], cArray_charPtr_dtor_void_2[], Script_GetString[];
extern int D_0055D478;
extern void std_vector_1_ctor(void* p);
extern void std_vector_1_reserve(void* p, int n);
extern void std_vector_charPtr_ctor_void_2(void* p);
extern void std_vector_charPtr_reserve(void* p, int n);
extern int cArrayCapacity_Int(int* n);
extern void func_0043FDD0(void* p);
extern void __register_global_object(void* obj, void* dtor, void* link);
extern int cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(void* fn, void* name, void* desc, int n, ...);
void StaticInit_globalization(void)
{
    {
        int n[1];
        Obj_4D6B50* o = (Obj_4D6B50*)D_0055CA40;
        n[0] = 0x6A4;
        std_vector_1_ctor(o);
        std_vector_1_reserve(o, cArrayCapacity_Int(n));
        o->ready = 1;
        __register_global_object(o, cArray_1_dtor, D_0055CA30);
    }
    {
        int n[1];
        Obj_4D6B50* o = (Obj_4D6B50*)D_0055CA70;
        n[0] = 0xA00;
        std_vector_charPtr_ctor_void_2(o);
        std_vector_charPtr_reserve(o, cArrayCapacity_Int(n));
        o->ready = 1;
        __register_global_object(o, cArray_charPtr_dtor_void_2, D_0055CA58);
    }
    func_0043FDD0(D_0055CA90);
    D_0055D478 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_GetString, D_00493898, "GetString", 1, D_004938A0);
}