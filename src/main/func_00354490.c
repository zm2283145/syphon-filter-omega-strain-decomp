#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Factory: allocate a 0x8C-byte personnel screen and construct it inline (member at +0x6C, string at +0x80). */
extern "C" {
extern char D_004BB008[];
extern char D_004DEF90[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void GuiPersonnelScreen_ctor(void* self);
void func_00354710(void* m);
void func_00298690(void* str);
}
struct O354490 { void* vtable; char pad4[0x68]; char m6C[0x14]; char s80[0xC]; };
extern "C" O354490* func_00354490(void)
{
    O354490* p;
    {
        AllocGuard guard;
        p = (O354490*)Mem_Alloc(0, 0x8C, D_004BB008, 0x2A);
    }
    if (p) {
        GuiPersonnelScreen_ctor(p);
        p->vtable = D_004DEF90;
        func_00354710(p->m6C);
        func_00298690(p->s80);
    }
    return p;
}