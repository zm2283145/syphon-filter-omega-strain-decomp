typedef struct { int state; char pad4[0x18]; char q1C[0x48]; int f64; char pad68[0x20]; int f88; char pad8C[4]; } RtPeer;
typedef struct {
    int f0; RtPeer *peers; char pad8[0x24]; unsigned int npeers; char pad30[8]; unsigned int f38; int f3C;
} RtUdp;
typedef struct {
    unsigned char flags; unsigned char b1;
    unsigned short len; unsigned int seq4; unsigned int seq8;
} RtHdr;
extern int rt_udp_setup_packet_header(RtUdp *r, RtPeer *e, int kind, RtHdr *hdr);
extern int rt_udp_buffer_data_for_send(RtPeer *e, RtHdr *hdr, void *body, int n);
extern void rt_udp_send_messages(RtUdp *r, RtPeer *e);
extern int rt_list_buf_get_head(void *list, void **pkt);
extern void *rt_list_buf_get_next(void *pkt);
extern int rt_udp_append_data_to_packet(RtUdp *r, RtPeer *e, int flags, void *pkt, void *data, int len);
extern int rt_udp_get_send_header(void *pkt, unsigned char *st);
extern int rt_udp_get_packet_header(void *pkt, RtHdr *hdr);
int rt_udp_send(RtUdp *r, unsigned int idx, unsigned char flags, void *data, unsigned int len)
{
    RtHdr h;
    unsigned char st[4];
    void *p;
    void *found = 0;
    RtPeer *e;
    int ret;
    p = 0;
    if (r == 0) return 2;
    if (idx >= r->npeers) return 3;
    e = &r->peers[idx];
    if (e->state != 12) return 3;
    if (data == 0 || len == 0 || r->f38 < len) return 1;
    if (rt_list_buf_get_head(e->q1C, &p) != 0) return 10;
    while (p != 0 && !(unsigned char)(flags & 1) && r->f3C != 0) {
        if (rt_udp_get_send_header(p, st) != 0 || rt_udp_get_packet_header(p, &h) != 0 || st[0] != 0) { p = rt_list_buf_get_next(p); continue; }
        {
            if (found != 0 && (flags & 2)) {
                found = (h.flags & 2) ? 0 : found;
            }
            if ((h.flags & 7) == (flags & 7) && found == 0 && h.len + len <= r->f38 && !(h.flags & 0x80))
                found = p;
        }
        p = rt_list_buf_get_next(p);
    }
    if (found != 0) {
        ret = rt_udp_append_data_to_packet(r, e, flags, found, data, len);
        if (ret != 0) return ret;
    } else {
        ret = rt_udp_setup_packet_header(r, e, flags, &h);
        if (ret != 0) return ret;
        h.flags |= 0x40;
        h.len = len;
        ret = rt_udp_buffer_data_for_send(e, &h, data, len);
        if (ret != 0) return ret;
        if ((unsigned char)(flags & 1)) e->f88++;
        if (e->f64 == 0 && (flags & 4)) e->f64 = h.seq8;
    }
    rt_udp_send_messages(r, e);
    return 0;
}

