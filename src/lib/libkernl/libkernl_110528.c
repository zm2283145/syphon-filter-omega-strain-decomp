/*
 * lib/libkernl: 4 files, 00110528-001107F8
 * One translation unit merged from per-function files by tools/merge_units.py
 * (docs/merge_units.md); each `merge_units: begin` block is one original file.
 */

/* merge_units: begin func_00110528 */
typedef struct { int count; int max_count; int init_count; int wait_threads; unsigned int attr; unsigned int option; } Sema;
typedef struct { int x0[4]; int rec_id; int pkt_addr; int rpc_id; int client; int rpc_number; int send_size; int receive; int recv_size; int rmode; int server; } CallPkt;
typedef struct { int pkt_addr; int rpc_id; int sema_id; int mode; int command; int buff; int gp; int end_function; void *end_param; int server; } Client;
extern char D_004E4780[];
extern CallPkt *func_0010FD88(void *);
extern void func_0010FB10(void *, int);
extern void func_0010FE30(void *);
extern int func_0010F948(unsigned int, void *, int, void *, void *, int);
extern int CreateSema(Sema *);
extern int DeleteSema(int);
extern int WaitSema(int);
int sceSifCallRpc(Client *cd, int rpc_number, int mode, void *sendbuf, int ssize, void *recvbuf, int rsize, void *endfunc, void *efarg)
{
    Sema sema;
    CallPkt *call;
    void *gp;

    call = func_0010FD88(D_004E4780);
    if (!call)
        return -1;
    cd->end_param = efarg;
    cd->rpc_id = call->rpc_id;
    cd->pkt_addr = (int)call;
    cd->end_function = (int)endfunc;
    __asm__ volatile("move %0, $gp" : "=r"(gp));
    cd->gp = (int)gp;
    call->rpc_number = rpc_number;
    call->send_size = ssize;
    call->receive = (int)recvbuf;
    call->recv_size = rsize;
    call->pkt_addr = (int)call;
    { int s = cd->server; call->client = (int)cd; call->server = s; }

    if (!(mode & 2)) {
        if (sendbuf == recvbuf) {
            func_0010FB10(sendbuf, ssize < rsize ? rsize : ssize);
        } else {
            if (ssize > 0)
                func_0010FB10(sendbuf, ssize);
            if (rsize > 0)
                func_0010FB10(recvbuf, rsize);
        }
    }

    if (mode & 1) {
        if (!endfunc)
            call->rmode = 0;
        else
            call->rmode = 1;
        cd->sema_id = -1;
        if (func_0010F948(0x8000000A, call, 0x40, sendbuf, (void *)cd->buff, ssize))
            return 0;
        func_0010FE30(call);
        return -2;
    }

    sema.init_count = 0;
    sema.max_count = 1;
    cd->sema_id = CreateSema(&sema);
    if (cd->sema_id < 0) {
        func_0010FE30(call);
        return -3;
    }
    call->rmode = 1;
    if (!func_0010F948(0x8000000A, call, 0x40, sendbuf, (void *)cd->buff, ssize)) {
        DeleteSema(cd->sema_id);
        func_0010FE30(call);
        return -2;
    }
    WaitSema(cd->sema_id);
    DeleteSema(cd->sema_id);
    return 0;
}
/* merge_units: end func_00110528 */

/* merge_units: begin func_00110720 */
#define F_(b, o, T) (*(T*)((char*)(b) + (o)))
#define NULL 0
#pragma mpwc_relax on
int sceSifCheckStatRpc(int arg0) {
    int temp_a1;

    temp_a1 = F_(arg0, 0x0, int);
    if ((temp_a1 == NULL) || (F_(arg0, 0x4, int) != F_(temp_a1, 0x18, int)) || !(F_(temp_a1, 0x10, int) & 1)) {
        return 0;
    }
    return 1;
}
/* merge_units: end func_00110720 */

/* merge_units: begin func_00110760 */
typedef struct N0760 { int x0, x4, x8, xC, x10; struct N0760 *next; } N0760;
typedef struct { char pad[0x28]; N0760 *head; } L0760;
#if 0 /* merge_units */
extern L0760 D_004E4780;
#endif /* merge_units */
#define D_004E4780 (*(L0760*)&D_004E4780) /* merge_units */

extern int DIntr(void);
extern void EIntr(void);

void func_00110760(N0760 *n, int x)
{
    N0760 *p;
    DIntr();
    n->x0 = x;
    n->x4 = 0;
    n->x8 = 0;
    n->xC = 0;
    n->x10 = 0;
    n->next = 0;
    if (D_004E4780.head == 0) {
        D_004E4780.head = n;
    } else {
        p = D_004E4780.head;
        while (p->next) p = p->next;
        p->next = n;
    }
    EIntr();
}
#undef D_004E4780 /* merge_units */
/* merge_units: end func_00110760 */

/* merge_units: begin func_001107F8 */
typedef struct SifServe07F8 { int command; void *func; void *buff; int xC; void *cfunc; void *cbuff; char pad[0x20]; struct SifServe07F8 *next; struct SifServe07F8 *link; void *base; } SifServe07F8;
typedef struct { int x0; int x4; SifServe07F8 *link; } SifQueue07F8;

void func_001107F8(SifServe07F8 *sd, int id, void *func, void *buf, void *cfunc, void *cbuf, SifQueue07F8 *qd)
{
    SifServe07F8 *p;
    DIntr();
    sd->link = 0;
    sd->next = 0;
    /* Keep link clearing ahead of command publication. */
    __asm__ __volatile__("" ::: "memory");
    sd->command = id;
    /* Keep registration state before the queue snapshot. */
    __asm__ __volatile__("" ::: "memory");
    sd->func = func;
    sd->buff = buf;
    sd->cfunc = cfunc;
    sd->cbuff = cbuf;
    sd->base = qd;
    if (qd->link == 0) {
        qd->link = sd;
    } else {
        p = qd->link;
        while (p->next) p = p->next;
        p->next = sd;
    }
    EIntr();
}
/* merge_units: end func_001107F8 */
