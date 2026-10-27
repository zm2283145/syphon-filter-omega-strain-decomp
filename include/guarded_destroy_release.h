#ifndef GUARDED_DESTROY_RELEASE_H
#define GUARDED_DESTROY_RELEASE_H

/*
 * Allocator release(ptr, pool, destroy, file, line) shared by identical
 * template clones: under the allocator guard, run the element destructor
 * destroyFn(ptr, -1) when destroy is set and ptr is non-null, then
 * cMemMan_Deallocate. C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

extern "C" void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);

#define DEFINE_GUARDED_DESTROY_RELEASE(name, destroyFn)                       \
    extern "C" void destroyFn(void* p, int flags);                            \
    extern "C" void name(void* allocation, int pool, int destroy, char* file, \
                         int line)                                            \
    {                                                                         \
        AllocGuard guard;                                                     \
        if (destroy) {                                                        \
            if (allocation)                                                   \
                destroyFn(allocation, -1);                                    \
        }                                                                     \
        cMemMan_Deallocate(pool, allocation, file, line);                               \
    }

#endif /* GUARDED_DESTROY_RELEASE_H */