#ifndef NET_REGISTER_TYPE_H
#define NET_REGISTER_TYPE_H

/*
 * Network message type registration: describe each payload field of a
 * prototype (NetMessageField(desc, &field, size, count)) and register the
 * type with its factory. Returns 1 on success.
 *   NETREG_BEGIN(name, Proto)   first check returns early
 *   NETREG_BEGIN_KEEP(name, Proto)  the base check result is kept and
 *                                   tested again (inlined base class)
 *   NETREG_FIELD(member, size, count)
 *   NETREG_END(typeSym, factory)
 */
extern int NetRegisterMessageStart(void* reg);
extern int cMessage_RegisterFields(void* desc);
extern int NetMessageField(void* desc, void* field, int size, int count);
extern int NetRegisterMessage(void* type, int version, void* factory);

#define NETREG_BEGIN(name, Proto)                                             \
    unsigned char name(void* reg)                                             \
    {                                                                         \
        struct { long long file; Proto p; } L;                                \
        unsigned char ok = 0;                                                 \
        if (NetRegisterMessageStart(reg) == 0 && cMessage_RegisterFields(&L.file) != 0

#define NETREG_BEGIN_KEEP(name, Proto)                                        \
    unsigned char name(void* reg)                                             \
    {                                                                         \
        struct { long long file; Proto p; } L;                                \
        int base;                                                             \
        unsigned char ok = 0;                                                 \
        base = NetRegisterMessageStart(reg);                                            \
        if (base == 0 && cMessage_RegisterFields(&L.file) != 0 && base == 0

#define NETREG_FIELD(member, size, count)                                     \
        && NetMessageField(&L.file, &L.p.member, (size), (count)) == 0

#define NETREG_END(typeSym, factory)                                          \
        && NetRegisterMessage(typeSym, 2, factory) == 0)                     \
            ok = 1;                                                           \
        return ok;                                                            \
    }

#endif /* NET_REGISTER_TYPE_H */