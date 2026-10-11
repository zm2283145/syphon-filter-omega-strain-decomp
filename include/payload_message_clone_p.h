#ifndef PAYLOAD_MESSAGE_CLONE_P_H
#define PAYLOAD_MESSAGE_CLONE_P_H

/*
 * payload_message_clone.h with the base copy-constructor as a parameter:
 * allocate under the allocator guard, baseCtor(p, self), store the vtable
 * and copy the payload at +0x30 with payloadCopy.
 * C++ only (#pragma cplusplus on before including).
 */
#include "alloc_guard.h"

extern "C" void* Mem_Alloc(int pool, int size, char* file, int line);

struct PayloadMessageP {
    void* vtable;
    char base[0x2C];
    char payload[4];
};

#define DEFINE_PAYLOAD_MESSAGE_CLONE_P(name, size, fileSym, line, vtableSym,  \
                                       payloadCopy, baseCtor)                 \
    extern "C" {                                                              \
    extern char fileSym[];                                                    \
    extern char vtableSym[];                                                  \
    void payloadCopy(void* dst, void* src);                                   \
    void baseCtor(void* self, void* other);                                   \
    }                                                                         \
    extern "C" PayloadMessageP* name(PayloadMessageP* self)                   \
    {                                                                         \
        PayloadMessageP* p;                                                   \
        {                                                                     \
            AllocGuard guard;                                                 \
            p = (PayloadMessageP*)Mem_Alloc(0, (size), fileSym, (line));      \
        }                                                                     \
        if (p) {                                                              \
            baseCtor(p, self);                                                \
            p->vtable = vtableSym;                                            \
            payloadCopy(p->payload, self->payload);                           \
        }                                                                     \
        return p;                                                             \
    }

#endif /* PAYLOAD_MESSAGE_CLONE_P_H */