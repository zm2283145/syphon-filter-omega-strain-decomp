#ifndef NET_MSG_CLONE_H
#define NET_MSG_CLONE_H

/*
 * Clone (virtual slot 1) of cMessage-derived network messages:
 * "new T(*this)" under the allocator guard, with the copy constructors of
 * cMessage (vtable D_004DFD80, header words 4..1C and byte 20), the
 * middle class (vtable D_004DCF10) and the message itself inlined.
 *   DEFINE_NET_MSG_CLONE(name, size, fileSym, line, vtableSym, copy)
 * copy is a statement list using NMC_B(off) / NMC_W(off) to copy payload.
 * C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

struct NetMsgHeader {
    void* vtable;
    int w4, w8, wC, w10, w14, w18, w1C;
    char b20;
};

extern "C" {
void* Mem_Alloc(int pool, int size, char* file, int line);
extern char D_004DFD80[];
extern char D_004DCF10[];
}

#define NMC_B(off) (*(char*)((char*)p + (off)) = *(char*)((char*)self + (off)))
#define NMC_W(off) (*(int*)((char*)p + (off)) = *(int*)((char*)self + (off)))

#define DEFINE_NET_MSG_CLONE(name, size, fileSym, line, vtableSym, copy)      \
    extern "C" {                                                              \
    extern char fileSym[];                                                    \
    extern char vtableSym[];                                                  \
    }                                                                         \
    extern "C" NetMsgHeader* name(NetMsgHeader* self)                         \
    {                                                                         \
        NetMsgHeader* p;                                                      \
        {                                                                     \
            AllocGuard guard;                                                 \
            p = (NetMsgHeader*)Mem_Alloc(0, (size), fileSym, (line));         \
        }                                                                     \
        if (p) {                                                              \
            p->vtable = D_004DFD80;                                           \
            p->w4 = self->w4;                                                 \
            p->w8 = self->w8;                                                 \
            p->wC = self->wC;                                                 \
            p->w10 = self->w10;                                               \
            p->w14 = self->w14;                                               \
            p->w18 = self->w18;                                               \
            p->w1C = self->w1C;                                               \
            p->b20 = self->b20;                                               \
            p->vtable = D_004DCF10;                                           \
            p->vtable = vtableSym;                                            \
            copy;                                                             \
        }                                                                     \
        return p;                                                             \
    }

#endif /* NET_MSG_CLONE_H */