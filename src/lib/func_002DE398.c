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
extern void *memcpy(void *, const void *, unsigned int);
extern int func_002E51B8(int, NetConn **);
extern unsigned char func_00301F40();
extern int Net_SendPrefixedA(char, int, int, unsigned int, unsigned int, int, void *);
extern int Net_SendPrefixedB(char, int, int, unsigned int, unsigned int, int, void *);

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
    r = func_002E51B8(dest, &conn);
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
        h.seq = func_00301F40();
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





