typedef struct { unsigned char kind; unsigned char id; unsigned short len; int val; int seq; } ScfHdr;
typedef struct { int sock; char pad[0x44]; unsigned char b48; } ScfSock;
typedef struct { int f0; int f4; int addr[4]; unsigned short port; char pad[0x5A]; int f74; int seq2; int seq4; } ScfPeer;
extern void *memset(void *d, int c, unsigned int n);

int RtUdp_BuildHeader(ScfSock *s, ScfPeer *e, unsigned char flags, ScfHdr *h)
{
    int ret = 1;
    if (h == 0) return ret;
    if (e == 0) return ret;
    memset(h, 0, 12);
    h->id = s->b48;
    h->val = e->f74;
    h->kind = flags;
    if ((flags & 6) == 6 || (flags & 4)) {
        h->seq = e->seq4;
        e->seq4++;
        if (e->seq4 == 0) e->seq4++;
    } else if (flags & 2) {
        h->seq = e->seq2;
        e->seq2++;
        if (e->seq2 == 0) e->seq2++;
    }
    return 0;
}
