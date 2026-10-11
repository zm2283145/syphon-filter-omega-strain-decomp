#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
extern char D_004A9238[];
void Mem_Free(int heap, void* p, char* file, int line);
void operator_delete(void* p);
}
struct S_00279D80 { void** a; void** b; int na; int nb; };
static inline void Free_00279D80(void* p, int line) { AllocGuard g; Mem_Free(0, p, D_004A9238, line); }
extern "C" S_00279D80* func_00279D80(S_00279D80* self, short flag)
{
    if (self) {
        int i;
        for (i = 0; i < self->na; i++) Free_00279D80(self->a[i], 0x87);
        { int j; for (j = 0; j < self->nb; j++) Free_00279D80(self->b[j], 0x89); }
        Free_00279D80(self->a, 0x8B);
        Free_00279D80(self->b, 0x8C);
        if (flag > 0)
            operator_delete(self);
    }
    return self;
}