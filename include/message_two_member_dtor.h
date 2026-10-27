#ifndef MESSAGE_TWO_MEMBER_DTOR_H
#define MESSAGE_TWO_MEMBER_DTOR_H

/*
 * Deleting destructor of a cMessage-derived message whose payload
 * subobject at +0x30 owns two members (at +0x78 and +0x114) destroyed by
 * cFileMan_dtor: restore the class vtable, destroy the payload members,
 * run the cMessage base destructor, then delete when deleteFlag > 0.
 * One instantiation per message class (vtable differs).
 * C++ only (#pragma cplusplus on before including).
 */
extern "C" {
void cFileMan_dtor(void* member, int flags);
void cMessage_dtor(void* self, int flags);
void operator_delete(void* allocation);
}

struct TwoMemberMessage {
    void* vtable;
    char base[0x2C];
    char payload[0x48];
    char memberA[0x9C];
    char memberB[4];
};

#define DEFINE_MESSAGE_TWO_MEMBER_DTOR(name, vtableSym)                       \
    extern "C" char vtableSym[];                                              \
    extern "C" TwoMemberMessage* name(TwoMemberMessage* self,                 \
                                      short deleteFlag)                       \
    {                                                                         \
        if (self) {                                                           \
            self->vtable = vtableSym;                                         \
            if (self->payload) {                                              \
                cFileMan_dtor(self->memberB, -1);                             \
                cFileMan_dtor(self->memberA, -1);                             \
            }                                                                 \
            cMessage_dtor(self, 0);                                           \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* MESSAGE_TWO_MEMBER_DTOR_H */