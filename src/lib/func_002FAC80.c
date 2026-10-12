typedef struct N { int size; struct N *next; char data[1]; } N;
typedef struct { int x; N *cur; unsigned int size; unsigned int used; char *buf; N *head; } L;
extern void *memset(void *, int, unsigned int);
extern int func_002FAF18(L *);
extern int func_002FA4C8(L *, unsigned int);
extern int func_002FAC20(L *, N **);
extern int func_002FA5F8(L *, N *, char *, int);
int __attribute__((weak, section(".dtors_drop"))) func_002FA550(L *p) { return 0; }
int func_002FAC80(L *l, N **cur)
{
    L old;
    N *nl = 0;
    N *p;
    int r;
    if (func_002FAF18(l) == 0) return 2;
    old = *l;
    memset(l, 0, 0x18);
    r = func_002FA4C8(l, old.size);
    if (r) {
        *l = old;
        return r;
    }
    for (p = old.head; p; p = p->next) {
        func_002FAC20(l, &nl);
        func_002FA5F8(l, nl, p->data, p->size);
        if (cur && p == *cur) func_002FAC20(l, cur);
    }
    func_002FA550(&old);
    return 0;
}
