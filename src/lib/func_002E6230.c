typedef struct { int type; int a; int b; } E6230;
extern void *memset(void *, int, unsigned int);
extern void (*D_0048C480)(E6230 *);
extern int D_0048C484;
void func_002E6230(int a)
{
    void (**pf)(E6230 *) = &D_0048C480;
    E6230 e;
    if (*pf == 0) return;
    memset(&e, 0, 0xC);
    e.a = a;
    e.b = D_0048C484;
    e.type = 0;
    (*pf)(&e);
}