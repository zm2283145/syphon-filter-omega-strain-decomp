/*
 * lib/medius: 8 files, 00309FD8-0030A9D8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00309FD8 */
typedef struct { unsigned char flags; unsigned char id; unsigned short len; int val; int seq; } ScfHdr;
typedef struct { unsigned int type; char pad[4]; char name[16]; unsigned short port; char pad1[2]; int sendlist; char pad2[0x14]; int recvlist; char pad3[0x14]; int timer[2]; char pad4[0x18]; int f6C; int f70; int f74; int f78; int f7C; int f80; int f84; char pad5[8]; } ScfPeer;
typedef struct { int sock; ScfPeer *ents; char pad[0x28]; int pool1; int pool2; char pad2[0xC]; unsigned char b44; } ScfSock;
typedef struct { int f0; int f4; int f8; } ScfInfo;
extern char *strncpy(char *d, const char *s, unsigned int n);
extern int func_003089B0(ScfSock *s, int *idx);
extern int func_00306DE0(void);
extern int func_003060C0(int *timer);
extern int func_002FA4C8(int *list, int pool);
extern int func_0030AB20(ScfSock *s, ScfPeer *e);
extern int RtUdp_BuildHeader(ScfSock *s, ScfPeer *e, int kind, ScfHdr *hd);
extern int RtUdp_CopyPacket(ScfPeer *e, ScfHdr *hd, void *data, int len);
extern int RtUdp_QueueAck(ScfSock *s, ScfPeer *e, ScfInfo *info);

int func_00309FD8(ScfSock *s, ScfInfo *info, char *name, unsigned short port)
{
    ScfHdr hd;
    ScfPeer *e = 0;
    int idx = -1;
    int ret;
    if (info->f4 == 0) return 0;
    for (;;) {
        ret = func_003089B0(s, &idx);
        if (ret != 0) { ret = 7; break; }
        if (idx == -1) { ret = 7; break; }
        e = &s->ents[idx];
        e->f74 = info->f4;
        e->f78 = func_00306DE0();
        e->f7C = func_00306DE0();
        e->f80 = 0;
        e->port = port;
        e->f84 = info->f8;
        strncpy(e->name, name, 16);
        func_003060C0(e->timer);
        e->f70 = 1000;
        e->f6C = 0;
        if (func_002FA4C8(&e->sendlist, s->pool1) != 0 || func_002FA4C8(&e->recvlist, s->pool2) != 0) {
            e->type = 6;
            func_0030AB20(s, e);
            ret = 7;
        }
        break;
    }
    if (ret != 0) return ret;
    switch (e->type) {
    case 0:
        if (s->b44 == 0) {
            e->type = 7;
            break;
        }
        e->type = 9;
        ret = RtUdp_BuildHeader(s, e, 4, &hd);
        if (ret != 0) {
fail:
            e->type = 1;
            func_0030AB20(s, e);
            return ret;
        }
        hd.flags |= 0x40;
        ret = RtUdp_CopyPacket(e, &hd, 0, 0);
        if (ret != 0) goto fail;
        ret = RtUdp_QueueAck(s, e, info);
        break;
    case 8:
    case 9:
    case 11:
    case 12:
        ret = RtUdp_QueueAck(s, e, info);
        break;
    default:
        e->type = 1;
        ret = func_0030AB20(s, e);
        break;
    }
    return ret;
}
/* merge_units: end func_00309FD8 */

/* merge_units: begin func_0030A218 */
typedef struct { unsigned int type; char pad[0x8C]; } ScfPeer_0030A218;
typedef struct { int sock; ScfPeer_0030A218 *ents; } ScfSock_0030A218;
extern int RtUdp_CheckDuplicate(ScfSock_0030A218 *s, ScfPeer_0030A218 *e, void *p, unsigned char *dup);
#if 0 /* merge_units */
extern int RtUdp_QueueAck(ScfSock_0030A218 *s, ScfPeer_0030A218 *e, void *p);
#endif /* merge_units */
#define RtUdp_QueueAck(a0, a1, a2) (RtUdp_QueueAck((ScfSock *)(a0), (ScfPeer *)(a1), (ScfInfo *)(a2))) /* merge_units */

#if 0 /* merge_units */
extern int func_0030AB20(ScfSock_0030A218 *s, ScfPeer_0030A218 *e);
#endif /* merge_units */
#define func_0030AB20(a0, a1) (func_0030AB20((ScfSock *)(a0), (ScfPeer *)(a1))) /* merge_units */


int func_0030A218(ScfSock_0030A218 *s, void *p, int idx)
{
    ScfPeer_0030A218 *e;
    unsigned char dup = 0;
    if (idx == -1) return 7;
    e = &s->ents[idx];
    RtUdp_CheckDuplicate(s, e, p, &dup);
    if (!dup) {
        if (e->type == 12) {
            e->type = 3;
            return RtUdp_QueueAck(s, e, p);
        } else if (e->type - 4 < 2) {
            return RtUdp_QueueAck(s, e, p);
        } else {
            e->type = 1;
            return func_0030AB20(s, e);
        }
    } else {
        return RtUdp_QueueAck(s, e, p);
    }
}
#undef RtUdp_QueueAck /* merge_units */
#undef func_0030AB20 /* merge_units */
/* merge_units: end func_0030A218 */

/* merge_units: begin func_0030A300 */
typedef struct { int type; char pad[0x18]; int f1C; int f20; int f24; int f28; int f2C; int f30; int f34; int f38; int f3C; char pad2[0x4C]; int f8C; } ScfEnt;
typedef struct { int f0; ScfEnt *ent; char pad[0x24]; unsigned int count; } ScfTbl;

extern void func_002FA5B0(int *p);
int func_0030A300(ScfTbl *t, int unused, int idx)
{
    ScfEnt *e;
    int ret = 7;
    if (idx == -1) return ret;
    e = &t->ent[idx];
    if (e->type != 4) {
        e->type = 1;
        func_002FA5B0(&e->f1C);
        func_002FA5B0(&e->f34);
    }
    return 0;
}
/* merge_units: end func_0030A300 */

/* merge_units: begin func_0030A368 */
typedef struct { unsigned char kind; unsigned char id; unsigned short len; int val; int seq; } ScfHdr_0030A368;
typedef struct { int type; char pad[0x48]; int f4C; char pad2[0x24]; int f74; char pad3[0x18]; } ScfPeer_0030A368;
typedef struct { int sock; ScfPeer_0030A368 *ents; char pad[0x40]; unsigned char b48; } ScfSock_0030A368;
extern void *memset(void *d, int c, unsigned int n);
extern int Name_Compare48(const void *a, const void *b, int n);
extern void func_003060D8(int *t);

int func_0030A368(ScfSock_0030A368 *s, void *key, int idx)
{
    ScfHdr_0030A368 hdr;
    ScfPeer_0030A368 *e;
    int ret = 0;
    if (idx == -1) return 7;
    e = &s->ents[idx];
    memset(&hdr, 0, 12);
    hdr.val = e->f74;
    hdr.id = s->b48;
    if (Name_Compare48(&hdr, key, 12) == 0 && e->type == 12) {
        func_003060D8(&e->f4C);
    } else {
        ret = 4;
        if (e->type != 12) ret = 5;
    }
    return ret;
}
/* merge_units: end func_0030A368 */

/* merge_units: begin func_0030A440 */
typedef struct { unsigned char b[4]; } ScfU32u;
typedef struct { unsigned char flags; ScfU32u seq; } ScfAckIn;
typedef struct { unsigned char flags; int seq; } ScfAck;
typedef struct { unsigned int type; char pad[0x18]; int list; char pad2[0x2C]; int timer[2]; char pad3[0x3C]; } ScfPeer_0030A440;
typedef struct { int sock; ScfPeer_0030A440 *ents; } ScfSock_0030A440;
extern void *memcpy(void *d, const void *s, unsigned int n);
extern int RtUdp_UpdateRtt(ScfSock_0030A440 *s, ScfPeer_0030A440 *e, unsigned char flags, int seq);
extern int func_002FABD0(int *list, void **node);
extern unsigned int func_002FAEE8(void *node);
extern int func_00308F58(void *node, ScfHdr *out);
extern int func_002FA830(int *list, void *node);
extern void *func_002FAF00(void *node);
#if 0 /* merge_units */
extern void func_003060D8(int *timer);
#endif /* merge_units */
#define func_003060D8(a0) (func_003060D8((a0))) /* merge_units */


int RtUdp_HandleAck(ScfSock_0030A440 *s, int idx, ScfAckIn *in)
{
    ScfHdr hd;
    unsigned char aflags;
    int aseq;
    void *node = 0;
    ScfPeer_0030A440 *e;
    int ret;
    aflags = 0;
    aseq = 0;
    if (idx == -1) return 7;
    e = &s->ents[idx];
    memcpy(&aflags, &in->flags, 1);
    memcpy(&aseq, &in->seq, 4);
    ret = RtUdp_UpdateRtt(s, e, aflags, aseq);
    if (func_002FABD0(&e->list, &node) != 0) return 10;
    while (node != 0) {
        if (func_002FAEE8(node) != 0) {
            ret = func_00308F58(node, &hd);
            if (ret == 0 && hd.flags == aflags && hd.seq == aseq) {
                if (func_002FA830(&e->list, node) != 0) ret = 10;
                if (hd.len == 0) {
                    if (hd.flags & 0x40) e->type = 11;
                    if (hd.flags & 0x10) e->type = 4;
                } else if ((hd.id & 0x80) && hd.len == 0x40) {
                    e->type = 11;
                }
                func_003060D8(e->timer);
                return ret;
            }
        }
        node = func_002FAF00(node);
    }
    return ret;
}
#undef func_003060D8 /* merge_units */
/* merge_units: end func_0030A440 */

/* merge_units: begin func_0030A5C8 */
typedef struct { unsigned char b[12]; } ScfAddr12;
typedef struct { union { unsigned int w; struct { unsigned char flags; unsigned char id; unsigned short len; } f; } u; int val; unsigned int seq; } ScfHdr_0030A5C8;
typedef struct { unsigned int type; char pad[0x30]; int recvlist; char pad2[0x14]; int timer[2]; char pad3[0x2C]; unsigned int f80; char pad4[0xC]; } ScfPeer_0030A5C8;
typedef struct { int sock; ScfPeer_0030A5C8 *ents; char pad[0x20]; void *buf; } ScfSock_0030A5C8;
#if 0 /* merge_units */
extern void func_003060D8(int *timer);
#endif /* merge_units */
#define func_003060D8(a0) (func_003060D8((a0))) /* merge_units */

#if 0 /* merge_units */
extern int RtUdp_CheckDuplicate(ScfSock_0030A5C8 *s, ScfPeer_0030A5C8 *e, ScfHdr_0030A5C8 *p, unsigned char *dup);
#endif /* merge_units */
#define RtUdp_CheckDuplicate(a0, a1, a2, a3) (RtUdp_CheckDuplicate((ScfSock_0030A218 *)(a0), (ScfPeer_0030A218 *)(a1), (void *)(a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern int RtUdp_QueueAck(ScfSock_0030A5C8 *s, ScfPeer_0030A5C8 *e, ScfHdr_0030A5C8 *p);
#endif /* merge_units */
#define RtUdp_QueueAck(a0, a1, a2) (RtUdp_QueueAck((ScfSock *)(a0), (ScfPeer *)(a1), (ScfInfo *)(a2))) /* merge_units */

extern char *func_002FAED0(void *node);
extern int func_002FAC20(int *list, void **node);
extern int func_002FA5F8(int *list, void *node, void *data, int len);
extern int func_002FA758(int *list, void *data, int len);

int RtUdp_ReceiveData(ScfSock_0030A5C8 *s, ScfHdr_0030A5C8 *p, int idx)
{
    ScfHdr_0030A5C8 hd;
    void *node = 0;
    unsigned char dup = 0;
    void *prev = 0;
    int inserted = 0;
    ScfPeer_0030A5C8 *e;
    int ret;
    if (idx == -1) return 7;
    e = &s->ents[idx];
    func_003060D8(e->timer);
    ret = RtUdp_CheckDuplicate(s, e, p, &dup);
    if (!dup) {
        if ((p->u.w & 6) == 6 || (p->u.f.flags & 4)) {
            int *list = &e->recvlist;
            func_002FABD0(list, &node);
            for (; node != 0; node = func_002FAF00(node)) {
                if (func_002FAEE8(node) == 0) continue;
                *(ScfAddr12 *)&hd = *(ScfAddr12 *)func_002FAED0(node);
                if (!((hd.u.w & 6) == 6 || (hd.u.f.flags & 4))) continue;
                if ((int)(hd.seq - p->seq) > 0) {
                    if (hd.seq <= 0x7FFFFFFE) {
                        if (p->seq > 0x7FFFFFFE) {
                            prev = node;
                            continue;
                        }
                    } else if (p->seq <= 0x7FFFFFFE) goto older;
                    if (prev) {
                        if (func_002FA5F8(list, prev, s->buf, p->u.f.len + 12) != 0) return 10;
                    } else {
                        if (func_002FA758(list, s->buf, p->u.f.len + 12) != 0) return 10;
                    }
                    inserted = 1;
                    break;
                }
older:
                prev = node;
            }
            if (!inserted) {
                if (func_002FAC20(list, &node) != 0) return 10;
                if (func_002FA5F8(list, node, s->buf, p->u.f.len + 12) != 0) return 10;
            }
            ret = RtUdp_QueueAck(s, e, p);
        } else {
            int *list;
            if (p->u.f.flags & 2) e->f80 = p->seq;
            list = &e->recvlist;
            if (func_002FAC20(list, &node) != 0) return 10;
            if (func_002FA5F8(list, node, s->buf, p->u.f.len + 12) != 0) return 10;
        }
    } else if (p->u.f.flags & 4) {
        ret = RtUdp_QueueAck(s, e, p);
    }
    return ret;
}
#undef func_003060D8 /* merge_units */
#undef RtUdp_CheckDuplicate /* merge_units */
#undef RtUdp_QueueAck /* merge_units */
/* merge_units: end func_0030A5C8 */

/* merge_units: begin func_0030A880 */
typedef struct {
    char name[16];
    unsigned short port;
} Rec_a880;

typedef struct {
    char pad[0xC];
    int tbl;
} Obj_a880;

#if 0 /* merge_units */
extern char *strncpy(char *, const char *, unsigned int);
#endif /* merge_units */
#define strncpy(a0, a1, a2) (strncpy((a0), (a1), (a2))) /* merge_units */

#if 0 /* merge_units */
extern int func_002FAC20(int *tbl, void **h);
#endif /* merge_units */
#define func_002FAC20(a0, a1) (func_002FAC20((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int func_002FA5F8(int *tbl, void *h, void *rec, int size);
#endif /* merge_units */
#define func_002FA5F8(a0, a1, a2, a3) (func_002FA5F8((a0), (a1), (a2), (a3))) /* merge_units */

extern int func_002FA930(int *tbl, void *h, void *data, int size);
#if 0 /* merge_units */
extern void func_002FA830(int *tbl, void *h);
#endif /* merge_units */
#define func_002FA830(a0, a1) ((void)func_002FA830((a0), (a1))) /* merge_units */


int func_0030A880(Obj_a880 *o, void *key, const char *name, unsigned short port,
                  void *data, unsigned short len)
{
    Rec_a880 rec;
    void *h = 0;
    int err = 0;
    int created = 0;

    if (func_002FAC20(&o->tbl, &h) != 0) return 10;
    do {
        strncpy(rec.name, name, 16);
        rec.port = port;
        if (func_002FA5F8(&o->tbl, h, &rec, sizeof(rec)) != 0) { err = 10; break; }
        created = 1;
        if (func_002FAC20(&o->tbl, &h) != 0) { err = 10; break; }
        if (func_002FA930(&o->tbl, h, key, 12) != 0) { err = 10; break; }
        if (func_002FA930(&o->tbl, h, data, len) != 0) { err = 10; break; }
    } while (0);
    if (err != 0 && created) {
        if (func_002FAC20(&o->tbl, &h) == 0) func_002FA830(&o->tbl, h);
    }
    return err;
}
#undef strncpy /* merge_units */
#undef func_002FAC20 /* merge_units */
#undef func_002FA5F8 /* merge_units */
#undef func_002FA830 /* merge_units */
/* merge_units: end func_0030A880 */

/* merge_units: begin func_0030A9D8 */
typedef struct { unsigned int type; int f4; char name[16]; unsigned short port; char pad[0x5A]; int f74; char pad3[0x18]; } ScfPeer_0030A9D8;
typedef struct { int sock; ScfPeer_0030A9D8 *ents; char pad[0x24]; unsigned int count; } ScfSock_0030A9D8;
typedef struct { int f0; int f4; } ScfPkt;
extern int String_CompareN(const char *a, const char *b, int n);

int func_0030A9D8(ScfSock_0030A9D8 *s, ScfPkt *p, const char *name, unsigned short port, int *out)
{
    unsigned int i;
    int fallback = -1;
    ScfPeer_0030A9D8 *e;
    int ret = 2;
    if (s == 0) return ret;
    ret = 1;
    if (p == 0) return ret;
    if (name == 0) return ret;
    if (out == 0) return ret;
    *out = -1;
    for (i = 0; i < s->count; i++) {
        e = &s->ents[i];
        if (e->type == 0) continue;
        if (String_CompareN(name, e->name, 16) != 0) continue;
        if (port != e->port) continue;
        if (p->f4 == e->f74) {
            *out = i;
            break;
        }
        if (e->type - 8 < 2) {
            if (p->f4 == 0 || e->f74 == 0) fallback = i;
        }
    }
    if (*out == -1 && fallback != -1) *out = fallback;
    return 0;
}
/* merge_units: end func_0030A9D8 */
