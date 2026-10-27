#ifndef GUARDED_RELEASE_H
#define GUARDED_RELEASE_H

/*
 * Allocator deallocate(ptr, pool, flags, file, line) shared by identical
 * template clones (one per translation unit): cMemMan_Deallocate under the
 * allocator guard. flags is unused.
 * C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

extern "C" void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);

#define DEFINE_GUARDED_RELEASE(name)                                          \
    extern "C" void name(void* allocation, int pool, int flags, char* file,   \
                         int line)                                            \
    {                                                                         \
        AllocGuard guard;                                                     \
        cMemMan_Deallocate(pool, allocation, file, line);                               \
    }

#endif /* GUARDED_RELEASE_H */