typedef struct { unsigned char kind; unsigned char id; unsigned short pad; int val; int pad2; } ScfHdr;
typedef struct { int sock; char pad[0x44]; unsigned char b48; } ScfSock;
typedef struct { int f0; int f4; int addr[4]; unsigned short port; char pad[0x5A]; int f74; } ScfPeer;
extern void *memset(void *d, int c, unsigned int n);
extern int Socket_WriteAddressed(int sock, void *addr, unsigned short port, void *data, int len, unsigned short *sent);
int func_0030ABA8(ScfSock *s, void *addr, unsigned short port, int val)
{
    ScfHdr hdr;
    unsigned short sent = 0;
    int ret = 2;
    if (s == 0) return ret;
    memset(&hdr, 0, 12);
    hdr.id = s->b48;
    hdr.kind = 8;
    hdr.val = val;
    Socket_WriteAddressed(s->sock, addr, port, &hdr, 12, &sent);
    return 0;
}