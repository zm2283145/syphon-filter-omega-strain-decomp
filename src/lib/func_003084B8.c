typedef struct { unsigned char kind; unsigned char id; unsigned short len; int val; int seq; } ScfHdr;
typedef struct { unsigned int type; int f4; int addr[4]; unsigned short port; char pad[0x3A]; int timer[2]; char pad2[0x18]; int f74; char pad3[0x18]; } ScfPeer;
typedef struct { int sock; ScfPeer *ents; char pad[0x24]; unsigned int count; char pad2[0x18]; unsigned char b48; } ScfSock;
extern void *memset(void *d, int c, unsigned int n);
extern int Socket_WriteAddressed(int sock, void *addr, unsigned short port, void *data, int len, unsigned short *sent);
extern int RtUdp_SendPump(ScfSock *s, ScfPeer *e);
extern void func_003060F0(int *timer, unsigned int *elapsed);
extern void func_003060D8(int *timer);
extern int func_00309518(ScfSock *s);

int RtUdp_UpdateRegular(ScfSock *s)
{
    ScfHdr hdr;
    unsigned short sent = 0;
    unsigned int elapsed;
    unsigned int i = 0;
    ScfPeer *e;
    int ret = 2;
    if (s == 0) return ret;
    for (; i < s->count; i++) {
        e = &s->ents[i];
        ret = RtUdp_SendPump(s, e);
        if (ret != 0) return ret;
        if (e->type == 12) {
            func_003060F0(e->timer, &elapsed);
            if (elapsed > 5000) {
                memset(&hdr, 0, 12);
                hdr.val = e->f74;
                hdr.id = s->b48;
                Socket_WriteAddressed(s->sock, e->addr, e->port, &hdr, 12, &sent);
                func_003060D8(e->timer);
            }
        }
    }
    return func_00309518(s);
}

