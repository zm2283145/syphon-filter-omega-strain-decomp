typedef struct N7E18 { struct N7E18 *next; volatile int id; void *func; void *arg; } N7E18;
extern N7E18 *volatile D_004E9AC0;
extern int func_001161A0(void);
extern void func_001161F8(void);
extern int func_00117DB8();
static inline N7E18 *node_alloc(void) { N7E18 *n = D_004E9AC0; if (n) D_004E9AC0 = n->next; return n; }
extern int func_00117508(int);

int func_00118038(int id)
{
    N7E18 *n = (N7E18 *)(((unsigned int)id >> 8) << 4);
    int s = func_001161A0();
    if (id < 0 || ((id ^ n->id) & 0xFF)) {
        if (s) func_001161F8();
        return 0x80008002;
    }
    func_00117508(n->id);
    n->next = D_004E9AC0;
    D_004E9AC0 = n;
    n->id = 0;
    if (s) func_001161F8();
    return 0;
}