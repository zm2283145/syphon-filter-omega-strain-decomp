#ifndef ALLOC_DEALLOCATE_H
#define ALLOC_DEALLOCATE_H

/*
 * allocator<T>::deallocate(p, n) clones: if p is non-null, free it with
 * Mem_Free(0, p, fileSym, line) under the allocator guard; and the raw
 * guarded free wrapper free(p, pool, unused, file, line).
 * C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

extern "C" void Mem_Free(int pool, void* p, char* file, int line);

#define DEFINE_ALLOC_DEALLOCATE(name, fileSym, line)                          \
    extern "C" char fileSym[];                                                \
    extern "C" void name(void* self, void* p, int n)                          \
    {                                                                         \
        if (p) {                                                              \
            AllocGuard guard;                                                 \
            Mem_Free(0, p, fileSym, (line));                                  \
        }                                                                     \
    }

#define DEFINE_ALLOC_FREE_WRAPPER(name)                                       \
    extern "C" void name(void* p, int pool, int unused, char* file, int line) \
    {                                                                         \
        AllocGuard guard;                                                     \
        Mem_Free(pool, p, file, line);                                        \
    }

#endif /* ALLOC_DEALLOCATE_H */