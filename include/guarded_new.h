#ifndef GUARDED_NEW_H
#define GUARDED_NEW_H

/*
 * Object factories ("new T"): cMemMan_Allocate(0, size, fileSym, 42) under the
 * allocator guard, then construct when the allocation succeeded.
 *   DEFINE_GUARDED_NEW_CTOR(name, size, fileSym, ctor)
 *       out-of-line constructor ctor(p), its result is returned
 *   DEFINE_GUARDED_NEW_VT(name, size, fileSym, baseCtor, vtableSym)
 *       inline constructor: baseCtor(p), store the class vtable
 *   DEFINE_GUARDED_NEW_VT_INT(name, size, fileSym, baseCtor, vtableSym,
 *                             offset, value)
 *       as above, plus one int member initialised to value
 * C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

extern "C" void* cMemMan_Allocate(int pool, int size, char* file, int line);

struct GuardedNewObject {
    void* vtable;
};

#define DEFINE_GUARDED_NEW_CTOR(name, size, fileSym, ctor)                    \
    extern "C" {                                                              \
    extern char fileSym[];                                                    \
    void* ctor(void* self);                                                   \
    }                                                                         \
    extern "C" void* name(void)                                               \
    {                                                                         \
        void* p;                                                              \
        {                                                                     \
            AllocGuard guard;                                                 \
            p = cMemMan_Allocate(0, (size), fileSym, 0x2A);                          \
        }                                                                     \
        if (p)                                                                \
            p = ctor(p);                                                      \
        return p;                                                             \
    }

#define DEFINE_GUARDED_NEW_VT(name, size, fileSym, baseCtor, vtableSym)       \
    extern "C" {                                                              \
    extern char fileSym[];                                                    \
    extern char vtableSym[];                                                  \
    void baseCtor(void* self);                                                \
    }                                                                         \
    extern "C" GuardedNewObject* name(void)                                   \
    {                                                                         \
        GuardedNewObject* p;                                                  \
        {                                                                     \
            AllocGuard guard;                                                 \
            p = (GuardedNewObject*)cMemMan_Allocate(0, (size), fileSym, 0x2A);       \
        }                                                                     \
        if (p) {                                                              \
            baseCtor(p);                                                      \
            p->vtable = vtableSym;                                            \
        }                                                                     \
        return p;                                                             \
    }

#define DEFINE_GUARDED_NEW_VT_INT(name, size, fileSym, baseCtor, vtableSym,   \
                                  offset, value)                              \
    extern "C" {                                                              \
    extern char fileSym[];                                                    \
    extern char vtableSym[];                                                  \
    void baseCtor(void* self);                                                \
    }                                                                         \
    extern "C" GuardedNewObject* name(void)                                   \
    {                                                                         \
        GuardedNewObject* p;                                                  \
        {                                                                     \
            AllocGuard guard;                                                 \
            p = (GuardedNewObject*)cMemMan_Allocate(0, (size), fileSym, 0x2A);       \
        }                                                                     \
        if (p) {                                                              \
            baseCtor(p);                                                      \
            p->vtable = vtableSym;                                            \
            *(int*)((char*)p + (offset)) = (value);                           \
        }                                                                     \
        return p;                                                             \
    }

#endif /* GUARDED_NEW_H */