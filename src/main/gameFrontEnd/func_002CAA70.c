#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void* Mem_Alloc(int pool, void* p, char* file, int line);
}
extern "C" void* func_002CAA70(void* p)
{
    AllocGuard g;
    char f[] = "sfo_malloc: should only be used in rtime lib";
    return Mem_Alloc(2, p, f, 0);
}
