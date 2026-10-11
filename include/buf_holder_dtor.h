#ifndef BUF_HOLDER_DTOR_H
#define BUF_HOLDER_DTOR_H

/*
 * Destructor body shared by identical buffer-holder destructor clones
 * (one per translation unit): free the buffer at +8 (file D_0049AF00,
 * line 100) under the allocator guard, then delete the object when
 * deleteFlag > 0. The repeated null tests come from nested inlined
 * member destructors/deallocators.
 * C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

extern "C" {
extern char D_0049AF00[];
void Mem_Free(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
}

typedef struct BufHolder {
    int first;
    int last;
    void* buffer;
} BufHolder;

#define DEFINE_BUF_HOLDER_DTOR(name)                                          \
    extern "C" BufHolder* name(BufHolder* self, short deleteFlag)             \
    {                                                                         \
        if (self) {                                                           \
            if (self) {                                                       \
                if (self) {                                                   \
                    void* p = self->buffer;                                   \
                    if (p) {                                                  \
                        if (p) {                                              \
                            AllocGuard guard;                                 \
                            Mem_Free(0, p, D_0049AF00, 0x64);                 \
                        }                                                     \
                    }                                                         \
                }                                                             \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

/*
 * Variant with one fewer inlined null test on self (34 clones).
 */
#define DEFINE_BUF_HOLDER_DTOR_SHALLOW(name)                                  \
    extern "C" BufHolder* name(BufHolder* self, short deleteFlag)             \
    {                                                                         \
        if (self) {                                                           \
            if (self) {                                                       \
                void* p = self->buffer;                                       \
                if (p) {                                                      \
                    if (p) {                                                  \
                        AllocGuard guard;                                     \
                        Mem_Free(0, p, D_0049AF00, 0x64);                     \
                    }                                                         \
                }                                                             \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* BUF_HOLDER_DTOR_H */