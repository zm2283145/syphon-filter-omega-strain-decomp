/* RtUdp packet parse/dispatch (medius). */
typedef struct { int state; char pad[0x88]; int key; } PpEnt;
typedef struct { int pad0; PpEnt *ents; char pad8[0x20]; char *buf; } PpSock;
typedef union { struct { unsigned char flags; unsigned char id; unsigned short len; int val; int seq; } h; unsigned int w; } PpHdr;
extern PpSock *D_00529860[];
extern void *memcpy(void *, const void *, unsigned int);
int __attribute__((weak, section(".dtors_drop"))) GetUDPSecurityMode(void) { return 0; } /* stub: defined in the same original TU */
extern int rt_udp_find_connection(PpSock *s, PpHdr *h, char *name, unsigned short port, int *idx);
extern int KM_Decrypt(int a, int key, int k, char *p, unsigned short len);
extern int rt_udp_process_peerkey(PpSock *s, PpEnt *e, PpHdr *h, char *p, unsigned short len);
extern int rt_udp_process_connect(PpSock *s, PpHdr *h, int idx);
extern int rt_udp_process_disconnect(PpSock *s, PpHdr *h, int idx);
extern int rt_udp_process_reset(PpSock *s, PpHdr *h);
extern int rt_udp_process_heartbeat(PpSock *s, PpHdr *h, int idx);
extern int rt_udp_process_acknowlege(PpSock *s, int idx, char *p, unsigned short len);
extern int rt_udp_process_data(PpSock *s, PpHdr *h, int idx, char *p, unsigned short len);
extern int rt_udp_process_unconnected_data(PpSock *s, PpHdr *h, char *name, unsigned short port, char *p, unsigned short len);
extern int rt_udp_process_new_connect(PpSock *s, PpHdr *h, char *name, unsigned short port);
extern int rt_udp_reset(PpSock *s, char *name, unsigned short port, int val);

int rt_udp_process_message(PpSock *s, char *name, unsigned short port, unsigned short len)
{
    PpHdr hdr;
    int key;
    int idx = -1;
    char *p;
    int enc;
    int k;
    PpEnt *e;
    int r;

    if (!name) return 1;
    if (!port) return 1;
    p = s->buf;
    len -= 12;
    memcpy(&hdr, p, 12);
    p += 12;
    if (hdr.h.len && (hdr.h.flags & 0x80)) {
        memcpy(&key, p + len - 4, 4);
        len -= 4;
        enc = 1;
    } else
        enc = 0;
    if (enc && GetUDPSecurityMode() != 1) return 0x13;
    if (len != hdr.h.len) return 5;
    k = hdr.h.id & 0x7F;
    if (k < 8) {
        if (k >= 0) {
            s = D_00529860[k];
            __asm__ __volatile__(""); /* scheduling barrier: keeps the hoisted `return 5` value after the table load (retail reuses v0 for k*4) */
            if (!s) return 5;
        }
    }
    r = rt_udp_find_connection(s, &hdr, name, port, &idx);
    if (r) return r;
    if (idx != -1) {
        if (!enc && hdr.h.len && GetUDPSecurityMode() == 1) return 0x14;
    } else {
        if (enc) {
            if ((hdr.w & 0xFFFF8000) == 0x408000) {
                r = rt_udp_process_new_connect(s, &hdr, name, port);
                if (r) return r;
            }
            return 0;
        }
        if (len == 0) {
            if (hdr.h.flags & 0x40) {
                if (GetUDPSecurityMode() == 1) return 0;
                r = rt_udp_process_new_connect(s, &hdr, name, port);
                if (r) return r;
            } else {
                if (!(hdr.h.flags & 0x10)) {
                    if (hdr.h.flags & 0x08) return 3;
                }
                r = rt_udp_reset(s, name, port, hdr.h.val);
                if (r) return r;
            }
        } else {
            if (hdr.h.flags & 0x20) return 3;
            if (hdr.h.flags & 0x40) return 3;
            if (!hdr.h.flags) {
                r = rt_udp_process_unconnected_data(s, &hdr, name, port, p, len);
                if (r) return r;
            }
        }
        return 0;
    }
    e = &s->ents[idx];
    if (enc && KM_Decrypt(-1, e->key, key, p, len)) return 0;
    if ((hdr.w & 0xFFFF8000) == 0x408000) {
        r = rt_udp_process_peerkey(s, e, &hdr, p, len);
        if (r) return r;
    } else if (hdr.h.len == 0) {
        if (hdr.h.flags & 0x40) {
            if (GetUDPSecurityMode() == 1) {
                e->state = 6;
                return 0;
            }
            r = rt_udp_process_connect(s, &hdr, idx);
            if (r) return r;
        } else if (hdr.h.flags & 0x10) {
            r = rt_udp_process_disconnect(s, &hdr, idx);
            if (r) return r;
        } else if (hdr.h.flags & 0x08) {
            r = rt_udp_process_reset(s, &hdr);
            if (r) return r;
        } else {
            r = rt_udp_process_heartbeat(s, &hdr, idx);
            if (r) return r;
        }
    } else {
        if (hdr.h.flags & 0x20) {
            r = rt_udp_process_acknowlege(s, idx, p, len);
            if (r) return r;
        }
        if (hdr.h.flags & 0x40) {
            r = rt_udp_process_data(s, &hdr, idx, p, len);
            if (r) return r;
        }
        if (!hdr.h.flags) {
            r = rt_udp_process_unconnected_data(s, &hdr, name, port, p, len);
            if (r) return r;
        }
    }
    return 0;
}
