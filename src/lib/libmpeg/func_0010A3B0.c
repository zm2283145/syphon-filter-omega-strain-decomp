typedef struct {
    unsigned long buf;
    unsigned char *base;
    unsigned char *ptr;
    unsigned int bits;
    int pad14;
    unsigned long pos;
    unsigned char *start;
    unsigned char *end;
    int size;
} BsA3B0;

typedef struct {
    long id;
    int len;
    int scramble;
    long pts;
    long dts;
    int x20;
    int x24;
    int x28;
} PesA3B0;

typedef enum { CbA3B0_NONE = 0, CbA3B0_STR = 6 } CbTypeA3B0;

typedef struct {
    CbTypeA3B0 type;
    unsigned char *header;
    unsigned char *data;
    unsigned int len;
    long pts;
    long dts;
} CbArgA3B0;

typedef struct {
    unsigned int pack[6];
    PesA3B0 pes;
} HdrA3B0;

typedef int (*HandlerA3B0)(void *, CbArgA3B0 *, void *);

typedef struct {
    unsigned long key;
    unsigned long mask;
    HandlerA3B0 handler;
    void *arg;
    void *gp;
    int pad;
} HookA3B0;

typedef struct {
    char pad[0x60];
    HookA3B0 *hooks;
    int count;
} LibA3B0;

typedef struct {
    char pad[0x40];
    LibA3B0 *lib;
} CtxA3B0;

extern void func_00109F18(BsA3B0 *, unsigned char *, unsigned char *, int);
extern unsigned int func_00109F50(BsA3B0 *, int);
extern unsigned char *func_0010A0F8(BsA3B0 *, int);
extern int func_0010A7D8(BsA3B0 *, unsigned int *);
extern int func_0010A998(LibA3B0 *, BsA3B0 *, PesA3B0 *);

static __inline__ void *ChangeGP_A3B0(void *gp)
{
    void *old;
    /* $gp swap: register moves only expressible in asm */
    __asm__ volatile("move %0, $gp\n\tmove $gp, %1" : "=&r"(old) : "r"(gp) : "memory");
    return old;
}

static __inline__ void SetGP_A3B0(void *gp)
{
    /* $gp restore: register move only expressible in asm */
    __asm__ volatile("move $gp, %0" : : "r"(gp) : "memory");
}

int func_0010A3B0(CtxA3B0 *m, unsigned char *p, int n, unsigned char *start, int size)
{
    BsA3B0 bs;
    HdrA3B0 hdr;
    CbArgA3B0 cb;
    BsA3B0 *b;
    HdrA3B0 *hp = &hdr;
    LibA3B0 *lib = m->lib;
    HandlerA3B0 deffunc = 0;
    void *defarg = 0;
    HookA3B0 *hooks = lib->hooks;
    int ret = 0;
    void *defgp;
    int cont = 1;
    int i;
    void *old;

    func_00109F18(&bs, p, start, size);
    b = &bs;
    for (i = 0; !deffunc && i < lib->count; i++) {
        if (hooks[i].key == 0xBDFF000000) {
            deffunc = hooks[i].handler;
            defarg = hooks[i].arg;
            defgp = hooks[i].gp;
        }
    }
    do {
        if (func_00109F50(b, 32) == 0x1BA)
            func_0010A7D8(b, hp->pack);
        while (func_00109F50(b, 24) == 1 && func_00109F50(b, 32) != 0x1BA
               && func_00109F50(b, 32) != 0x1B9 && b->pos < n * 8 && cont) {
            func_0010A998(lib, b, &hp->pes);
            if (n * 8 < b->pos)
                continue;
            for (i = 0; i < lib->count; i++) {
                if (hooks[i].key == (hp->pes.id & hooks[i].mask)) {
                    cb.type = CbA3B0_STR;
                    cb.header = func_0010A0F8(b, hp->pes.x28);
                    cb.data = func_0010A0F8(b, hp->pes.x20);
                    cb.len = hp->pes.x24;
                    cb.pts = hp->pes.pts;
                    cb.dts = hp->pes.dts;
                    old = ChangeGP_A3B0(hooks[i].gp);
                    cont = hooks[i].handler(m, &cb, hooks[i].arg);
                    SetGP_A3B0(old);
                    break;
                }
            }
            if (i == lib->count && deffunc) {
                cb.type = CbA3B0_STR;
                cb.header = func_0010A0F8(b, hp->pes.x28);
                cb.data = func_0010A0F8(b, hp->pes.x20);
                cb.len = hp->pes.x24;
                cb.pts = hp->pes.pts;
                cb.dts = hp->pes.dts;
                old = ChangeGP_A3B0(defgp);
                cont = deffunc(m, &cb, defarg);
                SetGP_A3B0(old);
            }
            if (cont)
                ret = b->pos >> 3;
        }
        if (n * 8 < b->pos)
            break;
    } while (func_00109F50(b, 32) == 0x1BA);
    return ret;
}
