#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Factory: allocate a 0x250-byte personnel screen and construct it inline (two strings, one payload). */
extern "C" {
extern char D_004DF020[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void GuiPersonnelScreen_ctor(void* self);
void func_00298690(void* str);
void func_00356730(void* payload);
}
struct O356600 { void* vtable; char pad4[0x68]; char s6C[0xC]; char s78[0xC]; char pad84[0x2C]; char pB0[0x1A0]; };
extern "C" O356600* func_00356600(void)
{
    O356600* p;
    {
        AllocGuard guard;
        p = (O356600*)Mem_Alloc(0, 0x250, "guiWidget.hh", 0x2A);
    }
    if (p) {
        GuiPersonnelScreen_ctor(p);
        p->vtable = D_004DF020;
        func_00298690(p->s6C);
        func_00298690(p->s78);
        func_00356730(p->pB0);
    }
    return p;
}