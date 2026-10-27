#include "types.h"
typedef struct { char pad[0xC]; unsigned char ready; } Obj_4D8B40;
extern char* D_00587FC0;
extern int D_00587FD0, D_00588000;
extern char D_00587FC8[], D_00587FF0[], D_00587FD8[], D_00493880[], D_00493898[], D_004938A0[];
extern char func_00470B20[], cArray_tRecord_dtor[], Script_cInventory__RegisterItem[];
extern int cNetMsg_RegisterMsg(void* fn, void* a, void* b);
extern void func_00471C00(void* p);
extern void func_00471BF0(void* p, int n);
extern int cArrayCapacity_Int(int* n);
extern void __register_global_object(void* obj, void* dtor, void* link);
extern int cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(void* fn, void* name, void* desc, int n, ...);
void StaticInit_inventory(void)
{
    D_00587FC0 = "cNetInventoryMsg";
    D_00587FD0 = cNetMsg_RegisterMsg(func_00470B20, D_00587FC8, "cNetInventoryMsg");
    {
        int n[1];
        Obj_4D8B40* o = (Obj_4D8B40*)D_00587FF0;
        n[0] = 0x10;
        func_00471C00(o);
        func_00471BF0(o, cArrayCapacity_Int(n));
        o->ready = 0;
        __register_global_object(o, cArray_tRecord_dtor, D_00587FD8);
    }
    D_00588000 = cScriptBase_registerFunc_intPintPint_intP_charP_int_etc(Script_cInventory__RegisterItem, D_00493880, "cInventory::RegisterItem", 2, D_004938A0, D_00493898);
}