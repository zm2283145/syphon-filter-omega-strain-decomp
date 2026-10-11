#ifndef PTR4_HOLDER_DTOR_H
#define PTR4_HOLDER_DTOR_H

/*
 * Deleting destructor of a small holder whose only owned resource is the
 * allocation at +4 (one clone per translation unit): free it under the
 * allocator guard (file fileSym, line 100), then delete the object when
 * deleteFlag > 0. The doubled null test comes from an inlined deallocator.
 * C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

extern "C" {
void Mem_Free(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
}

struct Ptr4Holder {
    int head;
    void* allocation;
};

#define DEFINE_PTR4_HOLDER_DTOR(name, fileSym)                                \
    extern "C" char fileSym[];                                                \
    extern "C" Ptr4Holder* name(Ptr4Holder* self, short deleteFlag)           \
    {                                                                         \
        if (self) {                                                           \
            void* p = self->allocation;                                       \
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

#endif /* PTR4_HOLDER_DTOR_H */