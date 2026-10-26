typedef struct {
    unsigned int state;
    char pad4[0x18];
    int list;
    char pad20[0x54];
    int seq;
    char pad78[0xC];
    int ack;
    char pad88[0x8];
} Ent9e70;

typedef struct {
    int pad0;
    Ent9e70 *ents;
} Mgr9e70;

typedef struct {
    int pad0;
    int seq;
    int ack;
} Pkt9e70;

typedef struct {
    int f0;
    int seq;
    int rest[1];
} Hdr9e70;

extern int rt_list_buf_get_head(int *list, void **node);
extern int rt_udp_get_packet_header(void *pkt, Hdr9e70 *out);
extern int rt_udp_set_packet_header(void *pkt, Hdr9e70 *in);
extern int rt_udp_send_reset(Mgr9e70 *m, Ent9e70 *e);
extern int RtUdp_QueueAck(Mgr9e70 *m, Ent9e70 *e, Pkt9e70 *p);

int rt_udp_process_connect(Mgr9e70 *m, Pkt9e70 *p, int idx)
{
    Hdr9e70 hd;
    void *node = 0;
    Ent9e70 *e;
    int ret = 0;

    if (idx == -1) return 7;
    e = &m->ents[idx];
    if (p->seq == 0) return 0;
    if (e->seq == 0 && e->state - 8 < 2) {
        e->seq = p->seq;
        node = 0;
        e->ack = p->ack;
        rt_list_buf_get_head(&e->list, &node);
        if (node == 0) {
            e->state = 6;
            rt_udp_send_reset(m, e);
            return 7;
        }
        rt_udp_get_packet_header(node, &hd);
        hd.seq = e->seq;
        rt_udp_set_packet_header(node, &hd);
    }
    if (e->state == 7) return 0;
    switch (e->state) {
    case 8:
    case 9:
    case 11:
    case 12:
        if (e->ack == 0) e->ack = p->ack;
        ret = RtUdp_QueueAck(m, e, p);
        break;
    default:
        e->state = 1;
        rt_udp_send_reset(m, e);
        break;
    }
    return ret;
}
