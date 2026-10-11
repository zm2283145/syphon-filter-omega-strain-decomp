#ifndef PAYLOAD_MESSAGE_CLONE_LATEVT_P_H
#define PAYLOAD_MESSAGE_CLONE_LATEVT_P_H

/*
 * payload_message_clone_p.h variant whose vtable store comes after the
 * payload copy: allocate under the allocator guard, baseCtor(p, self),
 * payloadCopy(p + 0x30, self + 0x30), then store the vtable.
 * C++ only (#pragma cplusplus on before including).
 */
#include "payload_message_clone_p.h"

#define DEFINE_PAYLOAD_MESSAGE_CLONE_LATEVT_P(name, size, fileSym, line,      \
                                              vtableSym, payloadCopy,         \
                                              baseCtor)                       \
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
            payloadCopy(p->payload, self->payload);                           \
            p->vtable = vtableSym;                                            \
        }                                                                     \
        return p;                                                             \
    }

#endif /* PAYLOAD_MESSAGE_CLONE_LATEVT_P_H */