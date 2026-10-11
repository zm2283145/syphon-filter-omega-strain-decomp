#ifndef STREAM_STRING_DTOR_H
#define STREAM_STRING_DTOR_H

/*
 * Destructor body shared by 31 identical string-holder destructor clones
 * (one per translation unit): if the "heap storage" bit (word & 1) is set,
 * free the long buffer at +8 (file D_0049AE90, line 100) under the allocator
 * guard, then delete the object when deleteFlag > 0.
 * C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

extern "C" {
extern char D_0049AE90[];
void Mem_Free(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
}

typedef struct StreamStringStorage {
    unsigned int word;   /* bit 0: longData is heap-owned */
    int length;
    char* longData;
} StreamStringStorage;

static inline void StreamString_FreeLong(char* allocation)
{
    if (allocation) {
        AllocGuard guard;
        Mem_Free(0, allocation, D_0049AE90, 0x64);
    }
}

#define DEFINE_STREAM_STRING_DTOR(name)                                       \
    extern "C" StreamStringStorage* name(StreamStringStorage* self,           \
                                         short deleteFlag)                    \
    {                                                                         \
        if (self) {                                                           \
            if (self->word & 1)                                               \
                StreamString_FreeLong(self->longData);                        \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* STREAM_STRING_DTOR_H */