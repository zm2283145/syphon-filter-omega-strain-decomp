#ifndef GUARDED_ALLOCATE_H
#define GUARDED_ALLOCATE_H

/*
 * Allocator allocate(size, pool, file, line): Mem_Alloc under the
 * allocator guard. C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

extern "C" void* Mem_Alloc(int pool, unsigned int size, char* file, int line);

#define DEFINE_GUARDED_ALLOCATE(name)                                         \
    extern "C" void* name(unsigned int size, int pool, char* file, int line)  \
    {                                                                         \
        AllocGuard guard;                                                     \
        return Mem_Alloc(pool, size, file, line);                             \
    }

#endif /* GUARDED_ALLOCATE_H */