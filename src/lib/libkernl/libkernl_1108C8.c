/*
 * lib/libkernl: 8 files, 001108C8-00110D38
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_001108C8 */
typedef struct N08C8 { char pad[0x38]; struct N08C8 *next; } N08C8;
typedef struct { char pad[0x8]; struct N08C8 *head; } L08C8;
extern int func_001161A0(void);
extern int func_001161F8(void);

N08C8 *func_001108C8(N08C8 *it, L08C8 *l)
{
    N08C8 *p, *n;
    func_001161A0();
    p = l->head;
    if (p == it) {
        l->head = p->next;
    } else if (p) {
        while (p->next != it) {
            p = p->next;
            if (!p) goto out;
        }
        p->next = it->next;
    }
out:
    func_001161F8();
    return p;
}
/* merge_units: end func_001108C8 */

/* merge_units: begin func_00110960 */
typedef struct N0960 { char pad[0x14]; struct N0960 *next; } N0960;
typedef struct { char pad[0x28]; struct N0960 *head; } L0960;
extern L0960 D_004E4780;

N0960 *func_00110960(N0960 *it)
{
    N0960 *p, *n;
    func_001161A0();
    p = D_004E4780.head;
    if (p == it) {
        D_004E4780.head = p->next;
    } else if (p) {
        while (p->next != it) {
            p = p->next;
            if (!p) goto out;
        }
        p->next = it->next;
    }
out:
    func_001161F8();
    return p;
}
/* merge_units: end func_00110960 */

/* merge_units: begin func_001109F0 */
typedef struct N09F0 { char pad[0x3C]; struct N09F0 *next; } N09F0;
typedef struct { int x0; int busy; int x8; N09F0 *head; } Q09F0;

N09F0 *func_001109F0(Q09F0 *q)
{
    N09F0 *n;
    func_001161A0();
    n = q->head;
    if (n == 0) {
        q->busy = 0;
    } else {
        q->busy = 1;
        q->head = n->next;
    }
    func_001161F8();
    return n;
}
/* merge_units: end func_001109F0 */

/* merge_units: begin func_00110A48 */
typedef struct { int src; int dest; int size; int attr; } DmaT;
typedef struct { int x0; int (*func)(int, int, int); int buf; int size; int x10; int x14; int x18; void *client; int pkt_addr; int rpc_number; int receive; int rsize; int rmode; unsigned int rid; } Srv;
typedef struct { int x0[4]; int rec_id; int x14; int rpc_id; void *client; int cid; } Rend;
#if 0 /* merge_units */
extern char D_004E4780[];
#endif /* merge_units */
#define D_004E4780 ((char*)&D_004E4780) /* merge_units */

extern void func_0010FB10(int, int);
extern Rend *func_0010FE80(void *, int);
extern Rend *func_0010FE50(void *);
extern int func_0010F948(unsigned int, void *, int, int, int, int);
extern unsigned int sceSifSetDma(DmaT *, int);
void func_00110A48(Srv *sd)
{
    DmaT dmat[2];
    Rend *rend;
    int rec;
    int index, sz = 0, id, i;

    rec = sd->func(sd->rpc_number, sd->buf, sd->size);
    if (rec)
        sz = sd->rsize;
    if (sd->size > 0)
        func_0010FB10(sd->buf, sd->size);
    if (sz > 0)
        func_0010FB10(rec, sz);
    func_001161A0();
    if (sd->rid & 4)
        rend = func_0010FE80(D_004E4780, sd->rid >> 16);
    else
        rend = func_0010FE50(D_004E4780);
    func_001161F8();
    rend->cid = 0x8000000A;
    rend->client = sd->client;
    if (sd->rmode) {
        while (!func_0010F948(0x80000008, rend, 0x40, rec, sd->receive, sz))
            ;
        return;
    }
    rend->rpc_id = 0;
    rend->rec_id = 0;
    index = 0;
    if (sz > 0) {
        dmat[index].src = rec;
        dmat[index].dest = sd->receive;
        dmat[index].size = sz;
        dmat[index].attr = 0;
        index++;
    }
    dmat[index].src = (int)rend;
    dmat[index].dest = sd->pkt_addr;
    dmat[index].size = 0x40;
    dmat[index].attr = 0;
    index++;
    do {
        id = sceSifSetDma(dmat, index);
        if (id == 0) {
            i = 0x100000; while (i--) ;
        }
    } while (id == 0);
}
#undef D_004E4780 /* merge_units */
/* merge_units: end func_00110A48 */

/* merge_units: begin func_00110C10 */
#if 0 /* merge_units */
extern void *func_001109F0(void *);
#endif /* merge_units */
#define func_001109F0(a0) ((void *)func_001109F0((Q09F0 *)(a0))) /* merge_units */

#if 0 /* merge_units */
extern void func_00110A48(void *);
#endif /* merge_units */
#define func_00110A48(a0) (func_00110A48((Srv *)(a0))) /* merge_units */

extern void SleepThread(void);

void func_00110C10(void *q)
{
    void *n;
    for (;;) {
        while ((n = func_001109F0(q)) != 0) func_00110A48(n);
        SleepThread();
    }
}
#undef func_001109F0 /* merge_units */
#undef func_00110A48 /* merge_units */
/* merge_units: end func_00110C10 */

/* merge_units: begin func_00110C50 */
typedef struct { int currentCount; int maxCount; int initCount; int numWaitThreads; unsigned int attr; unsigned int option; } SemaParam0C50;
extern int CreateSema(SemaParam0C50 *);
int D_00486248 = -1;
int D_0048624C = -1;

void func_00110C50(void)
{
    SemaParam0C50 p;
    if (D_00486248 == -1) {
        p.option = 0;
        p.initCount = 1;
        p.maxCount = 1;
        D_00486248 = CreateSema(&p);
        D_0048624C = CreateSema(&p);
    }
}
/* merge_units: end func_00110C50 */

/* merge_units: begin func_00110CB0 */
typedef struct { int x0; int x4; int x8; int xC; } Ent0CB0;
extern Ent0CB0 D_004E5D00[];
extern int D_00486248;
extern void func_00110C50(void);
extern int WaitSema(int);
extern int SignalSema(int);

Ent0CB0 *func_00110CB0(void)
{
    Ent0CB0 *e;
    func_00110C50();
    WaitSema(D_00486248);
    for (e = D_004E5D00; e < D_004E5D00 + 32; e++) {
        if (e->x4 == 0) {
            e->x4 = 0x10000000;
            SignalSema(D_00486248);
            return e;
        }
    }
    SignalSema(D_00486248);
    return 0;
}
/* merge_units: end func_00110CB0 */

/* merge_units: begin func_00110D38 */
typedef struct { int a[4]; } Ent0D38;
#if 0 /* merge_units */
extern Ent0D38 D_004E5D00[];
#endif /* merge_units */
#define D_004E5D00 ((Ent0D38*)&D_004E5D00) /* merge_units */


Ent0D38 *func_00110D38(unsigned int idx)
{
    Ent0D38 *r;
    func_00110C50();
    WaitSema(D_00486248);
    if (idx >= 32) {
        SignalSema(D_00486248);
        return 0;
    }
    r = &D_004E5D00[idx];
    SignalSema(D_00486248);
    return r;
}
#undef D_004E5D00 /* merge_units */
/* merge_units: end func_00110D38 */
