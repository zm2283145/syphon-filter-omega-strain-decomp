typedef struct N7E18 { struct N7E18 *next; volatile int id; void *func; void *arg; } N7E18;
extern N7E18 *volatile D_004E9AC0;
extern int func_001161A0(void);
extern void func_001161F8(void);
extern int func_00117DB8();
static inline N7E18 *node_alloc(void) { N7E18 *n = D_004E9AC0; if (n) D_004E9AC0 = n->next; return n; }
extern int func_00117420(void);
extern int func_00117B40(int, long, void *, void *);
extern int func_001176B8(int);

int func_00117E18(long t, void *h, void *arg)
{
    int s, id;
    N7E18 *n;
    if (h == 0) return 0x80000016;
    s = func_001161A0();
    n = node_alloc();
    if (n == 0) {
        if (s) func_001161F8();
        return 0x80008005;
    }
    id = func_00117420();
    if (id < 0) {
        n->next = D_004E9AC0;
        D_004E9AC0 = n;
        n->id = 0;
        if (s) func_001161F8();
        return id;
    }
    n->func = h;
    n->arg = arg;
    n->id = id;
    func_00117B40(id, t, func_00117DB8, n);
    func_001176B8(id);
    if (s) func_001161F8();
    return ((int)n << 4) | (id & 0xFE) | 1;
}