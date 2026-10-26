#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_0049A890[];
void Mem_Free(int heap, void* p, char* file, int line);
void PtrVec_Reserve(void* p, int a);
}
struct E_00130B10 { int x0; void* a; void* b; };
struct S_00130B10 { char pad[0x2C]; char m2C[4]; int n; E_00130B10** arr; };
static inline void Free_00130B10(void* p, int line) { AllocGuard g; Mem_Free(0, p, D_0049A890, line); }
static inline void Del_00130B10(void* p, int line) { if (p) { AllocGuard g; Mem_Free(0, p, D_0049A890, line); } }
#pragma opt_strength_reduction off
extern "C" void cGameSystem_RemoveVUMGOBJNames(S_00130B10* self)
{
    int i;
    for (i = 0; i < self->n; i++) {
        E_00130B10* e = self->arr[i];
        Free_00130B10(e->a, 0x948);
        Del_00130B10(e->b, 0x94B);
        e->a = 0;
        e->b = 0;
        e->x0 = 0;
        Free_00130B10(e, 0x950);
    }
    self->n = 0;
    PtrVec_Reserve(self->m2C, 0x100);
}