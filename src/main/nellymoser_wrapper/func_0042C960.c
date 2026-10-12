#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" void* Mem_Alloc(int, int, char*, int);
extern "C" void* sfo_malloc_42C960(int n, int m) {
    AllocGuard g;
    char msg[] = "sfo_malloc: should only be used in rtime lib";
    return Mem_Alloc(2, n * m, msg, 0);
}
