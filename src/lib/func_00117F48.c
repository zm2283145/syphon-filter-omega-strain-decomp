typedef struct N7E18 { struct N7E18 *next; volatile int id; void *func; void *arg; } N7E18;
extern N7E18 *volatile D_004E9AC0;
extern int func_001161A0(void);
extern void func_001161F8(void);
extern int func_00117DB8();
static inline N7E18 *node_alloc(void) { N7E18 *n = D_004E9AC0; if (n) D_004E9AC0 = n->next; return n; }
extern int func_001173B0(void);
extern int func_00117A48(int, long, void *, void *);
extern int func_00117608(int);

int func_00117F48(long t, void *h, void *arg)
{
    int id;
    N7E18 *n;
    if (h == 0) return 0x80000016;
    n = node_alloc();
    if (n == 0) return 0x80008005;
    id = func_001173B0();
    if (id < 0) {
        n->next = D_004E9AC0;
        D_004E9AC0 = n;
        n->id = 0;
        return id;
    }
    n->func = h;
    n->arg = arg;
    n->id = id;
    func_00117A48(id, t, func_00117DB8, n);
    func_00117608(id);
    return ((int)n << 4) | (id & 0xFE) | 1;
}