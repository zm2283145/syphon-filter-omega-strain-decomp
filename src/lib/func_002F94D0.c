typedef struct L2F94D0 { struct L2F94D0 *next; struct L2F94D0 *prev; int a, sub; int b, c, d; void *h1C, *h20, *h24, *h28, *h2C; } L2F94D0;
extern L2F94D0 *D_004908D8;
extern L2F94D0 *func_002F7D68(int);
extern void func_002F7F10(L2F94D0 *, int);
extern void func_002F7E20(int);
extern void func_002FB3C0(void *);
void func_002F94D0(int id)
{
    L2F94D0 *p;
    int s;
    p = func_002F7D68(id);
    if (p == 0) return;
    while ((s = p->sub) != 0) {
        func_002F7F10(p, s);
        func_002F7E20(s);
    }
    if (p->h20) func_002FB3C0(&p->h20);
    if (p->h1C) func_002FB3C0(&p->h1C);
    if (p->h2C) func_002FB3C0(&p->h2C);
    if (p->h24) func_002FB3C0(&p->h24);
    if (p->h28) func_002FB3C0(&p->h28);
    if (D_004908D8 == p) D_004908D8 = p->prev;
    p->prev->next = p->next;
    p->next->prev = p->prev;
    if (D_004908D8 == p) D_004908D8 = 0;
    func_002FB3C0(&p);
}