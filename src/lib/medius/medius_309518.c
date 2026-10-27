typedef struct { int sock; char pad[0x24]; void *buf; char pad2[0xC]; unsigned short f38; char pad3[0xE]; unsigned int state; } RtCtx;
typedef struct { int a[4]; } RtAddr;
extern int rt_comm_receive_from(int sock, RtAddr *addr, unsigned short *port, void *buf, unsigned short size, unsigned short *len);
extern int rt_udp_process_message(RtCtx *c, RtAddr *addr, unsigned short port, unsigned short len);

int rt_udp_receive_messages(RtCtx *c)
{
    RtAddr addr;
    unsigned short port;
    unsigned short len = 0;
    int r;
    do {
        len = 0;
        if (c->state < 8)
            r = rt_comm_receive_from(c->sock, &addr, &port, c->buf, 0x5AA, &len);
        else
            r = rt_comm_receive_from(c->sock, &addr, &port, c->buf, c->f38 + 12, &len);
        if (r == 0) {
            if (len == 0) break;
            if (len >= 12) rt_udp_process_message(c, &addr, port, len);
        }
    } while (len != 0);
    return 0;
}
