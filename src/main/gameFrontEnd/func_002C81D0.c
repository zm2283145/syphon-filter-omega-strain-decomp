#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern int D_0048C358;
extern int D_0048C350;
extern int D_0048C348;
extern void* D_0051EF70;
extern char D_004ACF10[];
void func_0010CE60(int id, int sema);
void func_0010CFB0(int thread);
void func_0010CF70(int thread);
void Mem_Free(int pool, void* p, char* file, int line);
}
struct Obj81D0 { char pad[0x310]; unsigned char active; };
extern "C" void func_002C81D0(Obj81D0* o)
{
    if (o->active) {
        Alloc_Lock(2);
        func_0010CE60(2, D_0048C358);
        D_0048C348 = -1;
        if (D_0048C350 != -1) {
            func_0010CFB0(D_0048C350);
            func_0010CF70(D_0048C350);
            D_0048C350 = -1;
        }
        D_0048C358 = -1;
        {
            void* p = D_0051EF70;
            AllocGuard guard;
            Mem_Free(0, p, D_004ACF10, 0x89C);
        }
        D_0051EF70 = 0;
        o->active = 0;
    }
}