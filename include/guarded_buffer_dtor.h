#ifndef GUARDED_BUFFER_DTOR_H
#define GUARDED_BUFFER_DTOR_H

/*
 * Deleting destructors of a small buffer holder {int first; int count;
 * void* buffer;}: free the buffer at +8 (line 100, per-unit file name)
 * under the allocator guard, then delete when deleteFlag > 0.
 * C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

extern "C" {
void cMemMan_Deallocate(int pool, void* allocation, char* file, int line);
void operator_delete(void* allocation);
}

typedef struct GuardedBuffer {
    int first;
    int count;
    void* buffer;
} GuardedBuffer;

#define GUARDED_BUFFER_FREE(self, file)                                       \
    {                                                                         \
        void* p = (self)->buffer;                                             \
        if (p) {                                                              \
            if (p) {                                                          \
                AllocGuard guard;                                             \
                cMemMan_Deallocate(0, p, file, 0x64);                                   \
            }                                                                 \
        }                                                                     \
    }

/* inlined clear (count = 0) then free */
#define DEFINE_GUARDED_BUFFER_CLEAR_DTOR(name, file)                          \
    extern "C" char file[];                                                   \
    extern "C" GuardedBuffer* name(GuardedBuffer* self, short deleteFlag)     \
    {                                                                         \
        if (self) {                                                           \
            if (self) {                                                       \
                self->count = 0;                                              \
                GUARDED_BUFFER_FREE(self, file)                               \
            }                                                                 \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

/* out-of-line clear call preFn(self) then free */
#define DEFINE_GUARDED_BUFFER_CALL_DTOR(name, preFn, file)                    \
    extern "C" char file[];                                                   \
    extern "C" void preFn(GuardedBuffer* self);                               \
    extern "C" GuardedBuffer* name(GuardedBuffer* self, short deleteFlag)     \
    {                                                                         \
        if (self) {                                                           \
            preFn(self);                                                      \
            GUARDED_BUFFER_FREE(self, file)                                   \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* GUARDED_BUFFER_DTOR_H */