#pragma cplusplus on
#include "types.h"
#include "alloc_guard.h"
extern "C" void* cMemMan_Allocate(int, int, char*, int);
extern "C" void* sfo_calloc(int n, int m) {
    AllocGuard g;
    char msg[] = "sfo_malloc: should only be used in rtime lib";
    return cMemMan_Allocate(2, n * m, msg, 0);
}
