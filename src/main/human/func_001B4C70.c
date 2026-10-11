#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" { void operator_delete(void* p); void Mem_Free(int pool, void* p, char* file, int line); extern char D_0049EDF0[]; }
struct O_1B4C70 { int vt; void* buf; };
extern "C" void* func_001B4C70(O_1B4C70* self, short deleteFlag)
{
    if (self) {
        void* b = self->buf;
        if (b) {
            {
                AllocGuard guard;
                Mem_Free(0, b, D_0049EDF0, 0x55C);
            }
            self->buf = 0;
        }
        if (deleteFlag > 0) operator_delete(self);
    }
    return self;
}