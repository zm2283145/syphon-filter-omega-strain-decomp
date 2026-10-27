#ifndef GUARDED_BASE_DESTROY_RELEASE_H
#define GUARDED_BASE_DESTROY_RELEASE_H

/*
 * Like DEFINE_GUARDED_DESTROY_RELEASE, but the destroy call passes 0
 * (non-deleting destructor): under the allocator guard, destroyFn(p, 0)
 * when destroy is set and p is non-null, then cMemMan_Deallocate(pool, p, file, line).
 * C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

extern "C" void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);

#define DEFINE_GUARDED_BASE_DESTROY_RELEASE(name, destroyFn)                  \
    extern "C" void destroyFn(void* p, int flags);                            \
    extern "C" void name(void* allocation, int pool, int destroy, char* file, \
                         int line)                                            \
    {                                                                         \
        AllocGuard guard;                                                     \
        if (destroy) {                                                        \
            if (allocation)                                                   \
                destroyFn(allocation, 0);                                     \
        }                                                                     \
        cMemMan_Deallocate(pool, allocation, file, line);                               \
    }

#endif /* GUARDED_BASE_DESTROY_RELEASE_H */