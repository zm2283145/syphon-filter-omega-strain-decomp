#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct T285EE0 { void* vt; char pad[0x5C]; int x60; void* p64; void* p68; void* p6C; };
extern "C" {
extern char D_004DCF90[];
extern char D_004A93D0[];
extern char g_TargetVisMgr[];
void Mem_Free(int pool, void* p, char* file, int line);
void TargetVis_Unregister(void* mgr, int id);
void cGOBJ_dtor(void* p, int f);
void operator_delete(void* p);
}
static inline void Rel285EE0(void* p, int line)
{
    if (p) {
        AllocGuard g;
        Mem_Free(0, p, D_004A93D0, line);
    }
}
extern "C" T285EE0* cTank_dtor(T285EE0* self, short del)
{
    if (self) {
        self->vt = D_004DCF90;
        Rel285EE0(self->p64, 0x1DA);
        Rel285EE0(self->p68, 0x1DD);
        Rel285EE0(self->p6C, 0x1E0);
        TargetVis_Unregister(g_TargetVisMgr, self->x60);
        cGOBJ_dtor(self, 0);
        if (del > 0)
            operator_delete(self);
    }
    return self;
}