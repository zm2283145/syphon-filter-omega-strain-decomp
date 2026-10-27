#ifndef RTUDP_TYPES_H
#define RTUDP_TYPES_H

/*
 * RtUdp peer-connection object (network lib, functions around
 * 0x002F9000-0x00307FFF such as rt_p2p_send). ~28 src/lib files
 * re-derive it as UpnpObj / UpnpEnt / UpnpSlot; same layout here.
 * Plain C for ee-gcc 2.96 (lib); also fine in MW.
 * Every API function returns 2 for a NULL object, 0 on success.
 */
typedef struct RtUdpSlot {
    int h;
    int a;
    int b;
} RtUdpSlot; /* 0xC */

typedef struct RtUdpPeer {
    int type;                /* +0x00 */
    int f4;                  /* +0x04 handle, -1 = unused */
    int f8;                  /* +0x08 */
    unsigned char bC, bD, bE, bF;
    unsigned char b10, b11;
    char addr[16];           /* +0x12 dotted address */
    unsigned short port;     /* +0x22 */
    int f24;                 /* +0x24 */
} RtUdpPeer; /* 0x28 */

typedef struct RtUdpObj {
    RtUdpSlot slot[32];      /* +0x000 */
    int h180;                /* +0x180 socket/handle (some files: void*) */
    RtUdpPeer* ent;          /* +0x184 peer array (heap) */
    int count;               /* +0x188 peer count */
    int f18C;
    int f190;                /* +0x190 heap block */
    unsigned char b194, b195, b196, b197;
    void (*cb198)(int idx, unsigned short n, int x);
    int f19C;
    int f1A0;
    void (*cb1A4)(int idx, int x);
    int f1A8;
    int f1AC;
    void (*cb1B0)(void* buf, int len, int code);
} RtUdpObj; /* 0x1B4 */

typedef char rtudp_peer_size[(sizeof(RtUdpPeer) == 0x28) ? 1 : -1];
typedef char rtudp_obj_size[(sizeof(RtUdpObj) == 0x1B4) ? 1 : -1];

#endif /* RTUDP_TYPES_H */
