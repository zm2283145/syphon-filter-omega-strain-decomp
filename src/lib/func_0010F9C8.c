/* _sceSifCmdIntrHdlr: libkernel SIF command interrupt handler (copies packet, dispatches sys/usr cmd). */
typedef int u_long128 __attribute__((mode(TI)));
typedef struct { void (*func)(void *, void *); void *arg; void *gp; } SifCmdHandler;
typedef struct {
    void *buf;
    int f4;
    int f8;
    SifCmdHandler *sys;
    int nsys;
    SifCmdHandler *usr;
    int nusr;
} SifCmdData;
typedef struct { unsigned int psize:8; unsigned int dsize:24; unsigned int dest; int cid; unsigned int opt; } SifCmdHeader;
extern SifCmdData D_004E2D58;
extern void isceSifSetDChain(void);

static inline void *_change_gp(void *gp)
{
    void *old;
    __asm__ volatile("move %0, $gp\n\tmove $gp, %1" : "=&r"(old) : "r"(gp) : "memory");
    return old;
}

static inline void *_enter_gp(void *gp)
{
    void *old;
    /* pin: retail loads the new gp into v1 in both dispatch branches */
    register void *ngp __asm__("$3") = gp;
    __asm__ volatile("move %0, $gp\n\tmove $gp, %1" : "=&r"(old) : "r"(ngp) : "memory");
    return old;
}

int _sceSifCmdIntrHdlr(int ca)
{
    u_long128 pkt[7];
    SifCmdData *d = &D_004E2D58;
    volatile SifCmdHeader *h = (volatile SifCmdHeader *)d->buf;
    int size, n, i, id;
    /* pin: retail reloads cid into v1 for the sign test */
    register int cid __asm__("$3");
    u_long128 *src;
    u_long128 *dst;
    void (*func)(void *, void *);
    void *gp;
    volatile SifCmdHeader *vh;

    size = h->psize;
    /* keeps the handler argument live here, which shifts allocation to match retail */
    __asm__("" : : "r"(ca));
    if (size == 0)
        return 0;
    size = (size + 15) / 16;
    n = size;
    h->psize = 0;
    src = (u_long128 *)h;
    if (n > 0) {
        dst = pkt;
        i = n;
        do {
            *dst++ = *src++;
        } while (--i);
    }
    isceSifSetDChain();
    vh = (volatile SifCmdHeader *)pkt;
    if ((cid = vh->cid) < 0) {
        id = vh->cid & 0x7FFFFFFF;
        if (id < d->nsys) {
            func = d->sys[id].func;
            if (func) {
                gp = _enter_gp(d->sys[id].gp);
                func(pkt, d->sys[id].arg);
                _change_gp(gp);
            }
        }
    } else {
        id = vh->cid;
        if (id < d->nusr) {
            func = d->usr[id].func;
            if (func) {
                gp = _enter_gp(d->usr[id].gp);
                func(pkt, d->usr[id].arg);
                _change_gp(gp);
            }
        }
    }
    __asm__ volatile("sync\n\tei");
    return 0;
}

