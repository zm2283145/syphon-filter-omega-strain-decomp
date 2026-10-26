/*
 * lib/medius: 11 files, 002DDFF8-002DE9F0
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002DDFF8 */
typedef struct { unsigned char c, d; char data[0x1FE]; } P2DDFF8;
unsigned char D_0048C4AC = 0;
extern int D_0048C4B0;
extern unsigned short D_0058C0B0;
extern P2DDFF8 D_0051F0D8;
extern int NetIEnableUDP(void);
extern void *memcpy(void *, const void *, unsigned int);
extern int Net_IpToString(char *, int);
extern int rt_p2p_send_to(int, char *, unsigned short, P2DDFF8 *, unsigned short);
int NetISendMessageByUDPToIP(int a, int b, unsigned int c, unsigned int d, int len, void *data)
{
    char buf[16];
    int r;
    if (!D_0048C4AC) {
        r = NetIEnableUDP();
        if (r) return r;
    }
    if (c >= 6) return 0x17;
    if (d >= 0x100) return 0x17;
    if (len <= 0) return 0x17;
    if (len >= 0x1FF) return 0x1F;
    if (data == 0) return 0x17;
    if (b == 0) return 0x17;
    D_0051F0D8.c = c;
    D_0051F0D8.d = d;
    memcpy(D_0051F0D8.data, data, len);
    Net_IpToString(buf, b);
    return rt_p2p_send_to(D_0048C4B0, buf, D_0058C0B0, &D_0051F0D8, len + 2) ? 0x25 : 0;
}
/* merge_units: end func_002DDFF8 */

/* merge_units: begin func_002DE100 */
typedef struct { unsigned char c, d; char data[0x1FE]; } P2DE100;
extern P2DE100 D_0051F2D8;
extern int Net_TranslateSendFlags(signed char, unsigned char *);
extern int NetGetConnInfo(unsigned int, char **);
extern int NetGetServerIpAddress(unsigned int);
#if 0 /* merge_units */
extern int rt_p2p_send_to(int, int, unsigned short, P2DE100 *, unsigned short);
#endif /* merge_units */
#define rt_p2p_send_to(a0, a1, a2, a3, a4) (rt_p2p_send_to((a0), (char *)(a1), (a2), (P2DDFF8 *)(a3), (a4))) /* merge_units */

extern int RtUdp_SendToPeers(int, int, unsigned char, P2DE100 *, unsigned short);

int Net_SendPrefixedA(signed char type, unsigned int idx, int port, unsigned int c, unsigned int d, int len, void *data)
{
    char *p = 0;
    unsigned char flags = 0;
    int r;
    if (idx >= 4) return 0x17;
    if (c >= 6) return 0x17;
    if (d >= 0x100) return 0x17;
    if (len <= 0) return 0x17;
    if (len >= 0x1FF) return 0x1F;
    if (data == 0) return 0x17;
    r = Net_TranslateSendFlags(type, &flags);
    if (r) return r;
    D_0051F2D8.c = c;
    D_0051F2D8.d = d;
    memcpy(D_0051F2D8.data, data, len);
    if (port == 0xFFFF) {
        if (rt_p2p_send_to(D_0048C4B0, NetGetServerIpAddress(idx), D_0058C0B0, &D_0051F2D8, len + 2)) return 0x25;
    } else {
        r = NetGetConnInfo(idx, &p);
        if (r) return r;
        if (p == 0) return r;
        if (port != *(int *)(p + 0x400)) {
            if (RtUdp_SendToPeers(D_0048C4B0, port, flags, &D_0051F2D8, len + 2)) return 0x25;
        }
    }
    return r;
}
#undef rt_p2p_send_to /* merge_units */
/* merge_units: end func_002DE100 */

/* merge_units: begin func_002DE280 */
typedef struct { unsigned char d, e; char data[0x1FE]; } P2DE280;
extern P2DE280 D_0051F4D8;
extern int Net_SendConvertRecipient(signed char, unsigned int, int, int, P2DE280 *);
int Net_SendPrefixedB(signed char a, unsigned int idx, int c, unsigned int d, unsigned int e, int len, void *data)
{
    char *p = 0;
    int r;
    if (idx >= 4) return 0x17;
    if (d >= 6) return 0x17;
    if (e >= 0x100) return 0x17;
    if (len <= 0) return 0x17;
    if (len >= 0x1FF) return 0x1F;
    if (data == 0) return 0x17;
    r = NetGetConnInfo(idx, &p);
    if (r) return r;
    if (p == 0) return r;
    if (c == *(int *)(p + 0x400)) return r;
    D_0051F4D8.d = d;
    D_0051F4D8.e = e;
    memcpy(D_0051F4D8.data, data, len);
    return Net_SendConvertRecipient(a, idx, c, len + 2, &D_0051F4D8);
}
/* merge_units: end func_002DE280 */

/* merge_units: begin func_002DE398 */
typedef struct NetHdr {
    unsigned char chan;
    unsigned char sub;
    unsigned short len;
    unsigned short count;
    unsigned short index;
    unsigned char seq;
    unsigned char pad[3];
    int total;
    int offset;
} NetHdr;

typedef struct NetConn {
    char pad[0x44C];
    int state;
} NetConn;

extern int D_005983EC;
#if 0 /* merge_units */
extern int NetGetConnInfo(int, NetConn **);
#endif /* merge_units */
#define NetGetConnInfo(a0, a1) (NetGetConnInfo((unsigned int)(a0), (char * *)(a1))) /* merge_units */

extern unsigned char randomMT();
#if 0 /* merge_units */
extern int Net_SendPrefixedA(char, int, int, unsigned int, unsigned int, int, void *);
#endif /* merge_units */
#define Net_SendPrefixedA(a0, a1, a2, a3, a4, a5, a6) (Net_SendPrefixedA((signed char)(a0), (unsigned int)(a1), (a2), (a3), (a4), (a5), (a6))) /* merge_units */

#if 0 /* merge_units */
extern int Net_SendPrefixedB(char, int, int, unsigned int, unsigned int, int, void *);
#endif /* merge_units */
#define Net_SendPrefixedB(a0, a1, a2, a3, a4, a5, a6) (Net_SendPrefixedB((signed char)(a0), (unsigned int)(a1), (a2), (a3), (a4), (a5), (a6))) /* merge_units */


/* Sends a typed message, splitting payloads of 0x1FF+ bytes into 0x1EA-byte chunks with a 0x14-byte header. */
int Net_SendTyped(char type, int dest, int port, unsigned int chan, unsigned int sub, int len, void *data)
{
    NetConn *conn;
    unsigned int flags;
    int sent;
    int plen;
    int n;
    int i;
    char ptype;
    unsigned int tag;
    NetHdr h;
    char pkt[0x200];
    int r;

    sent = 0;
    plen = 0;
    conn = 0;
    if (chan >= 6)
        return 0x17;
    if (sub >= 0x100)
        return 0x17;
    if (len <= 0)
        return 0x17;
    if (data == 0)
        return 0x17;
    r = NetGetConnInfo(dest, &conn);
    if (r != 0 || conn == 0)
        return r;
    if (conn->state == 4)
        return 0xF;
    if (len >= 0x1FF) {
        if (port == 0xFFFF)
            return 0x1F;
        n = (unsigned int)(len + 0x1E9) / 0x1EA;
        tag = D_005983EC;
        flags = 0;
        ptype = type | 0x50;
        h.seq = randomMT();
    } else {
        plen = len;
        ptype = type;
        flags = chan;
        sent = plen;
        tag = sub;
        n = 1;
        memcpy(pkt, data, plen);
    }
    for (i = 0; i < n; i++) {
        if (plen != len) {
            int chunk = len - sent;
            if (chunk > 0x1EA)
                chunk = 0x1EA;
            h.index = i;
            h.chan = chan;
            h.sub = sub;
            h.total = len;
            plen = chunk + 0x14;
            h.count = n;
            h.len = chunk;
            h.offset = sent;
            memcpy(pkt, &h, 0x14);
            memcpy(pkt + 0x14, (char *)data + sent, chunk);
            sent += chunk;
        }
        if (dest == 0xFFFF || dest == 0) {
            r = Net_SendPrefixedA(ptype, dest, port, flags, tag, plen, pkt);
            if (r != 0)
                return r;
        } else {
            r = Net_SendPrefixedB(ptype, dest, port, flags, tag, plen, pkt);
            if (r != 0)
                return r;
        }
    }
    return 0;
}
#undef NetGetConnInfo /* merge_units */
#undef Net_SendPrefixedA /* merge_units */
#undef Net_SendPrefixedB /* merge_units */
/* merge_units: end func_002DE398 */

/* merge_units: begin func_002DE5E8 */
typedef struct { signed char bits[0x24]; int lo; int hi; } Set;
typedef struct { char p[0x400]; int self; char p2[0x48]; int state; } Conn;
#if 0 /* merge_units */
extern int NetGetConnInfo(unsigned int, Conn **);
#endif /* merge_units */
#define NetGetConnInfo(a0, a1) (NetGetConnInfo((a0), (char * *)(a1))) /* merge_units */

extern int NetIGetClient(int *, unsigned int, int);
#if 0 /* merge_units */
extern int Net_SendTyped(char, int, int, unsigned int, unsigned int, int, void *);
#endif /* merge_units */
#define Net_SendTyped(a0, a1, a2, a3, a4, a5, a6) (Net_SendTyped((a0), (a1), (a2), (a3), (a4), (a5), (a6))) /* merge_units */


int NetSendTargetClientBitmask(signed char type, unsigned int idx, unsigned int chan, unsigned int sub, int len, void *data, Set *s)
{
    Conn *conn = 0;
    int ok = 0;
    int r;
    int i;
    if (chan >= 6) return 0x17;
    if (sub >= 0x100) return 0x17;
    if (len <= 0) return 0x17;
    if (data == 0) return 0x17;
    if (s == 0) return 0x17;
    r = NetGetConnInfo(idx, &conn);
    if (r) return r;
    if (conn == 0) return r;
    if (conn->state == 4) return 0xF;
    if (s->hi >= 0) for (i = s->lo; i <= s->hi; i++) {
        if (i == conn->self) continue;
        NetIGetClient(&ok, idx, i);
        if (ok && ((s->bits[i >> 3] >> (i & 7)) & 1)) {
            if (Net_SendTyped(type, idx, i, chan, sub, len, data)) r = 0xD;
        }
    }
    return r;
}

/* score: 3 insn diff (sra v0/v1 scheduling in bit test) */
#undef NetGetConnInfo /* merge_units */
#undef Net_SendTyped /* merge_units */
/* merge_units: end func_002DE5E8 */

/* merge_units: begin func_002DE770 */
extern void FilterTargetClientBitmask(char *, int, int);
#if 0 /* merge_units */
extern int NetSendTargetClientBitmask(signed char, int, unsigned int, unsigned int, int, int, char *);
#endif /* merge_units */
#define NetSendTargetClientBitmask(a0, a1, a2, a3, a4, a5, a6) (NetSendTargetClientBitmask((a0), (unsigned int)(a1), (a2), (a3), (a4), (void *)(a5), (Set *)(a6))) /* merge_units */

int NetISendFilteredMessage(signed char a, int b, unsigned int c, unsigned int d, int e, int f, int g)
{
    char buf[0x30];
    if (c >= 6) return 0x17;
    if (d >= 0x100) return 0x17;
    if (e <= 0) return 0x17;
    if (f == 0) return 0x17;
    FilterTargetClientBitmask(buf, b, g);
    return NetSendTargetClientBitmask(a, b, c, d, e, f, buf);
}
#undef NetSendTargetClientBitmask /* merge_units */
/* merge_units: end func_002DE770 */

/* merge_units: begin func_002DE828 */
#if 0 /* merge_units */
extern int Net_SendTyped(signed char, int, int, int, unsigned int, int, int);
#endif /* merge_units */
#define Net_SendTyped(a0, a1, a2, a3, a4, a5, a6) (Net_SendTyped((char)(a0), (a1), (a2), (unsigned int)(a3), (a4), (a5), (void *)(a6))) /* merge_units */

int NetISendApplicationMessage(signed char a, int b, int c, unsigned int d, int e, int f)
{
    if (d >= 0x100) return 0x17;
    if (e <= 0) return 0x17;
    if (f == 0) return 0x17;
    return Net_SendTyped(a, b, c, 2, d, e, f);
}
#undef Net_SendTyped /* merge_units */
/* merge_units: end func_002DE828 */

/* merge_units: begin func_002DE880 */
#if 0 /* merge_units */
extern int Net_SendTyped(signed char, int, int, int, unsigned int, int, int);
#endif /* merge_units */
#define Net_SendTyped(a0, a1, a2, a3, a4, a5, a6) (Net_SendTyped((char)(a0), (a1), (a2), (unsigned int)(a3), (a4), (a5), (void *)(a6))) /* merge_units */

int NetSendDmeMessage(signed char a, int b, int c, unsigned int d, int e, int f)
{
    if (d >= 0x100) return 0x17;
    if (e <= 0) return 0x17;
    if (f == 0) return 0x17;
    return Net_SendTyped(a, b, c, 0, d, e, f);
}
#undef Net_SendTyped /* merge_units */
/* merge_units: end func_002DE880 */

/* merge_units: begin func_002DE8D8 */
extern int NetIGetObject(unsigned char **, unsigned int);
extern void (*D_0058C0B8[])(unsigned int, unsigned int);
void RemoteObjectCreation(unsigned int a, unsigned int b)
{
    unsigned char *p;
    void (*f)(unsigned int, unsigned int);
    if (a < 0x100 && b < 0x1000) {
        NetIGetObject(&p, b);
        if (p) {
            f = D_0058C0B8[*p];
            if (f) f(a, b);
        }
    }
}
/* merge_units: end func_002DE8D8 */

/* merge_units: begin func_002DE950 */
extern void (*D_0058C0F8[])(int, unsigned int, unsigned int);
void RemoteObjectUpdate(int a, unsigned int b, unsigned int c)
{
    unsigned char *p;
    void (*f)(int, unsigned int, unsigned int);
    if (b >= 0x1000) return;
    if (c < 0x40 || c == -2 || c == -1) {
        NetIGetObject(&p, b);
        if (p) {
            f = D_0058C0F8[*p];
            if (f) f(a, b, c);
        }
    }
}
/* merge_units: end func_002DE950 */

/* merge_units: begin func_002DE9F0 */
extern void (*D_0058C138[])(unsigned int, unsigned int);
void RemoteObjectDelete(unsigned int a, unsigned int b)
{
    unsigned char *p;
    void (*f)(unsigned int, unsigned int);
    if (a < 0x100 && b < 0x1000) {
        NetIGetObject(&p, b);
        if (p) {
            f = D_0058C138[*p];
            if (f) f(a, b);
        }
    }
}
/* merge_units: end func_002DE9F0 */
