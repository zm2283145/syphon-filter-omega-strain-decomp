typedef struct { void *fn; void *arg; int gp; int pad; } HEnt;
extern HEnt *D_00487868;
extern int D_0048786C;
extern HEnt D_004E9AC8[];
extern int func_001161A0(void);
extern void func_001161F8(void);
extern void *memset(void *, int, unsigned int);
int func_00118310(int which, int arg)
{
    HEnt *tbl, *p;
    int cnt, i, oldgp, prev;
    if (which) {
        tbl = D_004E9AC8;
        cnt = 32;
    } else {
        tbl = D_00487868;
        cnt = D_0048786C;
    }
    __asm__ volatile ("move %0, $gp" : "=r" (oldgp));
    p = tbl;
    for (i = 0; i < cnt; i++, p++) {
        if (p->fn) {
            __asm__ volatile ("move $3, $gp\n\tmove $gp, %0" : : "r" (p->gp) : "$3", "memory");
            ((void (*)(int, void *))p->fn)(arg, p->arg);
        }
    }
    __asm__ volatile ("move %0, $gp\n\tmove $gp, %1" : "=&r" (prev) : "r" (oldgp));
    return prev;
}