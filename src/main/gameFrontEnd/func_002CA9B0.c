#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void Mem_Free(int pool, void* p, char* file, int line);
}
extern "C" void sfo_malloc_2CA9B0(void* p)
{
    AllocGuard g;
    char f[] = "sfo_malloc: should only be used in rtime lib";
    Mem_Free(2, p, f, 0);
}
