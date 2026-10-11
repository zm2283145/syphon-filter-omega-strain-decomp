typedef struct N7E18 { struct N7E18 *next; volatile int id; void *func; void *arg; } N7E18;
extern N7E18 *volatile D_004E9AC0;
extern int func_001161A0(void);
extern void func_001161F8(void);
extern int func_00117468(int);

int func_001180E0(int id)
{
    N7E18 *n = (N7E18 *)(((unsigned int)id >> 8) << 4);
    int r;
    if (id < 0 || ((id ^ n->id) & 0xFF)) return 0x80008002;
    r = func_00117468(n->id);
    if (r == 0) {
        n->next = D_004E9AC0;
        D_004E9AC0 = n;
        n->id = 0;
    }
    return r;
}