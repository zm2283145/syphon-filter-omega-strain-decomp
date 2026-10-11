typedef struct N { int a; struct N *next; } N;
typedef struct { int x; N *cur; N *end; int p3, p4; N *f14; } L;
extern int func_002FAF18(L *);
extern int func_002FABD0(L *, N **);
extern int func_002FA5F8(L *, N *, int, int);
extern N *func_002FAF00(N *);
int func_002FA758(L *l, int b, int c)
{
    N *n[1];
    N *m;
    int r;
    n[0] = 0;
    if (func_002FAF18(l) == 0) return 2;
    if (b == 0) return 2; if (c == 0) return 2;
    r = func_002FABD0(l, n);
    if (r) return r;
    r = func_002FA5F8(l, n[0], b, c);
    if (r) return r;
    r = func_002FABD0(l, n);
    if (r) return r;
    m = func_002FAF00(n[0]);
    if (m) {
        l->f14 = m;
        n[0]->next = m->next;
        m->next = n[0];
    }
    if (l->cur == l->end) l->cur = 0;
    return 0;
}

