#ifndef OWNED_BUFFER8_DTOR_DEEP_H
#define OWNED_BUFFER8_DTOR_DEEP_H

/*
 * Variants of owned_buffer8_dtor.h with extra inlined null tests on self
 * (nested inlined destructors):
 *   DEFINE_OWNED_BUFFER8_DTOR_MID(name, fileSym)   two tests
 *   DEFINE_OWNED_BUFFER8_DTOR_DEEP(name, fileSym)  three tests
 * C++ only (#pragma cplusplus on before including).
 */
#include "owned_buffer8_dtor.h"

#define DEFINE_OWNED_BUFFER8_DTOR_MID(name, fileSym)                          \
    extern "C" char fileSym[];                                                \
    extern "C" OwnedBuffer8* name(OwnedBuffer8* self, short deleteFlag)       \
    {                                                                         \
        if (self) {                                                           \
            if (self) {                                                       \
                void* p = self->buffer;                                       \
                if (p) {                                                      \
                    if (p) {                                                  \
                        AllocGuard guard;                                     \
                        cMemMan_Deallocate(0, p, fileSym, 0x64);                        \
                    }                                                         \
                }                                                             \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#define DEFINE_OWNED_BUFFER8_DTOR_DEEP(name, fileSym)                         \
    extern "C" char fileSym[];                                                \
    extern "C" OwnedBuffer8* name(OwnedBuffer8* self, short deleteFlag)       \
    {                                                                         \
        if (self) {                                                           \
            if (self) {                                                       \
                if (self) {                                                   \
                    void* p = self->buffer;                                   \
                    if (p) {                                                  \
                        if (p) {                                              \
                            AllocGuard guard;                                 \
                            cMemMan_Deallocate(0, p, fileSym, 0x64);                    \
                        }                                                     \
                    }                                                         \
                }                                                             \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* OWNED_BUFFER8_DTOR_DEEP_H */