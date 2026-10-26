typedef struct { int state; char pad04[0x18]; char sub[0x58]; int f74; char pad78[0x18]; } RtPeer;
typedef struct { int f0; RtPeer *peers; } RtUdp;
typedef struct { int a; int b; int pad[2]; } RtInfo;
extern int rt_udp_connect(RtUdp *h, void *a, int *out);
extern int rt_list_buf_get_head(char *o, int *out);
extern int rt_udp_get_packet_header(int s, RtInfo *i);
extern int rt_udp_set_packet_header(int s, RtInfo *i);
int rt_udp_pre_accept(RtUdp *h, void *a, int *out)
{
    int s = 0;
    RtInfo info;
    RtPeer *p;
    int r;
    if (out == 0) return 1;
    *out = -1;
    if (h == 0) return 2;
    if (a == 0) return 1;
    r = rt_udp_connect(h, a, out);
    if (r != 0) return r;
    p = &h->peers[*out];
    p->f74 = 0;
    if (rt_list_buf_get_head(p->sub, &s) != 0) {
        p->state = 6;
        return 10;
    }
    if (rt_udp_get_packet_header(s, &info) != 0) {
        p->state = 6;
        return 11;
    }
    info.b = 0;
    if (rt_udp_set_packet_header(s, &info) != 0) {
        p->state = 6;
        return 11;
    }
    return 0;
}
