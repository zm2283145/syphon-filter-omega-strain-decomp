typedef struct SifServe07F8 { int command; void *func; void *buff; int xC; void *cfunc; void *cbuff; char pad[0x20]; struct SifServe07F8 *next; struct SifServe07F8 *link; void *base; } SifServe07F8;
typedef struct { int x0; int x4; SifServe07F8 *link; } SifQueue07F8;
extern int func_001161A0(void);
extern void func_001161F8(void);

void func_001107F8(SifServe07F8 *sd, int id, void *func, void *buf, void *cfunc, void *cbuf, SifQueue07F8 *qd)
{
    SifServe07F8 *p;
    func_001161A0();
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
    func_001161F8();
}

