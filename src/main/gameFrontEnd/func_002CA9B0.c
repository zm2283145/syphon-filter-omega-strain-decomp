#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
struct F2CA9B0 { char c[0x2D]; };
extern "C" {
extern F2CA9B0 D_0048C100;
void Mem_Free(int pool, void* p, char* file, int line);
}
extern "C" void sfo_malloc_2CA9B0(void* p)
{
    AllocGuard g;
    F2CA9B0 f = D_0048C100;
    Mem_Free(2, p, f.c, 0);
}