/*
 * lib/medius: 8 files, 002E31D0-002E4190
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_002E31D0 */
typedef struct { unsigned char mask[0x24]; int n; int f28; } R;
typedef struct { unsigned char f0; unsigned char f1; unsigned short id; } H;
typedef struct { unsigned char f0; unsigned char f1; char pad[0x22]; int f24; int f28; } E;
typedef struct { int h; char data[1]; } M;
extern M D_0051F8D8;
extern unsigned int D_0048C450;
extern unsigned int D_005983F0;
extern int NetIGetObject(E **, unsigned int);
extern void NetGetFilteredObjectTargetClients(R *, unsigned int);
extern unsigned char CheckFieldsForUpdate(E *, unsigned int, unsigned char, unsigned char *, char *, int *);
extern int NetSendTargetClientBitmask(signed char, unsigned int, unsigned int, unsigned int, int, void *, R *);
extern int NetSendDmeMessage(signed char, unsigned int, int, unsigned int, int, void *);

int SendGroupedFieldUpdate(unsigned int id, unsigned char type, unsigned char kind)
{
    H h;
    R r;
    unsigned char fl;
    E *e;
    int len;
    int ret;
    M *m;

    e = 0;
    len = 0;
    fl = 0;
    if (id >= 0x1000) return 0x17;
    ret = NetIGetObject(&e, id);
    if (ret != 0) return ret;
    if (e == 0) return ret;
    if (e->f1 != 0) NetGetFilteredObjectTargetClients(&r, id);
    m = &D_0051F8D8;
    *(int *)&h = 0;
    h.id = id;
    h.f0 = e->f0;
    len = 4;
    h.f1 = CheckFieldsForUpdate(e, id, kind, &fl, m->data, &len);
    m->h = *(int *)&h;
    e->f28 = 0;
    fl |= type;
    e->f24 = 0;
    if (h.f1 == 0) return 0;
    if (e->f1 != 0) NetSendTargetClientBitmask(fl, D_0048C450, 0, D_005983F0, len, m, &r);
    else NetSendDmeMessage(fl, D_0048C450, -1, D_005983F0, len, m);
    return 0;
}
/* merge_units: end func_002E31D0 */

/* merge_units: begin func_002E3340 */
typedef struct { char pad[0x400]; int self; char pad2[0x40]; int n; } S;
typedef struct {
    unsigned char f0; unsigned char f1; unsigned char f2; unsigned char f3;
    int f4; unsigned int f8; char name[0x10];
    char *f1C; char *f20; int f24; int f28; int f2C; int f30; int f34; int *f38; int *f3C;
} E_002E3340;
typedef struct { int pad; int f4; int f8; } X;
typedef struct { int size; int n; char pad[0x20]; X *items[0x40]; int offs[0x40]; } T;
typedef struct {
    unsigned char f0; unsigned char f1; unsigned char f2; unsigned char f3;
    unsigned char f4; unsigned short f6; unsigned short id;
    int fC; int f10; char name[0x10];
} H_002E3340;
extern T D_0058DF98[];
extern char D_0051FAD8[];
extern int D_0058806C;
extern unsigned int D_005983F4;
extern int (*D_00590218[])(int, unsigned int);
#if 0 /* merge_units */
extern int NetIGetObject(E_002E3340 **, unsigned int);
#endif /* merge_units */
#define NetIGetObject(a0, a1) (NetIGetObject((E * *)(a0), (a1))) /* merge_units */

extern int NetGetConnInfo(unsigned int, S **);
extern unsigned char NetClientIndexToClientIndexPacket(unsigned int);
extern char *Libc_Strcpy(char *, const char *);
extern void *memcpy(void *, const void *, unsigned int);
extern int NetIGetClient(int *, unsigned int, int);

int NetISendObjectFullUpdate(int to, unsigned int id)
{
    H_002E3340 h;
    R r;
    E_002E3340 *e;
    S *s;
    T *t;
    register X *x asm("$5"); /* pinned: retail keeps x in a1 across the copy loop */
    int ret;
    int i;
    int off;
    int sz;
    int ok;
    int j;

    e = 0;
    s = 0;
    if (id >= 0x1000) return 0x17;
    NetIGetObject(&e, id);
    if (e == 0) return 0xA;
    ret = NetGetConnInfo(D_0048C450, &s);
    if (ret != 0) return ret;
    if (s == 0) return ret;
    if (e->f1 != 0) {
        if (to == -1) NetGetFilteredObjectTargetClients(&r, id);
        else if (D_00590218[e->f1](to, id) == 0) return 0;
    }
    t = &D_0058DF98[e->f0];
    if (t == 0) return 0xA;
    if (e->f4 != -1 && e->f4 != s->self) return 8;
    off = 0x24;
    h.f0 = NetClientIndexToClientIndexPacket(e->f8);
    h.id = id;
    h.f6 = e->f4;
    h.f1 = e->f0;
    h.f2 = e->f1;
    h.f4 = e->f2;
    h.f3 = e->f3;
    h.fC = e->f2C;
    h.f10 = e->f30;
    Libc_Strcpy(h.name, e->name);
    memcpy(D_0051FAD8, &h, sizeof(h));
    for (i = 0; i < t->n; i++) {
        x = t->items[i];
        if (x == 0) return 0xA;
        sz = x->f4 * x->f8;
        if (sz > 0x1FE - off) break;
        memcpy(&D_0051FAD8[off], e->f1C + t->offs[i], sz);
        off += sz;
        e->f3C[i] = D_0058806C;
    }
    e->f34 = D_0058806C;
    if (to == -1) {
        memcpy(e->f20, e->f1C, t->size);
        for (j = 0; j < s->n; j++) {
            NetIGetClient(&ok, D_0048C450, j);
            if (ok != 0) e->f38[j] = D_0058806C;
        }
    } else {
        e->f38[to] = D_0058806C;
    }
    if (e->f1 != 0 && to == -1) NetSendTargetClientBitmask(0x50, D_0048C450, 0, D_005983F4, off, D_0051FAD8, &r);
    else NetSendDmeMessage(0x50, D_0048C450, to, D_005983F4, off, D_0051FAD8);
    return 0;
}
#undef NetIGetObject /* merge_units */
/* merge_units: end func_002E3340 */

/* merge_units: begin func_002E3718 */
extern int NetIDataStreamBytesFree(int *, unsigned int);
extern int NetGetStreamChannel(unsigned int, char **);
#if 0 /* merge_units */
extern int NetGetConnInfo(unsigned int, char **);
#endif /* merge_units */
#define NetGetConnInfo(a0, a1) (NetGetConnInfo((a0), (S * *)(a1))) /* merge_units */

extern int rt_circ_buf_store(char *, void *, int);
extern int rt_circ_buf_normalize(char *, int);
int NetIAddToDataStream(unsigned int id, void *data, int len)
{
    char *p = 0;
    char *e = 0;
    int avail = 0;
    int r;
    if (id >= 0x800) return 0x17;
    if (data == 0) return 0x17;
    if (len <= 0) return 0x17;
    r = NetIDataStreamBytesFree(&avail, id);
    if (r) return r;
    if (avail < len) return 0x1F;
    r = NetGetStreamChannel(id, &e);
    if (r) return r;
    if (e == 0) return r;
    r = NetGetConnInfo(D_0048C450, &p);
    if (r) return r;
    if (p == 0) return r;
    if (*(int *)(p + 0x400) != *(int *)(e + 0xC)) return 9;
    if (rt_circ_buf_store(e + 0x2C, data, len)) return 0x1F;
    rt_circ_buf_normalize(e + 0x2C, 1);
    memcpy(*(void **)(e + 0x10), *(void **)(e + 0x3C), *(int *)(e + 0x34));
    return 0;
}
#undef NetGetConnInfo /* merge_units */
/* merge_units: end func_002E3718 */

/* merge_units: begin func_002E3830 */
/* EE soft-float double libcalls are aliased to their retail functions. */
__asm__("dpcmp = SoftFloat_UnpackAndCompare\n"
        "dpmul = SoftFloat_DoubleMultiply\n"
        "dpadd = SoftFloat_DoubleAdd\n"
        "dpsub = SoftFloat_DoubleSub\n"
        "fptodp = SoftFloat_FloatToDouble");

typedef struct {
    char pad0[0xC];
    unsigned int type;
    int pad10;
    int mode;
    float thr;
} Cmp2E3830;

#define ABS(x) ((x) < 0 ? -(x) : (x))
#define SQ(x) ((x) * (x))

int ElementErrorExceedsThreshold(Cmp2E3830* c, void* pa, void* pb)
{
    int ret = 0;
    if (c == 0) return ret;
    if (pa == 0) return ret;
    if (pb == 0) return ret;
    switch (c->type) {
    case 0: {
        signed char x = *(signed char*)pa, y = *(signed char*)pb;
        signed char d = x - y < 0 ? y - x : x - y;
        if (c->mode == 1)
            return d != 0;
        return (signed char)c->thr < d;
    }
    case 1: {
        unsigned char x = *(unsigned char*)pa, y = *(unsigned char*)pb;
        unsigned char d = x - y < 0 ? y - x : x - y;
        if (c->mode == 1)
            return d != 0;
        return (unsigned char)c->thr < d;
    }
    case 2: {
        short x = *(short*)pa, y = *(short*)pb;
        short d = x - y < 0 ? y - x : x - y;
        if (c->mode == 1)
            return d != 0;
        return (short)c->thr < d;
    }
    case 3: {
        unsigned short x = *(unsigned short*)pa, y = *(unsigned short*)pb;
        unsigned short d = x - y < 0 ? y - x : x - y;
        if (c->mode == 1)
            return d != 0;
        return (unsigned short)c->thr < d;
    }
    case 4: {
        int d = ABS(*(int*)pa - *(int*)pb);
        if (c->mode == 1)
            return d != 0;
        return (int)c->thr < d;
    }
    case 5: {
        unsigned int d = *(unsigned int*)pa - *(unsigned int*)pb;
        if (c->mode == 1)
            return d != 0;
        return (unsigned int)c->thr < d;
    }
    case 6: {
        float d = ABS(*(float*)pa - *(float*)pb);
        if (c->mode == 1)
            return d != 0.0f;
        return c->thr < d;
    }
    case 7: {
        double d = ABS(*(double*)pa - *(double*)pb);
        if (c->mode == 1)
            return d != 0.0;
        return d > c->thr;
    }
    case 8: {
        short* a = pa; short* b = pb;
        int dx = a[0] - b[0];
        int dy = a[1] - b[1];
        return !((float)(dx * dx + dy * dy) <= c->thr * c->thr);
    }
    case 9: {
        short* a = pa; short* b = pb;
        int dx = a[0] - b[0];
        int dy = a[1] - b[1];
        int dz = a[2] - b[2];
        return !((float)(dx * dx + dy * dy + dz * dz) <= c->thr * c->thr);
    }
    case 10: {
        int* a = pa; int* b = pb;
        int dx = a[0] - b[0];
        int dy = a[1] - b[1];
        return !((float)(dx * dx + dy * dy) <= c->thr * c->thr);
    }
    case 11: {
        int* a = pa; int* b = pb;
        int dx = a[0] - b[0];
        int dy = a[1] - b[1];
        int dz = a[2] - b[2];
        return !((float)(dx * dx + dy * dy + dz * dz) <= c->thr * c->thr);
    }
    case 12: {
        float* a = pa; float* b = pb;
        float dx = a[0] - b[0];
        float dy = a[1] - b[1];
        return !(dx * dx + dy * dy <= c->thr * c->thr);
    }
    case 13: {
        float* a = pa; float* b = pb;
        float dx = a[0] - b[0];
        float dy = a[1] - b[1];
        float dz = a[2] - b[2];
        return !(dx * dx + dy * dy + dz * dz <= c->thr * c->thr);
    }
    case 14: {
        double* a = pa; double* b = pb;
        return !(SQ(a[0] - b[0]) + SQ(a[1] - b[1]) <= (double)(c->thr * c->thr));
    }
    case 15: {
        double* a = pa; double* b = pb;
        return !(SQ(a[0] - b[0]) + SQ(a[1] - b[1]) + SQ(a[2] - b[2]) <= (double)(c->thr * c->thr));
    }
    }
    return ret;
}
/* merge_units: end func_002E3830 */

/* merge_units: begin func_002E3DE0 */
typedef union { struct { int a; int b; int c; int d; int e; int f; } s; int w[6]; } Msg;
typedef struct { int f0; int f4; int f8; int fC; int f10; int f14; int (*f18)(Msg *); } T_002E3DE0;
typedef struct { char pad[0x20]; T_002E3DE0 *t[0x40]; int off[0x40]; } Sub;
typedef struct { int f0; int f4; Sub s; } E_002E3DE0;
typedef struct { unsigned char b0; char pad[0x1B]; int f1C; int f20; } A;
#if 0 /* merge_units */
extern E_002E3DE0 D_0058DF98[];
#endif /* merge_units */
#define D_0058DF98 ((E_002E3DE0*)&D_0058DF98) /* merge_units */

#if 0 /* merge_units */
extern int ElementErrorExceedsThreshold(T_002E3DE0 *, int, int);
#endif /* merge_units */
#define ElementErrorExceedsThreshold(a0, a1, a2) (ElementErrorExceedsThreshold((Cmp2E3830 *)(a0), (void *)(a1), (void *)(a2))) /* merge_units */


unsigned char GlobalFieldErrorExceedsThreshold(A *a, int k, unsigned char n)
{
    Msg m; Msg *mp = &m;
    E_002E3DE0 *e;
    Sub *s;
    T_002E3DE0 *t;
    int p, q, i;

    if (a == 0) return 0;
    e = &D_0058DF98[a->b0];
    s = &e->s;
    if (e == 0) return 0;
    t = s->t[n];
    if (t == 0) return 0;
    p = a->f1C + s->off[n];
    if (p == 0) return 0;
    q = a->f20 + s->off[n];
    if (q == 0) return 0;
    if (t->f14 == 5) {
        mp->s.a = k;
        mp->s.b = n;
        mp->s.e = p;
        mp->s.c = t->f4;
        mp->s.f = q;
        mp->s.d = t->f8;
        if (t->f18 != 0) return t->f18(mp);
        return 0;
    }
    for (i = 0; i < t->f8; i++) {
        if (ElementErrorExceedsThreshold(t, p, q)) return 1;
        p += t->f4;
        q += t->f4;
    }
    return 0;
}
#undef D_0058DF98 /* merge_units */
#undef ElementErrorExceedsThreshold /* merge_units */
/* merge_units: end func_002E3DE0 */

/* merge_units: begin func_002E3F20 */
typedef struct { unsigned char type, f1, cb, f3, f4, pad5; unsigned short size; unsigned short f8; unsigned short len; } H_002E3F20;
typedef struct { H_002E3F20 h; char payload[4]; } Out;
extern int rt_circ_buf_is_wrapped(void *, unsigned char *);
#if 0 /* merge_units */
extern int rt_circ_buf_normalize(void *, int);
#endif /* merge_units */
#define rt_circ_buf_normalize(a0, a1) (rt_circ_buf_normalize((char *)(a0), (a1))) /* merge_units */

extern int rt_circ_buf_get_start_used_ptr(void *, char **);

int NetGetDataStreamPacket(Out *out, unsigned int id, int len)
{
    char *e = 0;
    char *data = 0;
    unsigned char flag = 0;
    int base, sz, f8;
    H_002E3F20 h;

    if (out == 0) return 0;
    if (len <= 0) return 0;
    if (id >= 0x800) return 0;
    if (NetGetStreamChannel(id, &e) != 0 || e == 0) return 0;
    h.type = id;
    h.f1 = e[5];
    h.cb = e[3];
    h.f3 = e[1];
    h.f4 = e[2];
    h.len = len;
    base = *(unsigned short *)(e + 0x10);
    sz = *(unsigned short *)(e + 0x14) - base;
    f8 = *(unsigned short *)(e + 0x18) - base;
    h.size = sz;
    h.f8 = f8;
    out->h = h;
    if (rt_circ_buf_is_wrapped(e + 0x2C, &flag)) return 0;
    if (flag) {
        if (rt_circ_buf_normalize(e + 0x2C, 1)) return 0;
        memcpy(*(void **)(e + 0x10), *(void **)(e + 0x3C), *(int *)(e + 0x34));
    }
    if (rt_circ_buf_get_start_used_ptr(e + 0x2C, &data)) return 0;
    memcpy(out->payload, data, len);
    return len + 0xC;
}
#undef rt_circ_buf_normalize /* merge_units */
/* merge_units: end func_002E3F20 */

/* merge_units: begin func_002E4078 */
extern int D_00590318[];
extern int D_005983F8;
#if 0 /* merge_units */
extern int NetGetConnInfo(unsigned int, char **);
#endif /* merge_units */
#define NetGetConnInfo(a0, a1) (NetGetConnInfo((a0), (S * *)(a1))) /* merge_units */

extern int NetIGetDataStream(unsigned char **, unsigned int);
extern int NetIGetSessionMasterClientIndex(int *, unsigned int);
#if 0 /* merge_units */
extern void NetSendDmeMessage(int, unsigned int, int, int, int, unsigned char *);
#endif /* merge_units */
#define NetSendDmeMessage(a0, a1, a2, a3, a4, a5) ((void)NetSendDmeMessage((signed char)(a0), (a1), (a2), (unsigned int)(a3), (a4), (void *)(a5))) /* merge_units */

void SendCloseDataStream(int x, unsigned int id)
{
    unsigned char *e = 0;
    char *p = 0;
    int st;
    unsigned char b[1];
    if (id >= 0x1000) return;
    if (D_0048C450 >= 4) return;
    if (NetGetConnInfo(D_0048C450, &p)) return;
    if (p == 0) return;
    if (NetIGetDataStream(&e, id)) return;
    if (p == 0) return;
    if (NetIGetSessionMasterClientIndex(&st, D_0048C450)) return;
    if (st < 0) return;
    if (st >= 0x100) return;
    if (D_00590318[e[3]] && *(int *)(p + 0x400) != st && x == -1) x = st;
    b[0] = id;
    NetSendDmeMessage(0x50, D_0048C450, x, D_005983F8, 1, b);
}
#undef NetGetConnInfo /* merge_units */
#undef NetSendDmeMessage /* merge_units */
/* merge_units: end func_002E4078 */

/* merge_units: begin func_002E4190 */
#if 0 /* merge_units */
extern int NetGetStreamChannel(unsigned int, unsigned char **);
#endif /* merge_units */
#define NetGetStreamChannel(a0, a1) (NetGetStreamChannel((a0), (char * *)(a1))) /* merge_units */

extern int rt_circ_buf_get_avail(unsigned char *, int *);
int NetIDataStreamBytesFree(int *out, unsigned int id)
{
    unsigned char *p = 0;
    int v = 0;
    int r;
    if (out == 0) return 0x17;
    *out = 0;
    if (id >= 0x800) return 0x17;
    r = NetGetStreamChannel(id, &p);
    if (r) return r;
    if (p == 0) return 0;
    if (p[0] != 2) return 9;
    if (p[4]) return 9;
    if (p + 0x2C == 0) return 9;
    if (rt_circ_buf_get_avail(p + 0x2C, &v) == 0) {
        *out = v;
        return 0;
    }
    return 9;
}
#undef NetGetStreamChannel /* merge_units */
/* merge_units: end func_002E4190 */
