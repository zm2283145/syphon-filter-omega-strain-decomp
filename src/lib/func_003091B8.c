typedef struct { unsigned char cnt; char pad1[3]; int t[3]; } RtHdr;
typedef struct { unsigned int w; int x4; int seq; int xC; } RtPktHdr;
typedef struct { int sock; int pad4[14]; unsigned int x3C; } RtCtx;
typedef struct { int x0; int pad4; int addr[4]; unsigned short port; short pad1A; int list[14]; int timer54[2]; int timer5C[2]; int x64; int pad68[2]; int x70; int pad74[5]; int x88; int key; } RtConn;
typedef struct RtPkt RtPkt;
extern int rt_time_elapsed(void *, unsigned int *);
extern void rt_time_start(void *);
extern void rt_time_get_time_stamp(void *);
extern int rt_list_buf_get_head(void *, RtPkt **);
extern RtPkt *rt_list_buf_get_next(RtPkt *);
extern int rt_list_buf_get_data_ptr(RtPkt *);
extern void rt_list_buf_remove(void *, RtPkt *);
extern int rt_udp_get_send_header(RtPkt *, RtHdr *);
extern void rt_udp_set_send_header(RtPkt *, RtHdr *);
extern void rt_udp_get_packet_header(RtPkt *, RtPktHdr *);
extern void rt_udp_set_packet_header(RtPkt *, RtPktHdr *);
extern void rt_udp_get_packet_seed(RtPkt *, int *);
extern void rt_udp_set_packet_seed(RtPkt *, int);
extern void rt_udp_get_packet_data(RtPkt *, int *, int *);
int __attribute__((weak, section(".dtors_drop"))) GetUDPSecurityMode(void) { return 0; } /* stub: defined in the same original TU */
extern void KM_GetSymmetricKey(int, int, char *);
extern void KM_DeleteSymmetricKey(int, int);
extern int KM_Encrypt(int, int, int, int);
extern void KM_AddSymmetricKey(int, int, char *);
extern int Socket_WriteAddressed(int, int *, unsigned short, int, unsigned short, unsigned short *);

int RtUdp_SendPump(RtCtx *c, RtConn *k)
{
    RtHdr hdr;
    RtPktHdr h;
    char buf[64];
    unsigned short out;
    unsigned int now;
    RtPkt *pk = 0;
    unsigned int el;
    int a = 0;
    int b = 0;
    int enc = 0;
    RtPkt *last = 0;
    int expired;
    unsigned short n;
    int r;

    if (!k->x0) return 0;
    rt_time_elapsed(k->timer54, &now);
    if (!(c->x3C < now)) {
        if (!k->x88) return 0;
    }
    if (rt_list_buf_get_head(k->list, &pk) != 0) return 10;
    while (pk) {
        if (rt_udp_get_send_header(pk, &hdr) != 0) goto next;
        expired = 0;
        if (hdr.cnt) {
            rt_time_elapsed(hdr.t, &el);
            expired = k->x70 * hdr.cnt < el;
        }
        if (!expired && hdr.cnt) {
            pk = rt_list_buf_get_next(pk);
            continue;
        }
        rt_udp_get_packet_header(pk, &h);
        rt_udp_get_packet_data(pk, &a, &b);
        if (((unsigned short *)&h.w)[1] != b) goto next;
        out = 0;
        rt_udp_get_packet_seed(pk, &enc);
        if (enc == 0) {
            if (GetUDPSecurityMode() == 1) {
                if ((h.w & 0xFFFF8000) == 0x408000) {
                    KM_GetSymmetricKey(-1, k->key, buf);
                    KM_DeleteSymmetricKey(-1, k->key);
                    enc = KM_Encrypt(-1, k->key, a, b);
                    KM_AddSymmetricKey(-1, k->key, buf);
                } else if (((unsigned short *)&h.w)[1]) {
                    enc = KM_Encrypt(-1, k->key, a, b);
                }
                if (enc) {
                    rt_udp_set_packet_seed(pk, enc);
                    *(unsigned char *)&h.w |= 0x80;
                    rt_udp_set_packet_header(pk, &h);
                }
            }
        }
        n = b + 12;
        if (enc) n += 4;
        r = Socket_WriteAddressed(c->sock, k->addr, k->port, rt_list_buf_get_data_ptr(pk) + 12, n, &out);
        if (out == 0) break;
        if (r != 0 || n != out) return 16;
        if (h.seq == k->x64) {
            if (expired)
                k->x64 = 0;
            else
                rt_time_start(k->timer5C);
        }
        if (*(unsigned char *)&h.w & 4) {
            rt_time_start(hdr.t);
            if (!hdr.cnt)
                hdr.cnt = 2;
            else
                hdr.cnt++;
            rt_udp_set_send_header(pk, &hdr);
        } else
            last = pk;
        if (!expired && (*(unsigned char *)&h.w & 1))
            k->x88--;
        rt_time_get_time_stamp(k->timer54);
    next:
        pk = rt_list_buf_get_next(pk);
        if (last) {
            rt_list_buf_remove(k->list, last);
            last = 0;
        }
    }
    return 0;
}
