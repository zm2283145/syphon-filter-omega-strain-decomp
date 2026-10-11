#ifndef PACKET_ONCE_PROCESS_H
#define PACKET_ONCE_PROCESS_H

/*
 * Library helper (EE-GCC 2.96): unless already done, run func_0030F050 on
 * the two buffers at 0x108 and 0x208 with the context, and mark the object
 * done when it returns 0. Plain C.
 */
typedef struct PacketOnce {
    char pad[0x108];
    char a[0x100];
    char b[4];
    unsigned char done;
} PacketOnce;

extern int func_0030F050(void* a, void* b, void* ctx);

#define DEFINE_PACKET_ONCE_PROCESS(name)                        \
    void name(void* ctx, PacketOnce* p)                         \
    {                                                           \
        if (!p->done) {                                         \
            if (func_0030F050(p->a, p->b, ctx) == 0)            \
                p->done = 1;                                    \
        }                                                       \
    }

#endif /* PACKET_ONCE_PROCESS_H */