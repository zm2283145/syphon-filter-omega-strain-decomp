#ifndef NET_WRITE_ONE_WORD_H
#define NET_WRITE_ONE_WORD_H

/*
 * Network message serialize (vtable slot 4): writes the 32-bit field at
 * 0x24 to the network write cursor as two little-endian halves. Plain C.
 */
extern unsigned char* D_005061D0; /* network write cursor */

static inline void NetW1_write16(int v)
{
    short s = v;
    *D_005061D0++ = s;
    *D_005061D0++ = s >> 8;
}

static inline void NetW1_write32(int v)
{
    NetW1_write16((unsigned short)v);
    NetW1_write16(v >> 16);
}

typedef struct NetW1Msg { char pad[0x24]; int value; } NetW1Msg;

#define DEFINE_NET_WRITE_ONE_WORD(name) \
    void name(NetW1Msg* self)           \
    {                                   \
        NetW1_write32(self->value);     \
    }

#endif /* NET_WRITE_ONE_WORD_H */