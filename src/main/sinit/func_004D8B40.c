#include "types.h"
typedef struct { char pad[0xC]; unsigned char ready; } Obj_4D8B40;
extern char* D_00587FC0;
extern int D_00587FD0, D_00588000;
extern char D_004C3380[], D_00587FC8[], D_00587FF0[], D_00587FD8[], D_00493880[], D_00493898[], D_004938A0[], D_004C33A0[];
extern char func_00470B20[], func_00471AA0[], Script_cInventory__RegisterItem[];
extern int func_002824D0(void* fn, void* a, void* b);
extern void func_00471C00(void* p);
extern void func_00471BF0(void* p, int n);
extern int func_001361D0(int* n);
extern void __register_global_object(void* obj, void* dtor, void* link);
extern int func_003D8740(void* fn, void* name, void* desc, int n, ...);
void func_004D8B40(void)
{
    D_00587FC0 = D_004C3380;
    D_00587FD0 = func_002824D0(func_00470B20, D_00587FC8, D_004C3380);
    {
        int n[1];
        Obj_4D8B40* o = (Obj_4D8B40*)D_00587FF0;
        n[0] = 0x10;
        func_00471C00(o);
        func_00471BF0(o, func_001361D0(n));
        o->ready = 0;
        __register_global_object(o, func_00471AA0, D_00587FD8);
    }
    D_00588000 = func_003D8740(Script_cInventory__RegisterItem, D_00493880, D_004C33A0, 2, D_004938A0, D_00493898);
}