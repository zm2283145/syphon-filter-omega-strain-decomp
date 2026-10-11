#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
extern char D_004BDFD8[];
}
struct P3EA340 { void* allocation; };
extern "C" P3EA340* func_003EA340(P3EA340* self, short deleteFlag)
{
    if (self) {
        void* p = self->allocation;
        if (p) {
            AllocGuard guard;
            Mem_Free(0, p, D_004BDFD8, 0x9B);
        }
        if (deleteFlag > 0)
            operator_delete(self);
    }
    return self;
}