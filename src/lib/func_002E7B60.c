typedef struct { int off; int a; int b; int kind; int pad[4]; } E2ED280;
typedef struct { int a; int cnt; char name[0x20]; E2ED280 *objs[64]; int vals[64]; } S2ED280;
typedef struct { unsigned char sidx; unsigned char cnt; unsigned short id; } Hdr2E7B60;
typedef struct {
    unsigned char sidx;
    char pad1[3];
    int h;
    char pad8[0x14];
    char *buf1;
    char *buf2;
    char pad24[0x18];
    int *stamps;
} Obj2E7B60;

extern S2ED280 D_0058DF98[];
extern signed char D_0058C178[];
extern int D_0058806C;
extern void *memcpy(void *, const void *, unsigned int);
extern int NetIGetObject(Obj2E7B60 **out, unsigned int idx);
extern void RemoteObjectUpdate(int a0, int id, int k, int size);

int FieldUpdatePacketHandler(int a0, int a1, unsigned int a2, Hdr2E7B60 *h)
{
    Obj2E7B60 *o = 0;
    unsigned int n = 0;
    int len;
    unsigned char *p;
    S2ED280 *s;
    int k;
    E2ED280 *e;

    if (h == 0) return -1;
    if (a2 >= 0x100) return -1;
    if (h->id >= 0x1000) return -1;
    len = 4;
    p = (unsigned char *)h + 4;
    if (D_0058C178[h->id] != 2) {
        s = &D_0058DF98[h->sidx];
        for (; n < h->cnt; n++) {
            k = *p++;
            if (k >= s->cnt) return -1;
            e = s->objs[k];
            len++;
            if (e == 0) return -1;
            p += e->a * e->b;
            len += e->a * e->b;
        }
        return len;
    }
    {
        int r = NetIGetObject(&o, h->id);
        if (o == 0 || r != 0) return -1;
    }
    s = &D_0058DF98[o->sidx];
    if (s == 0) return -1;
    for (; n < h->cnt; n++) {
        char *dst;
        k = *p++;
        if (k >= s->cnt) return -1;
        e = s->objs[k];
        len++;
        if (e == 0) return -1;
        dst = o->buf2 + s->vals[k];
        memcpy(o->buf1 + s->vals[k], p, e->a * e->b);
        memcpy(dst, p, e->a * e->b);
        {
            /* last resort: sched1 puts the a3 arg copy before the len/p adds, so sz never gets a3 */
            register int sz asm("$7") = e->a;
            sz *= e->b;
            o->stamps[k] = D_0058806C;
            len += sz;
            p += sz;
            RemoteObjectUpdate(o->h, h->id, k, sz);
        }
    }
    return len;
}




