#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004BF258[];
extern char D_004E0A40[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void func_0041C7D0(void* self);

}
struct G0041BD30 { void* vtable; };
#define GW(off) (*(int*)((char*)p + (off)))
#define GB(off) (*(char*)((char*)p + (off)))
#define GH(off) (*(unsigned short*)((char*)p + (off)))
extern "C" G0041BD30* func_0041BD30(void)
{
    G0041BD30* p;
    {
        AllocGuard guard;
        p = (G0041BD30*)Mem_Alloc(0, 0x90, D_004BF258, 0x2A);
    }
    if (p) {
        func_0041C7D0(p);
        p->vtable = D_004E0A40; GH(0x14) |= 0x80; GB(0x80) = 0; GW(0x84) = 0x64; GW(0x8C) = 0; GB(0x88) = 0;
    }
    return p;
}