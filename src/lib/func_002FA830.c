typedef struct N { int size; struct N *next; } N;
typedef struct { int x; N *cur; N *end; int free; int p4; N *last; } L;
extern int func_002FAF18(L *);
extern int func_002FB128(L *, N *, N **);
extern int func_002FAF48(L *);
extern int func_002FB1C0(L *);
extern int func_002FB238(L *);
int func_002FA830(L *l, N *n)
{
    N *prev[1];
    int r;
    prev[0] = 0;
    if (func_002FAF18(l) == 0) return 2;
    if (n == 0) return 2;
    if (n != l->last) {
        r = func_002FB128(l, n, prev);
        if (r) return r;
        prev[0]->next = n->next;
        l->free = l->free - ((n->size + 3) & ~3) - 8;
    } else {
        N *nx = n->next;
        if (nx == 0) {
            l->x = 0;
            l->cur = 0;
            l->free = 0;
            r = func_002FAF48(l);
            if (r) return r;
        } else {
            l->last = nx;
            l->free = l->free - ((n->size + 3) & ~3) - 8;
        }
    }
    r = func_002FB1C0(l);
    if (r) return r;
    return func_002FB238(l);
}
