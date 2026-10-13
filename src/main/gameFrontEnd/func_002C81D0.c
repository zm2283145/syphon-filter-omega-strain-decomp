#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern int D_0048C358;
extern int D_0048C350;
extern int D_0048C348;
extern void* D_0051EF70;
void RemoveIntcHandler(int id, int sema);
void TerminateThread(int thread);
void DeleteThread(int thread);
void Mem_Free(int pool, void* p, char* file, int line);
}
struct Obj81D0 { char pad[0x310]; unsigned char active; };
extern "C" void func_002C81D0(Obj81D0* o)
{
    if (o->active) {
        Alloc_Lock(2);
        RemoveIntcHandler(2, D_0048C358);
        D_0048C348 = -1;
        if (D_0048C350 != -1) {
            TerminateThread(D_0048C350);
            DeleteThread(D_0048C350);
            D_0048C350 = -1;
        }
        D_0048C358 = -1;
        {
            void* p = D_0051EF70;
            AllocGuard guard;
            Mem_Free(0, p, "gameFrontEnd.cc", 0x89C);
        }
        D_0051EF70 = 0;
        o->active = 0;
    }
}