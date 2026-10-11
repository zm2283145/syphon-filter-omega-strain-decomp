#ifndef CLEAR_BUFFER_DTOR_H
#define CLEAR_BUFFER_DTOR_H

/*
 * Deleting destructor of a vector of trivially destructible elements:
 * clear the count at +4, free the buffer at +8 under the allocator guard
 * (file fileSym, line 100), then delete when deleteFlag > 0.
 * C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
}

struct ClearBufferVector {
    int capacity;
    int count;
    void* data;
};

#define DEFINE_CLEAR_BUFFER_DTOR(name, fileSym)                               \
    extern "C" char fileSym[];                                                \
    extern "C" ClearBufferVector* name(ClearBufferVector* self,               \
                                       short deleteFlag)                      \
    {                                                                         \
        if (self) {                                                           \
            self->count = 0;                                                  \
            void* p = self->data;                                             \
            if (p) {                                                          \
                if (p) {                                                      \
                    AllocGuard guard;                                         \
                    Mem_Free(0, p, fileSym, 0x64);                            \
                }                                                             \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* CLEAR_BUFFER_DTOR_H */