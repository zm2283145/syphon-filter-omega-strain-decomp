#ifndef NET_WRITE_TWO_WORDS_H
#define NET_WRITE_TWO_WORDS_H

/*
 * Network message serialize (vtable slot 4): writes the two 32-bit fields
 * at 0x24 and 0x28 to the network write cursor as little-endian halves.
 * Plain C.
 */
extern unsigned char* D_005061D0; /* network write cursor */

static inline void NetW2_write16(int v)
{
    short s = v;
    *D_005061D0++ = s;
    *D_005061D0++ = s >> 8;
}

static inline void NetW2_write32(int v)
{
    NetW2_write16((unsigned short)v);
    NetW2_write16(v >> 16);
}

typedef struct NetW2Msg { char pad[0x24]; int a; int b; } NetW2Msg;

#define DEFINE_NET_WRITE_TWO_WORDS(name) \
    void name(NetW2Msg* self)            \
    {                                    \
        NetW2_write32(self->a);          \
        NetW2_write32(self->b);          \
    }

#endif /* NET_WRITE_TWO_WORDS_H */