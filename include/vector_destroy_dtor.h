#ifndef VECTOR_DESTROY_DTOR_H
#define VECTOR_DESTROY_DTOR_H

/*
 * Deleting destructor of a vector whose elements need destruction (one
 * clone per translation unit): destroy the elements with destroyFn(self),
 * free the buffer at +8 (file D_0049ECC8, line 100) under the allocator
 * guard, then delete the object when deleteFlag > 0.
 * C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

extern "C" {
extern char D_0049ECC8[];
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
}

struct DestroyVector {
    int capacity;
    int count;
    void* data;
};

#define DEFINE_VECTOR_DESTROY_DTOR(name, destroyFn)                           \
    extern "C" void destroyFn(DestroyVector* self);                           \
    extern "C" DestroyVector* name(DestroyVector* self, short deleteFlag)     \
    {                                                                         \
        if (self) {                                                           \
            destroyFn(self);                                                  \
            void* p = self->data;                                             \
            if (p) {                                                          \
                if (p) {                                                      \
                    AllocGuard guard;                                         \
                    cMemMan_Deallocate(0, p, D_0049ECC8, 0x64);                         \
                }                                                             \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

/*
 * Same body with a different allocation-site file string.
 */
#define DEFINE_VECTOR_DESTROY_DTOR_FILE(name, destroyFn, fileSym)             \
    extern "C" char fileSym[];                                                \
    extern "C" void destroyFn(DestroyVector* self);                           \
    extern "C" DestroyVector* name(DestroyVector* self, short deleteFlag)     \
    {                                                                         \
        if (self) {                                                           \
            destroyFn(self);                                                  \
            void* p = self->data;                                             \
            if (p) {                                                          \
                if (p) {                                                      \
                    AllocGuard guard;                                         \
                    cMemMan_Deallocate(0, p, fileSym, 0x64);                            \
                }                                                             \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* VECTOR_DESTROY_DTOR_H */