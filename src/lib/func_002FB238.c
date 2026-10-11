typedef struct N { int size; struct N *next; } N;
typedef struct { int x; unsigned int cur; unsigned int end; int free; int base; N *last; } L;
extern int func_002FABD0(L *, N **);
int func_002FB238(L *l)
{
    N *n[1];
    unsigned int m = 0;
    int r;
    n[0] = 0;
    r = func_002FABD0(l, n);
    if (r) return r;
    while (n[0]) {
        unsigned int e = (int)n[0] + ((n[0]->size + 3) & ~3) - l->base + 8;
        n[0] = n[0]->next;
        if (m < e) m = e;
    }
    l->cur = (m + 3) & ~3;
    if (l->cur == l->end) l->cur = 0;
    return 0;
}
