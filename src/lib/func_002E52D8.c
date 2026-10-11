typedef struct { int v[256]; } T2E52D8;
extern int func_002E51B8(unsigned int, T2E52D8 **);
int func_002E52D8(unsigned int a, unsigned int b, int *out)
{
    T2E52D8 *p = 0;
    int r;
    if (out == 0) return 0x17;
    *out = 0;
    if (a >= 4) return 0x17;
    if (b >= 0x100) return 0x17;
    r = func_002E51B8(a, &p);
    if (r) return r;
    if (p == 0) return 0xA;
    *out = p->v[b];
    return r;
}
