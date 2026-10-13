#include "types.h"
typedef struct { char pad[0xC]; unsigned char ready; } Obj_4D0190;
extern char D_004F8000[], D_004F7FF0[], D_004F8040[], D_004F8030[];
extern char D_00493890[];
extern char BlindDuration, BlindNVFactor;
extern char func_0017EFC0[], func_0025DA40[];
extern int D_004F8020, D_004F8028;
extern signed char D_004EA0C8;
extern char* D_004EA0B0;
extern void func_00219DF0(void* p);
extern void func_0025DBC0(void* p, int n);
extern void func_0025DBA0(void* p);
extern void func_0025DB90(void* p, int n);
extern int func_001361D0(int* n);
extern int Script_RegisterVariable();
extern void __register_global_object(void* obj, void* dtor, void* link);
void func_004D0190(void)
{
    {
        int n[1];
        Obj_4D0190* o = (Obj_4D0190*)D_004F8000;
        n[0] = 0x40;
        func_00219DF0(o);
        func_0025DBC0(o, func_001361D0(n));
        o->ready = 0;
        __register_global_object(o, func_0017EFC0, D_004F7FF0);
    }
    D_004F8020 = Script_RegisterVariable("BlindDuration", (int)&BlindDuration, D_00493890);
    D_004F8028 = Script_RegisterVariable("BlindNVFactor", (int)&BlindNVFactor, D_00493890);
    {
        int n[1];
        Obj_4D0190* o = (Obj_4D0190*)D_004F8040;
        n[0] = 0x80;
        func_0025DBA0(o);
        func_0025DB90(o, func_001361D0(n));
        o->ready = 0;
        __register_global_object(o, func_0025DA40, D_004F8030);
    }
    if (!D_004EA0C8) {
        D_004EA0B0 = "LOS Manager";
        D_004EA0C8 = 1;
    }
}
