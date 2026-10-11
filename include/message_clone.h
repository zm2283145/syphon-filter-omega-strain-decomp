#ifndef MESSAGE_CLONE_H
#define MESSAGE_CLONE_H

/*
 * Clone() of cMessage-derived messages: allocate `size` bytes under the
 * allocator guard (Mem_Alloc(0, size, fileSym, line)), then run the inlined
 * copy constructors: cMessage part (vtable D_004DFD80, words 0x04-0x1C and
 * the byte at 0x20), then BODY(p, self) for the derived parts (store each
 * derived vtable and copy the payload). Payload types derive from
 * ClonedMessageBase.
 * C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

extern "C" void* Mem_Alloc(int pool, int size, char* file, int line);
extern "C" char D_004DFD80[];

struct ClonedMessageBase {
    void* vtable;
    int w04;
    int w08;
    int w0C;
    int w10;
    int w14;
    int w18;
    int w1C;
    char b20;
};

#define DEFINE_MESSAGE_CLONE(name, T, size, fileSym, line, BODY)              \
    extern "C" char fileSym[];                                                \
    extern "C" T* name(T* self)                                               \
    {                                                                         \
        T* p;                                                                 \
        {                                                                     \
            AllocGuard guard;                                                 \
            p = (T*)Mem_Alloc(0, (size), fileSym, (line));                    \
        }                                                                     \
        if (p) {                                                              \
            p->vtable = D_004DFD80;                                           \
            p->w04 = self->w04;                                               \
            p->w08 = self->w08;                                               \
            p->w0C = self->w0C;                                               \
            p->w10 = self->w10;                                               \
            p->w14 = self->w14;                                               \
            p->w18 = self->w18;                                               \
            p->w1C = self->w1C;                                               \
            p->b20 = self->b20;                                               \
            BODY(p, self)                                                     \
        }                                                                     \
        return p;                                                             \
    }

#endif /* MESSAGE_CLONE_H */