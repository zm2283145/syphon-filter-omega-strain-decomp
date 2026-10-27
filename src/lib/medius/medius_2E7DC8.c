typedef struct { unsigned char type, f1, cb, f3, f4, pad5; unsigned short size; unsigned short f8; unsigned short len; char payload[4]; } H2E7DC8;
typedef struct { unsigned short pad0; unsigned short pad2; unsigned short pad4; unsigned short pad6; unsigned short pad8; unsigned short base; unsigned short span; } E2E7DC8;
typedef struct { unsigned char state, f1, f2, f3, f4, f5; char pad6[6]; int fC; char *buf; char *end; char *f18; int f1C; int f20; int pad24; int f28; char sub[8]; int f34; int pad38; char *f3C; } O2E7DC8;
extern int NetGetStreamChannel(unsigned char, O2E7DC8 **);
extern char *DMEmalloc(unsigned short);
extern int rt_circ_buf_create(void *, unsigned short, char *);
extern void DmeFree(void *);
extern int NetIGetSessionMasterClientIndex(int *, int);
extern int NetIGetClient(E2E7DC8 **, int, int);
extern int rt_circ_buf_get_avail(void *, unsigned int *);
extern int rt_circ_buf_free(void *, int);
extern int rt_circ_buf_store(void *, char *, unsigned int);
extern int rt_circ_buf_normalize(void *, int);
extern void *memcpy(void *, const void *, unsigned int);
extern void (*D_00598358[])(int, unsigned char, char *, unsigned short);
extern int D_0058806C;
int DataStreamUpdatePacketHandler(int a, int b, int c, H2E7DC8 *h)
{
    O2E7DC8 *o = 0;
    int cnt = 0x100;
    E2E7DC8 *e = 0;
    unsigned int n;
    char *p;
    int i;
    void (*cb)(int, unsigned char, char *, unsigned short);
    if (h == 0) return -1;
    if (NetGetStreamChannel(h->type, &o) != 0 || o == 0) return h->len + 0xC;
    if (o->state != 2) {
        if (h->f4 != 0) {
            o->buf = DMEmalloc(h->size);
            if (o->buf == 0) {
                o->state = 0;
                return h->len + 0xC;
            }
            if (rt_circ_buf_create(o->sub, h->size, o->buf) != 0) {
                DmeFree(&o->buf);
                o->buf = 0;
                return h->len + 0xC;
            }
            o->end = o->buf + h->size;
            o->f3 = h->cb;
            o->f5 = h->f1;
            o->f18 = o->buf;
            o->f1C = 0;
            o->f1 = h->f3;
            o->f2 = h->f4;
            o->f4 = 0;
            o->f20 = 90000;
            o->f28 = 0;
        }
        o->state = 2;
        NetIGetSessionMasterClientIndex(&cnt, a);
        if (c != cnt) {
            o->fC = c;
        } else {
            for (i = 0; i < 0x100; i++) {
                if (NetIGetClient(&e, a, i) != 0) continue;
                if (e == 0) continue;
                if ((int)(h->type - e->base) < e->span) {
                    o->fC = i;
                    break;
                }
            }
        }
    }
    p = h->payload;
    if (h->f4 != 0) {
        n = 0;
        if (rt_circ_buf_get_avail(o->sub, &n) == 0) {
            if (h->f3 != 0) {
                if (rt_circ_buf_free(o->sub, h->len - n) == 0) {
                    rt_circ_buf_store(o->sub, p, h->len);
                    rt_circ_buf_normalize(o->sub, 1);
                    memcpy(o->buf, o->f3C, o->f34);
                }
            } else if (n != 0) {
                n = h->len < n ? h->len : n;
                rt_circ_buf_store(o->sub, p, n);
                memcpy(o->buf, o->f3C, o->f34);
            }
        }
    }
    cb = D_00598358[h->cb];
    if (cb) cb(c, h->type, p, h->len);
    o->f28 = D_0058806C;
    return h->len + 0xC;
}




