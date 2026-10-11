#ifndef MSG_CLONE_INLINE28_H
#define MSG_CLONE_INLINE28_H

/*
 * Clone() of a 0x28-byte message whose copy constructor is fully inlined:
 * allocate under the allocator guard, store the base vtable, copy the base
 * words +4..+0x1C and the byte at +0x20, store the class vtable, copy the
 * word at +0x24. C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

extern "C" void* Mem_Alloc(int pool, int size, char* file, int line);

struct MsgInl28 {
    void* vtable;
    int w[7];
    signed char b;
    int x;
};

#define DEFINE_MSG_CLONE_INLINE28(name, size, fileSym, line, baseVt, classVt) \
    extern "C" {                                                              \
    extern char fileSym[];                                                    \
    extern char baseVt[];                                                     \
    extern char classVt[];                                                    \
    }                                                                         \
    extern "C" MsgInl28* name(MsgInl28* self)                                 \
    {                                                                         \
        MsgInl28* p;                                                          \
        {                                                                     \
            AllocGuard guard;                                                 \
            p = (MsgInl28*)Mem_Alloc(0, (size), fileSym, (line));             \
        }                                                                     \
        if (p) {                                                              \
            p->vtable = baseVt;                                               \
            p->w[0] = self->w[0];                                             \
            p->w[1] = self->w[1];                                             \
            p->w[2] = self->w[2];                                             \
            p->w[3] = self->w[3];                                             \
            p->w[4] = self->w[4];                                             \
            p->w[5] = self->w[5];                                             \
            p->w[6] = self->w[6];                                             \
            p->b = self->b;                                                   \
            p->vtable = classVt;                                              \
            p->x = self->x;                                                   \
        }                                                                     \
        return p;                                                             \
    }

#endif /* MSG_CLONE_INLINE28_H */