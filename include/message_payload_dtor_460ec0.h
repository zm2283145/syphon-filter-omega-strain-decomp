#ifndef MESSAGE_PAYLOAD_DTOR_460EC0_H
#define MESSAGE_PAYLOAD_DTOR_460EC0_H

/*
 * Deleting destructor of a message whose payload subobject at +0x20 owns
 * two members (+0x68, +0x104) destroyed by FileMan_Release, followed by the
 * base destructor func_00460EC0(self, -1); delete when deleteFlag > 0.
 * C++ only (#pragma cplusplus on before including).
 */
extern "C" {
void FileMan_Release(void* member, int flags);
void func_00460EC0(void* self, int flags);
void operator_delete(void* allocation);
}

struct PayloadMessage460 {
    char base[0x20];
    char payload[0x48];
    char memberA[0x9C];
    char memberB[4];
};

#define DEFINE_MESSAGE_PAYLOAD_DTOR_460EC0(name)                              \
    extern "C" PayloadMessage460* name(PayloadMessage460* self,               \
                                       short deleteFlag)                      \
    {                                                                         \
        if (self) {                                                           \
            if (self->payload) {                                              \
                FileMan_Release(self->memberB, -1);                             \
                FileMan_Release(self->memberA, -1);                             \
            }                                                                 \
            if (self)                                                         \
                func_00460EC0(self, -1);                                      \
            if (deleteFlag > 0)                                               \
                operator_delete(self);                                        \
        }                                                                     \
        return self;                                                          \
    }

#endif /* MESSAGE_PAYLOAD_DTOR_460EC0_H */