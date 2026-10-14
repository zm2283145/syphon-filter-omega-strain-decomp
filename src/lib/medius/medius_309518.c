typedef struct { int sock; char pad[0x24]; void *buf; char pad2[0xC]; unsigned short f38; char pad3[0xE]; unsigned int state; } RtCtx;
typedef struct { int a[4]; } RtAddr;
extern int func_002F61A0(int sock, RtAddr *addr, unsigned short *port, void *buf, unsigned short size, unsigned short *len);
extern int RtUdp_ParsePacket(RtCtx *c, RtAddr *addr, unsigned short port, unsigned short len);

int func_00309518(RtCtx *c)
{
    RtAddr addr;
    unsigned short port;
    unsigned short len = 0;
    int r;
    do {
        len = 0;
        if (c->state < 8)
            r = func_002F61A0(c->sock, &addr, &port, c->buf, 0x5AA, &len);
        else
            r = func_002F61A0(c->sock, &addr, &port, c->buf, c->f38 + 12, &len);
        if (r == 0) {
            if (len == 0) break;
            if (len >= 12) RtUdp_ParsePacket(c, &addr, port, len);
        }
    } while (len != 0);
    return 0;
}
