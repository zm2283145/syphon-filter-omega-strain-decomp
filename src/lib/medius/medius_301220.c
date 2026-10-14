/*
 * lib/medius: 3 files, 00301220-00301518
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00301220 */
extern unsigned int D_004908FC;
extern int D_004908F8;
extern void func_002FB3C0(int *);
extern int Net_AllocZeroed(int *, unsigned long);

int func_00301220(unsigned int n)
{
    if (n == 0) return 2;
    if (D_004908FC < n) {
        if (D_004908F8 != 0) func_002FB3C0(&D_004908F8);
        if (Net_AllocZeroed(&D_004908F8, n)) return 8;
        D_004908FC = n;
    }
    return 0;
}
/* merge_units: end func_00301220 */

/* merge_units: begin func_003012B0 */
typedef struct { unsigned int w0; unsigned short f4; unsigned short len; unsigned short pending; unsigned char data[1]; } M;
typedef struct { char pad0[6]; unsigned short h; char pad8[0x18]; char f20[0x48]; char q[0x18]; M msg; } C;
typedef struct { unsigned char type; char pad; unsigned short size; } H;
extern int func_002FE8B0(void);
extern int func_002FF220(C *, unsigned int);
extern int func_00301710(unsigned short, unsigned int *);
extern int func_002FB5C8(void);
extern int func_002F5988(void *, unsigned char **);
extern int func_00301988(unsigned char *, unsigned int);
extern void *memcpy(void *, const void *, unsigned int);
extern void *memset(void *, int, unsigned int);
extern unsigned int func_002F9780(unsigned short, int, unsigned char *, unsigned int);
extern int NetPacket_WritePrefix(unsigned char *, H *, volatile int *);
extern void func_00301A80(unsigned char *, unsigned int);
extern int NetRing_Commit(void *, int);
int NetConn_Flush(C *c)
{
    H hdr;
    volatile int x;
    unsigned int key;
    unsigned char *buf;
    void *q;
    M *m;
    unsigned int type;
    unsigned int len;
    unsigned int n;
    unsigned char *p;
    int total;
    int enc;
    int r;
    int ok;
    void *t;
    key = 0;
    buf = 0;
    ok = func_002FE8B0();
    if (ok != 1) return 2;
    q = c->q;
    if (q == 0) return 9;
    m = &c->msg;
    if (m == 0) return 9;
    type = m->w0 & 0x7F;
    len = m->len;
    t = c->f20;
    if (t == 0) return 9;
    if (m->pending == 0) return 0;
    if (len + 0x48 > 0x248) return 2;
    if (func_002FF220(c, len + 0x48) != 0) return 8;
    r = func_00301710(c->h, &key);
    if (r != 0) return r;
    enc = key != 0;
    if (enc == 1) {
        if (func_002FB5C8() != 1) return 0x1C;
    }
    if (func_002F5988(q, &buf) != 0) return 0x15;
    p = buf;
    total = 0;
    if (enc && len != 0) p += 7;
    else p += 3;
    if (type == 3 || type == 0x1B) {
        if (func_00301988(p, m->f4) != 0) return 7;
        p += 2;
        total = 2;
    }
    if (len != 0) {
        memcpy(p, m->data, len);
        if (enc == 1) {
            if ((key & 0xE0000000) == 0xE0000000) {
                n = (len + 0x3F) & 0xFFC0;
                if (len < n) {
                    memset(p + len, 0, n - len);
                    len = n;
                }
            }
            key = func_002F9780(c->h, 0xFFFF, p, len);
        }
        p += len;
        total += len;
    }
    hdr.type = type;
    if (enc) hdr.type = type | 0x80;
    hdr.size = total;
    r = NetPacket_WritePrefix(buf, &hdr, &x);
    if (r != 0) return r;
    if (enc == 1 && len != 0) func_00301A80(buf + 3, key);
    if (NetRing_Commit(q, p - buf) != 0) return 0x15;
    if ((unsigned int)(p - buf) > 0x248) return 2;
    m->len = 0;
    m->pending = 0;
    return 0;
}
/* merge_units: end func_003012B0 */

/* merge_units: begin func_00301518 */
typedef struct { unsigned char f0; char pad; unsigned short f2; } H_00301518;
extern int func_00300A58(unsigned char *, H_00301518 *, unsigned short *);
int func_00301518(unsigned char *buf, unsigned int len, unsigned int max, unsigned int *out)
{
    H_00301518 h;
    unsigned short x = 0;
    unsigned char *end;
    unsigned short sz;
    unsigned int v;
    int r;
    if (out == 0) return 2;
    *out = 0;
    if (buf == 0) return 2;
    end = buf + len;
    if (len <= max) {
        *out = len;
        return 0;
    }
    while (buf < end) {
        r = func_00300A58(buf, &h, &x);
        if (r != 0) return r;
        sz = x + h.f2;
        if (h.f2 != 0 && (h.f0 & 0x80)) sz += 4;
        v = *out + sz;
        if (max < v) return 0;
        buf += sz;
        *out = v;
    }
    return 0;
}
/* merge_units: end func_00301518 */
