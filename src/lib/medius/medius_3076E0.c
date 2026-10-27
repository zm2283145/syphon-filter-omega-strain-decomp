typedef struct {
    int state; int f4; char name[16]; unsigned short port; char pad1A[2];
    char f1C[0x18]; char f34[0x18]; char f4C[8]; char f54[8]; char pad5C[0x10];
    int f6C; int f70; int f74; int f78; int f7C; char pad80[0xC]; int f8C;
} RtPeer;
typedef struct {
    int f0; RtPeer *peers; int f8; char q[0x20]; unsigned int npeers; int f30; int f34;
} RtUdp;
typedef struct { char name[16]; unsigned short port; int f14; } RtAddr;
extern int rt_udp_get_resolved_address(RtUdp *r, char *name, unsigned short *port);
extern int rt_udp_get_local_address(RtUdp *r, char *name, unsigned short *port);
extern int strcmp(const char *a, const char *b);
extern char *strncpy(char *d, const char *s, unsigned int n);
extern int rt_udp_find_free_connection(RtUdp *r, int *idx);
extern int rt_list_buf_create(void *q, int n);
extern int randomNoneZero(void);
extern int rt_time_start(void *t);
extern int GetUDPSecurityMode(void);
extern int KM_GetSymmetricKey(int a, int b, unsigned char *buf);
extern int rt_udp_send_peerkey(RtUdp *r, RtPeer *p, unsigned char *buf);
extern int rt_udp_setup_packet_header(RtUdp *r, RtPeer *p, int kind, unsigned char *hdr);
extern int rt_udp_buffer_data_for_send(RtPeer *p, unsigned char *hdr, void *body, int n);
int rt_udp_connect(RtUdp *r, RtAddr *a, int *out)
{
    RtAddr self;
    unsigned char buf[0x40];
    unsigned char hdr[16];
    int idx = -1;
    RtPeer *p;
    int ret;
    if (out == 0) return 1;
    *out = -1;
    if (a == 0) return 1;
    if (r == 0) return 2;
    self.name[0] = 0;
    self.port = 0;
    rt_udp_get_resolved_address(r, self.name, &self.port);
    if (a->port == self.port && strcmp(a->name, self.name) == 0) return 0x15;
    self.name[0] = 0;
    self.port = 0;
    rt_udp_get_local_address(r, self.name, &self.port);
    if (a->port == self.port && strcmp(a->name, self.name) == 0) return 0x15;
    ret = rt_udp_find_free_connection(r, &idx);
    if (ret != 0) return ret;
    *out = idx;
    p = &r->peers[idx];
    if (rt_list_buf_create(p->f1C, r->f30) != 0) {
        r->peers[idx].state = 6;
        return 7;
    }
    if (rt_list_buf_create(p->f34, r->f34) != 0) {
        p->state = 6;
        return 7;
    }
    p->state = 9;
    p->f74 = randomNoneZero();
    p->f78 = randomNoneZero();
    p->f7C = randomNoneZero();
    p->port = a->port;
    strncpy(p->name, a->name, 16);
    rt_time_start(p->f4C);
    rt_time_start(p->f54);
    p->f70 = 1000;
    p->f6C = 0;
    p->f8C = a->f14;
    if (GetUDPSecurityMode() == 1) {
        KM_GetSymmetricKey(-1, p->f8C, buf);
        ret = rt_udp_send_peerkey(r, p, buf);
    } else {
        if (rt_udp_setup_packet_header(r, p, 4, hdr) != 0) {
            p->state = 6;
            return 7;
        }
        hdr[0] |= 0x40;
        ret = rt_udp_buffer_data_for_send(p, hdr, 0, 0);
    }
    if (ret != 0) {
        p->state = 6;
        return 7;
    }
    return 0;
}
