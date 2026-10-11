typedef struct { int v[256]; } T2E5420;
extern int func_002E51B8(unsigned int, T2E5420 **);
extern void func_002DD328(int *);
int func_002E5420(unsigned int a, unsigned int b)
{
    T2E5420 *p = 0;
    int r;
    if (a >= 4) return 0x17;
    if (b >= 0x100) return 0x17;
    r = func_002E51B8(a, &p);
    if (r) return r;
    if (p) {
        if (p->v[b]) func_002DD328(&p->v[b]);
        p->v[b] = 0;
    }
    return 0;
}
