#ifndef PAYLOAD_MESSAGE_CLONE_H
#define PAYLOAD_MESSAGE_CLONE_H

/*
 * Clone() of a message with an out-of-line payload copy: allocate under the
 * allocator guard, copy-construct the cMessage base (cMessage_ctor_cMessageR), store
 * the class vtable and copy the payload at +0x30 with payloadCopy.
 * C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

extern "C" void* cMemMan_Allocate(int pool, int size, char* file, int line);
extern "C" void cMessage_ctor_cMessageR(void* self, void* other);

struct PayloadMessage {
    void* vtable;
    char base[0x2C];
    char payload[4];
};

#define DEFINE_PAYLOAD_MESSAGE_CLONE(name, size, fileSym, line, vtableSym,    \
                                     payloadCopy)                             \
    extern "C" {                                                              \
    extern char fileSym[];                                                    \
    extern char vtableSym[];                                                  \
    void payloadCopy(void* dst, void* src);                                   \
    }                                                                         \
    extern "C" PayloadMessage* name(PayloadMessage* self)                     \
    {                                                                         \
        PayloadMessage* p;                                                    \
        {                                                                     \
            AllocGuard guard;                                                 \
            p = (PayloadMessage*)cMemMan_Allocate(0, (size), fileSym, (line));       \
        }                                                                     \
        if (p) {                                                              \
            cMessage_ctor_cMessageR(p, self);                                           \
            p->vtable = vtableSym;                                            \
            payloadCopy(p->payload, self->payload);                           \
        }                                                                     \
        return p;                                                             \
    }

#endif /* PAYLOAD_MESSAGE_CLONE_H */