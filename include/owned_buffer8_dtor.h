#ifndef OWNED_BUFFER8_DTOR_H
#define OWNED_BUFFER8_DTOR_H

/*
 * Deleting destructor of a holder owning the allocation at +8 (one null
 * test on self): free it under the allocator guard (file fileSym, line
 * 100), then delete the object when deleteFlag > 0.
 * C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
}

struct OwnedBuffer8 {
    int first;
    int last;
    void* buffer;
};

#define DEFINE_OWNED_BUFFER8_DTOR(name, fileSym)                              \
    extern "C" char fileSym[];                                                \
    extern "C" OwnedBuffer8* name(OwnedBuffer8* self, short deleteFlag)       \
    {                                                                         \
        if (self) {                                                           \
            void* p = self->buffer;                                           \
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

#endif /* OWNED_BUFFER8_DTOR_H */