typedef struct { int gen; int x4; int x8; char pad[0x74]; } E2BB520;
extern E2BB520 D_0051AAC0[];
extern int D_0048C098;
extern void func_002BC808(void);
extern void SyncDCache(void *, void *);
extern int sceDbcGetConnection(int);
E2BB520 *SyncDma(int a)
{    E2BB520 *p = D_0051AAC0;
    E2BB520 *q;
    int g0;
    D_0048C098 = 0;
    func_002BC808();
    SyncDCache(p, (char *)p + 0xFF);
    g0 = p->gen;
    q = p + 1;
    if (g0 > D_0048C098 && g0 > q->gen) {
        D_0048C098 = g0;
        return p;
    }
    if (q->gen > D_0048C098 && q->gen > g0) {
        D_0048C098 = q->gen;
        return &D_0051AAC0[1];
    }    if (sceDbcGetConnection(a) == 3) {
        p->x8 = 0;
        return p;
    }
    p->x8 = 0;
    return p;
}
