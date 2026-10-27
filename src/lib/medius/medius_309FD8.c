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
extern int rt_udp_find_free_connection(ScfSock *s, int *idx);
extern int randomNoneZero(void);
extern int rt_time_start(int *timer);
extern int rt_list_buf_create(int *list, int pool);
extern int rt_udp_send_reset(ScfSock *s, ScfPeer *e);
extern int rt_udp_setup_packet_header(ScfSock *s, ScfPeer *e, int kind, ScfHdr *hd);
extern int rt_udp_buffer_data_for_send(ScfPeer *e, ScfHdr *hd, void *data, int len);
extern int rt_udp_send_ack(ScfSock *s, ScfPeer *e, ScfInfo *info);

int rt_udp_process_new_connect(ScfSock *s, ScfInfo *info, char *name, unsigned short port)
{
    ScfHdr hd;
    ScfPeer *e = 0;
    int idx = -1;
    int ret;
    if (info->f4 == 0) return 0;
    for (;;) {
        ret = rt_udp_find_free_connection(s, &idx);
        if (ret != 0) { ret = 7; break; }
        if (idx == -1) { ret = 7; break; }
        e = &s->ents[idx];
        e->f74 = info->f4;
        e->f78 = randomNoneZero();
        e->f7C = randomNoneZero();
        e->f80 = 0;
        e->port = port;
        e->f84 = info->f8;
        strncpy(e->name, name, 16);
        rt_time_start(e->timer);
        e->f70 = 1000;
        e->f6C = 0;
        if (rt_list_buf_create(&e->sendlist, s->pool1) != 0 || rt_list_buf_create(&e->recvlist, s->pool2) != 0) {
            e->type = 6;
            rt_udp_send_reset(s, e);
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
        ret = rt_udp_setup_packet_header(s, e, 4, &hd);
        if (ret != 0) {
fail:
            e->type = 1;
            rt_udp_send_reset(s, e);
            return ret;
        }
        hd.flags |= 0x40;
        ret = rt_udp_buffer_data_for_send(e, &hd, 0, 0);
        if (ret != 0) goto fail;
        ret = rt_udp_send_ack(s, e, info);
        break;
    case 8:
    case 9:
    case 11:
    case 12:
        ret = rt_udp_send_ack(s, e, info);
        break;
    default:
        e->type = 1;
        ret = rt_udp_send_reset(s, e);
        break;
    }
    return ret;
}
/* merge_units: end func_00309FD8 */

/* merge_units: begin func_0030A218 */
typedef struct { unsigned int type; char pad[0x8C]; } ScfPeer_0030A218;
typedef struct { int sock; ScfPeer_0030A218 *ents; } ScfSock_0030A218;
extern int rt_udp_is_duplicate_packet(ScfSock_0030A218 *s, ScfPeer_0030A218 *e, void *p, unsigned char *dup);
#if 0 /* merge_units */
extern int rt_udp_send_ack(ScfSock_0030A218 *s, ScfPeer_0030A218 *e, void *p);
#endif /* merge_units */
#define rt_udp_send_ack(a0, a1, a2) (rt_udp_send_ack((ScfSock *)(a0), (ScfPeer *)(a1), (ScfInfo *)(a2))) /* merge_units */

#if 0 /* merge_units */
extern int rt_udp_send_reset(ScfSock_0030A218 *s, ScfPeer_0030A218 *e);
#endif /* merge_units */
#define rt_udp_send_reset(a0, a1) (rt_udp_send_reset((ScfSock *)(a0), (ScfPeer *)(a1))) /* merge_units */


int rt_udp_process_disconnect(ScfSock_0030A218 *s, void *p, int idx)
{
    ScfPeer_0030A218 *e;
    unsigned char dup = 0;
    if (idx == -1) return 7;
    e = &s->ents[idx];
    rt_udp_is_duplicate_packet(s, e, p, &dup);
    if (!dup) {
        if (e->type == 12) {
            e->type = 3;
            return rt_udp_send_ack(s, e, p);
        } else if (e->type - 4 < 2) {
            return rt_udp_send_ack(s, e, p);
        } else {
            e->type = 1;
            return rt_udp_send_reset(s, e);
        }
    } else {
        return rt_udp_send_ack(s, e, p);
    }
}
#undef rt_udp_send_ack /* merge_units */
#undef rt_udp_send_reset /* merge_units */
/* merge_units: end func_0030A218 */

/* merge_units: begin func_0030A300 */
typedef struct { int type; char pad[0x18]; int f1C; int f20; int f24; int f28; int f2C; int f30; int f34; int f38; int f3C; char pad2[0x4C]; int f8C; } ScfEnt;
typedef struct { int f0; ScfEnt *ent; char pad[0x24]; unsigned int count; } ScfTbl;

extern void rt_list_buf_clear(int *p);
int rt_udp_process_reset(ScfTbl *t, int unused, int idx)
{
    ScfEnt *e;
    int ret = 7;
    if (idx == -1) return ret;
    e = &t->ent[idx];
    if (e->type != 4) {
        e->type = 1;
        rt_list_buf_clear(&e->f1C);
        rt_list_buf_clear(&e->f34);
    }
    return 0;
}
/* merge_units: end func_0030A300 */

/* merge_units: begin func_0030A368 */
typedef struct { unsigned char kind; unsigned char id; unsigned short len; int val; int seq; } ScfHdr_0030A368;
typedef struct { int type; char pad[0x48]; int f4C; char pad2[0x24]; int f74; char pad3[0x18]; } ScfPeer_0030A368;
typedef struct { int sock; ScfPeer_0030A368 *ents; char pad[0x40]; unsigned char b48; } ScfSock_0030A368;
extern void *memset(void *d, int c, unsigned int n);
extern int Libc_Memcmp(const void *a, const void *b, int n);
extern void rt_time_get_time_stamp(int *t);

int rt_udp_process_heartbeat(ScfSock_0030A368 *s, void *key, int idx)
{
    ScfHdr_0030A368 hdr;
    ScfPeer_0030A368 *e;
    int ret = 0;
    if (idx == -1) return 7;
    e = &s->ents[idx];
    memset(&hdr, 0, 12);
    hdr.val = e->f74;
    hdr.id = s->b48;
    if (Libc_Memcmp(&hdr, key, 12) == 0 && e->type == 12) {
        rt_time_get_time_stamp(&e->f4C);
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
extern int rt_udp_calculate_rto(ScfSock_0030A440 *s, ScfPeer_0030A440 *e, unsigned char flags, int seq);
extern int rt_list_buf_get_head(int *list, void **node);
extern unsigned int rt_list_buf_get_data_size(void *node);
extern int rt_udp_get_packet_header(void *node, ScfHdr *out);
extern int rt_list_buf_remove(int *list, void *node);
extern void *rt_list_buf_get_next(void *node);
#if 0 /* merge_units */
extern void rt_time_get_time_stamp(int *timer);
#endif /* merge_units */
#define rt_time_get_time_stamp(a0) (rt_time_get_time_stamp((a0))) /* merge_units */


int rt_udp_process_acknowlege(ScfSock_0030A440 *s, int idx, ScfAckIn *in)
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
    ret = rt_udp_calculate_rto(s, e, aflags, aseq);
    if (rt_list_buf_get_head(&e->list, &node) != 0) return 10;
    while (node != 0) {
        if (rt_list_buf_get_data_size(node) != 0) {
            ret = rt_udp_get_packet_header(node, &hd);
            if (ret == 0 && hd.flags == aflags && hd.seq == aseq) {
                if (rt_list_buf_remove(&e->list, node) != 0) ret = 10;
                if (hd.len == 0) {
                    if (hd.flags & 0x40) e->type = 11;
                    if (hd.flags & 0x10) e->type = 4;
                } else if ((hd.id & 0x80) && hd.len == 0x40) {
                    e->type = 11;
                }
                rt_time_get_time_stamp(e->timer);
                return ret;
            }
        }
        node = rt_list_buf_get_next(node);
    }
    return ret;
}
#undef rt_time_get_time_stamp /* merge_units */
/* merge_units: end func_0030A440 */

/* merge_units: begin func_0030A5C8 */
typedef struct { unsigned char b[12]; } ScfAddr12;
typedef struct { union { unsigned int w; struct { unsigned char flags; unsigned char id; unsigned short len; } f; } u; int val; unsigned int seq; } ScfHdr_0030A5C8;
typedef struct { unsigned int type; char pad[0x30]; int recvlist; char pad2[0x14]; int timer[2]; char pad3[0x2C]; unsigned int f80; char pad4[0xC]; } ScfPeer_0030A5C8;
typedef struct { int sock; ScfPeer_0030A5C8 *ents; char pad[0x20]; void *buf; } ScfSock_0030A5C8;
#if 0 /* merge_units */
extern void rt_time_get_time_stamp(int *timer);
#endif /* merge_units */
#define rt_time_get_time_stamp(a0) (rt_time_get_time_stamp((a0))) /* merge_units */

#if 0 /* merge_units */
extern int rt_udp_is_duplicate_packet(ScfSock_0030A5C8 *s, ScfPeer_0030A5C8 *e, ScfHdr_0030A5C8 *p, unsigned char *dup);
#endif /* merge_units */
#define rt_udp_is_duplicate_packet(a0, a1, a2, a3) (rt_udp_is_duplicate_packet((ScfSock_0030A218 *)(a0), (ScfPeer_0030A218 *)(a1), (void *)(a2), (a3))) /* merge_units */

#if 0 /* merge_units */
extern int rt_udp_send_ack(ScfSock_0030A5C8 *s, ScfPeer_0030A5C8 *e, ScfHdr_0030A5C8 *p);
#endif /* merge_units */
#define rt_udp_send_ack(a0, a1, a2) (rt_udp_send_ack((ScfSock *)(a0), (ScfPeer *)(a1), (ScfInfo *)(a2))) /* merge_units */

extern char *rt_list_buf_get_data_ptr(void *node);
extern int rt_list_buf_get_tail(int *list, void **node);
extern int rt_list_buf_insert(int *list, void *node, void *data, int len);
extern int rt_list_buf_set_new_head(int *list, void *data, int len);

int rt_udp_process_data(ScfSock_0030A5C8 *s, ScfHdr_0030A5C8 *p, int idx)
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
    rt_time_get_time_stamp(e->timer);
    ret = rt_udp_is_duplicate_packet(s, e, p, &dup);
    if (!dup) {
        if ((p->u.w & 6) == 6 || (p->u.f.flags & 4)) {
            int *list = &e->recvlist;
            rt_list_buf_get_head(list, &node);
            for (; node != 0; node = rt_list_buf_get_next(node)) {
                if (rt_list_buf_get_data_size(node) == 0) continue;
                *(ScfAddr12 *)&hd = *(ScfAddr12 *)rt_list_buf_get_data_ptr(node);
                if (!((hd.u.w & 6) == 6 || (hd.u.f.flags & 4))) continue;
                if ((int)(hd.seq - p->seq) > 0) {
                    if (hd.seq <= 0x7FFFFFFE) {
                        if (p->seq > 0x7FFFFFFE) {
                            prev = node;
                            continue;
                        }
                    } else if (p->seq <= 0x7FFFFFFE) goto older;
                    if (prev) {
                        if (rt_list_buf_insert(list, prev, s->buf, p->u.f.len + 12) != 0) return 10;
                    } else {
                        if (rt_list_buf_set_new_head(list, s->buf, p->u.f.len + 12) != 0) return 10;
                    }
                    inserted = 1;
                    break;
                }
older:
                prev = node;
            }
            if (!inserted) {
                if (rt_list_buf_get_tail(list, &node) != 0) return 10;
                if (rt_list_buf_insert(list, node, s->buf, p->u.f.len + 12) != 0) return 10;
            }
            ret = rt_udp_send_ack(s, e, p);
        } else {
            int *list;
            if (p->u.f.flags & 2) e->f80 = p->seq;
            list = &e->recvlist;
            if (rt_list_buf_get_tail(list, &node) != 0) return 10;
            if (rt_list_buf_insert(list, node, s->buf, p->u.f.len + 12) != 0) return 10;
        }
    } else if (p->u.f.flags & 4) {
        ret = rt_udp_send_ack(s, e, p);
    }
    return ret;
}
#undef rt_time_get_time_stamp /* merge_units */
#undef rt_udp_is_duplicate_packet /* merge_units */
#undef rt_udp_send_ack /* merge_units */
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
extern int rt_list_buf_get_tail(int *tbl, void **h);
#endif /* merge_units */
#define rt_list_buf_get_tail(a0, a1) (rt_list_buf_get_tail((a0), (a1))) /* merge_units */

#if 0 /* merge_units */
extern int rt_list_buf_insert(int *tbl, void *h, void *rec, int size);
#endif /* merge_units */
#define rt_list_buf_insert(a0, a1, a2, a3) (rt_list_buf_insert((a0), (a1), (a2), (a3))) /* merge_units */

extern int rt_list_buf_append_data(int *tbl, void *h, void *data, int size);
#if 0 /* merge_units */
extern void rt_list_buf_remove(int *tbl, void *h);
#endif /* merge_units */
#define rt_list_buf_remove(a0, a1) ((void)rt_list_buf_remove((a0), (a1))) /* merge_units */


int rt_udp_process_unconnected_data(Obj_a880 *o, void *key, const char *name, unsigned short port,
                  void *data, unsigned short len)
{
    Rec_a880 rec;
    void *h = 0;
    int err = 0;
    int created = 0;

    if (rt_list_buf_get_tail(&o->tbl, &h) != 0) return 10;
    do {
        strncpy(rec.name, name, 16);
        rec.port = port;
        if (rt_list_buf_insert(&o->tbl, h, &rec, sizeof(rec)) != 0) { err = 10; break; }
        created = 1;
        if (rt_list_buf_get_tail(&o->tbl, &h) != 0) { err = 10; break; }
        if (rt_list_buf_append_data(&o->tbl, h, key, 12) != 0) { err = 10; break; }
        if (rt_list_buf_append_data(&o->tbl, h, data, len) != 0) { err = 10; break; }
    } while (0);
    if (err != 0 && created) {
        if (rt_list_buf_get_tail(&o->tbl, &h) == 0) rt_list_buf_remove(&o->tbl, h);
    }
    return err;
}
#undef strncpy /* merge_units */
#undef rt_list_buf_get_tail /* merge_units */
#undef rt_list_buf_insert /* merge_units */
#undef rt_list_buf_remove /* merge_units */
/* merge_units: end func_0030A880 */

/* merge_units: begin func_0030A9D8 */
typedef struct { unsigned int type; int f4; char name[16]; unsigned short port; char pad[0x5A]; int f74; char pad3[0x18]; } ScfPeer_0030A9D8;
typedef struct { int sock; ScfPeer_0030A9D8 *ents; char pad[0x24]; unsigned int count; } ScfSock_0030A9D8;
typedef struct { int f0; int f4; } ScfPkt;
extern int Libc_Strncmp(const char *a, const char *b, int n);

int rt_udp_find_connection(ScfSock_0030A9D8 *s, ScfPkt *p, const char *name, unsigned short port, int *out)
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
        if (Libc_Strncmp(name, e->name, 16) != 0) continue;
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
