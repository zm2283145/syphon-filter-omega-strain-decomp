#pragma cplusplus on

#include "types.h"
#include "alloc_guard.h"

/* Create the 0x60-byte text record at +0xDC under the allocator guard. */
struct R34DC20 { char pad[0x10]; unsigned char a10; char pad11; unsigned char a12; };
struct S34DC20 { char pad[0xDC]; R34DC20* aDC; };
extern "C" {
extern char D_004BA880[];
extern char D_00587C80[];
void* Mem_Alloc(int pool, int size, char* file, int line);
void func_00356C70(S34DC20* o);
void* Gui_GetScreenList(void);
void* func_00418420(void* mgr, char* name);
R34DC20* func_003D0940(void* p, int a, int b, int c, int d, void* e, char* f);
void func_0034DC20(S34DC20* o);
}
void func_0034DC20(S34DC20* o)
{
    void* p;
    func_00356C70(o);
    {
        AllocGuard guard;
        p = Mem_Alloc(0, 0x60, D_004BA880, 0x83);
    }
    if (p) p = func_003D0940(p, 0, 0, 10, 10, func_00418420(Gui_GetScreenList(), "callout"), D_00587C80);
    o->aDC = (R34DC20*)p;
    o->aDC->a10 = 2;
    o->aDC->a12 = 1;
}