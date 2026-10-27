#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" {
void cMemMan_Deallocate(int pool, void* p, char* file, int line);
}
extern "C" void sfo_free(void* p)
{
    AllocGuard g;
    char f[] = "sfo_malloc: should only be used in rtime lib";
    cMemMan_Deallocate(2, p, f, 0);
}
