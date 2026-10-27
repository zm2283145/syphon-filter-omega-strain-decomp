typedef struct { int state; char pad[0x88]; int f8C; } RtPeer;
typedef struct { int f0; RtPeer *peers; char pad[0x24]; unsigned int npeers; } RtUdp;
extern int rt_udp_setup_packet_header(RtUdp *p, RtPeer *e, int kind, unsigned char *hdr);
extern int rt_udp_buffer_data_for_send(RtPeer *e, unsigned char *hdr, void *body, int n);
extern int GetUDPSecurityMode(void);
extern int KM_GetSymmetricKey(int a, int b, void *out);
extern int rt_udp_send_peerkey(RtUdp *r, RtPeer *e, void *buf);
int rt_udp_accept(RtUdp *r, unsigned int idx)
{
    char buf[64];
    unsigned char hdr[12];
    RtPeer *e;
    int ret;
    if (r == 0) return 1;
    if (idx >= r->npeers) return 1;
    e = &r->peers[idx];
    if (e->state != 7) return 4;
    e->state = 8;
    if (GetUDPSecurityMode() == 1) {
        KM_GetSymmetricKey(-1, e->f8C, buf);
        ret = rt_udp_send_peerkey(r, e, buf);
    } else {
        ret = rt_udp_setup_packet_header(r, e, 4, hdr);
        if (ret != 0) goto fail;
        hdr[0] |= 0x40;
        ret = rt_udp_buffer_data_for_send(e, hdr, 0, 0);
    }
    if (ret != 0) {
fail:
        e->state = 6;
        return 7;
    }
    return 0;
}
