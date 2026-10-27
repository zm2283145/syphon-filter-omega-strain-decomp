typedef struct { unsigned char kind; unsigned char id; unsigned short len; int val; int seq; } ScfHdr;
typedef struct { unsigned int type; int f4; int addr[4]; unsigned short port; char pad[0x3A]; int timer[2]; char pad2[0x18]; int f74; char pad3[0x18]; } ScfPeer;
typedef struct { int sock; ScfPeer *ents; char pad[0x24]; unsigned int count; char pad2[0x18]; unsigned char b48; } ScfSock;
extern void *memset(void *d, int c, unsigned int n);
extern int rt_comm_send_to(int sock, void *addr, unsigned short port, void *data, int len, unsigned short *sent);
extern int rt_udp_send_messages(ScfSock *s, ScfPeer *e);
extern void rt_time_elapsed(int *timer, unsigned int *elapsed);
extern void rt_time_get_time_stamp(int *timer);
extern int rt_udp_receive_messages(ScfSock *s);

int rt_udp_event_process(ScfSock *s)
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
        ret = rt_udp_send_messages(s, e);
        if (ret != 0) return ret;
        if (e->type == 12) {
            rt_time_elapsed(e->timer, &elapsed);
            if (elapsed > 5000) {
                memset(&hdr, 0, 12);
                hdr.val = e->f74;
                hdr.id = s->b48;
                rt_comm_send_to(s->sock, e->addr, e->port, &hdr, 12, &sent);
                rt_time_get_time_stamp(e->timer);
            }
        }
    }
    return rt_udp_receive_messages(s);
}

