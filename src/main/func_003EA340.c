#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
}
struct P3EA340 { void* allocation; };
extern "C" P3EA340* MemCard_dtor(P3EA340* self, short deleteFlag)
{
    if (self) {
        void* p = self->allocation;
        if (p) {
            AllocGuard guard;
            Mem_Free(0, p, "MemCard.hh", 0x9B);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}