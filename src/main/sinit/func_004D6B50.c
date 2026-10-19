#include "types.h"
typedef struct { char pad[0xC]; unsigned char ready; } Obj_4D6B50;
extern char D_0055CA40[], D_0055CA30[], D_0055CA70[], D_0055CA58[], D_0055CA90[];
extern char D_00493898[], D_004938A0[];
extern char func_003FEFD0[], func_00288670[], Script_GetString[];
extern int D_0055D478;
extern void func_003FDEC0(void* p);
extern void func_003FDEB0(void* p, int n);
extern void func_002888C0(void* p);
extern void func_00336DE0(void* p, int n);
extern int func_001361D0(int* n);
extern void func_0043FDD0(void* p);
extern void __register_global_object(void* obj, void* dtor, void* link);
extern int Script_RegisterNative_2(void* fn, void* name, void* desc, int n, ...);
void StaticInit_RegisterGlobalization(void)
{
    {
        int n[1];
        Obj_4D6B50* o = (Obj_4D6B50*)D_0055CA40;
        n[0] = 0x6A4;
        func_003FDEC0(o);
        func_003FDEB0(o, func_001361D0(n));
        o->ready = 1;
        __register_global_object(o, func_003FEFD0, D_0055CA30);
    }
    {
        int n[1];
        Obj_4D6B50* o = (Obj_4D6B50*)D_0055CA70;
        n[0] = 0xA00;
        func_002888C0(o);
        func_00336DE0(o, func_001361D0(n));
        o->ready = 1;
        __register_global_object(o, func_00288670, D_0055CA58);
    }
    func_0043FDD0(D_0055CA90);
    D_0055D478 = Script_RegisterNative_2(Script_GetString, D_00493898, "GetString", 1, D_004938A0);
}