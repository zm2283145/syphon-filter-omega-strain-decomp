#pragma cplusplus on




#include "types.h"
#include "alloc_guard.h"
struct Pt2_NEnt { char* name; int a; int b; };
struct Pt2_NType { int pad; char list[1]; };
struct Pt2_NReg { char pad[8]; Pt2_NType** types; };
extern "C" {
extern Pt2_NReg* D_00554F28;
extern signed char D_00499C71[];
extern char D_004BD3B0[];
void* Mem_Alloc(int, int, char*, int);
void func_003D8A10(void*, Pt2_NEnt**);
}
extern "C" void func_003D88E0(int type, char* name, int a, int b) {
    Pt2_NEnt* tmp[1];
    Pt2_NType* t;
    Pt2_NEnt* e;
    if (name[0] == 'm' && (D_00499C71[name[1]] & 1)) name++;
    { int i = type - 100; t = D_00554F28->types[i]; }
    {
        AllocGuard g;
        e = (Pt2_NEnt*)Mem_Alloc(0, 0xC, D_004BD3B0, 0x96);
    }
    if (e) {
        e->a = a;
        e->b = b;
        e->name = name;
    }
    tmp[0] = e;
    func_003D8A10(t->list, tmp);
}
