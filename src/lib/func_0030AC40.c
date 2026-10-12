typedef struct { unsigned char kind; unsigned char id; unsigned short len; int val; int seq; } ScfHdr;
typedef struct { unsigned char b[4]; } ScfU32u;
typedef struct { unsigned char flags; unsigned char pad[7]; ScfU32u seq; } ScfRxHdr;
typedef struct { int sock; char pad[0x44]; int b48; } ScfSock;
typedef struct { int f0; int f4; int addr[4]; unsigned short port; char pad[0x5A]; int f74; } ScfPeer;
extern void *memset(void *d, int c, unsigned int n);
extern void *memcpy(void *d, const void *s, unsigned int n);
extern int RtUdp_CopyPacket(ScfPeer *e, ScfHdr *h, void *data, int len);

int RtUdp_QueueAck(ScfSock *s, ScfPeer *e, ScfRxHdr *p)
{
    ScfHdr hdr;
    unsigned char ack[5];
    memset(&hdr, 0, 12);
    hdr.kind = 0x20;
    hdr.id = s->b48;
    hdr.val = e->f74;
    hdr.len = 5;
    ack[0] = p->flags;
    memcpy(&ack[1], &p->seq, 4);
    return RtUdp_CopyPacket(e, &hdr, ack, 5);
}

