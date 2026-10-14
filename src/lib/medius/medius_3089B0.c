/*
 * lib/medius: 6 files, 003089B0-00308EF8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_003089B0 */
typedef struct { int type; char pad[0x18]; int f1C; int f20; int f24; int f28; int f2C; int f30; int f34; int f38; int f3C; char pad2[0x4C]; int f8C; } ScfEnt;
typedef struct { int f0; ScfEnt *ent; char pad[0x24]; unsigned int count; } ScfTbl;
extern void *memset(void *d, int c, unsigned int n);
int func_003089B0(ScfTbl *t, int *out)
{
    unsigned int i = 0;
    if (out == 0) return 1;
    *out = -1;
    for (; i < t->count; i++) {
        if (t->ent[i].type == 0) {
            memset(&t->ent[i], 0, 0x90);
            *out = i;
            return 0;
        }
    }
    return 8;
}
/* merge_units: end func_003089B0 */

/* merge_units: begin func_00308A58 */
typedef struct { unsigned char kind; unsigned char id; unsigned short len; int val; int seq; } ScfHdr;
typedef struct { int sock; char pad[0x44]; unsigned char b48; } ScfSock;
typedef struct { int f0; int f4; int addr[4]; unsigned short port; char pad[0x5A]; int f74; int seq2; int seq4; } ScfPeer;

int RtUdp_BuildHeader(ScfSock *s, ScfPeer *e, unsigned char flags, ScfHdr *h)
{
    int ret = 1;
    if (h == 0) return ret;
    if (e == 0) return ret;
    memset(h, 0, 12);
    h->id = s->b48;
    h->val = e->f74;
    h->kind = flags;
    if ((flags & 6) == 6 || (flags & 4)) {
        h->seq = e->seq4;
        e->seq4++;
        if (e->seq4 == 0) e->seq4++;
    } else if (flags & 2) {
        h->seq = e->seq2;
        e->seq2++;
        if (e->seq2 == 0) e->seq2++;
    }
    return 0;
}
/* merge_units: end func_00308A58 */

/* merge_units: begin func_00308B38 */
typedef struct { unsigned char flags; unsigned char id; unsigned short len; int val; int seq; } ScfHdr_00308B38;
typedef struct { unsigned int type; char pad[0x18]; int list; char pad2[0x70]; } ScfPeer_00308B38;
extern int func_002FAC20(int *list, void **node);
extern int func_002FA5F8(int *list, void *node, void *data, int len);
extern int func_002FA930(int *list, void *node, void *data, int len);
extern int func_002FA830(int *list, void *node);

int RtUdp_CopyPacket(ScfPeer_00308B38 *e, ScfHdr_00308B38 *hd, void *data, int len)
{
    ScfHdr_00308B38 tmp;
    int zero;
    void *node = 0;
    int ok = 0;
    int ret = 0;
    unsigned int i;
    int r;
    if (hd == 0) return 1;
    if (e == 0) return 1;
    hd->len = len;
    for (i = 0; i < 4; i++) {
        r = func_002FAC20(&e->list, &node);
        if (r != 0) {
            ret = 10;
            break;
        }
        switch (i) {
        case 0:
            memset(&tmp, 0, 12);
            r = func_002FA5F8(&e->list, node, &tmp, 12);
            if (r == 0) ok = 1;
            break;
        case 1:
            if (ok) r = func_002FA930(&e->list, node, hd, 12);
            break;
        case 2:
            if (len && data && ok) r = func_002FA930(&e->list, node, data, len);
            break;
        case 3:
            zero = 0;
            if (len && data && ok) r = func_002FA930(&e->list, node, &zero, 4);
            break;
        default:
            r = 1;
            break;
        }
        if (r != 0) {
            if (ok && func_002FAC20(&e->list, &node) == 0) func_002FA830(&e->list, node);
            ret = 10;
            break;
        }
    }
    return ret;
}
/* merge_units: end func_00308B38 */

/* merge_units: begin func_00308D18 */
typedef struct {
    unsigned char flags;
    unsigned char b1;
    unsigned short off;
    unsigned char rest[8];
} Hdr8d18;

typedef struct {
    char pad[0x1C];
    int list;
} Obj8d18;

extern void *memcpy(void *, const void *, unsigned int);
#if 0 /* merge_units */
extern void *memset(void *, int, unsigned int);
#endif /* merge_units */
#define memset(a0, a1, a2) (memset((a0), (a1), (a2))) /* merge_units */

extern int func_00308F58(void *pkt, Hdr8d18 *out);
extern int func_00308FB8(void *pkt, Hdr8d18 *in);
#if 0 /* merge_units */
extern int func_002FA930(int *list, void *pkt, void *data, int size);
#endif /* merge_units */
#define func_002FA930(a0, a1, a2, a3) (func_002FA930((a0), (a1), (a2), (a3))) /* merge_units */

extern int func_002FABD0(int *list, void **pkt);
extern void *func_002FAF00(void *pkt);
extern char *func_002FAED0(void *pkt);
extern int func_002FAEE8(void *pkt);
extern int Name_Compare48(const char *a, const char *b, int n);

int func_00308D18(int unused, Obj8d18 *o, unsigned char flags, void *pkt, void *data, int len)
{
    Hdr8d18 hd, cur;
    char *p;

    if (pkt == 0) return 1;
    if (data == 0) return 1;
    if (len == 0) return 1;
    func_00308F58(pkt, &hd);
    if (func_002FA930(&o->list, pkt, data, len) != 0) return 10;
    func_002FABD0(&o->list, &pkt);
    while (pkt != 0) {
        func_00308F58(pkt, &cur);
        if (Name_Compare48((char *)&hd, (char *)&cur, 12) == 0) {
            memcpy(func_002FAED0(pkt) + hd.off + 0x18, data, len);
            p = func_002FAED0(pkt);
            p += func_002FAEE8(pkt);
            memset(p - 4, 0, 4);
            hd.off += len;
            hd.flags |= flags & 7;
            func_00308FB8(pkt, &hd);
            pkt = 0;
            break;
        }
        pkt = func_002FAF00(pkt);
    }
    return 0;
}
#undef memset /* merge_units */
#undef func_002FA930 /* merge_units */
/* merge_units: end func_00308D18 */

/* merge_units: begin func_00308E78 */
typedef struct { unsigned char b[12]; } ScfAddr12;
typedef struct { unsigned char b[4]; } ScfU32u;
#if 0 /* merge_units */
extern unsigned int func_002FAEE8(void *pkt);
#endif /* merge_units */
#define func_002FAEE8(a0) ((unsigned int)func_002FAEE8((a0))) /* merge_units */

#define SCF_PKT_GET12(name, off) int name(void *pkt, ScfAddr12 *out) { int ret = 1; if (pkt == 0) return ret; if (out == 0) return ret; *out = *(ScfAddr12 *)(func_002FAED0(pkt) + off); return 0; }
#define SCF_PKT_SET12(name, off) int name(void *pkt, ScfAddr12 *in) { int ret = 1; if (pkt == 0) return ret; if (in == 0) return ret; *(ScfAddr12 *)(func_002FAED0(pkt) + off) = *in; return 0; }

int func_00308E78(void *pkt, ScfAddr12 *out)
{
    int ret = 1;
    if (pkt == 0) return ret;
    if (out == 0) return ret;
    if (func_002FAEE8(pkt) != 0) {
        *out = *(ScfAddr12 *)func_002FAED0(pkt);
        return 0;
    }
    return 10;
}
#undef func_002FAEE8 /* merge_units */
/* merge_units: end func_00308E78 */

/* merge_units: begin func_00308EF8 */
#if 0 /* merge_units */
extern unsigned int func_002FAEE8(void *pkt);
#endif /* merge_units */
#define func_002FAEE8(a0) ((unsigned int)func_002FAEE8((a0))) /* merge_units */
SCF_PKT_SET12(func_00308EF8, 0)
#undef func_002FAEE8 /* merge_units */
/* merge_units: end func_00308EF8 */
