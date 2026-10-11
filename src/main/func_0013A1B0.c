#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"

extern "C" void Mem_Free(int pool, void* allocation, char* file, int line);
struct Elem_A1B0 { char pad[0x20]; char live; };
extern "C" void func_0013A1B0(Elem_A1B0* allocation, int pool, int destroy, char* file, int line)
{
    AllocGuard guard;
    if (destroy) {
        if (allocation)
            allocation->live = 0;
    }
    Mem_Free(pool, allocation, file, line);
}