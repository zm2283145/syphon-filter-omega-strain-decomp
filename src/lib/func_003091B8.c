typedef struct { unsigned char cnt; char pad1[3]; int t[3]; } RtHdr;
typedef struct { unsigned int w; int x4; int seq; int xC; } RtPktHdr;
typedef struct { int sock; int pad4[14]; unsigned int x3C; } RtCtx;
typedef struct { int x0; int pad4; int addr[4]; unsigned short port; short pad1A; int list[14]; int timer54[2]; int timer5C[2]; int x64; int pad68[2]; int x70; int pad74[5]; int x88; int key; } RtConn;
typedef struct RtPkt RtPkt;
extern int func_003060F0(void *, unsigned int *);
extern void func_003060C0(void *);
extern void func_003060D8(void *);
extern int func_002FABD0(void *, RtPkt **);
extern RtPkt *func_002FAF00(RtPkt *);
extern int func_002FAED0(RtPkt *);
extern void func_002FA830(void *, RtPkt *);
extern int func_00308E78(RtPkt *, RtHdr *);
extern void func_00308EF8(RtPkt *, RtHdr *);
extern void func_00308F58(RtPkt *, RtPktHdr *);
extern void func_00308FB8(RtPkt *, RtPktHdr *);
extern void func_00309018(RtPkt *, int *);
extern void func_003090A8(RtPkt *, int);
extern void func_00309120(RtPkt *, int *, int *);
int __attribute__((weak, section(".dtors_drop"))) func_00306D88(void) { return 0; } /* stub: defined in the same original TU */
extern void func_002F8DC8(int, int, char *);
extern void func_002F8F70(int, int);
extern int func_002F9780(int, int, int, int);
extern void func_002F8C50(int, int, char *);
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
    func_003060F0(k->timer54, &now);
    if (!(c->x3C < now)) {
        if (!k->x88) return 0;
    }
    if (func_002FABD0(k->list, &pk) != 0) return 10;
    while (pk) {
        if (func_00308E78(pk, &hdr) != 0) goto next;
        expired = 0;
        if (hdr.cnt) {
            func_003060F0(hdr.t, &el);
            expired = k->x70 * hdr.cnt < el;
        }
        if (!expired && hdr.cnt) {
            pk = func_002FAF00(pk);
            continue;
        }
        func_00308F58(pk, &h);
        func_00309120(pk, &a, &b);
        if (((unsigned short *)&h.w)[1] != b) goto next;
        out = 0;
        func_00309018(pk, &enc);
        if (enc == 0) {
            if (func_00306D88() == 1) {
                if ((h.w & 0xFFFF8000) == 0x408000) {
                    func_002F8DC8(-1, k->key, buf);
                    func_002F8F70(-1, k->key);
                    enc = func_002F9780(-1, k->key, a, b);
                    func_002F8C50(-1, k->key, buf);
                } else if (((unsigned short *)&h.w)[1]) {
                    enc = func_002F9780(-1, k->key, a, b);
                }
                if (enc) {
                    func_003090A8(pk, enc);
                    *(unsigned char *)&h.w |= 0x80;
                    func_00308FB8(pk, &h);
                }
            }
        }
        n = b + 12;
        if (enc) n += 4;
        r = Socket_WriteAddressed(c->sock, k->addr, k->port, func_002FAED0(pk) + 12, n, &out);
        if (out == 0) break;
        if (r != 0 || n != out) return 16;
        if (h.seq == k->x64) {
            if (expired)
                k->x64 = 0;
            else
                func_003060C0(k->timer5C);
        }
        if (*(unsigned char *)&h.w & 4) {
            func_003060C0(hdr.t);
            if (!hdr.cnt)
                hdr.cnt = 2;
            else
                hdr.cnt++;
            func_00308EF8(pk, &hdr);
        } else
            last = pk;
        if (!expired && (*(unsigned char *)&h.w & 1))
            k->x88--;
        func_003060D8(k->timer54);
    next:
        pk = func_002FAF00(pk);
        if (last) {
            func_002FA830(k->list, last);
            last = 0;
        }
    }
    return 0;
}
